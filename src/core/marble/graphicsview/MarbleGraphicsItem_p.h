//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2009-2010 Bastian Holst <bastianholst@gmx.de>
//

#ifndef MARBLE_MARBLEGRAPHICSITEMPRIVATE_H
#define MARBLE_MARBLEGRAPHICSITEMPRIVATE_H

// Qt
#include <QDebug>
#include <QList>
#include <QSet>
#include <QSize>
#include <QSizeF>
#include <QRect>
#include <QPixmap>

// Marble
#include "AbstractMarbleGraphicsLayout.h"
#include "MarbleGraphicsItem.h"

namespace Marble
{

class MarbleGraphicsItemPrivate
{
public:
    QSizeF m_size;
    bool m_repaintNeeded;
    MarbleGraphicsItem::CacheMode m_cacheMode;
    QPixmap m_pixmap;
    bool m_visibility;

    MarbleGraphicsItem *const m_marbleGraphicsItem;

    // The parent of the item
    MarbleGraphicsItem *const m_parent;

    // The set of children.
    QSet<MarbleGraphicsItem *> m_children;
    // The layout handling the positions of the children
    AbstractMarbleGraphicsLayout *m_layout;

public:
    explicit MarbleGraphicsItemPrivate(MarbleGraphicsItem *marbleGraphicsItem,
                                       MarbleGraphicsItem *parent = nullptr) :
        m_repaintNeeded(true),
        m_cacheMode(MarbleGraphicsItem::NoCache),
        m_visibility(true),
        m_marbleGraphicsItem(marbleGraphicsItem),
        m_parent(parent),
        m_children(),
        m_layout(nullptr)
    {
        if (m_parent)
        {
            m_parent->d_func()->addChild(m_marbleGraphicsItem);
        }
    }

    virtual ~MarbleGraphicsItemPrivate()
    {
        // Remove from parent
        if (m_parent)
        {
            m_parent->d_func()->removeChild(m_marbleGraphicsItem);
        }

        // Delete all children
        qDeleteAll(m_children.toList());   // delete using a copy, since children may invalidate m_children's iterator

        // Delete Layout
        delete m_layout;
    }

    void addChild(MarbleGraphicsItem *child)
    {
        m_children.insert(child);
    }

    void removeChild(MarbleGraphicsItem *child)
    {
        m_children.remove(child);
    }

    virtual QVector<QPointF> positions() const = 0;

    virtual QVector<QPointF> absolutePositions() const = 0;

    /**
     * @brief Used to get the set of screen bounding rects
     */
    QVector<QRectF> boundingRects() const;

    virtual void setProjection(const ViewportParams *viewport) = 0;

    void updateChildPositions()
    {
        // This has to be done recursively because we need a correct size from all children.
        for (MarbleGraphicsItem *item: m_children)
        {
            item->d_func()->updateChildPositions();
        }

        // Adjust positions
        if (m_layout)
        {
            m_layout->updatePositions(m_marbleGraphicsItem);
        }
    }
};

}

#endif
