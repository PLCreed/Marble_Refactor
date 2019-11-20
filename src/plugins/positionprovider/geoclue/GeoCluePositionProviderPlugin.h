//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2009      Eckhart Wörner <ewoerner@kde.org>
//

#ifndef GEOCLUEPOSITIONPROVIDERPLUGIN_H
#define GEOCLUEPOSITIONPROVIDERPLUGIN_H

#include "GeoCute/Position.h"
#include "GeoCute/Status.h"

#include "PositionProviderPlugin.h"
#include "GeoDataAccuracy.h"
#include "GeoDataCoordinates.h"

namespace GeoCute
{
class PositionProvider;
}

namespace Marble
{

class GeoCluePositionProviderPlugin : public PositionProviderPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.kde.marble.GeoCluePositionProviderPlugin")
    Q_INTERFACES(Marble::PositionProviderPluginInterface)

public:
    GeoCluePositionProviderPlugin();
    ~GeoCluePositionProviderPlugin() override;

    QString name() const override;
    QString nameId() const override;
    QString guiString() const override;
    QString version() const override;
    QString description() const override;
    QString copyrightYears() const override;
    QVector<PluginAuthor> pluginAuthors() const override;
    QIcon icon() const override;
    void initialize() override;
    bool isInitialized() const override;

    PositionProviderPlugin *newInstance() const override;

    PositionProviderStatus status() const override;
    GeoDataCoordinates position() const override;
    GeoDataAccuracy accuracy() const override;
    QString error() const override;
    qreal speed() const override;
    qreal direction() const override;
    QDateTime timestamp() const override;

private:
    GeoCute::PositionProvider *m_positionProvider;
    PositionProviderStatus m_status;
    GeoDataCoordinates m_position;
    GeoDataAccuracy m_accuracy;

private Q_SLOTS:
    void updatePosition(GeoCute::Position newPosition);
    void updateStatus(GeoCute::Status newStatus);
};

}



#endif
