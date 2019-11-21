//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2012 Illya Kovalevskyy <illya.kovalevskyy@gmail.com>
//

#ifndef GEODATATOURPRIMITIVE_H
#define GEODATATOURPRIMITIVE_H

#include "geodata_export.h"
#include "GeoDataObject.h"

namespace Marble
{

class GEODATA_EXPORT GeoDataTourPrimitive : public GeoDataObject
{
public:
    bool operator==(const GeoDataTourPrimitive &other) const;
    bool operator!=(const GeoDataTourPrimitive &other) const;
};

} // namespace Marble

#endif // GEODATATOURPRIMITIVE_H
