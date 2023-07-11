#ifndef SFMINIT_H
#define SFMINIT_H

#include <QDialog>

namespace Ui {
class SFMInit;
}

class SFMInit : public QDialog
{
    Q_OBJECT

public:
    explicit SFMInit(QWidget* parent = nullptr);
    ~SFMInit();

private:
    Ui::SFMInit* ui;
};

#endif   // SFMINIT_H
