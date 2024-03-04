# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)

# 生成可执行文件
add_executable(SeqList SeqList.c SeqList.h SeqList-main.c)

# 链接到公共库 Common_lib
target_link_libraries(SeqList Common_lib)
