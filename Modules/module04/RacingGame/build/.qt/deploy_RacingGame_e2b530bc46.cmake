include("/Users/choeminhyeog/Desktop/seame/SEA-ME-warm-up/Modules/module04/RacingGame/build/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/RacingGame-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE RacingGame.app
)
