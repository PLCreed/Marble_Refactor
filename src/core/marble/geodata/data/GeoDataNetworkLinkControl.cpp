//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2013      Mohammed Nafees <nafees.technocool@gmail.com>
//

#include <QDateTime>

#include "GeoDataNetworkLinkControl.h"
#include "GeoDataContainer_p.h"
#include "GeoDataAbstractView.h"
#include "GeoDataUpdate.h"
#include "GeoDataTypes.h"

namespace Marble
{

class GeoDataNetworkLinkControlPrivate : public GeoDataContainerPrivate
{
public:
    qreal m_minRefreshPeriod;
    qreal m_maxSessionLength;
    QString m_cookie;
    QString m_message;
    QString m_linkName;
    QString m_linkDescription;
    QString m_linkSnippet;
    int m_maxLines;
    QDateTime m_expires;
    GeoDataUpdate m_update;
    GeoDataAbstractView *m_abstractView;

public:
    GeoDataNetworkLinkControlPrivate() :
        m_minRefreshPeriod(0.0),
        m_maxSessionLength(0.0),
        m_maxLines(2),
        m_expires(),
        m_update(),
        m_abstractView(nullptr)
    {}

    GeoDataNetworkLinkControlPrivate(const GeoDataNetworkLinkControlPrivate &other) :
        GeoDataContainerPrivate(other),
        m_minRefreshPeriod(other.m_minRefreshPeriod),
        m_maxSessionLength(other.m_maxSessionLength),
        m_cookie(other.m_cookie),
        m_message(other.m_message),
        m_linkName(other.m_linkName),
        m_linkDescription(other.m_linkDescription),
        m_linkSnippet(other.m_linkSnippet),
        m_maxLines(other.m_maxLines),
        m_expires(other.m_expires),
        m_update(other.m_update),
        m_abstractView(other.m_abstractView ? other.m_abstractView->copy() : nullptr)
    {}

    ~GeoDataNetworkLinkControlPrivate() override
    {
        delete m_abstractView;
    }

    GeoDataNetworkLinkControlPrivate &operator=(const GeoDataNetworkLinkControlPrivate &other)
    {
        GeoDataContainerPrivate::operator=(other);
        m_minRefreshPeriod = other.m_minRefreshPeriod;
        m_maxSessionLength = other.m_maxSessionLength;
        m_cookie   = other.m_cookie;
        m_message  = other.m_message;
        m_linkName = other.m_linkName;
        m_linkDescription = other.m_linkDescription;
        m_linkSnippet = other.m_linkSnippet;
        m_maxLines = other.m_maxLines;
        m_expires  = other.m_expires;
        m_update = other.m_update;

        delete m_abstractView;
        m_abstractView = other.m_abstractView ? other.m_abstractView->copy() : nullptr;

        return *this;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////

GeoDataNetworkLinkControl::GeoDataNetworkLinkControl()
    : GeoDataContainer(new GeoDataNetworkLinkControlPrivate)
{}

GeoDataNetworkLinkControl::GeoDataNetworkLinkControl(const GeoDataNetworkLinkControl &other)
    : GeoDataContainer(other, new GeoDataNetworkLinkControlPrivate(*other.d_func()))
{}

GeoDataNetworkLinkControl &GeoDataNetworkLinkControl::operator=(const GeoDataNetworkLinkControl &other)
{
    if (this != &other)
    {
        Q_D(GeoDataNetworkLinkControl);
        *d = *other.d_func();
    }

    return *this;
}

bool GeoDataNetworkLinkControl::operator==(const GeoDataNetworkLinkControl &other) const
{
    Q_D(const GeoDataNetworkLinkControl);
    const GeoDataNetworkLinkControlPrivate *const other_d = other.d_func();

    if (!GeoDataContainer::equals(other)
        || (d->m_minRefreshPeriod != other_d->m_minRefreshPeriod)
        || (d->m_maxSessionLength != other_d->m_maxSessionLength)
        || (d->m_cookie != other_d->m_cookie)
        || (d->m_message != other_d->m_message)
        || (d->m_linkName != other_d->m_linkName)
        || (d->m_linkDescription != other_d->m_linkDescription)
        || (d->m_linkSnippet != other_d->m_linkSnippet)
        || (d->m_maxLines != other_d->m_maxLines)
        || (d->m_expires != other_d->m_expires)
        || (d->m_update != other_d->m_update))
    {
        return false;
    }

    if (!d->m_abstractView && !other_d->m_abstractView)
    {
        return true;
    }
    if ((!d->m_abstractView && other_d->m_abstractView)
        || (d->m_abstractView && !other_d->m_abstractView))
    {
        return false;
    }

    if (*d->m_abstractView != *other_d->m_abstractView)
    {
        return false;
    }

    return true;
}

bool GeoDataNetworkLinkControl::operator!=(const GeoDataNetworkLinkControl &other) const
{
    return !this->operator==(other);
}

GeoDataNetworkLinkControl::~GeoDataNetworkLinkControl()
{}

GeoDataFeature *GeoDataNetworkLinkControl::clone() const
{
    return new GeoDataNetworkLinkControl(*this);
}


const char *GeoDataNetworkLinkControl::nodeType() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return GeoDataTypes::GeoDataNetworkLinkControlType;
}

qreal GeoDataNetworkLinkControl::minRefreshPeriod() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_minRefreshPeriod;
}

void GeoDataNetworkLinkControl::setMinRefreshPeriod(qreal minRefreshPeriod)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_minRefreshPeriod = minRefreshPeriod;
}

