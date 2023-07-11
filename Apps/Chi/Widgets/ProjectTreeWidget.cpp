#include "ProjectTreeWidget.h"
#include "BaseTreeWidgetItem.h"
#include "ProjectTreeWidgetItem.h"
#include <QApplication>
ProjectTreeWidget::ProjectTreeWidget(QWidget* parent)
    : QTreeWidget(parent)
{
    connect(this,
            SIGNAL(itemPressed(QTreeWidgetItem*, int)),
            this,
            SLOT(slot_pressed(QTreeWidgetItem*, int)));
}

ProjectTreeWidget::~ProjectTreeWidget() {}

void ProjectTreeWidget::newProject(Project* project)
{
    ProjectTreeWidgetItem* projectitem = new ProjectTreeWidgetItem(project);
    this->addTopLevelItem(projectitem);
}

void ProjectTreeWidget::slot_pressed(QTreeWidgetItem* item, int value)
{
    BaseTreeWidgetItem* baseitem = dynamic_cast<BaseTreeWidgetItem*>(item);
    if (nullptr == item) return;

    if (qApp->mouseButtons() == Qt::RightButton) {
        baseitem->execMenu();
    }
}
