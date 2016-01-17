/*
* Problem: Write a program that inputs two integers n and k, where n>=k. Your program should calculate
* the number of different ways that k bishops could be placed on an nXn chessboard. 
*/
#include <cstdlib>
#include <iostream>
using namespace std;

//K bishop program that inputs two integers n and k, where n>=k. 
int k, n; 
bool ok(int q[], int c, int n)
{
    //row and col identification in which bishop is in
    int row = q[c]/n;
	int col = q[c]%n;

    for(int i=0; i<c; i++)
	{
		//diagonal test
        if((row-q[i]/n) == abs(col - q[i]%n))
			return false;
    }

    return true;
}

void backtrack(int &c, int count)
{
    c--;
    if(c==-1)
	{
		cout<<"There are "<< count <<"  different ways to place " << k << " bishops on an "<< n << "*" << n << " chessboard."<<endl;
        system("PAUSE");
		exit(1);
	}
}

int main()
{
	while(true)
	{

        cout << "Enter the value of n : ";
        cin >> n;
        cout << "Enter the value of k : ";
        cin >> k;
        if(n<0) 
			break;

        int* q = new int[k]; 
        int count = 0, b = 0, t;
        q[b] = 0;

        while(true)
		{ 
            while(b<k)
			{ 
				while(q[b]<n*n)
				{
                    if(ok(q,b,n))
						break;
					else
						q[b]++;
                }

                if(q[b]==n*n)
				{
                    backtrack(b, count);
                    q[b]++;
                    continue;
                }

                else
				{
                    t = q[b];
                    b++;
                    q[b] = t;
                }
            }
            count++;
            backtrack(b, count);
            q[b]++;
			
        }
		
    }
	
   return 0;
	
}
