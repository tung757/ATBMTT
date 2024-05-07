#include<iostream>
#include<math.h>
using namespace std;
string htb(char a)
{
	switch(a)
	{
		case '0':return "0000";
		case '1':return "0001";
		case '2':return "0010";
		case '3':return "0011";
		case '4':return "0100";
		case '5':return "0101";
		case '6':return "0110";
		case '7':return "0111";
		case '8':return "1000";
		case '9':return "1001";
		case 'A':return "1010";
		case 'B':return "1011";
		case 'C':return "1100";
		case 'D':return "1101";
		case 'E':return "1110";
		case 'F':return "1111";
	}
}
string hextobin(string a)
{
	string s="";
	for(int i=0;i<a.length();i++)
	{
		s=s+htb(a[i]);
	}
	return s;
}
string dtb(int n)
{
	if(n==0)
	{
		return "0";
	}
	else if(n==1)
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
string dectobin(int n)
{
	string k=dtb(n);
	if(k.length()<4)
	{
		for(int i=k.length()+1;i<=4;i++)
		{
			k="0"+k;
		}
	}
	return k;
}
long bintodec(string a)
{
	long p=0;
	int j=0;
	for(int i=a.length()-1;i>=0;i--)
	{
		if(a[i]=='1')
		{
			p=p+pow(2,j);
		}
		j++;
	}
	return p;
}
string bth(string a)
{
	string x[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
	string g[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	for(int i=0;i<16;i++)
	{
		if(a==x[i])
		{
			return g[i];
		}
	}
}
string bintohex(string a)
{
	string k="";
	for(int i=0;i<a.length();i=i+4)
	{
		string s="";
		s=s+a[i]+a[i+1]+a[i+2]+a[i+3];
		k=k+bth(s);
	}
	return k;
}
string cd(string h, int a[],int n)
{
	string s="";
	for(int i=0;i<n;i++)
	{
		s=s+h[a[i]-1];
	}
	return s;
}
string dleft(string h, int k)
{
	for(int i=0;i<k;i++)
	{
		string s="";
		for(int j=1;j<h.length();j++)
		{
			s=s+h[j];
		}
		s=s+h[0];
		h=s;
	}
	return h;
}
string axor(string a, string b)
{
	if(a.length()<b.length())
	{
		for(int i=a.length()+1;i<=b.length();i++)
		{
			a="0"+a;
		}
	}
	else
	{
		for(int i=b.length()+1;i<=a.length();i++)
		{
			b="0"+b;
		}
	}
	string s="";
	for(int i=0;i<a.length();i++)
	{
		if(a[i]==b[i])
		{
			s=s+"0";
		}
		else
		{
			s=s+"1";
		}
	}
	return s;
}
void mahoa(string m, int initial_perm[64], int exp_d[48],string rkb[16],int sbox[8][4][16], int per[32], string rk[16], int final_perm[64], string &M)
{
	string m1=hextobin(m);
	m1=cd(m1,initial_perm,64);
	cout <<"\nSau khi hoan vi IP : "<<bintohex(m1)<< endl;
	string left="";
	for(int i=0;i<32;i++)
	{
		left=left+m1[i];
	}
	string right="";
	for(int i=32;i<64;i++)
	{
		right=right+m1[i];
	}
	for(int i=0;i<16;i++)
	{
		string right_expanded=cd(right,exp_d,48);
		string xor_x=axor(right_expanded,rkb[i]);
		string sbox_str = "";
		for(int j=0;j<8;j++)
		{
			string h="";
			h=h+xor_x[j*6]+xor_x[j*6+5];
			
			long row=bintodec(h);
			
			h="";
			h=h+xor_x[j * 6 + 1] + xor_x[j * 6 + 2] + xor_x[j * 6 + 3] + xor_x[j * 6 + 4];
			long col=bintodec(h);
			
			int val = sbox[j][row][col];
			
			sbox_str = sbox_str + dectobin(val);
			
			
		}
		sbox_str = cd(sbox_str, per, 32);
		string result = axor(left, sbox_str);
		left = result;
		if(i!=15)
		{
			string tg=left;
			left=right;
			right=tg;
		}
		cout << "Lan "<<i + 1<<" "<<bintohex(left)<<" "<<bintohex(right)<<" "<<rk[i]<< endl;
	}
	string combine = left + right;
	string cipher_text = cd(combine, final_perm, 64);
	M=bintohex(cipher_text);
}
int main()
{
	int initial_perm[64] = {58, 50, 42, 34, 26, 18, 10, 2,
			                60, 52, 44, 36, 28, 20, 12, 4,
			                62, 54, 46, 38, 30, 22, 14, 6,
			                64, 56, 48, 40, 32, 24, 16, 8,
			                57, 49, 41, 33, 25, 17, 9, 1,
			                59, 51, 43, 35, 27, 19, 11, 3,
			                61, 53, 45, 37, 29, 21, 13, 5,
			                63, 55, 47, 39, 31, 23, 15, 7};
	int exp_d[48] = {32, 1, 2, 3, 4, 5, 4, 5,
		         6, 7, 8, 9, 8, 9, 10, 11,
		         12, 13, 12, 13, 14, 15, 16, 17,
		         16, 17, 18, 19, 20, 21, 20, 21,
		         22, 23, 24, 25, 24, 25, 26, 27,
		         28, 29, 28, 29, 30, 31, 32, 1};
	int per[32] = {16,  7, 20, 21,
		       29, 12, 28, 17,
		       1, 15, 23, 26,
		       5, 18, 31, 10,
		       2,  8, 24, 14,
		       32, 27,  3,  9,
		       19, 13, 30,  6,
		       22, 11,  4, 25};
	int sbox[8][4][16] = {{{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
         {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
         {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
         {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
 
        {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
         {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
         {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
         {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
 
        {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
         {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
         {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
         {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
 
        {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
         {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
         {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
         {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
 
        {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
         {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
         {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
         {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
 
        {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
         {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
         {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
         {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
 
        {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
         {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
         {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
         {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
 
        {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
         {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
         {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
         {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};
    int final_perm[64] = {40, 8, 48, 16, 56, 24, 64, 32,
			              39, 7, 47, 15, 55, 23, 63, 31,
			              38, 6, 46, 14, 54, 22, 62, 30,
			              37, 5, 45, 13, 53, 21, 61, 29,
			              36, 4, 44, 12, 52, 20, 60, 28,
			              35, 3, 43, 11, 51, 19, 59, 27,
			              34, 2, 42, 10, 50, 18, 58, 26,
			              33, 1, 41, 9, 49, 17, 57, 25};
	string h = "123456ABCD132536";
	string key = "AABB09182736CCDD";
	key = hextobin(key);
	int keyp[56] = {57, 49, 41, 33, 25, 17, 9,
		        1, 58, 50, 42, 34, 26, 18,
		        10, 2, 59, 51, 43, 35, 27,
		        19, 11, 3, 60, 52, 44, 36,
		        63, 55, 47, 39, 31, 23, 15,
		        7, 62, 54, 46, 38, 30, 22,
		        14, 6, 61, 53, 45, 37, 29,
		        21, 13, 5, 28, 20, 12, 4};
	key = cd(key, keyp, 56);
	int shift_table[16] = {1, 1, 2, 2,
               2, 2, 2, 2,
               1, 2, 2, 2,
               2, 2, 2, 1};
    int key_comp[48] = {14, 17, 11, 24, 1, 5,
			            3, 28, 15, 6, 21, 10,
			            23, 19, 12, 4, 26, 8,
			            16, 7, 27, 20, 13, 2,
			            41, 52, 31, 37, 47, 55,
			            30, 40, 51, 45, 33, 48,
			            44, 49, 39, 56, 34, 53,
			            46, 42, 50, 36, 29, 32};
	string left="";
	for(int i=0;i<28;i++)
	{
		left=left+key[i];
	}
	string right="";
	for(int i=28;i<56;i++)
	{
		right=right+key[i];
	}
    string rkb[16];
    string rk[16];
    for(int i=0;i<16;i++)
    {
    	left=dleft(left,shift_table[i]);
    	right=dleft(right,shift_table[i]);
    	string combine_str = left + right;
    	string round_key = cd(combine_str, key_comp, 48);
    	rkb[i]=round_key;
    	rk[i]=bintohex(round_key);
	}
	string rkb_v[16];
	string rk_v[16];
	int l=0;
	for(int i=15;i>=0;i--)
	{
		rkb_v[l]=rkb[i];
		rk_v[l]=rk[i];
		l++;
	}
	string M;
    mahoa(h,initial_perm,exp_d,rkb,sbox,per,rk,final_perm,M);
    cout << "\nBan ma la : "<<M;
    mahoa(M,initial_perm,exp_d,rkb_v,sbox,per,rk_v,final_perm,M);
    cout << "\nBan ro la : "<<M;
    
    
}
