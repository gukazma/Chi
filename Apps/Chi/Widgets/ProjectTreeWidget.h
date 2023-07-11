#pragma once
#include <QTreeWidget>

class Project;
class ProjectTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit ProjectTreeWidget(QWidget* parent = nullptr);
    ~ProjectTreeWidget();

    void newProject(Project* project);
private slots:
    void slot_pressed(QTreeWidgetItem* item, int value);

private:
};