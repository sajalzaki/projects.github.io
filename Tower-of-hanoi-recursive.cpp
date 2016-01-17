
/*
* Problem: Write an iterative program
* to solve the Towers of Hanoi problem.
*/
#include <iostream>
using namespace std;
// Hanoi Tower recursive Solution
int count=0;
void move(char from, char to, char mid, int n)
{
	
	if(n==1)
		cout<<"Move No:  " << ++count<<"  Ring number:"<<n<<" move from " << from << " to " << to << endl;
	else
	{
		move(from, mid, to, n-1);
		cout<<"Move No:  " << ++count<<"  Ring number:"<<n<<" move from " << from << " to " << to << endl;
		move(mid, to, from, n-1);
	}

}
int main()
{
	char from = '1';
	char to = '3';
	char mid = '2';
	int n;
	move(from, to , mid , 5);
	
	system("PAUSE");
	return 0;

}
