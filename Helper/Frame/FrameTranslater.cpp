#include "FrameTranslater.h"


#pragma mark -

float SizeGetMaximum(Size size)
{
    return size.width > size.height ? size.width : size.height;
}
float SizeGetMinimun(Size size)
{
    return size.width < size.height ? size.width : size.height;
}

void getRatios(Size canvas, float* ratioX, float* ratioY)
{
    // like UIWindow's bounds, ios 7 and below ,  always will be (768 x 1024)(ipad) not influnce by orientation.
    // 2014-9-23 note: ios 7 and below : 320 X 568 , but in ios 8 : 568 X 320
    // get the width and height
    Size screenSize = Director::getInstance()->getVisibleSize();
    float width = screenSize.width;
    float height = screenSize.height;
    if (canvas.width > canvas.height) {             // landscape is width > height
        width = SizeGetMaximum(screenSize);
        height = SizeGetMinimun(screenSize);
    }
    
    // after get the width and height , than caculate the ratio
    *ratioX = (float)width / (float)canvas.width;
    *ratioY = (float)height / (float)canvas.height;
}


#pragma mark - Ratio

Size FrameTranslater::_canvas;
float FrameTranslater::_ratioX = 1;
float FrameTranslater::_ratioY = 1;

void FrameTranslater::setCanvas(Size canvas)
{
    _canvas = canvas;
    getRatios(canvas, &_ratioX, &_ratioY);
}

Size FrameTranslater::getCanvas()
{
    return _canvas;
}

float FrameTranslater::convertFontSize(float fontSize) {
    return fontSize * ((_ratioX + _ratioY) / 2);
}

float FrameTranslater::convertCanvasX(float x) {
    x *= _ratioX;
    return x;
}

float FrameTranslater::convertCanvasY(float y) {
    y *= _ratioY;
    return y;
}

float FrameTranslater::convertCanvasWidth(float width) {
    width *= _ratioX;
    return width;
}

float FrameTranslater::convertCanvasHeight(float height) {
    height *= _ratioY;
    return height;
}

Vec2 FrameTranslater::convertCanvasPoint(Vec2 point)
{
    float x = convertCanvasX(point.x);
    float y = convertCanvasY(point.y);
    return Vec2(x, y);
}

Size FrameTranslater::convertCanvasSize(Size size)
{
    float width = convertCanvasWidth(size.width);
    float height = convertCanvasHeight(size.height);
    return Size(width, height);
}

Rect FrameTranslater::convertCanvasRect(Rect canvas)
{
    float x = convertCanvasX(canvas.origin.x);
    float y = convertCanvasY(canvas.origin.y);
    float width = convertCanvasWidth(canvas.size.width);
    float height = convertCanvasHeight(canvas.size.height);
    return Rect(x, y, width, height);
}
