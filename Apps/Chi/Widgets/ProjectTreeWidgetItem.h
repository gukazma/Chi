#pragma once
#include "BaseTreeWidgetItem.h"
class Project;
class ProjectTreeWidgetItem : public BaseTreeWidgetItem
{
    Q_OBJECT
public:
    ProjectTreeWidgetItem(Project* project);
    ~ProjectTreeWidgetItem() = default;

    void execMenu();

public slots:
    void slot_newSFMProject();

private:
    QMenu* m_menu;
    void   updateMenu();
};