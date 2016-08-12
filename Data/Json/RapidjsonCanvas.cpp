#include "RapidjsonCanvas.h"

#include "RapidjsonValues.h"
#include "FrameTranslater.h"

Size RapidjsonCanvas::parseSize(rapidjson::Value &value)
{
    return CanvasCGSize(rParseSize(value));
}

Vec2 RapidjsonCanvas::parseVec2(rapidjson::Value &value)
{
    return CanvasCGVec2(rParseVec2(value));
}