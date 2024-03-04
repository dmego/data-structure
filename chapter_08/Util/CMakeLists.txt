# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)

#设置动态库/静态库生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(SqList_guard_lib STATIC SqList.c SqList.h)

