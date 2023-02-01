// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Yerbas Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef YERBAS_QT_ASSETCONTROLTREEWIDGET_H
#define YERBAS_QT_ASSETCONTROLTREEWIDGET_H

#include <QKeyEvent>
#include <QTreeWidget>

class AssetControlTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit AssetControlTreeWidget(QWidget *parent = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // YERBAS_QT_ASSETCONTROLTREEWIDGET_H
