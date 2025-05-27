cmake_minimum_required(VERSION 3.19)
project(MakePlayList VERSION 1.0.1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

string(REPLACE "." "," PROJECT_VERSION_STR "${PROJECT_VERSION}" ",0")
configure_file(${CMAKE_SOURCE_DIR}/MakePlayList.rc.in ${CMAKE_SOURCE_DIR}/MakePlayList.rc @ONLY)

qt_standard_project_setup()

qt_add_executable(MakePlayList
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    plsfiles.cpp
    plsfiles.h
    filelist.cpp
    filelist.h
    filediredit.cpp
    filediredit.h
    MakePlayList.qrc
    MakePlayList.rc
)

target_link_libraries(MakePlayList
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

target_include_directories(MakePlayList
    PRIVATE ${CMAKE_SOURCE_DIR}
)

install(TARGETS MakePlayList
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET MakePlayList
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

add_compile_definitions(APP_VERSION="${PROJECT_VERSION}")
