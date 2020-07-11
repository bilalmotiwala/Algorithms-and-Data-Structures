#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <random>
using namespace std;

double integral_sinus(double x1, double x2)
{		
	//Setting up and Specifying the number of samples needed.
	long int N_samples;
	double integral = 0;
	
	cout << "Please Specify the Number of Samples [N_samples](Higher = Closer to True Value) : " <<endl;
	cin >> N_samples;
	
	//Generating random number between x1 and x2 such that x1<= random_number < x2.
	default_random_engine generator;
  	uniform_real_distribution<double> distribution(x1, x2);
	
	for(long int i=0; i < N_samples; i++)
	{
		double a = distribution(generator);
		integral += sin(a);
	}

	double answer1 = (x2-x1) / N_samples;
	double answer2 = answer1 * integral;
	
	cout << "Estimated value from " << N_samples << " samples : " << answer2;
	return 0;
}; 

int main()
{

	double x1;
	double x2;
	int exit = 0;
	
	while(!exit)
	{
		cout << "Integration of f(x) sinxdx using Monte Carlo method" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << endl;
		
		cout << "Please Specify the Value of the Lower Bound [x1] : " << endl;
		cin >> x1;
		cout << "Please Specify the Value of the Upper Bound [x2] : " << endl;
		cin >> x2;
	
		cout << endl;
		cout << "Your specified bounds are, x1 = " << x1 << " and x2 = " << x2 << "." << endl;
	
		integral_sinus(x1, x2);
		
		cout << endl;
		cout << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Do you wish to repeat with new bounds or quit? Enter 0 to Repeat, 1 to Exit." << endl;
		cin >> exit;
	}
	return 0;
}
