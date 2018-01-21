// This is a program linking together OpenCV and MATLAB
// Please see the program ML_Engine_Demo for the full program.
// This version is minimal for only passing data into matlab
// from an OpenCV Mat object
//=============================================================================
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "engine.h"  // MATLAB Engine Header File required for building in Visual Studio 
#include "mex.h"

#define BUFSIZE 256
//=============================================================================
void linearize(const cv::Mat& mat_in, double* arr_out, const size_t M, const size_t N)
{ // Swap from row-major to col-major
	for (int row = 0; row < M; row++)
		for (int col = 0; col < N; col++)
			arr_out[col * M + row] = static_cast<double>(mat_in.at<unsigned char>(row, col));
}
//=============================================================================
int main()
{
	Engine *ep;	// Pointer to an MATLAB Engine

							/*
							* Start the MATLAB engine
							*	- MATLAB runs in the background
							*	- Access to MATLAB command prompt
							*	- Visibility to workspace variables
							*/
	ep = engOpen(NULL);

	// Reset MATLAB Environment
	engEvalString(ep, "clc, clear, close all;");

	// Evaluate string in MATLAB environment to point to a specific folder - there is nothing in this directory currently
	engEvalString(ep, "cd C:/Users/josh/Dropbox/joshMATLAB");					// Change to active directory 

																																																			// Read and display image:																																																																	
	cv::Mat img = cv::imread("image.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cv::imshow("OpenCV", img);

	//// Convert the Mat object into a double array
	const size_t M = img.rows;
	const size_t N = img.cols;
	double* arr_out = (double*)malloc(sizeof(double) * M * N);
	linearize(img, arr_out, M, N);

	// Pass image into MATLAB and evaluate it inside a .m script
	mxArray *mx_Arr;
	mx_Arr = mxCreateDoubleMatrix(M, N, mxREAL);
	memcpy(mxGetPr(mx_Arr), arr_out, M * N * sizeof(double));
	engPutVariable(ep, "img_from_OpenCV", mx_Arr);
	engEvalString(ep, "figure, imshow(img_from_OpenCV, [],'Border','tight');");
	engEvalString(ep, "[img_in_MATLAB, PSNR] = TestBench_moving_stats(img_from_OpenCV);");  // Call entire MATLAB scripts/functions and pass arguments

																																													/// Retrieve data from MATLAB to process in C code
																																													//	Data marshalling
	mxArray *PSNR;
	//...

	/// Operate on data retrieved from MATLAB
	//...

	/// Push C results to MATLAB workspace for
	//	1. Visualization
	//	2. Analysis
	//	3. And Testing
	//...

	// Grab PSNR from workspace
	PSNR = engGetVariable(ep, "PSNR");															// Pointer to MATLAB variable 
	const double* I_psnr = static_cast<double*>(mxGetData(PSNR));		// Pointer in C variable
	std::cout << "PSNR = " << *I_psnr << std::endl;

	/// Close program and exit open windows
	//cv::waitKey(0); // Wait on key-press from user
	engEvalString(ep, "close all;");
	// De-Allocate memory
	//...
	return 0;
}
