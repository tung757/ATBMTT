#include<iostream>
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
int main()
{
	cout << nd(550,1759);
	return 0;
}
