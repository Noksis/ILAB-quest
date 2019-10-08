#include <stdio.h>
#include <math.h>
#include <assert.h>
#pragma warning (disable: 4996)
int Max=3;
const int OneRoot = 1;
const int TwoRoot = 2;
const int InfinitRoot = -1;
const int ZeroRoot = 0;
const int UTest = 30;
const double  mistake = 1e-12;

int Input(double coeff[], int Max);

int Solver_Line(double a, double b, double* x1);

int Solver_Square(double a, double b, double c, double* x1, double* x2);

int Unit_Test();


double Compare(double x1,double x2);
/*!
	\brief Main function
	\version 1.2.1
	\return 0 Programm is succesful working
*/

int main() {
	int intnroots = -2;
	double x1 = NAN, x2 = NAN;
	double coeff[3] = { 0 };
	assert(Unit_Test());
	printf("Hello, I solve square equation, please enter odds\n");

	if (Input(coeff, Max) != 0)
		return 0;
	intnroots = Solver_Square(coeff[0], coeff[1], coeff[2], &x1, &x2);


	assert(intnroots != -2);
	switch (intnroots) {
	case InfinitRoot: 
		printf("Infinity number of roots");
		break;
	case TwoRoot:
		printf("x1 = %lf x2 = %lf ", x1, x2);
		break;
	case OneRoot:
		printf("x1 = %lf", x1);
		break;
	case ZeroRoot:
		printf("Sorry, you have not roots");
		break;
	}

} 
/*!
	\brief Input function
	\details
	This is an input function. 
	You enter values; if the format is incorrect, it gives an error.
	When the value is accepted, it reports this and writes the number of successfully entered variables
	\param [in] coeff[] Empty array
	\param [in] Max Array size for coefficients
	\param [out] coeff[] Array of coefficients. Contains desired coefficients
	\return 1 If you havenot attempts

*/

int Input(double coeff[], int Max) {
	int i = 0, j = 0;
	for (int b = 0; i < Max;) {
		b = scanf("%lf", &coeff[i]);
		if (b == 0) {
			printf("Wrong Input!\nYou have %d/5 attempts\n",(5-++j));
			scanf("%*s");
			if (j == 5) {
				printf("Error limit exceeded\n");
				return -1;
			}
		}
		else 
			printf("Accept input %d/%d\n", ++i, Max);
	}
	return 0;
}
/*!
	\brief Programm which solve  square equation
	\details
	You accept 3 value: there are coefficients our equation. If a = 0, b = 0,c = 0 we have infinity number
	of roots. If a = 0, b = 0 u have not roots. If a = 0 we have line equation and we use LineSolver(b,c).
	If c = 0, x1 = 0 and we need LineSolver(a,b). If a != 0 , b != 0 , c != 0 we should calculate discriminant
	and compare with 0: we will have 0 roots if discriminant < 0, we will have 1 roots if discr. = 0, we will
	have 2 roots if discr. > 0
	\param [in] a Is coefficients ax^2 + bx + c = 0
	\param [in] b is coefficients ax^2 + bx + c = 0
	\param [in] c is coefficients ax^2 + bx + c = 0
	\param [in] x1 adress first root
	\param [in] x2 adress second root
	\return 0 if we havenot roots
	\return 1 if we have one root
	\return 2 if we have two roots
	\return -1 if we have infinity number of root

*/
int Solver_Square(double a, double b, double c, double* x1, double* x2) {
	double d = 0, sq = 0;
	assert(x1 != NULL);
	assert(x2 != NULL);
	if ((Compare(a,0) || Compare(b,0) || Compare(c,0)) == 0) {
		*x1 = 0;
		*x2 = 0;
		return -1;
	}
	else if ((Compare(a,0) || Compare(b,0)) == 0) {
		*x1 = 0;
		*x2 = 0;
		return 0;
	}
	else if (Compare(a,0) == 0) 
		return  Solver_Line(b,c,x1);
	else if (Compare(c,0) == 0) {
		*x2 = 0;
		Solver_Line(a, b, x1);
		if (*x1 == *x2)
			return 1;
		return  2;
	}
	else if (Compare (a,0 )&& Compare(b,0) && Compare(c,0)) {
		d = b * b - 4 * a * c;
		if (d < 0)
			return 0;
		assert(d >= 0);
		sq = sqrt(d);
		if (Compare(d,0) == 0) {
			*x1 = -b / 2 / a;
			return 1;
		}
		else {
			*x1 = (-b + sq) / 2 / a;
			*x2 = (-b - sq) / 2 / a;
		}
	}

	return 2;

}
/*!
	\brief Program which solve line equation
	\param [in] a is first coefficients in ax + b = 0
	\param [in] b is second coefficients in ax + b = 0
	\param [in] *x1  adress first root
*/
int Solver_Line(double a, double b, double* x1) {
	if ((Compare(a,0) || Compare(b,0)) == 0)
		return -1;
	if (Compare(a,0) == 0 && Compare(b,0))
		return 0;
	if (Compare(b,0)==0) {
		*x1 = 0;
		return 1;
	}
	if (Compare(a,0) && Compare(b,0)) {
		*x1 = -b / a;
		return 1;
	}
}
/*!
	\brief Program which compare two values
	\param [in] x1 is first value
	\param [in] x2 if second value
	\return 1 If x1-x2 > mistake
	\return 0 If x1-x2 < mistake
*/
double Compare(double x1, double x2) {
	return (fabs(x1 - x2) > mistake);
}
/*!
	\brief Program which test my programm
	\return 1 if test are successful
	\return -1 if u fail test and print number fail test
*/
int Unit_Test() {
	double x1 = NAN, x2 = NAN;
	double Values[UTest] = { 0,0, 0,-1 , 0,  0,
						  0,0, 1, 0 , 0,  0,
						  1,2, 1, 1, -1,  0,
						  2,1, 2, 0,  0,  0,
						  1,1,-12, 2, 3, -4 };
	for (int i = 0; i < UTest; i = i + 6) {
		if (Solver_Square(Values[i], Values[1+i], Values[2+i], &x1, &x2) == Values[3 + i]) {
			if (Values[3 + i] != -1 && Values[3 + i] != 0)
				if (Values[4 + i] != x1 || Values[5 + i] != x2) {
					printf("Fail %d Unit Test\n", (i / 5 + 1));
					return -1;
				}
		}
		else {
			printf("Fail %d Unit Test", (i / 5 + 1));
			return -1;
		}
		}
return 1;
}
