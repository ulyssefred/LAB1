#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
class Cderivative
{
private:
	const double low_boundary = 0.0;
	const double high_boundary = 1.0;
	double deltaX;
public:
	Cderivative(double input_deltaX);
	double function(double x);
	double derivative(double x);
	double forward_scheme_result(double x);
	double backward_scheme_result(double x);
	double central_scheme_result(double x);
	double forward_shceme_error(double x);
	double backward_scheme_error(double x);
	double central_scheme_error(double x);
	void display_function();
};

