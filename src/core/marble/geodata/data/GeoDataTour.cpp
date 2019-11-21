//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2013 Illya Kovalevskyy <illya.kovalevskyy@gmail.com>
//

#include "GeoDataTour.h"
#include "GeoDataFeature_p.h"
#include "GeoDataTypes.h"
#include "GeoDataPlaylist.h"

namespace Marble
{

class GeoDataTourPrivate : public GeoDataFeaturePrivate
{
public:
    GeoDataPlaylist *m_playlist;

public:
    GeoDataTourPrivate() :
        m_playlist(nullptr)
    {
        // nothing to do
    }
    GeoDataTourPrivate(const GeoDataTourPrivate &other)
        : GeoDataFeaturePrivate(other),
        m_playlist(nullptr)
    {
        if (other.m_playlist)
        {
            m_playlist = new GeoDataPlaylist(*other.m_playlist);
        }
    }

    ~GeoDataTourPrivate() override
    {
        delete m_playlist;
    }

    GeoDataTourPrivate &operator=(const GeoDataTourPrivate &other)
    {
        if (this == &other)
        {
            return *this;
        }

        GeoDataFeaturePrivate::operator=(other);

        GeoDataPlaylist *newPlaylist = nullptr;
        if (other.m_playlist)
        {
            newPlaylist = new GeoDataPlaylist(*other.m_playlist);
        }
        delete m_playlist;
        m_playlist = newPlaylist;

        return *this;
    }

};


///TODO why????
const GeoDataTour GeoDataTour::null;// = GeoDataTour();

GeoDataTour::GeoDataTour() : GeoDataFeature(new GeoDataTourPrivate)
{
    // nothing to do
}

GeoDataTour::GeoDataTour(const GeoDataTour &other)
    : GeoDataFeature(other, new GeoDataTourPrivate(*other.d_func()))
{}

GeoDataTour::~GeoDataTour()
{
    // nothing to do;
}

GeoDataTour &GeoDataTour::operator=(const GeoDataTour &other)
{
    if (this != &other)
    {
        Q_D(GeoDataTour);
        *d = *other.d_func();
    }

    return *this;
}

bool GeoDataTour::operator==(const GeoDataTour &other) const
{
    Q_D(const GeoDataTour);
    return equals(other)
           && *d->m_playlist == *other.d_func()->m_playlist;
}

bool GeoDataTour::operator!=(const GeoDataTour &other) const
{
    return !this->operator==(other);
}

GeoDataFeature *GeoDataTour::clone() const
{
    return new GeoDataTour(*this);
}

GeoDataPlaylist *GeoDataTour::playlist()
{
    Q_D(GeoDataTour);
    return d->m_playlist;
}

const GeoDataPlaylist *GeoDataTour::playlist() const
{
    Q_D(const GeoDataTour);
    return d->m_playlist;
}

void GeoDataTour::setPlaylist(GeoDataPlaylist *playlist)
{
    Q_D(GeoDataTour);
    d->m_playlist = playlist;
    d->m_playlist->setParent(this);
}

const char *GeoDataTour::nodeType() const
{
    return GeoDataTypes::GeoDataTourType;
}

} // namespace Marble
