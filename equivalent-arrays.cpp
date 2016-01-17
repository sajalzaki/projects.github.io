/*
* Consider the two arrays a and b.
* a = 1,2,3,4,5
* b = 3,4,5,1,2
* It is possible to transform array a into array b by right shifting each element of a to the “right”
* three places. If an element “falls off” the back of the array have it come around the front and
* keep counting positions. That is how 3 in array ended up in the first position of array b. One
* way to look at this is to imagine that we are moving the element around in a circular manner.
* In the example above, we have right shifted the array 3 positions to the right. 
* Problem: Write a function
* bool equivalent(int a[], int b[], int n)
* which takes two arrays a and b of length n and returns true is they are shift equivalent and false
* otherwise.
*/
#include <iostream>
//Equivalent Arrays

bool equivalent(int a[], int b[], int n)
{
	for (int j=0; j<n; j++)
	{
		for(int i=0; i<n; i++)
		{
			if(a[i]!=b[(i+j)%n])
				goto next_shift;
		}
		return true;
next_shift:;
	}
	return false;
}
		

int main()
{
	using namespace std;
	int n;
	cout << "Enter size of array:" <<endl;
	cin>>n;
	int *a = new int [n];
	int *b = new int [n];
	int k;
	for(k=0; k<n; k++)
	{
		cout<<"Enter numbers for your first array:"<<endl;
		cin>>a[k];
	}
	for(k=0; k<n; k++)
	{
		cout<<"Enter numbers for your second array:"<<endl;
		cin>>b[k];
	}
	bool ok = equivalent(a,b,n);
	if(ok)
	
		cout<< "They are shift equivalent."<<endl;

	

	else
	
		cout<<"They are not shift equivalent"<<endl;
	system("PAUSE");
	return 0;
	


}
