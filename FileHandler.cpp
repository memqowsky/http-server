#include "FileHandler.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

std::vector<unsigned char> FileHandler::readFile(const boost::filesystem::path& filePath) {
    std::ifstream textFile(filePath.string(), std::ios::binary);
    if (textFile.is_open()) {
        textFile.seekg(0, std::ios::end);
        std::streampos fileSize = textFile.tellg();
        textFile.seekg(0, std::ios::beg);
        std::vector<unsigned char> fileData(fileSize);
        textFile.read(reinterpret_cast<char*>(&fileData[0]), fileSize);
        textFile.close();
        return fileData;
    } else {
        std::cout << "Can't open the file: " << filePath.string();
        return std::vector<unsigned char>();
    }
}

void FileHandler::processFile(const boost::filesystem::path& filePath, const std::string fileContentType, FillResponseType fillResponseCallback){
    std::cout << "Processing file...\n";
    if(fillResponseCallback){
        fillResponseCallback(readFile(filePath), fileContentType);
    } else {
        std::cout << "Can't load response...\n";
    }
}

void FileHandler::processRegularFile(const boost::filesystem::path& filePath, FillResponseType fillResponseCallback){
    std::cout << "Processing regular file...\n";
    try{
        if(boost::filesystem::exists(filePath)){
            std::cout << "File " << filePath << " exists.\n";
            if(boost::filesystem::is_regular_file(filePath)){
                std::cout << "File " << filePath << " is regular file.\n";
                std::string fileExt = filePath.extension().string();
                auto extenstionIterator = std::find_if(mContentTypePairHolder.begin(), mContentTypePairHolder.end(), [&fileExt](const std::pair<std::string, std::string>& pair){return pair.first == fileExt;});
                if(extensionIterator != mContentTypePairHolder.end()){
                    processFile(filePath, (*extensionIterator).second, fillResponseCallback);
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