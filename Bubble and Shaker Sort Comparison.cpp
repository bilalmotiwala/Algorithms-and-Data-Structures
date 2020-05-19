#include <iostream>
using namespace std;

int bubbleswap(int a[], int n)
{
	int count;
	int i;
	int temp;
	bool swap;
	int passes = 0;
	
	do
	{
		swap = false;
		for (i=0; i<n; i++)
		{
			for (count = 0; count < n-1; count++)
			{
				if(a[count] > a[count+1])
				{
					temp = a[count];
					a[count] = a[count+1];
					a[count+1] = temp;
					swap = true;
				}
			}
			passes++;
		}	
	} while (swap);
	
	cout << "Number of Times Outer Loop Run to Complete Bubble Sort: " << passes <<endl;
	return 0;
}

int shakerswap(int a[], int n)
{
	int i;
	int j;
	int m;
	int min = 0;
	int max = n;
	int temp;
	int passes = 0;
	
	while(min < max)
	{
		m = 0;
		passes++;
		for(i = min; i < max; i++)
		{
			if(a[i] > a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				m++;
			}
		}
		max--;
		
		for(j = max; j> min; j--)
		{
			if(a[j] < a[j-1])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				m++;
			}
		}
		min++;
		
		if(m == 0)
		{
			break;
		}
	}
	
	cout << "Number of Times Outer Loop Run to Complete Shaker Sort: " << passes <<endl;
	return 0;
}

int main()
{
	//Initialzing Variables and Getting User Input for Size of the Array.
	int n;
	int i;
	cout << "Please Enter the Size of Array: " <<endl;
	cin >> n;
	
	//Filling the Array with Random Numbers and Duplicating it.
	int A[n];
	int B[n];
	
	cout << "Randomly Generated Array" << endl;
	cout << "------------------------" << endl;
	for(i=0; i<n; i++)
	{
		A[i] = rand() % 300;
		B[i] = A[i];
		cout << "Element " << i << ": " << A[i] << endl;
	}
	cout << endl;
	
	//Running the BubbleSort and printing it with number of runs needed in outer loop of the sort.
	bubbleswap(A,n);
	cout <<endl;
	cout << "Randomly Generated Array Sorted Using Bubble Sort" << endl;
	cout << "-------------------------------------------------" << endl;
	for(i=0; i<n; i++)
	{
		cout << "Element " << i << ": " << A[i] <<endl;
	}
	cout <<endl;
	
	//Running the Shakersort and printing it with number of runs needed in outer loop of the sort.
	shakerswap(B,n);
	cout <<endl;
	cout << "Randomly Generated Array Sorted Using Shaker Sort" << endl;
	cout << "-------------------------------------------------" << endl;
	for(i=0; i<n; i++)
	{
		cout << "Element " << i << ": " << B[i] <<endl;
	}
	return 0;	
}
