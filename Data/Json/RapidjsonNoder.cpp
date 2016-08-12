#include "RapidjsonNoder.h"

#include "RapidjsonValues.h"
#include "RapidjsonCanvas.h"
#include "FrameTranslater.h"


void RapidjsonNoder::applyNodeProperties(cocos2d::Node *node, rapidjson::Value &config)
{
    if (config.IsNull()) return;
    if (config.HasMember("Size")) {
        rapidjson::Value& sizeVal = config["Size"];
        Size size = rCanvasParseSize(sizeVal);
        node->setContentSize(size);
    }

    if (config.HasMember("Position")) {
        rapidjson::Value& pointVal = config["Position"];
        Vec2 point = rCanvasParseVec2(pointVal);
        node->setPosition(point);
    }
}

void RapidjsonNoder::applyLabelProperties(cocos2d::Label *label, rapidjson::Value &config)
{
    if (config.IsNull()) return;
    
    applyNodeProperties(label, config);
    
    if (config.HasMember("String")) {
        rapidjson::Value& stringVal = config["String"];
        const char* string = stringVal.GetString();
        label->setString(string);
    }
    
    if (config.HasMember("Font_size")) {
        rapidjson::Value& fontSizeVal = config["Font_size"];
        int fontSize =  CanvasFontSize(fontSizeVal.GetInt());
        label->setSystemFontSize(fontSize);
    }
    
    if (config.HasMember("")) {
        rapidjson::Value& fontNameVal = config["Font_name"];
        std::string fontName = fontNameVal.GetString();
        label->setSystemFontName(fontName);
    }
}

void RapidjsonNoder::applyParticlsProperties(ParticleSystem* system, rapidjson::Value& config)
{
    if (config.IsNull()) return;
    
    applyNodeProperties(system, config);
    
    // in CCParticleSystem.h
    
    // mode A
    
    if (config.HasMember("Gravity")) {
        rapidjson::Value& gravity = config["Gravity"];
        Vec2 Gravity = rCanvasParseVec2(gravity);
        system->setGravity(Gravity);
    }
    
    if (config.HasMember("Speed")) {
        rapidjson::Value& speed = config["Speed"];
        double Speed = speed.GetDouble();
        system->setSpeed(Speed);
    }
    
    if (config.HasMember("SpeedVar")) {
        rapidjson::Value& speedVar = config["SpeedVar"];
        double SpeedVar = speedVar.GetDouble();
        system->setSpeedVar(SpeedVar);
    }
    
    // mode B
    
    if (config.HasMember("StartColor")) {
        rapidjson::Value& startColor = config["StartColor"];
        Color4F StartColor = rParseColor4F(startColor);
        system->setStartColor(StartColor);
    }
}