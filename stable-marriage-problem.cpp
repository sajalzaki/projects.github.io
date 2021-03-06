/*
* The Problem:
* You have n men and n woman, and their preference rankings of each other, and you need
* to match them up so that the total matching is “stable.”
* You are given 2 n X n arrays, mp (men’s preference) which gives the men’s ranking of the
* women, and wp (women’s preference) which gives the women’s ranking of the men.
* So mp[i][j] gives man i's ranking of woman j and likewise for the women’s ranking of the men in
* wp.
* For example in the following tables we have n=3 and the women and men are “named” 0, 1 or 2
* and the raking are in the range 0 = highest, 1 second highest and 2 lowest.
* int mp[3][3]={0,2,1,
* 0,2,1,
* 1,2,0};
* int wp[3][3]={2,1,0,
* 0,1,2,
* 2,0,1};
* So man 1 assigns woman 2 the rank of 1 (i.e. second highest) and prefers woman 0 the best. 
*/
#include <iostream>
#include <cstdlib> 

using namespace std;
//Stable Marriage Using Backtracking

bool ok(int q[], int c)
{
	//Men Preference
	int mp[3][3] ={0,2,1,
		           0,2,1,
				   1,2,0};
	//Women Preference
	int wp[3][3] ={2,1,0,
				   0,1,2,
				   2,0,1};
		
		for (int i = 0; i < c; i++)
		{
			if(q[c] == q[i]) // if woman is already assigned to man
				return false;

			//Checking new pair against each existing pair
			if (mp[i][q[c]] < mp[i][q[i]] && (wp[q[c]][i] < wp[q[c]][c]))
				return false;

			if (mp[c][q[i]] < mp[c][q[c]] && (wp[q[i]][c] < wp[q[i]][i])) 
				return false;
		}
		return true;
}

	

void print(int q[])
{
	static int count=0;
	cout<<endl<<"Solution : "<<++count<<endl;

	for(int i=0; i<3; i++)
		cout<<q[i];
	cout<<endl;
	system("PAUSE");
}



int BackTrack(int &c) 
{
	c--;
	if(c==-1)
		
		return 0; 
}



int main() 
{
	int q[3];
	int c=0;
	q[0]=0;
	while(true) 
	{
		c++;
		if(c==3)
		{
			print(q);
			BackTrack(c);
		}
		else
		{
			q[c]=-1; 
		}

		while(true) 
		{
			q[c]++;
			if(q[c]==3)
				BackTrack(c);

			else if(ok(q,c))
				break;
		}
	}
}



