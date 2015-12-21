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

#ifndef LIBRARY_PACKAGEPAD_H
#define LIBRARY_PACKAGEPAD_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include <librepcbcommon/uuid.h>
#include <librepcbcommon/fileio/if_xmlserializableobject.h>

/*****************************************************************************************
 *  Class PackagePad
 ****************************************************************************************/

namespace library {

/**
 * @brief The PackagePad class
 */
class PackagePad final : public IF_XmlSerializableObject
{
        Q_DECLARE_TR_FUNCTIONS(PackagePad)

    public:

        // Constructors / Destructor
        explicit PackagePad(const Uuid& uuid = Uuid::createRandom(),
                            const QString& name = QString()) noexcept;
        explicit PackagePad(const XmlDomElement& domElement) throw (Exception);
        ~PackagePad() noexcept;

        // Getters
        const Uuid& getUuid() const noexcept {return mUuid;}
        QString getName() const noexcept {return mName;}

        // Setters
        void setName(const QString& name) noexcept;

        // General Methods

        /// @copydoc IF_XmlSerializableObject#serializeToXmlDomElement()
        XmlDomElement* serializeToXmlDomElement() const throw (Exception) override;


    private:

        // make some methods inaccessible...
        PackagePad(const PackagePad& other);
        PackagePad& operator=(const PackagePad& rhs);

        // Private Methods

        /// @copydoc IF_XmlSerializableObject#checkAttributesValidity()
        bool checkAttributesValidity() const noexcept override;


        // Pin Attributes
        Uuid mUuid;
        QString mName;
};

} // namespace library

#endif // LIBRARY_PACKAGEPAD_H
