# Vertical Seismic Profiling Software

This software is being created by Khushnood Qadir and Prajjaval Singh, with an aim to provide VSP software with state of the art workflows. The software is being currently written in C++. It is suppose to work on Windows/Linux, but it is currently being developed only for Windows.


## Installation

For installing the software following resources are required:
1. IDE, preferrably Microsoft Visual Studio Community
2. [Qt](https://www.qt.io/download-open-source)
3. [CMake](https://cmake.org/download/). We require CMake version greater than v3.0.0

To compile the code, do the following.
1. git clone <HTTP/SSH>
2. Open CMake GUI and provide the location to your source code and location where you would like to build your solution. The mandatory CMake variable is CMAKE_PREFIX_PATH. This can be defined in the GUI or the script can read the value from Environment Variable (CMAKE_LIB_PATH)
3. Open the solution upon successful compilation and generation. To run, VSProc target need to be set as startup project in Visual Studio Community.
