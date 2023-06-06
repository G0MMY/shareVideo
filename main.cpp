#include "headers/server/TCPServer.hpp"
#include <iostream>

int main() {
    http::TCPServer server{ "127.0.0.1", 8080 };

    try {
        server.StartListen();
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}