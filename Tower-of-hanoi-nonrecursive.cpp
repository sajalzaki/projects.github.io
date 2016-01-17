/*
* Problem: Write an iterative program
* to solve the Towers of Hanoi problem.
*/
#include <iostream>
#include<vector>
// Hanoi Tower Using Vector
using namespace std;
int main()
{
	vector<int> t[3]; // three towers A,B,C represented as an array of 3 vectors
	int n, candidate,to, from, move=0; // move counts the move number
	cout<<"Please Enter the number of rings to move: ";
	cin>>n;
	cout<<endl;
	//intitialize the 3 towers
	for(int i=n+1;i>=1;i--)
		t[0].push_back(i);
		t[1].push_back(n+1);
		t[2].push_back(n+1);
		// initialize towers and candidate
		from=0;
		to=1;
		candidate=1;
		while(n%2==0? (t[1].size()<n+1 && t[2].size() <n+1 ) : t[1].size()<n+1)
		{
			cout<<"Move Number "<<++move<<": Transfer ring "<<candidate<<" from tower "<<  char(from+65)<<" to tower "<<char(to+65)<<endl;
			t[to].push_back(candidate);
			t[from].pop_back();
			
			if (t[(to+1)%3].back() < t[(to+2)%3].back())
				from=(to+1)%3;
			else
				from=(to+2)%3;
			if( t[(from+1)%3].back()>t[from].back() )
				to=(from+1)%3;
			else
				to=(from+2)%3;
			candidate=t[from].back(); 
		}
		system("PAUSE");
}
