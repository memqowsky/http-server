cmake_minimum_required(VERSION 3.10)
project(HTTPServer)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    HTTPServer.cpp
    FileHandler.cpp
)

set(HEADERS
    HTTPServer.hpp
    FileHandler.hpp
)

# Make executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

#boost/filesystem
find_package(Boost COMPONENTS filesystem REQUIRED)
target_link_libraries(${PROJECT_NAME} Boost::filesystem)

#boost
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})