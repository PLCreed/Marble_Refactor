//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2010      Bastian Holst <bastianholst@gmx.de>
//

#ifndef MARBLE_DATAMIGRATION_H
#define MARBLE_DATAMIGRATION_H

#include <QObject>

#include "marble_export.h"

namespace Marble
{

class MARBLE_EXPORT DataMigration : public QObject
{
    Q_OBJECT

public:
    explicit DataMigration(QObject *parent);
    ~DataMigration() override;

public slots:
    void exec();

private:
    static void moveFiles(const QString &source, const QString &target);
};

}

#endif // MARBLE_DATAMIGRATION_H
