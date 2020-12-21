#include <iostream>
#include <json/json.h>

std::string createJson() {
    std::string jsonStr;
    Json::Value root, lang, mail;
    Json::StreamWriterBuilder writerBuilder;
    std::ostringstream  os;
    root["name"] = "mars";
    root["age"] = 24;

    std::unique_ptr<Json::StreamWriter> jsonWritter(writerBuilder.newStreamWriter());
    jsonWritter->write(root, &os);
    jsonStr = os.str();
    std::cout << jsonStr << std::endl;
    return jsonStr;
}

bool parseJson(const std::string &info) {
   if (info.empty()) {
       return false;
   }
   bool res;
   JSONCPP_STRING errs;
   Json::Value root, lang, mail;
   Json::CharReaderBuilder readerBuilder;

   std::unique_ptr<Json::CharReader> const jsonReader(readerBuilder.newCharReader());
   res = jsonReader->parse(info.c_str(), info.c_str() + info.length(), &root, &errs);
   if (!res || !errs.empty()) {
       std::cout << "parseJson err. " << errs << std::endl;
   }
   std::cout << "name: " << root["name"].asString() << std::endl;
   std::cout << "age: " << root["age"].asInt() << std::endl;
   return true;
}

int main() {
    std::string str = createJson();
    std::cout << str << std::endl;

    parseJson(str);
    return 0;
}

