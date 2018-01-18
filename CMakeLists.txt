# WARNING!
# This project requires latest available glibc for i386!
#

# C++ standart
set(CMAKE_CXX_STANDARD 17)

# Source directory
set(SRC_DIR src)

# Linker script
set(LINKER_SCRIPT "link.ld")

# Additional g++ flags
set(CXX_ADDITIONAL_FLAGS "-m32")
set(C_ADDITIONAL_FLAGS "-m32")

# Additional linker flags
set(LINKER_ADDITIONAL_FLAGS "-m32 -nostdlib")

#####
cmake_minimum_required(VERSION 2.8)
enable_language(ASM_NASM)
set(CAN_USE_ASSEMBLER TRUE)
project(RKernel C CXX)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CXX_ADDITIONAL_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_ADDITIONAL_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${LINKER_ADDITIONAL_FLAGS} ${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/${LINKER_SCRIPT}")
file(GLOB_RECURSE CPP_SRC ${SRC_DIR}/*.cpp ${SRC_DIR}/*.h ${SRC_DIR}/*.c)
file(GLOB_RECURSE ASM_SRC ${SRC_DIR}/*.asm)
set(PROJECT_SRC ${CPP_SRC} ${ASM_SRC})
add_executable(${PROJECT_NAME} ${PROJECT_SRC})
