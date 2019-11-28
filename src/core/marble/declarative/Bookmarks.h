//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2012      Dennis Nienhüser <nienhueser@kde.org>
//

#ifndef MARBLE_DECLARATIVE_BOOKMARKS_H
#define MARBLE_DECLARATIVE_BOOKMARKS_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "GeoDataTreeModel.h"
#include "Placemark.h"

namespace Marble {

class MarbleQuickItem;

class BookmarksModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    explicit BookmarksModel(QObject *parent = nullptr);

    int count() const;

public slots:
    qreal longitude(int index) const;

    qreal latitude(int index) const;

    QString name(int index) const;

signals:
    void countChanged();
};

class Bookmarks : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Marble::MarbleQuickItem *map READ map WRITE setMap NOTIFY mapChanged)
    Q_PROPERTY(BookmarksModel * model READ model NOTIFY modelChanged)

public:
    explicit Bookmarks(QObject *parent = nullptr);

    MarbleQuickItem *map();

    void setMap(MarbleQuickItem *widget);

    BookmarksModel *model();

    Q_INVOKABLE bool isBookmark(qreal longitude, qreal latitude) const;

    Q_INVOKABLE Placemark *placemark(int index);

public slots:
    void addBookmark(Placemark *placemark, const QString &folder);
    void removeBookmark(qreal longitude, qreal latitude);
    void updateBookmarkDocument();

signals:
    void mapChanged();

    void modelChanged();

private:
    MarbleQuickItem *m_marbleQuickItem;
    BookmarksModel *m_proxyModel;
    GeoDataTreeModel m_treeModel;
};

}

#endif
