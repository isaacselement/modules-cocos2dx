#ifndef __iCombos__VecHelper__
#define __iCombos__VecHelper__

#include "cocos2d.h"
using namespace cocos2d;

class VecHelper
{
    
public:
    static Vec2 getWindowCenter() {
        Size size = Director::getInstance()->getWinSize();
        return Vec2(size.width / 2, size.height / 2);
    };
};

#endif /* defined(__iCombos__VecHelper__) */


