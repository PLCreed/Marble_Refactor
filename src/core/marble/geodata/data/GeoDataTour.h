//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2013 Illya Kovalevskyy <illya.kovalevskyy@gmail.com>
//

#ifndef GEODATATOUR_H
#define GEODATATOUR_H

#include "geodata_export.h"
#include "GeoDataFeature.h"

namespace Marble
{

class GeoDataPlaylist;
class GeoDataSoundCue;

class GeoDataTourPrivate;

class GEODATA_EXPORT GeoDataTour : public GeoDataFeature
{
public:
    static const GeoDataTour null;

public:
    GeoDataTour();
    GeoDataTour(const GeoDataTour &other);
    ~GeoDataTour() override;

    GeoDataTour &operator=(const GeoDataTour &other);

    bool operator==(const GeoDataTour &other) const;
    bool operator!=(const GeoDataTour &other) const;

    GeoDataFeature *clone() const override;

    GeoDataPlaylist *playlist();
    const GeoDataPlaylist *playlist() const;
    void setPlaylist(GeoDataPlaylist *playlist);

    const char *nodeType() const override;

private:
    Q_DECLARE_PRIVATE(GeoDataTour)

};

} // namespace Marble

#endif // GEODATATOUR_H
