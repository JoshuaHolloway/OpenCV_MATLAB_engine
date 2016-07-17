# OpenCV_MATLAB_engine
This is a minimal C++ program that passes OpenCV Mat object image data into MATLAB via the MATLAB engine.

Environment used:
Windows 7 Professional 64-bit, 
Visual Studio 2015 Professional 64-bit, 
MATLAB R2016a, 
OpenCV 3.1.0

The following property settings are machine specific. The general properties are described in the following two links:
http://www.mathworks.com/help/matlab/matlab_external/compiling-engine-applications-in-an-ide.html, 
http://docs.opencv.org/master/d6/d8a/tutorial_windows_visual_studio_Opencv.html#gsc.tab=0

Configuration Properties -> C/C++ -> General ->Additional Include Directories:
C:\Program Files\MATLAB\R2016a\extern\include, 
C:\opencv310\opencv\build\include


Configuration Properties -> Linker -> General ->Additional Library Directories:
C:\Program Files\MATLAB\R2016a\extern\lib\win64\microsoft, 
C:\opencv310\opencv\build\x64\vc14\lib

Configuration Properties -> Linker -> General -> Use Library Dependency Inputs: YES, 
Configuration Properties -> Linker -> Input -> Additional Dependencies: 
opencv_world310d.lib, libmx.lib, libut.lib, libmat.lib, libeng.lib, libmwimfilter.lib

Place the following .dll’s in the location that the .exe is created from VS:
opencv_world310d.dll, 
kernel32.dll, 
libmx.dll, 
libut.dll, 
msvcp120.dll, 
msvcr120.dll,
ole32.dll

It is relatively easy to extend this to perform more advanced linking of C++ and MATLAB as described here:
http://www.mathworks.com/campaigns/portals/matlab-coder.html
