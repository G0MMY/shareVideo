#ifndef JSON_HPP
#define JSON_HPP

#include "json.hpp"
#include <string>

using namespace std;
using Json = nlohmann::json;

class ProcessJson {
public:
    static string hello() {
        Json t = Json::parse(R"({"hello":"world"})");

        return t.dump();
    }
};

#endif
