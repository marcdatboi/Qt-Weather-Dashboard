



cmake_minimum_required(VERSION 3.16)
project(weatherdashboard)

set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH "C:/Dev Frameworks/Qt/6.10.3/android_arm64_v8a/bin")

# Source files
set(SOURCES
        src/MainWindow.cpp
        src/main.cpp
        src/WeatherNowWidget.cpp

)

# Header Files
set(HEADERS
        include/MainWindow.hpp
        include/WeatherNowWidget.hpp

)

find_package(Qt6 COMPONENTS REQUIRED Widgets Core Gui)
add_executable(weatherdashboard
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(weatherdashboard PRIVATE include)
target_link_libraries(weatherdashboard PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
)