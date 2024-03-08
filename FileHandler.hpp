#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <iostream>
#include <boost/filesystem.hpp>
#include <functional>

typedef std::function<void(const std::vector<unsigned char>& vectorFileContent, const std::string&)> FillResponseType;

enum class fileExtension {
    UNKNOWN = 0,
    HTML = 1,
    TXT
};

class FileHandler{
public:
    FileHandler() = default;
    ~FileHandler() = default;
    FileHandler(const FileHandler&) = delete;
    std::vector<unsigned char> readFile(const boost::filesystem::path& filePath);
    void processFile(const boost::filesystem::path& filePath, const std::string fileContentType, FillResponseType fillResponseCallback);
    void processRegularFile(const boost::filesystem::path& filePath, FillResponseType);
private:
    std::vector<std::pair<std::string, std::string>> mContentTypePairHolder = {
        {".html", "text/html"},
        {".txt", "text/plain"},
        {".jpg", "image/jpeg"}
    };

};

#endif // FILE_HANDLER_HPP