/*
* Problem: Print out the actual shortest path as well as its cost. The path should be output as the sequence of
* rows to choose, going from left to right on the original cost array.
*/
#include<iostream>
//Shortest path without memorization
using namespace std;
const int rows = 5; 
const int cols = 6; 
int cost(int i, int j)
{ 
	// i is the row, j is the column 
	int weight[rows][cols]={ 
		{3,4,1,2,8,6}, 
		{6,1,8,2,7,4}, 
		{5,9,3,9,9,5}, 
		{8,4,1,3,2,6}, 
		{3,7,2,1,2,3}}; 
		
		//base case
		if(j==0) 
			return weight[i][0];

		// recursive call 
		int left =weight[i][j]+ cost(i,j-1) ;
		int up = weight[i][j]+ cost(i-1>=0?i-1:rows-1,j-1); 
		int down = weight[i][j] + cost(i+1<=rows-1?i+1:0,j-1); 

		// find the value of the shortest path through cell (i,j) 
		int min = left;
		if (up<min)
		{
			min=up;
		}
		if (down<min) 
		{
			min=down;
		}
		return min; 
} 
 
int main()
{
	int ex[rows]; 
	// get the shortest path out of each cell on the right 
	for( int i=0; i<rows; i++)
		ex[i]=cost(i,cols-1); 
	// now find the smallest of them
	int min= ex[0]; 
	for( int i=1; i<rows; i++)
		if(min > ex[i])
			min=ex[i];
	
	cout<<"The shortest path is of length : "<<min<<endl;
	system("PAUSE"); 
	return EXIT_SUCCESS; 
 
} 
