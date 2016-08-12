#include "CountdownTimer.h"

CountdownTimer::CountdownTimer()
{
}

CountdownTimer::~CountdownTimer()
{
}

CountdownTimer* CountdownTimer::createTimer()
{
    CountdownTimer* countdownTimer = new CountdownTimer();
    if(countdownTimer && countdownTimer->init())
    {
        countdownTimer->autorelease();
        return countdownTimer;
    }
    else
    {
        delete countdownTimer;
        countdownTimer = NULL;
    }
    return NULL;
}

bool CountdownTimer::init()
{
    label = Label::create();
    label->setPosition(0,0);
    this->addChild(label);
    return true;
}

void CountdownTimer::setTime(float time)
{
    this->time = time;
}

void CountdownTimer::update(float delta)
{
    static int mil = 0;
    mil--;
    if (mil < 0) mil = 9;
    
    if (time <= 0 && mil == 9) {
        pause();
        timesOverCallback();
        return;
    }
    
    
    time -= delta;
    
    char* mtime = new char[10];
    sprintf(mtime,"%02d : %02d : %d0", (int)time/60, (int)time%60, mil);
    label->setString(mtime);
    
}

void CountdownTimer::start()
{
    schedule(schedule_selector(CountdownTimer::update), 0.1);
}

void CountdownTimer::pause()
{
    unschedule(schedule_selector(CountdownTimer::update));
}
