cmake_minimum_required(VERSION 3.28.3)

project(MirtilleVirtualMachine)

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
    src/testNet.c
    )
    
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

add_executable(MVM ${SRCS} ${HEADERS})