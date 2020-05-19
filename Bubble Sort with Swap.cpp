#include <iostream>
using namespace std;

int bubbleswap(int a[], int n)
{
	int count;
	int temp;
	bool swap;
	int passes = 0;
	
	do
	{
		swap = false;
		for (count = 0; count < n-1; count++)
		{
			if(a[count] > a[count+1])
			{
				passes++;
				temp = a[count];
				a[count] = a[count+1];
				a[count+1] = temp;
				swap = true;
			}
		}
	} while (swap);
	
	cout << "Passes Needed to Complete Sort: " << passes <<endl;
	return 0;
}


int main()
{
	int i;
	int A[16] = {9, 4, -17, 23, 5, 12, 7, -3, 2, 4, 19, -1, -21, 3, 9,8};
	int n = 16;
	
	cout << "Unsorted Array" << endl;
	for(i=0; i<n; i++)
	{
		cout << "Element " << i << ": " << A[i] <<endl;
	}
	
	cout << endl;
	bubbleswap(A,16);
	
	cout << endl;
	cout << "Array Sorted Using Bubblesort" << endl;
	for(i=0; i<n; i++)
	{
		cout << "Element " << i << ": " << A[i] <<endl;
	}
}
