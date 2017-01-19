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

Configuration Properties -> Linker -> General -> Use Library Dependency Inputs: YES

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

Note that the Image Watch plugin to Visual Studio is an especially convenient tool for visualizing your processed images directly inside VS: https://visualstudiogallery.msdn.microsoft.com/e682d542-7ef3-402c-b857-bbfba714f78d, http://docs.opencv.org/2.4/doc/tutorials/introduction/windows_visual_studio_image_watch/windows_visual_studio_image_watch.html

======================================
======================================
Extra Videos Related to MATLAB and C++:
--------------------------------------
Calling MATLAB from C Code:
https://www.mathworks.com/videos/calling-matlab-from-c-code-68913.html

Signal Processing Design Using MATLAB and C/C++
https://www.mathworks.com/videos/signal-processing-design-using-matlab-and-cc-100369.html

MATLAB and C/C++: The Perfect Combination for Signal Processing:
https://www.mathworks.com/videos/matlab-and-cc-the-perfect-combination-for-signal-processing-92862.html

Generating C Code from MATLAB Code:
https://www.mathworks.com/videos/generating-c-code-from-matlab-code-68964.html

Learn the difference between using MATLAB Coder and MATLAB Compiler:
https://www.mathworks.com/videos/generating-c-code-from-matlab-code-68964.html

Generating C Code from MATLAB Code:
https://www.mathworks.com/videos/generating-c-code-from-matlab-code-68964.html

Unit Testing Your Generated Code Using MATLAB Coder:
https://www.mathworks.com/videos/unit-testing-your-generated-code-using-matlab-coder-115873.html

Addressing Implementation Constraints Using MATLAB Coder:
https://www.mathworks.com/videos/addressing-implementation-constraints-using-matlab-coder-119134.html

MATLAB for C/C++ Programmers:
https://www.mathworks.com/videos/matlab-for-cc-programmers-81699.html

Rapid Development Platform for Low-Power C-Programmable DSP Using MATLAB and Simulink:
https://www.mathworks.com/videos/rapid-development-platform-for-low-power-c-programmable-dsp-using-matlab-and-simulink-101694.html

Embedded Coder Overview:
https://www.mathworks.com/videos/matlab-coder-overview-61200.html







