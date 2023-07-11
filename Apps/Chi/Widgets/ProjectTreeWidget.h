#pragma once
#include <QTreeWidget>
class ProjectTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit ProjectTreeWidget(QWidget* parent = nullptr);
    ~ProjectTreeWidget();

private slots:
    void slot_pressed(QTreeWidgetItem* item, int value);

private:
};