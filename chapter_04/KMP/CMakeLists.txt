# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/status)

# 生成可执行文件
add_executable(KMP SString.c SString.h KMP.c KMP.h KMP-main.c)

# 链接到公共库 Common_lib
target_link_libraries(KMP Common_lib)