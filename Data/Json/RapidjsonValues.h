#ifndef __iCombos__RapidjsonValues__
#define __iCombos__RapidjsonValues__


#include "cocos2d.h"
USING_NS_CC;

#include "json/document.h"


class RapidjsonValues
{
private:
    
    template <class T>
    static void parseValuesInArray(rapidjson::Value &value, T *a);
    
    
public:
    
    static Color4F parseColor4F(rapidjson::Value& value);
    
    static Color4B parseColor4B(rapidjson::Value& value);
    
    static Size parseSize(rapidjson::Value& value);
    
    static Vec2 parseVec2(rapidjson::Value& value);
    
    static int parseInt(rapidjson::Value& value);
    static double parseDouble(rapidjson::Value &value);
};

#endif /* defined(__iCombos__RapidjsonValues__) */



#define rParseColor4F(value) RapidjsonValues::parseColor4F(value)

#define rParseColor4B(value) RapidjsonValues::parseColor4B(value)

#define rParseSize(value) RapidjsonValues::parseSize(value)

#define rParseVec2(value) RapidjsonValues::parseVec2(value)

#define rParseInt(value) RapidjsonValues::parseInt(value)
