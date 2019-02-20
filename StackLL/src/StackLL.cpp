//============================================================================
// Name        : StackLL.cpp
// Author      : Pranav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack s;
	int n;
	int i;

	cout<<"How many elements do you want to enter\n";
	cin>>n;

	cout<<"\nEnter "<<n<<" elements:\n";
	for(i=0;i<n;i++)
	{
		s.push();
	}

	//cout<<"\nStack Elements are:";
	//s.display();

	cout<<"\n\nElements in Stack are: ";
	for(i=0;i<n;i++)
	{
		s.pop();
	}


}
