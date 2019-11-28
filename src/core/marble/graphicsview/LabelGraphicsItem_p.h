//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2009      Bastian Holst <bastianholst@gmx.de>
//

#ifndef MARBLE_LABELGRAPHICSITEMPRIVATE_H
#define MARBLE_LABELGRAPHICSITEMPRIVATE_H

#include <QString>
#include <QSizeF>
#include <QImage>
#include <QFont>
#include <QIcon>

#include "FrameGraphicsItem_p.h"

namespace Marble
{

class LabelGraphicsItem;

class LabelGraphicsItemPrivate : public FrameGraphicsItemPrivate
{
public:
    LabelGraphicsItemPrivate(LabelGraphicsItem *labelGraphicsItem, MarbleGraphicsItem *parent);

    // TODO: This has to go up to MarbleGraphicsItem
    static QFont font();

    QString m_text;
    QImage m_image;
    QIcon m_icon;

    QSizeF m_minimumSize;
};

} // namespace Marble

#endif
