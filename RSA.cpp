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
string bang(int n)
{
	string a[27]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"," "};
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
		case ' ':return " ";
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
void mahoaandgiaima(int e, int n, int d)
{
	cout << "\nNhap chuoi can ma hoa : ";
	string s;
	getline(cin,s);
	int a[s.length()];
	int h=s.length();
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<27;j++)
		{
			if(cts(s[i])==bang(j))
			{
				a[i]=j;
			}
		}
	}
	s="";
	for(int i=0;i<h;i++)
	{
		if(a[i]!=26)
		{
			a[i]=gtm(a[i],e,n);
			s=s+bang(a[i]%26);
		}
		else
		{
			s=s+bang(26);
		}
	}
	cout << "Ban ma la : "<<s<< endl;
	s="";
	for(int i=0;i<h;i++)
	{
		if(a[i]!=26)
		{
			a[i]=gtm(a[i],d,n);
			s=s+bang(a[i]);
		}
		else
		{
			s=s+bang(26);
		}
	}
	cout << "Ban giai ma la : "<<s<<endl;
}
//void giaima(int d, int m, int n)
//{
//	cout <<"\nGiai ma la :"<< gtm(m,d,n);
//}
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
	mahoaandgiaima(e,n,d);
	return 0;
}
