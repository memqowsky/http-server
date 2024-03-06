#include "HTTPServer.hpp"

int main(int argc, char* argv[]){
    unsigned int serverPort;
    if(argc == 2){
        serverPort = std::stoi(argv[1]);
    } else if (argc != 2){
        printf("Bad count of arguments, usage ./HTTPServer [PORT]\n");
        return 0;
    }
    HTTPServer server(serverPort);
    return 0;
}