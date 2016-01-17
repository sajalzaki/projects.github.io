/*
* Prblem: Write a program to find and print the first perfect square (i*i) whose last two digits
* are both odd. 
*/
#include <iostream>
#include<conio.h> 
#include<stdio.h> 
#include<climits>


using namespace std;
//Perfect Square Problem

int perfectSq()
{

	int a,b;

	for ( a =5; a<UINT_MAX; a+=2)
	{
		b =a*a;


		if((b/10)%2 !=0)
		{
			cout <<" Number : "<< a<< endl;
			cout <<" Square : "<< b<< endl;
			break;
		}
		else 
		{
			cout<<"Perfect Square Not Found!" <<endl;
			break;
		}


	}
	return 0;




}
int main()
{
	perfectSq();
	cout<<endl;

	system("PAUSE");
	return 0;
}
