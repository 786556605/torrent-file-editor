/*
 * Copyright (C) 2015  Ivan Romanov <drizt@land.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <QAbstractItemModel>

class AbstractTreeItem;

class AbstractTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit AbstractTreeModel(AbstractTreeItem *root, QObject *parent = 0);
    ~AbstractTreeModel();

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex	parent(const QModelIndex & index) const;
    int	rowCount(const QModelIndex & parent = QModelIndex()) const;

protected:
    AbstractTreeItem *root() const;

private:
    AbstractTreeItem *_root;
};
