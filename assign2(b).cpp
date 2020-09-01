//============================================================================
// Name        : assign2(b).cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class string
{
	char s[10];

public:
	string()
	{
		int len;
		len=0;
	}

	void getstring()
	{
		cin>>s;
	}

	void dispstring()
	{
		cout<<s;
	}
};

int main()
{
	string a;
	a.getstring();

	return 0;
}
