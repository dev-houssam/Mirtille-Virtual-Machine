cmake_minimum_required(VERSION 3.28.3 FATAL_ERROR)

project(MirtilleVirtualMachine VERSION 1.0 LANGUAGES C)

# Crée des variables avec les fichiers à compiler
set(SRCS
    src/main.c
    src/me_graph.c   
    src/me_network.c    
    src/me_stp.c
    src/me_video.c
    src/me_debug.c
    src/me_heap.c
    src/me_portaudio.c
    src/me_system.c
    src/me_vm.c
    src/me_ai.c
    src/me_engine.c
    src/me_memory.c
    src/me_sound.c
    src/me_trame.c
    )
    
# src/testNet.c


set(HEADERS
    include/me_ai.h
    include/me_graph.h
    include/me_sound.h
    include/me_video.h
    include/me_backups.h
    include/me_heap.h
    include/me_stp.h
    include/me_vm.h
    include/me_ai.h
    include/me_debug.h
    include/me_memory.h
    include/me_system.h
    include/me_engine.h
    include/me_network.h
    include/me_trame.h
    include/me_error.h
    include/me_portaudio.h
    include/me_utils.h 
    )

# find_package(portaudio)

add_executable(MVM ${SRCS} ${HEADERS})

# set(GLUT /home/houssam/freeglut)

# ouou
# set(glfw3_DIR /usr/local/lib/cmake/glfw3)
# set(glm_DIR /usr/local/lib/cmake/glm)

# include("/home/houssam/freeglut/CMakeLists.txt")

# add_definitions(-lglut -lGLU -lGL)

# find_package(libglut REQUIRED)

find_package(OpenGL REQUIRED)
# find_package(GLUT REQUIRED)
#find_package(GLEW REQUIRED)

# find_package(glfw3 REQUIRED)
# find_package(glm REQUIRED)
# ouou

# find_package(OpenGL REQUIRED)

# target_link_libraries(MVM PUBLIC GL GLUT portaudio)

add_definitions(-lGL -lGLU -lglut -lpthread -D_REENTRANT)

target_link_libraries(MVM PUBLIC GL glut GLU  portaudio)


# target_link_libraries(app PUBLIC stb glfw3 GL X11)

# add_dependencies(MirtilleVirtualMachine OpenGL)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

# target_link_libraries(MirtilleVirtualMachine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

# add_subdirectory("path to PortAudio location" "some binary directory" EXCLUDE_FROM_ALL)

# rm -rf CMakeFiles/ cmake_install.cmake CMakeCache.txt