#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget* parent = nullptr);
    ~NewProjectDialog();

private slots:
    void slot_accept();

private:
    Ui::NewProjectDialog* ui;
};

#endif   // NEWPROJECTDIALOG_H
