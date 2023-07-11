#include "NewProjectDialog.h"
#include "Core/Project.h"
#include "ui_NewProjectDialog.h"
#include <QFileDialog>
NewProjectDialog::NewProjectDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(slot_accept()));
    connect(ui->toolButton, &QToolButton::clicked, [&]() {
        auto result = QFileDialog::getExistingDirectory(this, tr("New Project"), "");
        if (!result.isEmpty()) {
            ui->lineEdit_projectDir->setText(result);
        }
    });
}

void NewProjectDialog::slot_accept()
{
    g_project.create(ui->lineEdit_projectDir->text().toStdString(),
                     ui->lineEdit_projectName->text().toStdString());
}


NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}
