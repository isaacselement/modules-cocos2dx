#include "RapidjsonWrapper.h"



void RapidjsonWrapper::getDocumentByFile(rapidjson::Document& doc, const std::string &jsonfilename)
{
    const char* file_path = FileUtils::getInstance()->fullPathForFilename(jsonfilename).c_str();
    CCLOG("external file path = %s",file_path);
    
    std::string contentStr = FileUtils::getInstance()->getStringFromFile(file_path);
    doc.Parse<0>(contentStr.c_str());
    CCLOG("%s\n", contentStr.c_str());
    
    if(doc.HasParseError())
    {
        CCLOG("GetParseError%u\n", doc.GetParseError());
    }
}
