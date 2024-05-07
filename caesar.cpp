#include<iostream>
using namespace std;
void mahoa(int k, int m, int &M)
{
	M=(m+k)%26;
	cout << "Ban ma hoa la : "<<M<< endl;
}
void giaima(int k, int M)
{
	int m= (M-k)%26;
	cout << "Ban giai ma la : "<<m;
}
int main()
{
	int k,m,M;
	mahoa(5,2,M);
	giaima(5,M);
	return 0;
}
