cmake_minimum_required(VERSION 3.19)
project(MakePlayList VERSION 1.1.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.3/msvc2022_64")
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

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
    MakePlayList.rc
    about_dialog.cpp
    about_dialog.h
    about_dialog.ui
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

if (EXISTS $<TARGET_FILE_DIR:MakePlayList>/MakePlayList.ico)
  add_custom_command(TARGET MakePlayList POST_BUILD COMMAND ${CMAKE_COMMAND} -E rm $<TARGET_FILE_DIR:MakePlayList>/MakePlayList.ico)
endif()
add_custom_command(TARGET MakePlayList POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/MakePlayList.ico $<TARGET_FILE_DIR:MakePlayList>)
