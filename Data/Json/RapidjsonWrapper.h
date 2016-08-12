#ifndef __iCombos__RapidjsonWrapper__
#define __iCombos__RapidjsonWrapper__

#include "cocos2d.h"
USING_NS_CC;

#include "json/document.h"


class RapidjsonWrapper
{
public:
    
    static void getDocumentByFile(rapidjson::Document& doc, const std::string &jsonfilename);
};

#endif /* defined(__iCombos__RapidjsonWrapper__) */
