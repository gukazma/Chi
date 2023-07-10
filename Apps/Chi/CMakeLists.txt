set(TARGET_NAME Chi)

# just for qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        OpenGL
        REQUIRED)

find_package(Boost COMPONENTS filesystem system thread REQUIRED)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})
set(QRC_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Resources/resources.qrc)
set(APPRC_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Resources/appicon.rc)
file(GLOB_RECURSE CPP_HEAD_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE CPP_SOUCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE CU_SOUCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cu)
file(GLOB_RECURSE UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${CPP_HEAD_FILES} ${CPP_SOUCE_FILES} ${CU_SOUCE_FILES} ${UI_FILES})

add_executable(${TARGET_NAME} ${CPP_HEAD_FILES} ${CPP_SOUCE_FILES} ${CU_SOUCE_FILES} ${UI_FILES} ${QRC_FILE} ${APPRC_FILE})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME Chi)
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Apps)

target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

target_link_libraries(${TARGET_NAME} PRIVATE 
Qt5::Core
Qt5::Gui
Qt5::Widgets
Chi::Primitives
Chi::SFM
Boost::system
Boost::filesystem
Boost::dynamic_linking
Boost::thread
)

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)