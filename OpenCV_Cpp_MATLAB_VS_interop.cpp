// Josh Holloway
// This is a program linking together OpenCV and MATLAB
//=============================================================================
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <stdlib.h>
#include <iostream>
#include "engine.h"  // MATLAB Engine Header File required for building in Visual Studio 
#include "mex.h"
//=============================================================================
void linearize(const cv::Mat& mat_in, double* arr_out, const size_t M, const size_t N)
{ // Swap from row-major to col-major
	for (int row = 0; row < M; row++)
		for (int col = 0; col < N; col++)
			arr_out[col * M + row] = static_cast<double>(mat_in.at<unsigned char>(row, col));
}
//=============================================================================
class matlabClass
{
private:
	Engine *ep;				// Pointer to a MATLAB Engine
	mxArray *mx_Arr;  // To store the image data inside MATLAB
public:
	matlabClass() // Default constructor
	{
		// Start the MATLAB engine
		ep = engOpen(NULL);

		// Reset MATLAB Environment
		engEvalString(ep, "clc, clear, close all;");
	}
	~matlabClass() // Destructor
	{
		//free(ep);
		engEvalString(ep, "close all;");
	}
	void command(const char* str)
	{
		engEvalString(ep, str);
	}
	void passImageIntoMatlab(const cv::Mat& img)
	{
		// Convert the Mat object into a double array
		double* linImgArrDouble = (double*)malloc(sizeof(double) * img.rows * img.cols);
		linearize(img, linImgArrDouble, img.rows, img.cols);

		// Copy image data into an mxArray inside C++ environment
		mx_Arr = mxCreateDoubleMatrix(img.rows, img.cols, mxREAL);
		memcpy(mxGetPr(mx_Arr), linImgArrDouble, img.rows * img.cols * sizeof(double));

		/// C++ -> MATLAB
		// Put variable into MATLAB workstpace
		engPutVariable(ep, "img_from_OpenCV", mx_Arr);
		engEvalString(ep, "figure, imshow(img_from_OpenCV, [],'Border','tight');");
	}
	void getAudioFromMatlab()
	{
		// Read in audio file and play sound:
		engEvalString(ep, "[y,Fs] = audioread('handel.wav');");
		engEvalString(ep, "sound(y,Fs);");
	}
	void returnScalarFromMatlab()
	{
		command("matlabVal=42;");

		// Grab value from workspace
		mxArray *cppValmxArray;
		cppValmxArray = engGetVariable(ep, "matlabVal");															// Pointer to MATLAB variable 
		const double* cppValDblPtr = static_cast<double*>(mxGetData(cppValmxArray));	// Pointer to C variable
		std::cout << "Value passed from MATLAB into C++ = " << *cppValDblPtr << std::endl;
	}
	void returnVectorFromMatlab()
	{
		// Create a row-vector in MATLAB
		command("matlabVal=[1,2]");

		mxArray *cppValmxArray;
		cppValmxArray = engGetVariable(ep, "matlabVal");															// Pointer to MATLAB variable 
		const double* cppValDblPtr = static_cast<double*>(mxGetData(cppValmxArray));	// Pointer to C variable
		std::cout << "Vector passed from MATLAB into C++ = " << cppValDblPtr[0] << " " << cppValDblPtr[1] << std::endl;
	}
	//void returnMatrixFromMatlab()
};
//=============================================================================
int main()
{
	// Instiantial matlab engine object
	matlabClass matlabObj;

	// Change to active directory 
	matlabObj.command("cd C:/Users/josh/Dropbox/joshMATLAB");
	// Read and display image:																																																																
	// Clear command window
	matlabObj.command("clc, clear, close all;");

	// Read image into environment as a cv::Mat object
	cv::Mat img = cv::imread("image.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cv::imshow("OpenCV", img);

	/// C++ -> MATLAB
	// Send image data to MATLAB workspace
	matlabObj.passImageIntoMatlab(img);

	/// MATLAB -> C++
	// Read audio data from MATLAB into C++ workspace
	matlabObj.getAudioFromMatlab();

	/// MATLAB -> C++
	// Demonstrate how to pass a value from MATLAB into C++ workspace
	matlabObj.returnScalarFromMatlab();

	/// MATLAB -> C++
	// Demonstrate how to pass a vector from MATLAB into C++ workspace
	matlabObj.returnVectorFromMatlab();

	/// Close program and exit open windows
	cv::waitKey(0); // Wait on key-press from user
	return 0;
}
