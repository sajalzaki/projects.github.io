/*
* Problem: Modify the Eight Queens program (1 dimensional array – no goto version) so that it prints out a
* chessboard with some “fancy” representation of a queen in the appropriate positions.
*/
#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;
int count=0;
//8 queens 1D array program without GOTO's with Fancy Chess Board
bool ok(int q[], int col)
{
	for(int i=0; i<col; i++)
	if(q[col]==q[i] || (col-i)==abs(q[col]-q[i]))
		return false;
	return true;
}

void backtrack(int &col)
{
	col--;
	if(col==-1)
	{
		system("PAUSE"); 
		exit(1);
	}
}

void print(int q[])
{
	cout<< "Solution no:" << ++count <<endl<<endl;
	int i,j,k,l;
	
	typedef char box[5][7];
	box bb,wb,*board[8][8];
	box wq, bq;
	//fill in bb=black box and wb=whitebox
	
	for(i=0;i<5;i++)
		for( j=0;j<7;j++)
		{
			wb[i][j]=' ';
			wq[i][j]=' ';
			bb[i][j]=char(219);
			bq[i][j]= char(219);
		}
		
		// creates a white queen
		wq[1][1] = wq[2][1] = wq[3][1] = wq[3][2] = wq[2][3] =
		wq[3][3] = wq[3][4] = wq[1][5] = wq[2][5] =
		wq[3][5] = char(219);
		

		bq[1][1] = bq[2][1] = bq[3][1] = bq[3][2] = bq[2][3] = 
		bq[3][3] = bq[3][4] = bq[1][5] = bq[2][5] =	
		bq[3][5] = ' ';

		//fill board with pointers to bb and wb in alternate positions
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(q[i]==j)
				{
					if((i+j)%2==0)
						board[i][j]=&wq;
					else
						board[i][j]=&bq;
				}
				if(q[i]!=j)
				{
					if((i+j)%2==0)
						board[i][j]=&wb;
					else
						board[i][j]=&bb;
				}
			}
		}
		
		// print the board via the pointers in array board
		// first print upper border
		cout<<" ";
		for(i=0;i<7*8;i++)
			cout<<'_';
			 cout<<endl;
			 // now print the board
			 
			 for(i=0;i<8;i++)
				 for(k=0;k<5;k++)
				 {
					 cout<<" "<<char(179); //print left border
					 
					 for(j=0;j<8;j++)
						 for(l=0;l<7;l++)
							 cout<<(*board[i][j])[k][l];
					 cout<<char(179)<<endl; 
				 }
				 //before exiting print lower border
				 cout<<" ";
				 for(i=0;i<7*8;i++)
					 cout<<char(196);
				 cout<<endl;
}
int main()
{
	int q[8]; q[0]=0;
	int c=1;
	// the boolean variable "from_backtrack" keeps track if we need
	// to reset the row to the top of the current column or not.
	bool from_backtrack=false;
	// The outer loop keeps looking for solutions
	// The program terminates from function backtrack
	// when we are forced to backtack into column -1
	while(true)
	{
		while(c<8)
		{
		// if we just returned from backtrack,use current value of q[c]
		// if not, get ready to start at the top of this column
		if(!from_backtrack)
		q[c]=-1; //start at the top
		from_backtrack= false; // reset for the next time through

			while(q[c]<8)
			{ 
				// place queen in this column or backtrack as required
				q[c]++;
				if(q[c]==8)
				{
					backtrack(c);
					continue;
				}
				// if the row = 8, there is no valid square in this column
				// so backtrack and continue the loop in the previous column
				if(ok(q,c))
				{
					break;
				}
				//if this position is ok, place the queen
				// and move on to the next column,
				// otherwise keep looking in this column
				
			}
			c++;// placed ok, move to the next column
		}
		// one complete solution found, print it.
		print(q); // board completed, print it out
		backtrack(c); //find the next place for the queen, going back as far as need be
		from_backtrack = true;
	}
}
