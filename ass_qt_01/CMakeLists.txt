cmake_minimum_required(VERSION 3.16)

project(ass_qt_01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC  ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 REQUIRED COMPONENTS Quick Svg Multimedia)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appass_qt_01
    main.cpp
    Resource.qrc
)

qt_add_qml_module(appass_qt_01
    URI ass_qt_01
    VERSION 1.0
    QML_FILES
        Main.qml
        RESOURCES Resource.qrc
        SOURCES musicload.h musicload.cpp
        SOURCES customimage.h customimage.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appass_qt_01 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appass_qt_01
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appass_qt_01
    PRIVATE Qt6::Quick Qt6::Svg  Qt6::Multimedia
)
target_link_libraries(appass_qt_01 PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appass_qt_01
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
