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
		int r0=n,r1=a,x0=0,x1=1,y0=1,y1=0,qi;
		while(r1!=1)
		{
			qi=r0/r1;
			int tg=r1;
			r1=r0%r1;
			r0=tg;
			tg=x1;
			x1=x0-qi*x1;
			x0=tg;
			tg=y1;
			y1=y0-qi*y1;
			y0=tg;
		}
		while(x1<0)
		{
			x1=x1+n;
		}
		return x1;
	}
	else
	{
		return -1;
	}
}
string dtobin(int n)
{
	if(n==1)
	{
		return "1";
	}
	else
	{
		if(n%2==0)
		{
			return dtobin(n/2)+"0";
		}
		else
		{
			return dtobin(n/2)+"1";
		}
	}
}
int gtm(int a, int b, int n)
{
	int f=1;
	string x=dtobin(b);
	for(int i=0;i<x.length();i++)
	{
		f=f*f % n;
		if(x[i]=='1')
		{
			f=f*a % n;
		}
	}
	return f;
}
void taokhoa(int p, int a, int x, int &y)
{
	y=gtm(a,x,p);
	cout << "Khoa cong khai : {"<<p<<","<<a<<","<<y<<"}"<< endl;
	cout << "Khoa bi mat : {"<<p<<","<<a<<","<<x<<"}"<< endl;
}
void mahoa(int p, int a, int y, int k, int &C1, int &C2, int m)
{
	int K=gtm(y,k,p);
	C1=gtm(a,k,p);
	C2=(K*m)%p;
	cout << "Ban ro la : "<< m<< endl;
	cout << "Ban ma hoa la : {"<<C1<<","<<C2<<"}"<< endl;
}
void giaima(int p, int a, int x, int C1, int C2, int &M)
{
	int K=gtm(C1,x,p);
	M=(C2*nd(K,p))%p;
	cout << "Ban ro la : "<<M<< endl;
}
int main()
{
	int p,a,x,y,M,m,C1,C2;
	taokhoa(23,5,12,y);
	mahoa(23,5,y,6,C1,C2,15);
	giaima(23,5,12,C1,C2,M);
	return 0;
}
