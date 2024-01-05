# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)

# 生成可执行文件
add_executable(SqStack SqStack.c SqStack.h SqStack-main.c)

# 链接到公共库 Common_lib
target_link_libraries(SqStack Common_lib)