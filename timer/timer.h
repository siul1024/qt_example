#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QPushButton>

class QProgressBar;
class QPushButton;

class Timer : public QWidget
{
    Q_OBJECT

public:
    Timer(QWidget *parent = 0);

public slots:
    void updateProgress();
    void stopTimer();
    void resetProgress();
    void startTimer();

public:
    QPushButton  *start_button;
    QPushButton  *stop_button;
    QPushButton  *reset_button;

private:
    QProgressBar *progressBar;
    QTimer *timer;

};

#endif
