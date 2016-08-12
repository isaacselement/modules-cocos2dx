#ifndef __iCombos__FrameTranslater__
#define __iCombos__FrameTranslater__

#include "cocos2d.h"
USING_NS_CC;

class FrameTranslater
{
private:
    static Size _canvas;
    static float _ratioX;
    static float _ratioY;
    
public:
    static void setCanvas(Size canvas);
    static Size getCanvas();
    
    static float convertFontSize(float fontSize);
    static float convertCanvasX(float x);
    static float convertCanvasY(float y);
    static float convertCanvasWidth(float width);
    static float convertCanvasHeight(float height);
    static Vec2 convertCanvasPoint(Vec2 point);
    static Size convertCanvasSize(Size size);
    static Rect convertCanvasRect(Rect canvas);
};

#endif /* defined(__iCombos__FrameTranslater__) */


#define CanvasX(x) FrameTranslater::convertCanvasX(x)
#define CanvasY(y) FrameTranslater::convertCanvasY(y)
#define CanvasW(w) FrameTranslater::convertCanvasWidth(w)
#define CanvasH(h) FrameTranslater::convertCanvasHeight(h)

#define CanvasFontSize(px) FrameTranslater::convertFontSize(px)

#define CanvasSize(w, h) FrameTranslater::convertCanvasSize(Size(w, h))
#define CanvasVec2(x, y) FrameTranslater::convertCanvasPoint(Vec2(x, y))
#define CanvasRect(x, y, w, h) FrameTranslater::convertCanvasRect(Rect(x, y, w, h))

#define CanvasCGSize(size) FrameTranslater::convertCanvasSize(size)
#define CanvasCGRect(rect) FrameTranslater::convertCanvasRect(rect)
#define CanvasCGVec2(vec2) FrameTranslater::convertCanvasPoint(vec2)
