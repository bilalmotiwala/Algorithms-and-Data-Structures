#include <iostream>
using namespace std;

int desc_selectionsort (int A[], int n)
{
	int i;
	int j;
	int largest;
	int temp;
	
	for(i=0; i<n-1; i++)
	{
		largest = i;
		for(j = i+1; j < n; j++)
		{
			if( A[j] > A[largest])
			{
				largest = j;
			}
		}
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
	}
}

int main()
{	
	int a[12] = { 2,-4,16,11,39,20,4,8,-17,62,30,12 };
	int n = 12;
	int k;
	
	cout << "Unsorted Array" << endl;
	for(k=0; k<n; k++)
	{
		cout << "Element " << k << ": " << a[k] <<endl;
	}

	desc_selectionsort (a, 12);
	
	cout << "Array in Descending Order using Selection Sort" <<endl;
	for(k=0; k<n; k++)
	{
		cout << "Element " << k << ": " << a[k] <<endl; 
	}
}
