cmake_minimum_required(VERSION 3.0.0)

project(p2pgroupchat-gui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)



find_package(Boost COMPONENTS thread system REQUIRED)
find_package(Crypto++ REQUIRED)
find_package(OpenP2P COMPONENTS Root UDP TCP IP Crypt Transport Concurrency Event Util REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Xml Sql REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} ${Crypto++_INCLUDE_DIR} ${OpenP2P_INCLUDE_DIRS})

set(${PROJECT_NAME}libs ${Boost_LIBRARIES} ${Crypto++_LIBRARIES} ${OpenP2P_LIBRARIES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/defines.h.cmake
                                ${CMAKE_CURRENT_BINARY_DIR}/defines.h @ONLY)

file (GLOB_RECURSE Sources "*.cpp")
file (GLOB_RECURSE Headers "*.h")
file(GLOB_RECURSE Resources "*.qrc" )
file(GLOB_RECURSE UIS "*.ui" )
file(GLOB_RECURSE Styles "*.qss")

qt5_add_resources(ResourceSources ${Resources})
qt5_wrap_ui(UISources ${UIS})

add_executable(${PROJECT_NAME} ${Sources} ${Headers}  ${ResourceSources} ${UISources})

target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}libs})

qt5_use_modules(${PROJECT_NAME} Widgets Network Sql)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_NAME}/bin)

if (UNIX)
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
	install(FILES ${Styles} DESTINATION bin)
elseif (WIN32)
	install(TARGETS ${PROJECT_NAME} DESTINATION .)
	install(FILES ${Styles} DESTINATION .)
endif()
