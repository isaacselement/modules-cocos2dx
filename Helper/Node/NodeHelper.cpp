#include "NodeHelper.h"

void NodeHelper::setSwallowTouchesOn(cocos2d::Node *node) {
    EventListenerTouchOneByOne *eventListener = EventListenerTouchOneByOne::create();
    eventListener->setSwallowTouches(true);
    eventListener->onTouchBegan = [](Touch *touch, Event *event){ return  true; };
    eventListener->onTouchMoved = [](Touch *touch, Event *event){};
    eventListener->onTouchEnded = [](Touch *touch, Event *event){};
    node->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, node);
}