qreal GeoDataNetworkLinkControl::maxSessionLength() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_maxSessionLength;
}

void GeoDataNetworkLinkControl::setMaxSessionLength(qreal maxSessionLength)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_maxSessionLength = maxSessionLength;
}

QString GeoDataNetworkLinkControl::cookie() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_cookie;
}

void GeoDataNetworkLinkControl::setCookie(const QString &cookie)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_cookie = cookie;
}

QString GeoDataNetworkLinkControl::message() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_message;
}

void GeoDataNetworkLinkControl::setMessage(const QString &message)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_message = message;
}

QString GeoDataNetworkLinkControl::linkName() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_linkName;
}

void GeoDataNetworkLinkControl::setLinkName(const QString &linkName)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_linkName = linkName;
}

QString GeoDataNetworkLinkControl::linkDescription() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_linkDescription;
}

void GeoDataNetworkLinkControl::setLinkDescription(const QString &linkDescription)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_linkDescription = linkDescription;
}

QString GeoDataNetworkLinkControl::linkSnippet() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_linkSnippet;
}

void GeoDataNetworkLinkControl::setLinkSnippet(const QString &linkSnippet)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_linkSnippet = linkSnippet;
}

int GeoDataNetworkLinkControl::maxLines() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_maxLines;
}

void GeoDataNetworkLinkControl::setMaxLines(int maxLines)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_maxLines = maxLines;
}

QDateTime GeoDataNetworkLinkControl::expires() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_expires;
}

void GeoDataNetworkLinkControl::setExpires(const QDateTime &expires)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_expires = expires;
}

GeoDataUpdate &GeoDataNetworkLinkControl::update()
{
    Q_D(GeoDataNetworkLinkControl);
    return d->m_update;
}

const GeoDataUpdate &GeoDataNetworkLinkControl::update() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_update;
}

void GeoDataNetworkLinkControl::setUpdate(const GeoDataUpdate &update)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_update = update;
}

GeoDataAbstractView *GeoDataNetworkLinkControl::abstractView() const
{
    Q_D(const GeoDataNetworkLinkControl);
    return d->m_abstractView;
}

void GeoDataNetworkLinkControl::setAbstractView(GeoDataAbstractView *abstractView)
{
    Q_D(GeoDataNetworkLinkControl);
    d->m_abstractView = abstractView;
    d->m_abstractView->setParent(this);
}

}
