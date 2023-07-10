#pragma once
#include <QTreeWidget>
class ProjectTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit ProjectTreeWidget(QWidget* parent = nullptr);
    ~ProjectTreeWidget();

private:
};