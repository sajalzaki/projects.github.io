/*
*     @@
*    @@@@
*     @@
* Problem: Write a program which allocates the integers 1-8 to the squares in the figure above, subject to
* the restrictions that no two adjacent squares contain consecutive integers.
* By adjacent we mean vertically, horizontally, or diagonally.
*/
#include <iostream>
#include <cmath>
using namespace std;
bool ok( int q[8], int c ) 
{ //array for checking adjacents
	int a[8][5] = { { -1 }, { 0, -1 }, { 0, -1 }, { 0, 1, 2, -1 }, { 0, 1, 3, -1 }, { 1, 4, -1 }, { 2, 3, 4, -1 }, { 3, 4, 5, 6, -1 }};
	//row test
	for ( int i = 0 ; i < c ; i++ )
		if ( q[i] == q[c] )
			return false;
	//adjacent test 
	for ( int i = 0 ; a[c][i] != -1 ; i++ ) 
	{
		if ( 1 == abs( q[c] - q[ a[c][i] ] ) )
			return false; 
	}
	return true;
} 
void backtrack(int &col)
{
	--col;
	if(col == -1)
	{ 
		system("pause");
		exit(1);
	}
} 
void print(int q[])
{
	static int count =0;
	cout << "Solution" << " " << ++count << " is : ";
	for(int i=0; i<8; i++)
		cout << q[i] << " ";
	cout <<endl; 
}
int main()
{ 
	int q[8], c = 0; 
	bool from_backtrack=false; 
	while(true)
	{ 
		while(c<8)
		{
			if(!from_backtrack) 
				q[c] = -1;
			from_backtrack = false; 
			while(q[c]<8)
			{
				q[c]++; 
				if(q[c] == 8)
				{ 
					backtrack(c);
					continue; 
				} 
				if ( ok(q,c) ) 
					break;
			}
			c++;
		} 
		print(q);
		backtrack(c); 
		from_backtrack = true;
	} 
} 
