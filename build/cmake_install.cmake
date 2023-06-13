# Install script for directory: /home/kuanghongliang/Documents/vscode_projects/kusr_code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local/llvm")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/log/cmake_install.cmake")
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/3rd/cmake_install.cmake")
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/test/cmake_install.cmake")
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/perf/cmake_install.cmake")
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/fun/cmake_install.cmake")
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/cfun/cmake_install.cmake")
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/lib/cmake_install.cmake")
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/src/cmake_install.cmake")
  include("/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/tools/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/kuanghongliang/Documents/vscode_projects/kusr_code/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
