#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <stdexcept>

using namespace std;

namespace http {

    class TCPServer {
        string ip;
        struct sockaddr_in address;
        int serverSocket, pendingSocket, addrLength;
        
    public:
        
        TCPServer(string ip, int port): ip{ ip } {
            addrLength = sizeof(address);
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons(port);
        }
        ~TCPServer() {}
        void StartListen();
    
    private: 

        void Listen();
        void Start();
        void Stop();

    };
}
