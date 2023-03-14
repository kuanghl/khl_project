cmake_minimum_required(VERSION 3.0.0)
project(episode LANGUAGES C)
 
# 1. 查找内核头文件目录
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(KernelHeaders REQUIRED)
# 2. 将内核头文件目录添加到本次编译的头文件目录，相当于-I
include_directories(${KERNELHEADERS_INCLUDE_DIRS})
 
# 3. 设置最终的模块文件和目标文件
set(MODULE_FILE "${PROJECT_NAME}.ko")
set(KBUILD_FILE "obj-m := ${PROJECT_NAME}.o")
 
# 4. 设置某些有特殊要求的目标对象的编译参数，这里是目标文件中有浮点运算，而编译器默认关闭了 msse
set(KBUILD_FILE "${KBUILD_FILE}\nCFLAGS_src/${PROJECT_NAME}.o += -mhard-float -msse -msse2 ")
set(KBUILD_FILE "${KBUILD_FILE}\nCFLAGS_src/episode_space_index.o += -mhard-float -msse -msse2 ")
 
# 5. 设置模块构建命令，用变量代替
set(KBUILD_CMD $(MAKE) -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR})
 
# 6. 遍历src目录获取所有的.c文件，并将他们添加到sources_absolute列表中，GLOB_RECURSE会遍历匹配src目录的所有文件以及子目录下面的文件
file(GLOB_RECURSE sources_absolute ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
# 7. 针对每一个.c文件，获取其相对路径，放到sources_relative列表中，并将待构建目标文件追加到KBuild文件中，同时在构建目录下创建对应的文件夹用来存放将要生成的目标文件
foreach(file ${sources_absolute})
  # 7.1 RELATIVE_PAT推断出指定文件file相对于特定目录的路径，并将该路径赋值给变量${file}
  file(RELATIVE_PATH file "${CMAKE_CURRENT_SOURCE_DIR}" "${file}")
  # 7.2 提取上一步拿到的变量${file}中的目录，保存到变量file_dir
  get_filename_component(file_dir "${file}" DIRECTORY)
  # 7.3 提取上一步拿到的变量${file}中的文件名称（不含目录和文件名的后缀），保存到变量file_name_we
  get_filename_component(file_name_we "${file}" NAME_WE)
  
  # 7.4 在构建目录下，给上面解析的文件创建对应的目录，用来保存.c生成的.o文件
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${file_dir})
 
  # 7.5 将待构建的目标文件（.o文件）追加到Kbuild文件中
  set(KBUILD_FILE "${KBUILD_FILE}\n${PROJECT_NAME}-y += ${file_dir}/${file_name_we}.o")
 
  # 7.6 将源代码文件的相对路径放到sources_relative 列表中
  list(APPEND sources_relative "${file_dir}/${file_name_we}.c")
endforeach()
 
# 8. 追加编译选项到KBuild文件中
set(KBUILD_FILE "${KBUILD_FILE}\nccflags-y := -DMODULE_NAME=\\\"${PROJECT_NAME}\\\"")
 
# 9. 删除sources_relative列表后面的空格
message(WARNING ${sources_relative})
string(REGEX REPLACE "\n$" "" ${sources_relative} "${sources_relative}")
message(WARNING ${sources_relative})
 
# 10. 将前面${KBUILD_FILE}缓存的数据写入到Kbuild文件中
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild ${KBUILD_FILE})
 
# 11. 创建一个custom_command命令，用于构建内核模块
add_custom_command(OUTPUT ${MODULE_FILE}
  COMMAND ${KBUILD_CMD}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${sources_relative} VERBATIM)
# 12. 创建一个构建目标
add_custom_target(${PROJECT_NAME} ALL DEPENDS ${MODULE_FILE})