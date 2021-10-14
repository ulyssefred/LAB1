#include "Cderivative.h"
//initial deltaX
Cderivative::Cderivative(double input_deltaX)
{
	deltaX = input_deltaX;
}
//function f(x)
long double Cderivative::function(double x)
{
	long double temp = ((3 * x * x * x) + (2 * x) + 1);
	return temp;
}
//derivatived function f'(x)
long double Cderivative::derivative(double x)
{
	long double temp = ((9 * x * x) + 2);
	return temp;
}
//compute forward_scheme_result
long double Cderivative::forward_scheme_result(double x)
{	
	long double result = ((function(x + deltaX) - function(x))/deltaX);
	return result;
}
//compute backward_scheme_result
long double Cderivative::backward_scheme_result(double x)
{
	long double result = ((function(x) - function(x - deltaX))/deltaX);
	return result;
}
//compute central_scheme_result
long double Cderivative::central_scheme_result(double x)
{
	long double result = ((function(x + deltaX) - function(x - deltaX))/(2.*deltaX));
	return result;
}
//compute forward_shceme_error
long double Cderivative::forward_shceme_error(double x)
{	
	long double error = fabs(forward_scheme_result(x) - derivative(x));
	return error;
}
//compute backward_scheme_error
long double Cderivative::backward_scheme_error(double x)
{
	long double error = fabs( backward_scheme_result(x) - derivative(x));
	return error;
}
//compute central_scheme_error
long double Cderivative::central_scheme_error(double x)
{
	long double error =  fabs(central_scheme_result(x) - derivative(x));
	return error;
}
//display forward, backward, central scheme error
void Cderivative::display_function()
{	
	double i;
	i = low_boundary;
	long double forward_error;
	/*long double backward_error;*/
	long double central_error;
	int computerTimes = int (high_boundary / deltaX);
	ofstream oFile;
	oFile.open("data_collect_sheet.csv", ios::app); 
	/*cout <<setw(25)<<"when deltaX ="<< setw(25) << deltaX<<endl;*/
	oFile << "deltaX" << "," << deltaX<<endl;
	oFile << "forward_error" << "," << "central_error" << endl;
	for (int y = 1; y <= computerTimes+1 ; y++) {
		forward_error = forward_shceme_error(i);
		/*backward_error = backward_scheme_error(i);*/
		central_error = central_scheme_error(i);
		oFile << forward_error << "," << central_error<< endl;
		//cout << setw(25) << "forward_error =" << setw(25) <<forward_error << endl;
		///*cout << setw(25) << "backward_error =" << setw(25) <<backward_error  << endl;*/
		//cout << setw(25) << "central_error =" << setw(25) <<central_error  << endl;
		i += deltaX;
	}
	oFile.close();
}
