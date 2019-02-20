//==========================================================================
// Name        : assignment1.cpp
// Author      : Pranav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//==========================================================================

#include "Stack.h"
#include <iostream>
#include <string.h>
#include "Stack.cpp"

using namespace std;

int priority(char);
string inToPost(string);
string reverse(string);

int priority(char c)
{
	switch(c)
	{
		case '+':return 1;
		case '-':return 1;

		case '*':return 2;
		case '/':return 2;

		case '^':return 3;

		default:return 0;
	}
}

int asso(char c)
{
	 if(c=='-' || c=='+' || c=='%' || c=='*' || c=='/')			//associativity left to right
	        return 1;
	 if(c=='^')													//since power(^) has reverse assoc for POSTFIX
	        return 2;
	    return 0;
}

int assopre(char c)
{
	 if(c=='-' || c=='+' || c=='%' || c=='*' || c=='/')			//associativity left to right
	        return 2;
	 if(c=='^')													//since power(^) has reverse assoc for POSTFIX
	        return 1;
	    return 0;
}

string reverse(string rev)
{
	string r = "";
	int l = rev.length()-1;
	for(int x=l;x>=0;x--)
	{
		char t = rev.at(x);
		if(t=='(')
			t=')';
		else if(t==')')
			t='(';

		r = r+t;
	}
	return r;
}

string inToPre(string exp)
{
	string expRev = reverse(exp);
	string pre;
	Stack<char> s;
	char c,o;
	int i = 0;
	while(expRev[i]!='\0')
	{
		c = expRev[i];
		if(c=='(')
		{
			s.push(c);
		}
		else if(c==')')
		{
			while(!s.isEmpty() && s.top_data()!='(')
				pre=pre+s.pop();
			s.pop();
		}
		else if(!s.isEmpty())
		{
			o = s.top_data();
			if(priority(c)==0)
			{
				pre=pre+expRev[i];
			}
			else if(priority(c)<priority(o))
			{
				while(!s.isEmpty() && priority(c)<priority(s.top_data()))

					pre=pre+s.pop();
				s.push(c);
			}
			else if(priority(c)>priority(o))
			{
				s.push(c);
			}
			else if(priority(c)==priority(o))
			{
				if(assopre(c)==1)
				{
					pre=pre+s.pop();
					s.push(c);
				}
				else
					s.push(c);
			}
		}
		else
		{
			if(priority(c)==0)
			{
				pre=pre+expRev[i];
			}
			else
			{
				s.push(expRev[i]);
			}
		}
		i++;
	}
	while(!s.isEmpty())
	{
		pre=pre+s.pop();
	}
	return (reverse(pre));
}

string inToPost(string exp)
{
	string post;
	Stack<char> s;
	char c,o;
	int i = 0;
	while(exp[i]!='\0')
	{
		c = exp[i];
		if(c=='(')
		{
			s.push(c);
		}
		else if(c==')')
		{
			while(!s.isEmpty() && s.top_data()!='(')
				post=post+s.pop();
			s.pop();
		}
		else if(!s.isEmpty())
		{
			o = s.top_data();
			if(priority(c)==0)
			{
				post=post+exp[i];
			}
			else if(priority(c)<priority(o))
			{
				while(!s.isEmpty() && priority(c)<priority(s.top_data()))

					post=post+s.pop();
				s.push(c);
			}
			else if(priority(c)>priority(o))
			{
				s.push(c);
			}
			else if(priority(c)==priority(o))
			{
				if(asso(c)==1)
				{
					post=post+s.pop();
					s.push(c);
				}
				else
					s.push(c);
			}
		}
		else
		{
			if(priority(c)==0)
			{
				post=post+exp[i];
			}
			else
			{
				s.push(exp[i]);
			}
		}
		i++;
	}
	while(!s.isEmpty())
	{
		post=post+s.pop();
	}
	return (post);
}

int evaluatePost(string exp)
{
	exp=inToPost(exp);
	int z,n;
	string post;
	Stack<int> s;
	int i = 0;
	while(exp[i]!='\0')
	{
		if(isdigit(exp[i]))
		{
			s.push(exp[i]-'0');
		}
		else if(isalpha(exp[i]))
		{
			cout<<"\nEnter the Value of "<<exp[i]<<"::";
			cin>>n;
			s.push(n);
		}
		else
		{
            int x = s.pop();
            int y = s.pop();
			switch(exp[i])
			{
			case '+':
				z=y+x;
				break;
			case '-':
				z=y-x;
				break;
			case '*':
				z=y*x;
				break;
			case '/':
				z=y/x;
				break;
			case '^':
				z=y^x;
				break;
			}
			s.push(z);
		}
		i++;
	}
	return s.pop();
}

int evaluatePre(string exp)
{
	string temp;
	temp=inToPre(exp);
	exp=reverse(temp);
	int z,n;
	string pre;
	Stack<int> s;
	int i = 0;
	while(exp[i]!='\0')
	{
		if(isdigit(exp[i]))
		{
			s.push(exp[i]-'0');
		}
		else if(isalpha(exp[i]))
		{
			cout<<"\nEnter the Value of "<<exp[i]<<"::";
			cin>>n;
			s.push(n);
		}
		else
		{
            int x = s.pop();
            int y = s.pop();
			switch(exp[i])
			{
			case '+':
				z=x+y;
				break;
			case '-':
				z=x-y;
				break;
			case '*':
				z=x*y;
				break;
			case '/':
				z=x/y;
				break;
			case '^':
				z=x^y;
				break;
			}
			s.push(z);
		}
		i++;
	}
	return s.pop();
}


int main()
{
	string exp,post,pre;
	Stack<char> S;

	int ch,ans;
	do
	{
		cout<<"\n1.To take the input\n2.Infix To Postfix\n3.Infix To Prefix\n4.Evaluate Postfix\n5.Evaluate Prefix\n6.Exit\n\n";
		cout<<"Please enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the Infix Expression : ";
				cin>>exp;
				break;
			case 2:
				cout<<"\nPOSFIX : ";
				post=inToPost(exp);
				cout<<post<<"\n";
				break;
			case 3:
				cout<<"\nPREFIX : ";
				pre=inToPre(exp);
				cout<<pre<<"\n";
				break;
			case 4:
				ans=evaluatePost(exp);
				cout<<"\nThe evaluated postfix is: "<<ans<<"\n";
				break;
			case 5:
				ans=evaluatePre(exp);
				cout<<"\nThe evaluated prefix is: "<<ans<<"\n";
				break;
			case 6:
				return 1;
				break;
		}

	}
	while (1);

	return 0;
}



