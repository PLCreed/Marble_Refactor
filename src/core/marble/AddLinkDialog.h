//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2015      Mikhail Ivchenko <ematirov@gmail.com>
//

#ifndef ADDLINKDIALOG_H
#define ADDLINKDIALOG_H

#include <QDialog>

#include "marble_export.h"

namespace Marble {

class MARBLE_EXPORT AddLinkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddLinkDialog(QWidget *parent = nullptr);
    ~AddLinkDialog() override;
    QString name() const;
    QString url() const;

private slots:
    void checkFields();

private:
    class Private;
    Private *const d;
};

}

#endif
