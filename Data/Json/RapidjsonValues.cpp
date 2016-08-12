#include "RapidjsonValues.h"


Color4F RapidjsonValues::parseColor4F(rapidjson::Value &value)
{
    double a[4];
    parseValuesInArray(value, a);
    return Color4F(a[0], a[1], a[2], a[3]);
}


Color4B RapidjsonValues::parseColor4B(rapidjson::Value &value)
{
    int a[4];
    parseValuesInArray(value, a);
    return Color4B(a[0], a[1], a[2], a[3]);
}


Size RapidjsonValues::parseSize(rapidjson::Value &value)
{
    int a[2];
    parseValuesInArray(value, a);
    return Size(a[0], a[1]);
}

Vec2 RapidjsonValues::parseVec2(rapidjson::Value &value)
{
    int a[2];
    parseValuesInArray(value, a);
    return Vec2(a[0], a[1]);
}

int RapidjsonValues::parseInt(rapidjson::Value &value)
{
    if (value.IsInt()) {
        return value.GetInt();
    }
    return 0;
}

double RapidjsonValues::parseDouble(rapidjson::Value &value)
{
    if (value.IsDouble()) {
        return value.GetDouble();
    }
    return 0;
}

#pragma mark - private

template <class T>
void RapidjsonValues::parseValuesInArray(rapidjson::Value &value, T *a)
{
    if(value.IsArray())
    {
        for(int i = 0; i < value.Capacity(); i++)
        {
            rapidjson::Value& v = value[i];
            if (typeid(a[0]) == typeid(int)) {
                a[i] = parseInt(v);
            } else if (typeid(a[0]) == typeid(double)) {
                a[i] = parseDouble(v);
            }
        }
    }
}

