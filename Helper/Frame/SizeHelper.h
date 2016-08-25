#ifndef __iCombos__SizeHelper__
#define __iCombos__SizeHelper__

#include "cocos2d.h"
using namespace cocos2d;

class SizeHelper
{
public:
    static float getWinSizeWidth() {
        Size size = Director::getInstance()->getWinSize();
        return size.width;
    }
    
    static float getWinSizeHeight() {
        Size size = Director::getInstance()->getWinSize();
        return size.height;
    }
};

#endif /* defined(__iCombos__SizeHelper__) */
