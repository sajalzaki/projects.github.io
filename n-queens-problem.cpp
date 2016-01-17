/*
* Problem: N queens problem. By the “n queens problem” we mean the problem of placing n queens on an nXn “chessboard”
* in such a way that no queen can capture any other on the next move.
*/
#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

//N queens problem
bool ok(int q[], int col)
{
	for(int i=0; i<col; i++)
	if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) 
		return false;

	return true;
}


void print(int p , int &cnt )
{
	
	cout<< "There are " << cnt << " solutions to the "<< p<< " queens problem." <<endl<<endl;
	
}


int main()
{
	cout << "Enter a number: "<< endl;
	int num;
	cin>>num;
	int n=0;
N: n++;
	int count =0;
	while(n<=num)
	{
		if(n>num)
		{
			print(n, count);
			system("PAUSE");
			exit(1);
		}
		
		int *q = new int [n]; 
		q[0]=0;
		int c=1;
		
		if(num ==1)
		{
			++count;
			print(n, count);
			system("PAUSE");
			exit(1);
		}
		
		if(c==n)
		{
			++count;
			print(n, count);
			goto N;
		}
		
		bool from_backtrack=false;
		
		while(true)
		{
			while(c<n)
			{
				if(!from_backtrack)
				q[c]=-1; 
				from_backtrack= false; 

				while(q[c]<n)
				{
					q[c]++;

					if(q[c]==n)
					{
						c--;
						if(c==-1)
						{
							print(n, count); 
							delete [] q;
							goto N;
						}
						continue;
					}
					
					if(ok(q,c))
					{
						break;
					}
				}
				c++;
				
				if(c>n)
				{
					print(n, count);
					system("PAUSE");
					exit(1);
				}
			}
			++count;
			c--;
			if(c==-1)
			{
				print(n, count);
				system("PAUSE"); 
				exit(1);
			}
		from_backtrack = true;
		}
	}
	system("PAUSE");
}
