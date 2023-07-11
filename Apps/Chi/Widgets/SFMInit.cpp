#include "SFMInit.h"
#include "ui_SFMInit.h"

SFMInit::SFMInit(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::SFMInit)
{
    ui->setupUi(this);
}

SFMInit::~SFMInit()
{
    delete ui;
}
