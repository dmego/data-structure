# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)

# 生成可执行文件
add_executable(SqList SqList.c SqList.c SqList-main.c)

#设置动态库/静态库生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(SqList_lib STATIC SqList.c SqList.h)

