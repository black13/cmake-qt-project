cmake_minimum_required(VERSION 2.8.11)

project(testproject)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH /usr/local/qt5/lib/cmake)

# Find the QtWidgets library
find_package(Qt5Widgets)

set(SOURCES
  src/main.cpp
  src/mainwindow.cpp
  src/call_back.h
  src/call_back.c
  src/mainwindow.h
)

set(FORMS
  src/mainwindow.ui
)

qt5_wrap_ui(FORM_H src/mainwindow.ui)

# Tell CMake to create the helloworld executable
add_executable(helloworld ${SOURCES} ${FORM_H})

# Use the Widgets module from Qt 5.
target_link_libraries(helloworld Qt5::Widgets)