# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(MODULE_NAME kioctl) # The name of the module.

add_definitions(-D__KERNEL__ -DMODULE) # Add a definition for kernel modules.

# Execute this command, to find your current Linux kernel version.
execute_process(
        COMMAND uname -r # This finds your kernel version.
        OUTPUT_VARIABLE KERNEL_RELEASE # Output the kernel release.
        OUTPUT_STRIP_TRAILING_WHITESPACE # Add a whitespace.
        )

# Now, we want to find the path with all the kernel modules.
find_path(
        KERNELHEADERS_DIR # Kernel headers directory.
        include/linux/user.h # Include this header file.
        PATHS /usr/src/linux-headers-${KERNEL_RELEASE} # The path of the kernel modules.
        )

message(STATUS "Kernel release: ${KERNEL_RELEASE}") # Message to show the kernel release.
message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}") # Message to show the directory with kernel headers/modules.

# Include the kernel directories with 'CMake'.
include_directories(
        ${KERNELHEADERS_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/
        )

set(DRIVER_FILE "${MODULE_NAME}.ko") # Set the name of the '*.ko' file.
set(KBUILD_CMD $(MAKE) -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}) # Execute the build command of 'make'.

FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild "${MODULE_NAME}-objs := kioctl_dev.o\n obj-m := ${MODULE_NAME}.o") # Let CMake generate the 'Kbuild' file.

# This is my custom command to make sure that all the dependencies are there.
add_custom_command(OUTPUT ${DRIVER_FILE}
        COMMAND ${KBUILD_CMD}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} # Current working directory.
        DEPENDS kioctl_dev.c VERBATIM # Dependencies.
        )

# This target is used to build the actual device driver (and the '*ko' file).
add_custom_target(kioctl_driver
        ALL DEPENDS ${DRIVER_FILE}
        )

# This target is used to load the module into the kernel (use it with 'sudo' rights).
add_custom_target(kioctl_load
        COMMAND insmod ./${MODULE_NAME}.ko
        )

# This target is used to unload the module from the kernel (use it with 'sudo' rights).
add_custom_target(kioctl_unload
        COMMAND rmmod ./${MODULE_NAME}.ko
        )

# Copy file/dir to point destination.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/load_module.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
