#include<iostream>
using namespace std;
string dtb(int n)
{
	if(n/2==0)
	{
		return "1";
	}
	else
	{
		if(n%2==0)
		{
			return dtb(n/2)+"0";
		}
		else
		{
			return dtb(n/2)+"1";
		}
	}
}
int abmn(int a, int b, int n)
{
	string s=dtb(b);
	int f=1;
	for(int i=0;i<s.length();i++)
	{
		f=(f*f)%n;
		if(s[i]=='1')
		{
			f=(f*a)%n;
		}
	}
	return f;
}
int main()
{
	cout << abmn(7,56,61);
	return 0;
}
