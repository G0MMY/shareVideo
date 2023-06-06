#include "../../headers/server/TCPServer.hpp"

void http::TCPServer::StartListen() {
    Start();
    Listen();
}

void http::TCPServer::Start() {
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw runtime_error("Error while trying to instantiate serverSocket");
        return;
    }
  
    int opt = 1;

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        throw runtime_error("Error while trying to set socket options");
        return;
    }

    if (bind(serverSocket, (struct sockaddr*)&address, addrLength) < 0) {
        throw runtime_error("Error while trying to bind serverSocket");
        return;
    }

    if (listen(serverSocket, 10) < 0) {
        throw runtime_error("Error while trying to listen on serverSocket");
    }
}

void http::TCPServer::Listen() {
    if ((pendingSocket = accept(serverSocket, (struct sockaddr*)&address, (socklen_t*)&addrLength)) < 0) {
        throw runtime_error("Error while trying to instantiate pendingSocket");
        return;
    }

    string hello = "hello world";
    char buffer[1024] = { 0 };
    int valread = read(pendingSocket, buffer, 1024);

    send(pendingSocket, hello.c_str(), hello.size(), 0);

    Stop();
}

void http::TCPServer::Stop() {
    close(pendingSocket);
    shutdown(serverSocket, SHUT_RDWR);
}

