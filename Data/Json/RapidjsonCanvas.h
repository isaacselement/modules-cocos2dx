#ifndef __iCombos__RapidjsonCanvas__
#define __iCombos__RapidjsonCanvas__


#include "cocos2d.h"
USING_NS_CC;

#include "json/document.h"


class RapidjsonCanvas
{
public:
    
    static Size parseSize(rapidjson::Value& value);
    
    static Vec2 parseVec2(rapidjson::Value& value);
    
};

#endif /* defined(__iCombos__RapidjsonCanvas__) */



#define rCanvasParseSize(value) RapidjsonCanvas::parseSize(value)

#define rCanvasParseVec2(value) RapidjsonCanvas::parseVec2(value)
