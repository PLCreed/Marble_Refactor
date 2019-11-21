//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2010      Harshit Jain <hjain.itbhu@gmail.com>
//

#ifndef MARBLE_GEODATATIMEPRIMITIVE_H
#define MARBLE_GEODATATIMEPRIMITIVE_H

#include "geodata_export.h"
#include "GeoDataObject.h"

namespace Marble
{

class GeoDataTimePrimitivePrivate;

/**
 * @short a base class for the style classes
 *
 * A GeoDataTimePrimitive is a base class for the time classes TimeSpan
 * and TimeStamp classes.
 *
 * @see GeoDataTimeSpan
 * @see GeoDataTimeStamp
 */
class GEODATA_EXPORT GeoDataTimePrimitive : public GeoDataObject
{
public:
    GeoDataTimePrimitive();
    GeoDataTimePrimitive(const GeoDataTimePrimitive &other);
    ~GeoDataTimePrimitive() override;

    const char *nodeType() const override;

    GeoDataTimePrimitive &operator=(const GeoDataTimePrimitive &other);

    /**
     * @brief Serialize the styleselector to a stream
     * @param  stream  the stream
     */
    void pack(QDataStream &stream) const override;

    /**
     * @brief  Unserialize the styleselector from a stream
     * @param  stream  the stream
     */
    void unpack(QDataStream &stream) override;

private:
    GeoDataTimePrimitivePrivate *const d;
};

}

#endif
