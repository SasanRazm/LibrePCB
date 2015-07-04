/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROJECT_SGI_SYMBOL_H
#define PROJECT_SGI_SYMBOL_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include <QtWidgets>
#include "sgi_base.h"

/*****************************************************************************************
 *  Forward Declarations
 ****************************************************************************************/

class SchematicLayer;

namespace project {
class SI_Symbol;
}

namespace library {
class Symbol;
class SymbolText;
}

/*****************************************************************************************
 *  Class SGI_Symbol
 ****************************************************************************************/

namespace project {

/**
 * @brief The SGI_Symbol class
 *
 * @author ubruhin
 * @date 2014-08-23
 */
class SGI_Symbol final : public SGI_Base
{
    public:

        // Constructors / Destructor
        explicit SGI_Symbol(SI_Symbol& symbol) noexcept;
        ~SGI_Symbol() noexcept;

        // General Methods
        void updateCacheAndRepaint() noexcept;

        // Inherited from QGraphicsItem
        QRectF boundingRect() const noexcept {return mBoundingRect;}
        QPainterPath shape() const noexcept {return mShape;}
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);


    private:

        // make some methods inaccessible...
        SGI_Symbol() = delete;
        SGI_Symbol(const SGI_Symbol& other) = delete;
        SGI_Symbol& operator=(const SGI_Symbol& rhs) = delete;

        // Private Methods
        SchematicLayer* getSchematicLayer(uint id) const noexcept;


        // Types

        struct CachedTextProperties_t {
            QString text;
            int fontPixelSize;
            qreal scaleFactor;
            bool rotate180;
            int flags;
            QRectF textRect;    // not scaled
        };


        // General Attributes
        SI_Symbol& mSymbol;
        const library::Symbol& mLibSymbol;
        QFont mFont;

        // Cached Attributes
        QRectF mBoundingRect;
        QPainterPath mShape;
        QHash<const library::SymbolText*, CachedTextProperties_t> mCachedTextProperties;
};

} // namespace project

#endif // PROJECT_SGI_SYMBOL_H