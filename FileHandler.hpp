#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <iostream>
#include <boost/filesystem.hpp>
#include <functional>

typedef std::function<void(const std::string&, const std::string&)> FillResponseType;

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
    std::string readTextFile(const boost::filesystem::path& filePath, FillResponseType);
    void processTxtFile(const boost::filesystem::path& filePath, FillResponseType);
    void processHtmlFile(const boost::filesystem::path& filePath, FillResponseType);
    void processRegularFile(const boost::filesystem::path& filePath, FillResponseType);
private:
    const std::string mHtmlContentType = "text/html";
    const std::string mTxtContentType = "text/html";
    const std::string mJpegContentType = "image/jpg";

};

#endif // FILE_HANDLER_HPP