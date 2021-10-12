#include "Cderivative.h"

int main()
{
	double deltaX;
	cout << "Please input deltaX " << endl;
	cin >> deltaX;
	Cderivative* example = new Cderivative(deltaX);
	example->display_function();
	delete example;
}
