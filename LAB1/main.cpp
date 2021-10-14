#include "Cderivative.h"

int main()
{
	/*cout << "Please input deltaX " << endl;*/
	double deltaXlist[] = { 0.1, 0.01, 0.001, 0.0001, 0.00001 };
	
	for (auto deltaX: deltaXlist) {
		Cderivative* example = new Cderivative(deltaX);
		example->display_function();
		delete example;
	}
	
	
}
