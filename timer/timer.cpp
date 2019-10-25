#include <QLayout>
#include <QProgressBar>
#include <QTimer>
#include <QMainWindow>
#include <QPushButton>

#include "timer.h"

Timer::Timer(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout();

    setWindowTitle(tr("Timer gg"));
    resize(300, 100);

    progressBar = new QProgressBar();
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);

    // Create the button, make "this" the parent
    start_button = new QPushButton("START", this);
    // set size and location of the button
    start_button->setGeometry(QRect(QPoint(10, 5),
    QSize(60, 30)));

    stop_button = new QPushButton("STOP", this);
    stop_button->setGeometry(QRect(QPoint(70, 5),
    QSize(60, 30)));

    reset_button = new QPushButton("RESET", this);
    reset_button->setGeometry(QRect(QPoint(130, 5),
    QSize(60, 30)));


    layout->addWidget(progressBar);
    setLayout(layout);

    //connect(timer, &QTimer::timeout, this, &Timer::updateProgress);
    connect(this->start_button , SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(this->stop_button , SIGNAL(clicked()), this, SLOT(stopTimer()));
    connect(this->reset_button , SIGNAL(clicked()), this, SLOT(resetProgress()));

}

//슬롯
void Timer::updateProgress()
{
    progressBar->setValue(progressBar->value()+1);
}

void Timer::startTimer()
{
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Timer::updateProgress);
    timer->start(1000);
    start_button->setEnabled(0);
}

void Timer::stopTimer()
{
    progressBar->setValue(progressBar->value());
    timer->stop();
    start_button->setEnabled(1);
}

void Timer::resetProgress()
{
    progressBar->setValue(0);

}


