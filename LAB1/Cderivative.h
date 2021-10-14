#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
class Cderivative
{
private:
	const double low_boundary = 0.;
	const double high_boundary = 1.;
	double deltaX;
public:
	Cderivative(double input_deltaX);
	long double function( double x);
	long double derivative( double x);
	long double forward_scheme_result(double x);
	long double backward_scheme_result(double x);
	long double central_scheme_result(double x);
	long double forward_shceme_error(double x);
	long double backward_scheme_error(double x);
	long double central_scheme_error(double x);
	void display_function();
};

