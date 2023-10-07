#!/bin/sh

device_name=knetlink
mode=777

# unload or load .ko to pc.
value=$1 # Get the first argument passed to this script.

# Check if we want to load the module into the kernel.
if [ "${value}" = "load" ]; then
    # sudo make load # Make the target 'load'.
    sudo insmod $device_name.ko

    module_information=$(grep $device_name /proc/modules) # Check if the module is within the kernel.
    device_number=$(grep $device_name /proc/devices) # Check if the device driver is there.

    echo "[KERNEL MODULES] - Information of the specific module: $module_information" # Print the kernel module.
    echo "[KERNEL MODULES] - Information of the specific device: $device_number" # Print the device driver information.

    sudo mknod /dev/$device_name c "${device_number%% *}" 0 # Create a node, so you can access the device driver.
    sudo chmod $mode /dev/$device_name # Change the access rights.

    echo "[KERNEL MODULES] - Loaded the device driver!" # Message that the device driver is loaded.
elif [ "${value}" = "unload" ]; then
    sudo rm /dev/$device_name # We are unloading, remove also the driver (just a file).
    # sudo make unload # Make the target 'unload'.
    sudo rmmod $device_name.ko
    # make clean # Clean all the targets.

    echo "[KERNEL MODULES] - Unloaded the device driver!" # Message that the device driver is unloaded.
else
    echo "[KERNEL MODULES] - No target specified, use as argument 'load' or 'unload' for loading/unloading the driver!" # No target specified.
fi