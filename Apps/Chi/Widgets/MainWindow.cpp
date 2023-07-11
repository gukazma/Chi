#include "MainWindow.h"
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
    auto result = QFileDialog::getSaveFileName(this, tr("New project"), "", "Chi Project(*.chi)");
    if (!result.isEmpty()) {}
}
void MainWindow::on_actionSaveProject_triggered() {}
void MainWindow::on_actionOpenProject_triggered() {}
