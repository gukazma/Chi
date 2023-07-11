#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

extern int  g_progress_percentage;
extern bool g_done;

#include <QDialog>
#include <QString>
#include <functional>
#include <memory>
#include <thread>
namespace Ui {
class ProgressBar;
}
class CoutRedirector;
class QTimer;
class ProgressBar : public QDialog
{
    Q_OBJECT

public:
    typedef std::function<void()> ThreadFunction;
    explicit ProgressBar(ThreadFunction func, const QString& title = tr("Please wait."),
                         QWidget* parent = nullptr);
    ~ProgressBar();
    void setText(const QString& text);
    void setValue(int);

Q_SIGNALS:
    void signal_setText(const QString& text);
    void signal_setValue(int);

public slots:
    void slot_setText(const QString& text);
    void slot_setValue(int);

private:
    Ui::ProgressBar*             ui;
    CoutRedirector*              coutRedirector;
    QTimer*                      timer;
    std::unique_ptr<std::thread> m_thread;
};

#endif   // PROGRESSBAR_H
