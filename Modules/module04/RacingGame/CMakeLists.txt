cmake_minimum_required(VERSION 3.19)
project(RacingGame LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(RacingGame
    WIN32 MACOSX_BUNDLE
    main.cpp
    racinggame.cpp
    racinggame.h
    racinggame.ui
    car.h
    car.cpp
    racetrack.h
    racetrack.cpp
    carthread.h
    carthread.cpp
)

target_link_libraries(RacingGame
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS RacingGame
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET RacingGame
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
