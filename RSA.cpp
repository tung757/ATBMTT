#include<iostream>
#include<cstdlib>
#include<ctime>
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
void nhap(int &p, int &q)
{
	cout << "Nhap p,q : ";
	cin >> p;
	cin >> q;
}
void khoa(int p, int q, int e, int &d, int &n, int xn)
{
	n=p*q;
	d=nd(e,xn);
	cout << "Khoa cong khai : ("<<n<<","<<e<<")"<< endl;
	cout << "Khoa bi mat : ("<<n<<","<<d<<")";
}
void mahoa(int e, int M, int n)
{
	cout <<"Ma hoa la :"<< gtm(M,e,n);
}
void giaima(int d, int m, int n)
{
	cout <<"\nGiai ma la :"<< gtm(m,d,n);
}
void sinhe(int &e, int &xn, int p, int q)
{
	xn=(p-1)*(q-1);
	do
	{
		e=rand() % ((xn-1)-2+1)+2;
	}
	while(gcd(e,xn)!=1);
	cout << "Gia tri cua e la : "<< e<< endl;
}
bool snt(int n)
{
	bool b= true;
	if(n<2)
	{
		b=false;
	}
	else
	{
		for(int i=2;i<=n/2;i++)
		{
			if(n%i==0)
			{
				b=false;
			}
		}
	}
	return b;
}
void sinhpq(int &p, int &q)
{
	do
	{
		do
		{
			p=rand() % (100-1+1)+1;
		}
		while(!snt(p));
		cout << "Gia tri cua p la : "<< p<< endl;
		do
		{
			q=rand() % (100-1+1)+1;
		}
		while(!snt(q));
		cout << "Gia tri cua q la : "<< q<< endl;
	}
	while(p==q);
}
int main()
{
	srand(time(NULL));
	int p,q,d,e,n,M,m,xn;
//	nhap(p,q);
	sinhpq(p,q);
	sinhe(e,xn,p,q);
	khoa(p,q,e,d,n,xn);
	cout <<"\nNhap ban ro : ";
	cin >> M;
	mahoa(e,M,n);
	giaima(d,gtm(M,e,n),n);
	return 0;
}
