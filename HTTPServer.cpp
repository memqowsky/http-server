#include "HTTPServer.hpp"
#include <sstream>

HTTPServer::HTTPServer(unsigned int serverPort) : mServerPort(serverPort) {
    mServerPort = serverPort;
    serverStart();
}

HTTPServer::~HTTPServer(){}

void HTTPServer::serverStart(){
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), mServerPort));
    printf("Server listening on port %d\n", mServerPort);

    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        handleRequest(socket);
    }
}

std::string HTTPServer::parseRequest(const std::string& request){
    auto firstSpaceIndex = request.find_first_of(" ");
    if(firstSpaceIndex == std::string::npos){
        return "";
    }
    return request.substr(0, firstSpaceIndex);
}

requestType HTTPServer::getRequestType(const std::string& request){
    if(parseRequest(request) == "GET"){
        return requestType::GET;
    } else {
        return requestType::UNKNOWN;
    }
}

void HTTPServer::handleGetRequest(const std::string& request){
    std::cout << "Request: " << request << std::endl;
    std::vector<std::string> parts;

    try{
        boost::split(parts, request, boost::is_any_of(" "));
        std::cout << "Part size: " << parts.size() << std::endl;
        for(auto e : parts){
            std::cout << "part: " << e << std::endl;
        }
        if(parts.size() > 1){
            std::cout << "Request data: " << parts[1] << std::endl;
            boost::filesystem::path filePath(parts[1]);
            boost::filesystem::path directFilePath = (boost::filesystem::current_path() / filePath);

            auto fillResponseCallback = [this](const std::string& response) -> void {
                mFileContent = response;
            };

            mFileHandler->processRegularFile(directFilePath, fillResponseCallback);
        } else {
            std::cout << "Error while parsing the request\n";
        }
    }
    catch(const std::exception& exception){
        std::cout << exception.what() << std::endl;
    }
}

std::string HTTPServer::buildResponse(){
    std::stringstream response;
    response << "HTTP/1.1 200 OK\r\nContent-Length: ";
    response << mFileContent.size();
    response <<  "\r\n\r\n";
    response << mFileContent;
    return response.str();
}

// Funkcja obsługująca żądania HTTP
void HTTPServer::handleRequest(tcp::socket& socket) {
    boost::asio::streambuf request;
    boost::asio::read_until(socket, request, "\r\n\r\n");

    std::istream requestStream(&request);
    std::string requestLine;
    std::getline(requestStream, requestLine);
    cout << "Received: " << requestLine << endl;

    requestType requestType = getRequestType(requestLine);

    if(requestType == requestType::GET){
        handleGetRequest(requestLine);
        cout << "Recieved GET request type\n";
    }
   
    boost::asio::write(socket, boost::asio::buffer(buildResponse()));
}