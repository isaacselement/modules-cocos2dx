#ifndef __iCombos__RapidjsonNoder__
#define __iCombos__RapidjsonNoder__

#include "cocos2d.h"
USING_NS_CC;

#include "json/document.h"


class RapidjsonNoder
{
private:
    
    
public:
    
    static void applyNodeProperties(Node* node, rapidjson::Value& config);
    
    static void applyLabelProperties(Label* label, rapidjson::Value& config);
  
    static void applyParticlsProperties(ParticleSystem* system, rapidjson::Value& config);
};

#endif /* defined(__iCombos__RapidjsonNoder__) */
