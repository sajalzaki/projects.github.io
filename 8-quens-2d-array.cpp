
/*
* The eight queens problem is to eight chess queens on an 8×8 chessboard so 
* that no two queens attack each other. which means that no two queens share the same row, 
* column, or diagonal. This problem is solved with backtracking using 2 dimensional array and goto statements.
*/
#include <iostream>
//8 queens 2 dimensional array program with backtracking

int main()
{
	using namespace std;
	int b[8][8] = {0},r,i,j,c=0,count=1;
	b[0][0]=1;
NC:c++;
	if(c==8)
	{
		goto print;
	}
	r=-1;
NR:r++;
	if(r==8)
	{
		goto backTrack;
	}

	//Row test
	for(i=0; i<c; i++)
	{
		if(b[r][i]==1)
			goto NR;
	}

	//Up-Diagonal test
	for (i=1; (r-i)>=0 && (c-i)>=0; i++)
	{
		if(b[r-i][c-i]==1)
			goto NR;
	}

	//Down-Diagonal test
	for (i=1; (r+i)<8 && (c-i)>-1; i++)
	{
		if(b[r+i][c-i]==1)
			goto NR;
	}

	b[r][c]=1;
	goto NC;

backTrack:
	c--;
	if(c==-1)
	{
		return 0;
	}

	r=0;

	while(b[r][c]!=1)
	{
		r++;
	}
	b[r][c]=0;
	goto NR;

print:
	
	
	cout<<"Solution" << " " <<":"<< count << "\n" << endl;
	
	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			cout<<b[i][j]<< " ";
		}
		cout<<"\n"<<endl;
		
	}

	cout<<endl;
	count++;
	
	
	system("pause");
	goto backTrack;

}










