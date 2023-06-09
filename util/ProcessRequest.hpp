#include <string>
#include "Json.hpp"

using namespace std;

enum Type {
    GET,
    POST,
    PUT,
    DELETE
};

struct Request {
    Type type;
    string route;
    Json body;

    Request() = default;
    Request(Type type, string route): type{ type }, route{ route } {}
};

struct ProcessRequest {
    Request operator()(string buffer) {
        Request req;
        char* s = "";

        for(int i=0;i<buffer.size();i++) {
            if (buffer[i] == ' ') {
                if (req.type == NULL) req.type = GetType(s); 
                else {
                    req.route = s;
                    break;
                }
                s = "";
            } else {
                s += buffer[i];
            }
        }

        return req;
    }
private:
    Type GetType(char* s) {
        if (s == "GET") return GET;
        if (s == "POST") return POST;
        if (s == "PUT") return PUT;
        if (s == "DELETE") return DELETE;
    }
};
