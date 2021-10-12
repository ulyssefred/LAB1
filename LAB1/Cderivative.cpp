#include "Cderivative.h"
//initial deltaX
Cderivative::Cderivative(double input_deltaX)
{
	deltaX = input_deltaX;
}
//function f(x)
double Cderivative::function(double x)
{
	double temp = (3 * x * x * x) + (2 * x) + 1;
	return temp;
}
//derivatived function f'(x)
double Cderivative::derivative(double x)
{
	double temp = (9 * x * x) + 2;
	return temp;
}
//compute forward_scheme_result
double Cderivative::forward_scheme_result(double x)
{	
	double result = (function(x + deltaX) - function(x))/deltaX;
	return result;
}
//compute backward_scheme_result
double Cderivative::backward_scheme_result(double x)
{
	double result = (function(x) - function(x - deltaX))/deltaX;
	return result;
}
//compute central_scheme_result
double Cderivative::central_scheme_result(double x)
{
	double result = (function(x + deltaX) - function(x - deltaX))/(2*deltaX);
	return result;
}
//compute forward_shceme_error
double Cderivative::forward_shceme_error(double x)
{	
	double error = forward_scheme_result(x) - derivative(x);
	return error;
}
//compute backward_scheme_error
double Cderivative::backward_scheme_error(double x)
{
	double error = backward_scheme_result(x) - derivative(x);
	return error;
}
//compute central_scheme_error
double Cderivative::central_scheme_error(double x)
{
	double error = central_scheme_result(x) - derivative(x);
	return error;
}
//display forward, backward, central scheme error
void Cderivative::display_function()
{	
	double i;
	double forward_error;
	double backward_error;
	double central_error;
	cout <<setw(25)<<"when deltaX ="<< setw(25) << deltaX<<endl;
	for (i = low_boundary; i <= high_boundary; i += deltaX) {
		forward_error = forward_shceme_error(i);
		backward_error = backward_scheme_error(i);
		central_error = central_scheme_error(i);
		cout << setw(25) << "forward_error =" << setw(25) <<forward_error << endl;
		cout << setw(25) << "backward_error =" << setw(25) <<backward_error  << endl;
		cout << setw(25) << "central_error =" << setw(25) <<central_error  << endl;
	}
}
