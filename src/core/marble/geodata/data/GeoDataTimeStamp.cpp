//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2010      Harshit Jain <hjain.itbhu@gmail.com>
//

// Qt
#include <QDataStream>
#include <QDateTime>

// GeoData
#include "GeoDataTimeStamp.h"
#include "GeoDataTypes.h"

namespace Marble
{

class GeoDataTimeStampPrivate
{
public:
    QDateTime m_when;
    GeoDataTimeStamp::TimeResolution m_resolution;

public:
    GeoDataTimeStampPrivate() :  m_resolution(GeoDataTimeStamp::SecondResolution){}
};

///////////////////////////////////////////////////////////////////////////////////

GeoDataTimeStamp::GeoDataTimeStamp() : GeoDataTimePrimitive(),
    d(new GeoDataTimeStampPrivate)
{}

GeoDataTimeStamp::GeoDataTimeStamp(const GeoDataTimeStamp &other)
    : GeoDataTimePrimitive(other), d(new GeoDataTimeStampPrivate(*other.d))
{}

GeoDataTimeStamp::~GeoDataTimeStamp()
{
    delete d;
}

GeoDataTimeStamp &GeoDataTimeStamp::operator=(const GeoDataTimeStamp &other)
{
    GeoDataTimePrimitive::operator=(other);
    *d = *other.d;
    return *this;
}

bool GeoDataTimeStamp::operator==(const GeoDataTimeStamp &other) const
{
    return equals(other)
           && d->m_resolution == other.d->m_resolution
           && d->m_when == other.d->m_when;
}

bool GeoDataTimeStamp::operator!=(const GeoDataTimeStamp &other) const
{
    return !this->operator==(other);
}


const char *GeoDataTimeStamp::nodeType() const
{
    return GeoDataTypes::GeoDataTimeStampType;
}

QDateTime GeoDataTimeStamp::when() const
{
    return d->m_when;
}

void GeoDataTimeStamp::setWhen(const QDateTime &when)
{
    d->m_when = when;
}

void GeoDataTimeStamp::setResolution(GeoDataTimeStamp::TimeResolution resolution)
{
    d->m_resolution = resolution;
}

GeoDataTimeStamp::TimeResolution GeoDataTimeStamp::resolution() const
{
    return d->m_resolution;
}

void GeoDataTimeStamp::pack(QDataStream &stream) const
{
    GeoDataTimePrimitive::pack(stream);

    stream << d->m_when;
}

void GeoDataTimeStamp::unpack(QDataStream &stream)
{
    GeoDataTimePrimitive::unpack(stream);

    stream >> d->m_when;
}

}
