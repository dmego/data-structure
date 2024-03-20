# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)
include_directories(${CMAKE_SOURCE_DIR}/chapter_02/SqList)
# 包含静态库路径
link_directories(../../../lib)
link_libraries(SqList_lib)

# 生成可执行文件
add_executable(exercises2.2.1 exercises2.2.1.c)
add_executable(exercises2.2.2 exercises2.2.2.c)
add_executable(exercises2.2.3 exercises2.2.3.c)
add_executable(exercises2.2.4 exercises2.2.4.c)
add_executable(exercises2.2.5 exercises2.2.5.c)
add_executable(exercises2.2.6 exercises2.2.6.c)
add_executable(exercises2.2.7 exercises2.2.7.c)
add_executable(exercises2.2.8 exercises2.2.8.c)
add_executable(exercises2.2.9 exercises2.2.9.c)
add_executable(exercises2.2.10 exercises2.2.10.c)
add_executable(exercises2.2.11 exercises2.2.11.c)
add_executable(exercises2.2.12 exercises2.2.12.c)
add_executable(exercises2.2.13 exercises2.2.13.c)
add_executable(exercises2.2.14 exercises2.2.14.c)
