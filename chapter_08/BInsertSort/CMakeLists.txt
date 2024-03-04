# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)

include_directories(${CMAKE_SOURCE_DIR}/chapter_08/Util)

# 包含静态库路径
link_directories(${PROJECT_SOURCE_DIR}/lib)
link_libraries(SqList_guard_lib)

# 生成可执行文件
add_executable(BInsertSort BInsertSort.c)