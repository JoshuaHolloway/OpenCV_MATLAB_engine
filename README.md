# OpenCV_MATLAB_engine
This is a minimal C++ program that passes OpenCV Mat object image data into MATLAB via the MATLAB engine.

Environment used:
Windows 10 64-bit, 
Visual Studio 2015 Enterprise 64-bit, 
MATLAB R2016b, 
OpenCV 3.2.0

The following property settings are machine specific. The general properties are described in the following two links:
http://www.mathworks.com/help/matlab/matlab_external/compiling-engine-applications-in-an-ide.html, 
http://docs.opencv.org/master/d6/d8a/tutorial_windows_visual_studio_Opencv.html#gsc.tab=0

Configuration Properties -> C/C++ -> General ->Additional Include Directories:
C:\Program Files\MATLAB\R2016b\extern\include
C:\opencv\build\include

Configuration Properties -> Linker -> General ->Additional Library Directories:
C:\Program Files\MATLAB\R2016b\extern\lib\win64\microsoft
C:\opencv\build\x64\vc14\lib

Configuration Properties -> VC++ Directories -> Executable Directories:
C:\Program Files\MATLAB\R2016b\bin\win64

Configuration Properties -> VC++ Directories -> Include Directories:
C:\Program Files\MATLAB\R2016b\extern\include

Configuration Properties -> VC++ Directories -> Library Directories:
C:\Program Files\MATLAB\R2016b\extern\lib\win64\microsoft

Configuration Properties -> Linker -> Input -> Additional Dependencies:
opencv_world320d.lib
libmx.lib
libeng.lib
libmex.lib
libmat.lib

Added the following files into the directory where the .exe is generated:
libmx.dll
libut.dll
libeng.dll
libmwi18n.dll
libmwfl.dll
opencv_world320d.dll
opencv_world320d.lib
kernel32.dll
msvcp120.dll
msvcp120d.dll
msvcr120d.dll
ole32.dll

The below files were found in: C:\Program Files\MATLAB\R2016b\bin\win64
libmx.dll
libut.dll
libeng.dll
libmwi18n.dll
libmwfl.dll

The below files were found in: C:\Windows\System32
kernel32.dll
msvcp120.dll
msvcp120d.dll
msvcr120d.dll
ole32.dll

The below file was found at: C:\opencv\build\x64\vc14\bin
opencv_world320d.dll

The below file was found at: C:\opencv\build\x64\vc14\lib
opencv_world320d.lib

The following must also be set: 
http://www.mathworks.com/help/matlab/matlab_external/building-and-running-engine-applications-on-windows-operating-systems.html
Set Run-Time Library Path on Windows Systems

At run time, tell the operating system where the API shared libraries reside by setting the Path environment variable. Set the value to the path returned by the following MATLAB® command:

res = fullfile(matlabroot,'bin',computer('arch'))
Change Path Each Time You Run the Application
To set the run-time library path from the Windows® command prompt, type the following command, where res is the value returned from the fullfile command. Set the path every time you open the Windows Command Processor.

set PATH=res;%PATH%
You must set the path each time that you open the Windows prompt.

Permanently Change Path
To set the run-time library path permanently to res, modify the Path variable using the Control Panel. For the setting to take effect, close the command prompt window, then open a new command prompt window.

To remove the run-time library path, follow the same instructions, deleting the path name from the variable.

Windows 10
Select Computer from the Start menu.
Choose System properties from the context menu.
Click Advanced system settings > Advanced tab.
Click Environment Variables.
Under System variables, select Path and click Edit.
Modify Path by inserting res; at the beginning of the Variable value: text field.
Click Ok to close the dialog boxes, then close the Control Panel dialog box.

If you have multiple versions of MATLAB installed on your system, the version you use to build your engine applications must be the first listed in your system Path environment variable. Otherwise, MATLAB displays Can't start MATLAB engine.

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







