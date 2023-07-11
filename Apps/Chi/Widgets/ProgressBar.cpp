#include "ProgressBar.h"
#include "ui_ProgressBar.h"
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QTimer>
#include <iostream>
#include <streambuf>
int  g_progress_percentage = 0;
bool g_done                = false;
class ProgressBar;
class CoutRedirector : public std::streambuf
{
public:
    CoutRedirector(ProgressBar* progressbar)
        : m_progressbar(progressbar)
    {
        m_old_buf = std::cout.rdbuf();
        std::cout.rdbuf(this);
    }

    virtual ~CoutRedirector() { std::cout.rdbuf(m_old_buf); }

protected:
    virtual int_type overflow(int_type v)
    {
        m_progressbar->setText(std::string(1, v).c_str());
        return m_old_buf->sputc(v);
    }

    virtual std::streamsize xsputn(const char* p, std::streamsize n)
    {
        std::string s(p, n);
        m_progressbar->setText(s.c_str());
        return m_old_buf->sputn(p, n);
    }

    std::streambuf* m_old_buf;
    ProgressBar*    m_progressbar;
};

ProgressBar::ProgressBar(ThreadFunction func, const QString& title, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ProgressBar)
{
    ui->setupUi(this);
    this->setWindowTitle(title);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
    coutRedirector = new CoutRedirector(this);
    connect(this, SIGNAL(signal_setText(const QString&)), this, SLOT(slot_setText(const QString&)));
    connect(this, SIGNAL(signal_setValue(int)), this, SLOT(slot_setValue(int)));
    timer = new QTimer(this);   // 创建一个定时器对象，this 表示将该对象添加到组件树中
    connect(timer, &QTimer::timeout, [&]() {   // 连接定时器的 timeout 信号到一个 lambda 函数中
        this->setValue(g_progress_percentage);
    });
    timer->start(100);   // 启动定时器，设置时间间隔为 100 毫秒
    m_thread = std::make_unique<std::thread>(func);
}

ProgressBar::~ProgressBar()
{
    delete ui;
    delete coutRedirector;
    delete timer;
    g_progress_percentage = 0;
    g_done                = false;
    m_thread->join();
}

void ProgressBar::setText(const QString& text)
{
    emit signal_setText(text);
}

void ProgressBar::setValue(int value)
{
    emit signal_setValue(value);
}

void ProgressBar::slot_setValue(int value)
{
    ui->progressBar->setValue(value);
    ui->progressBar->update();
    if (value >= 100 && g_done) {
        accept();
    }
}

void ProgressBar::slot_setText(const QString& text)
{
    ui->textEdit->insertPlainText(text);
    ui->textEdit->moveCursor(QTextCursor::End);
}