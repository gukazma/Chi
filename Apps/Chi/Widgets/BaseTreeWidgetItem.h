#pragma once
#include <QObject>
#include <QTreeWidgetItem>
class QMenu;
class BaseTreeWidgetItem : public QObject, public QTreeWidgetItem
{
    Q_OBJECT
public:
    BaseTreeWidgetItem()  = default;
    ~BaseTreeWidgetItem() = default;
    virtual void execMenu() {}

private:
};