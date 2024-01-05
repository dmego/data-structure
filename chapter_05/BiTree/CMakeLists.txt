# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)

# 生成可执行文件
add_executable(BiTree BiTree.c BiTree.h LinkQueue.c LinkQueue.h  SqStack.c SqStack.h BiTree-main.c)

# 链接到公共库 Common_lib
target_link_libraries(BiTree Common_lib)