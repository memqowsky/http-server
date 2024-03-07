#include "FileHandler.hpp"
#include <sstream>
#include <string>
#include <fstream>

std::string FileHandler::readTextFile(const boost::filesystem::path& filePath, FillResponseType fillResponseCallback){
    std::string line;
    std::ifstream textFile(filePath.string());
    if (textFile.is_open()) {
        std::stringstream fileStream;
        while (getline(textFile, line)) {
            fileStream << line;
            fileStream << '\n';
        }
        textFile.close();
        return fileStream.str();
    } else {
        std::cout << "Can't open the file: " << filePath.string();
        return "";
    }
}

void FileHandler::processHtmlFile(const boost::filesystem::path& filePath, FillResponseType fillResponseCallback){
    std::cout << "Processing HTML file...\n";
    fillResponseCallback(readTextFile(filePath, fillResponseCallback), mHtmlContentType);
}

void FileHandler::processTxtFile(const boost::filesystem::path& filePath, FillResponseType fillResponseCallback){
    std::cout << "Processing HTML file...\n";
    fillResponseCallback(readTextFile(filePath, fillResponseCallback), mTxtContentType);
}

void FileHandler::processRegularFile(const boost::filesystem::path& filePath, FillResponseType fillResponseCallback){
    std::cout << "Processing regular file...\n";
    try{
        if(boost::filesystem::exists(filePath)){
            std::cout << "File " << filePath << " exists.\n";
            if(boost::filesystem::is_regular_file(filePath)){
                std::cout << "File " << filePath << " is regular file.\n";
                std::string fileExt = filePath.extension().string();
                if(fileExt == ".html"){
                    processHtmlFile(filePath, fillResponseCallback);
                } else if (fileExt == ".txt"){
                    processTxtFile(filePath, fillResponseCallback);
                } else {
                    std::cout << "Can't process extension: " << fileExt << std::endl;
                }
            } else {
                std::cout << "File " << filePath << " is not regular file.\n";
            }
        } else {
            std::cout << "File " << filePath << " don't exist.\n";
        }
    } catch(const std::exception& e){
        std::cout << e.what();
    } 

}