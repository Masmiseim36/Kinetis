# CPU Support package for the Kinetis-Family from NXP

This CPU Support package enables the development for the Kinetis microcontroller family using the [Crossworks development environment](https://rowley.co.uk/arm/index.htm) from Rowley. The package provides all needed data and information to enabled the Development Environment to compile and debug applications on the Kinetis microcontroller
This Includes:

- CMSIS-Specific Code Files
- Memory-Map-Files
- Register-Descriptions for debugging
- Loader for programming the application to the Flash-memory

The Package is based on the [work from Rowley](https://www.rowleydownload.co.uk/arm/packages/Kinetis_V3.htm). The original versions are included in the git-History and are tagged with a Rowley label.
This package enhances the original package by

- Using the latest CMSIS-Files and register-descriptions provided by NXP
- Added controller specific feature files
- Adding Support for the following devices
  - MKL81
  - MKW35
  - MKW37
  - MKW38
  - MKW39
  - MKS20
- Add Aditional Files to the Project template
  - fsl_device_registers.h
  - system_<Device>.h/.c
  - <Device>.h
- use new introduced DeviceName macro for adding the controller specific files to the project

## Build and Install

The Package is provided unpacked and has to be packed before it can be installed. For this open the Project File located in the root of the project with the Crossworks IDE (File Kinetis.hzp). Then “compile" it like a normal project (Build -> Build Kinetis). This will create the CPU-Support package in the root-Folder of the project (-> Kinetis.hzq).
To install the new created package, go to Tools -> Packages -> Manually Install Packages and choose the new File.
![Package Manager](./doc/Menu_PackageManagerManual.png)
