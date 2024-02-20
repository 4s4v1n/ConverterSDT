cmake_minimum_required(VERSION 3.5)

project(Converter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        view/main_window.cpp
        view/main_window.hpp
        view/main_window.ui
        model/converter_decimal_to_p.cpp
        model/converter_decimal_to_p.hpp
        model/converter_p_to_decimal.cpp
        model/converter_p_to_decimal.hpp
        controller/controller.cpp
        controller/controller.hpp
        model/history.cpp
        model/history.hpp
        view/history_window.cpp
        view/history_window.hpp
        view/history_window.ui
)

qt_add_executable(Converter
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
)

target_link_libraries(Converter PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Converter PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Converter
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Converter)
endif()
