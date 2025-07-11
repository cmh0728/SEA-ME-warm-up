cmake_minimum_required(VERSION 3.19)
project(PhoneBookApp LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_standard_project_setup()

qt_add_executable(PhoneBookApp
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Contact.h
    Contact.cpp
    Contactlist.h
    Contactlist.cpp
    subwindow.h
    subwindow.cpp
    subwindow.ui
)


target_link_libraries(PhoneBookApp
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Gui
)

include(GNUInstallDirs)

install(TARGETS PhoneBookApp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET PhoneBookApp
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
