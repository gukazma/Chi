#include "MainWindow.h"
#include "Core/Project.h"
#include "Widgets/NewProjectDialog.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNewProject_triggered()
{
    NewProjectDialog newproject;
    newproject.exec();
    ui->projectTreeWidget->newProject(&g_project);
}
void MainWindow::on_actionSaveProject_triggered() {}
void MainWindow::on_actionOpenProject_triggered() {}
