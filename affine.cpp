#include<iostream>
#include<cstring>
using namespace std;
int gcd(int a, int b)
{
	if(a%b==0)
	{
		return b;
	}
	else
	{
		return gcd(b,a%b);
	}
}
int nd(int a, int n)
{
	if(gcd(a,n)==1)
	{
		int x0,x1,y0,y1,r0,r1,q;
		r0=n,r1=a;
		x0=0,y0=1,x1=1,y0=0;
		while(r1!=1)
		{
			int tg;
			q=r0/r1;
			tg=r1;
			r1=r0%r1;
			r0=tg;
			tg=x1;
			x1=x0-q*x1;
			x0=tg;
			tg=y1;
			y1=y0-q*y1;
			y0=tg;
		}
		while(x1<0)
		{
			x1=x1+n;
		}
		return x1;
	}
	else{
		return -1;
	}
}
string bang(int n)
{
	string a[26]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	return a[n];
}
string cts(char x)
{
	switch(x)
	{
		case 'A':return "A";
		case 'B':return "B";
		case 'C':return "C";
		case 'D':return "D";
		case 'E':return "E";
		case 'F':return "F";
		case 'G':return "G";
		case 'H':return "H";
		case 'I':return "I";
		case 'J':return "J";
		case 'K':return "K";
		case 'L':return "L";
		case 'M':return "M";
		case 'N':return "N";
		case 'O':return "O";
		case 'P':return "P";
		case 'Q':return "Q";
		case 'R':return "R";
		case 'S':return "S";
		case 'T':return "T";
		case 'U':return "U";
		case 'V':return "V";
		case 'W':return "W";
		case 'X':return "X";
		case 'Y':return "Y";
		case 'Z':return "Z";
	}
}
string mahoa(int a, int x, int b)
{
	int y=(a*x+b)%26;
	return bang(y);
}
string giaima(int a, int b, int y)
{
	int x;
	x=((y-b)*nd(a,26))%26;
	return bang(x);
}
void chuyen(int x, int y)
{
	string s="";
	cout << "Nhap chuoi can ma hoa : ";
	getline(cin,s);
	int a[s.length()];
	int h=s.length();
	int m=-1;
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<26;j++)
		{
			if(cts(s[i])==bang(j))
			{
				m++;
				a[m]=j;
			}
		}
	}
	s="";
	for(int i=0;i<h;i++)
	{
		s=s+mahoa(x,a[i],y);
	}
	cout << "Ban ma la : "<< s<< endl;
	m=-1;
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<26;j++)
		{
			if(cts(s[i])==bang(j))
			{
				m++;
				a[m]=j;
			}
		}
	}
	s="";
	for(int i=0;i<h;i++)
	{
		s=s+giaima(x,y,a[i]);
	}
	cout << "Ban giai ma la : "<< s<< endl;
}
int main()
{
	int a,b,x,y;
	chuyen(1,6);
	return 0;
}
