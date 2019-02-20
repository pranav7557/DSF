//============================================================================
// Name        : StackArray.cpp
// Author      : Pranav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

int main()
{
	int ch;
	cout<<"1.INTERGER\n2.FLOAT??\n";
	cin>>ch;
	if(ch==1)
	{

		Stack<int>s;
		int n;
		int i;

		cout<<"How many elements do you want to enter\n";
		cin>>n;

		cout<<"\nEnter "<<n<<" elements:\n";
		for(i=0;i<n;i++)
		{
			s.push();
		}

		cout<<"\nStack Elements are:";
		s.display();

		cout<<"\n\nElements in reverse order:";
		for(i=0;i<n;i++)
		{
			cout<<"\t"<<s.pop();
		}
	}
		else if(ch==2)
		{
			Stack<float>f;
			int n;
			int i;

			cout<<"How many elements do you want to enter\n";
			cin>>n;

			cout<<"\nEnter "<<n<<" elements:\n";
			for(i=0;i<n;i++)
			{
				f.push();
			}

			cout<<"\nStack Elements are:";
			f.display();

			cout<<"\n\nElements in reverse order:";
			for(i=0;i<n;i++)
			{
				cout<<"\t"<<f.pop();
			}

		}
}


