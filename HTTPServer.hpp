#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "FileHandler.hpp"
#include <memory>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

enum class requestType {
    UNKNOWN,
    GET
};

class HTTPServer{
public:
    HTTPServer(unsigned int serverPort);
    ~HTTPServer();
    void serverStart();
    void handleRequest(tcp::socket& socket);
    std::string parseRequest(const std::string& request);
    requestType getRequestType(const std::string& request);
    void handleGetRequest(const std::string& request);
    std::string buildResponse();
private:
    std::unique_ptr<FileHandler> mFileHandler = std::make_unique<FileHandler>();
    unsigned int mServerPort;
    std::string mFileContent;
};


#endif // HTTP_SERVER_HPP
