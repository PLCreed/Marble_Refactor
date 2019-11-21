//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2017      Mohammed Nafees <nafees.technocool@gmail.com>
//

#ifndef MARBLE_GEODATABUILDING_H
#define MARBLE_GEODATABUILDING_H

#include <QVector>

#include "geodata_export.h"
#include "GeoDataGeometry.h"
#include "GeoDataCoordinates.h"

namespace Marble {
class GeoDataBuildingPrivate;
class GeoDataMultiGeometry;

/**
 *  @class GeoDataBuilding
 *  @brief Contains important information about a building and its floors (levels)
 *
 *  GeoDataBuilding holds information such as minimum floor, maximum floor,
 *  floor data and their respective MultiGeometry and other possible metadata such
 *  as the total height of the building, type etc.
 */
class GEODATA_EXPORT GeoDataBuilding : public GeoDataGeometry
{
public:
    struct NamedEntry
    {
        GeoDataCoordinates point;
        QString            label;
    };
    static double parseBuildingHeight(const QString &buildingHeight);

public:
    explicit GeoDataBuilding();
    explicit GeoDataBuilding(const GeoDataGeometry &other);
    explicit GeoDataBuilding(const GeoDataBuilding &other);
    ~GeoDataBuilding() override;

    GeoDataBuilding &operator=(const GeoDataBuilding &other);

    const char *nodeType() const override;
    EnumGeometryId geometryId() const override;
    GeoDataGeometry *copy() const override;

    double height() const;
    void setHeight(double height);

    int minLevel() const;
    void setMinLevel(int minLevel);

    int maxLevel() const;
    void setMaxLevel(int maxLevel);

    /**
     * @brief the non existent levels in the building
     */
    QVector<int> nonExistentLevels() const;
    /**
     * @brief Sets the non existent levels of the building
     */
    void setNonExistentLevels(const QVector<int> &nonExistentLevels);

    /**
     * @brief the multigeometry associated with the building
     */
    GeoDataMultiGeometry *multiGeometry() const;

    /**
     * @brief the latlonaltbox for the contained multigeometry
     */
    const GeoDataLatLonAltBox &latLonAltBox() const override;

    QString name() const;
    void setName(const QString &name);

    QVector<NamedEntry> entries() const;
    void setEntries(const QVector<NamedEntry> &entries);

private:
    GeoDataBuildingPrivate *const d;
};

}

#endif
