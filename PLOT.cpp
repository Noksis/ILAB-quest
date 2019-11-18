#include "TXLib.h"
#include <math.h>
const int PIXELS = 16000;
const int PIXELS_Y = 600;
const int Time_Graph = 2000;
const int funсtion_count = 4;
const char text_Hi[] = { "Hello, I can build graph function. Please wait" };
const char text_1[] = { "There is a x^2 function" };
const char text_2[] = { "There is a sin function" };
const char text_3[] = { "There is a cos function" };
const char text_4[] = { "There is a SQRT function" };
typedef double (math_func)(double x,double* coefs,int ncoefs);

double Convert_X (double x){
	return ((txGetExtentX() / 2) + x);
}

double Convert_Y (double y) {
	return ((txGetExtentY() / 2)- y);
}

void plot(math_func* FUNC,double* coefs, int ncoefs,const char* NUMBER) {
	txSetFillColor(TX_BLACK);

	// Clear window
	txClear();
	txColor(128, 0, 0);

	// Draw axis
	txLine(Convert_X(0), Convert_Y(-txGetExtentY() / 2), Convert_X(0), Convert_Y(txGetExtentY() / 2));
	txLine(Convert_X(-txGetExtentX() / 2), Convert_Y(0), Convert_X(txGetExtentX() / 2), Convert_Y(0));

	// Print text
	txTextOut(Convert_X(50), Convert_Y(150), NUMBER);

	// 
	double Domain_F[PIXELS] = {};
	double Range_F[PIXELS] = {};

	// Put pixels on screen
	for (int i = 0; i < PIXELS; i++) {
		Domain_F[i] = -txGetExtentX() + (double)i/10;
		if (FUNC(Domain_F[i],coefs,ncoefs) != ~0ull) {
			Range_F[i] = FUNC(Domain_F[i],coefs,ncoefs);
			txSetPixel(Convert_X(Domain_F[i]), Convert_Y(Range_F[i]), TX_ORANGE);
		}
	}

	txSleep(Time_Graph);
}

double Sin(double x,double* usless1,int usless2) {
	return (sin(x)*20);
}
double Cos(double x, double* usless1, int usless2) {
	return (cos(x)*20);
}
double Sqrt(double x,double* usless1, int usless2) {
	if (x > 0)
		return(sqrt(x));
	else
					//~0ull means that function is not defined at this interval
		return(~0ull);
}
double Pow(double x, double* coefs, int impower) {
	double mult = x;
	for (int i = 1; i < coefs[impower - 1]; i++)
		x = x * mult;
	return(x);
}
int main(void) {
	double coefs[] = { 2 };
	int ncoefs = 1;
	// Arrow with text for function
	const char* Text[] = { text_1,text_2,text_3,text_4 };

	math_func* Function_arrow[funсtion_count] = { Pow, Sin, Cos, Sqrt };

    // Creating window
	txCreateWindow((PIXELS/20), PIXELS_Y);
	txTextOut(Convert_X(-150), Convert_Y(150), text_Hi);
	txSleep(5000);

	// Draw graphics
	for (int i = 0; i < 4; i++) {
		plot(Function_arrow[i],coefs,ncoefs,Text[i]);
	}
	return 0;
}

