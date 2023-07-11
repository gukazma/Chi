#include "ProjectTreeWidgetItem.h"
#include "Core/Project.h"
#include "Widgets/SFMInit.h"
#include <QAction>
#include <QMenu>

ProjectTreeWidgetItem::ProjectTreeWidgetItem(Project* project)
{
    this->setText(0, project->projectName.c_str());
    updateMenu();
}

void ProjectTreeWidgetItem::slot_newSFMProject()
{
    SFMInit sfminit;
    sfminit.exec();
}


void ProjectTreeWidgetItem::execMenu()
{
    updateMenu();
    m_menu->exec(QCursor::pos());
}

void ProjectTreeWidgetItem::updateMenu()
{
    if (nullptr == m_menu) {
        m_menu          = new QMenu;
        QAction* action = nullptr;
        action          = m_menu->addAction(tr("Add SFM project"));
        connect(action, SIGNAL(triggered()), this, SLOT(slot_newSFMProject()));
    }
}
