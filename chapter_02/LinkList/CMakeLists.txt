# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)

# 生成可执行文件
add_executable(LinkList LinkList.c LinkList.h LinkList-main.c)

# 链接到公共库 Common_lib
target_link_libraries(LinkList Common_lib)
#设置动态库/静态库生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(LinkList_lib STATIC LinkList.c LinkList.h)