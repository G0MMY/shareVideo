#ifndef RESPONSEWRITER_HPP
#define RESPONSEWRITER_HPP

#include "Json.hpp"
#include <string>
#include <iostream>
class ResponseWriter {
public:
    static string WriteGet(string content, int code) {
        string response = "HTTP/1.1 " + to_string(code);
        switch (code) {
            case 200:
                response = response + " OK";
                break;
            case 400:
                response = response + " Bad Request";
                break;
            case 500:
                response = response + " Internal Server Error";
                break;
        }
        response = response + "\nContent-Type: application/json\nContent-Length: " + to_string(content.size());

        return response + "\n\n" + content;
    }
};

#endif
