cmake_minimum_required(VERSION 3.24)
project(AntigravityTest VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(AntigravityTest main.cpp)

# Download and use raylib from source
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
    steam-audio
    GIT_REPOSITORY "https://github.com/ValveSoftware/steam-audio.git"
    GIT_TAG        "v4.7.0"
)
FetchContent_MakeAvailable(steam-audio)

#경로 가져오기
# dependency 관련 python 실행
# ${steam-audio_SOURCE_DIR}/core/build/dependencies.js의 
# portaudio, flatbuffers, pffft 세 라이브러리의 버전 변경

# 1. 탐색을 위한 정규식 필요

execute_process(
    COMMAND python "${steam-audio_SOURCE_DIR}/core/build/get_dependencies.py" "--platform" "windows" "--toolchain" "vs2022"
    WORKING_DIRECTORY ${steam-audio_SOURCE_DIR}/core/build
)

# build python 실행
target_link_libraries(AntigravityTest PRIVATE raylib)
target_link_libraries(AntigravityTest PRIVATE steam-audio)