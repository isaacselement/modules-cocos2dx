#ifndef __iCombos__CountdownTimer__
#define __iCombos__CountdownTimer__

#include "cocos2d.h"
USING_NS_CC;

class CountdownTimer : public Node
{
private:
    void update(float delta);
    
    float				time;
    
public:
    CountdownTimer();
    
    virtual ~CountdownTimer();
    
    static CountdownTimer* createTimer();
    
    bool init();
    
    void setTime(float time);

    void start();
    
    void pause();
    

    Label*				label;
    
    
    std::function<void(void)> timesOverCallback;
    
};

#endif /* defined(__iCombos__CountdownTimer__) */
