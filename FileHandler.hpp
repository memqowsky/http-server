#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <iostream>
#include <boost/filesystem.hpp>
#include <functional>

enum class fileExtension {
    UNKNOWN = 0,
    HTML = 1
};

class FileHandler{
public:
    FileHandler() = default;
    ~FileHandler() = default;
    FileHandler(const FileHandler&) = delete;
    std::string readHtmlFile(const boost::filesystem::path& filePath, std::function<void(const std::string&)>);
    void processHtmlFile(const boost::filesystem::path& filePath, std::function<void(const std::string&)>);
    void processRegularFile(const boost::filesystem::path& filePath, std::function<void(const std::string&)>);
private:

};

#endif // FILE_HANDLER_HPP