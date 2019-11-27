//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2009      Patrick Spendrin <ps_ml@gmx.de>
//

#ifndef MARBLE_ABSTRACTPROJECTIONPRIVATE_H
#define MARBLE_ABSTRACTPROJECTIONPRIVATE_H

#include <QtGlobal>

namespace Marble
{

class AbstractProjection;

class AbstractProjectionPrivate
{
public:
    Q_DECLARE_PUBLIC(AbstractProjection)

    qreal m_maxLat;
    qreal m_minLat;
    mutable qreal m_previousResolution;
    mutable qreal m_level;
    AbstractProjection *const q_ptr;

public:
    explicit AbstractProjectionPrivate(AbstractProjection *parent) :
        m_maxLat(0),
        m_minLat(0),
        m_previousResolution(-1),
        m_level(-1),
        q_ptr(parent)
    {}

    virtual ~AbstractProjectionPrivate() { }

    int levelForResolution(qreal resolution) const
    {
        if (m_previousResolution == resolution)
            return int(m_level);

        m_previousResolution = resolution;

        if (resolution < 0.0000005)
            m_level = 17;
        else if (resolution < 0.0000010)
            m_level = 16;
        else if (resolution < 0.0000020)
            m_level = 15;
        else if (resolution < 0.0000040)
            m_level = 14;
        else if (resolution < 0.0000080)
            m_level = 13;
        else if (resolution < 0.0000160)
            m_level = 12;
        else if (resolution < 0.0000320)
            m_level = 11;
        else if (resolution < 0.0000640)
            m_level = 10;
        else if (resolution < 0.0001280)
            m_level = 9;
        else if (resolution < 0.0002560)
            m_level = 8;
        else if (resolution < 0.0005120)
            m_level = 7;
        else if (resolution < 0.0010240)
            m_level = 6;
        else if (resolution < 0.0020480)
            m_level = 5;
        else if (resolution < 0.0040960)
            m_level = 4;
        else if (resolution < 0.0081920)
            m_level = 3;
        else if (resolution < 0.0163840)
            m_level = 2;
        else
            m_level = 1;

        return int(m_level);
    }

};

} // namespace Marble

#endif
