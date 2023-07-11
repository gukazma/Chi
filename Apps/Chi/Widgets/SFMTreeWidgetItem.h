#pragma once
#include "BaseTreeWidgetItem.h"
#include "Core/Project.h"
class SFMTreeWidgetItem : public BaseTreeWidgetItem
{
public:
    SFMTreeWidgetItem() = default;

    virtual void execMenu();

private:
    void updateMenu();

    QMenu* m_menu;
};