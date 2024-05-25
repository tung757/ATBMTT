#include<iostream>
using namespace std;
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
void mahoaandgiaima(int k)
{
	string s="";
	cout << "Nhap chuoi de ma hoa : ";
	getline(cin,s);
	int a[s.length()];
	int dem=s.length();
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<26;j++)
		{
			if(cts(s[i])==bang(j))
			{
				a[i]=j;
			}
		}
	}
	for(int i=0;i<s.length();i++)
	{
		a[i]=(a[i]+k)%26;
	}
	s="";
	for(int i=0;i<dem;i++)
	{
		s=s+bang(a[i]);
	}
	cout << "Ban ma hoa la : "<<s<< endl;
	for(int i=0;i<dem;i++)
	{
		a[i]=(a[i]-k)%26;
	}
	s="";
	for(int i=0;i<dem;i++)
	{
		s=s+bang(a[i]);
	}
	cout << "Ban giai ma la : "<<s<<endl;
}
int main()
{
	int k;
	mahoaandgiaima(6);
	return 0;
}
