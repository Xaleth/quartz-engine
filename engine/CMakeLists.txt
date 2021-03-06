cmake_minimum_required(VERSION 3.0)

project(quartz-engine LANGUAGES CXX CXXPCH)

add_subdirectory(source/include)
add_subdirectory(source/src)

add_library(${PROJECT_NAME} STATIC ${quartzSources} ${quartzHeaders})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2-static SDL2main glad luamod imgui)

set(dependencies ${CMAKE_CURRENT_LIST_DIR}/../third_party)
target_include_directories(${PROJECT_NAME} PUBLIC 
	${dependencies}/SDL2/include 
	${dependencies}/glad/include 
	${dependencies}/stb_image 
	${dependencies}/inih 
	${dependencies}/luamod/include
	${dependencies}/imgui/include
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/source/include/)

if(WIN32)
	target_link_libraries(${PROJECT_NAME} PRIVATE imm32.lib ole32.lib oleaut32.lib opengl32.lib version.lib winmm.lib)
endif()

if(UNIX AND NOT APPLE)
	find_package(X11 REQUIRED)
	find_package(Threads REQUIRED)
	target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_LIBRARIES} ${X11_Xxf86vm_LIB} GL)
endif()

if (MSVC)
    # do not use PCH on linux because it won't compile otherwise
    target_precompiled_header(${PROJECT_NAME} source/include/quartz/core/QuartzPCH.hpp TYPE c++-header)
    set_target_properties(quartz-engine.pch PROPERTIES FOLDER quartz-dependencies)
endif()

foreach(FILE ${quartzSources}) 
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

    string(REPLACE "/" "\\" GROUP "${GROUP}")

    set(GROUP "Source Files${GROUP}")
    source_group("${GROUP}" FILES "${FILE}")
endforeach()

foreach(FILE ${quartzHeaders})
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

    string(REPLACE "/" "\\" GROUP "${GROUP}")

    set(GROUP "Header Files${GROUP}")
    source_group("${GROUP}" FILES "${FILE}")
endforeach()
