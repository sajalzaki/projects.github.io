/*
* The eight queens problem is to eight chess queens on an 8×8 chessboard so 
* that no two queens attack each other. which means that no two queens share the same row, 
* column, or diagonal. This problem is solved with backtracking using 1 dimensional array and goto statements.
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	//8 queens 1 dimensional array program with backtracking
    int q[8], c = 0, i,j,count = 0;
    q[0] = 0;

NC: c++;
    if (c == 8) 
		goto print;
    q[c] = -1;

NR:q[c]++;
    if (q[c]==8) 
		goto backtrack;
    for (i = 0; i < c; i ++)
       if((q[i]== q[c]) || ((c-i) == (abs(q[c]-q[i])))) 
		   goto NR;

    goto NC;

backtrack: c --;
        if (c == -1)
		{
           cout << count << endl;
           return 0;
         }

    goto NR;

print:
    count ++;
	cout<< " Soultion : " << count <<endl;

    for (i = 0; i < 8; i++)
	{

       cout << q[i];
    
	}
	cout << endl;
	system("pause");
    goto backtrack;
}
