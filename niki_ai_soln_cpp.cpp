#include<iostream>
using namespace std;

void matrixMultiply(unsigned long long pri[2][2], unsigned long long sec[2][2])
{
	unsigned int mod = 1000000007;
	unsigned long long a= (pri[0][0]*sec[0][0] + pri[0][1]*sec[1][0]) % mod;
	unsigned long long b= (pri[0][0]*sec[0][1] + pri[0][1]*sec[1][1]) % mod;
	unsigned long long c= (pri[1][0]*sec[0][0] + pri[1][1]*sec[1][0]) % mod;
	unsigned long long d= (pri[1][0]*sec[0][1] + pri[1][1]*sec[1][1]) % mod;
	pri[0][0]=a;
	pri[0][1]=b;
	pri[1][0]=c;
	pri[1][1]=d;
}

void matrixPower(unsigned long long pri[2][2], unsigned long long n)
{
	if(n == 0 || n == 1)
		return;

	matrixPower(pri, n/2);
	matrixMultiply(pri, pri);

	if (n%2 != 0)
	{
		unsigned long long sec[2][2] = {{1,1},{1,0}};
		matrixMultiply(pri, sec);
	}
}

int calcBitstrings(unsigned long long n)
{
	if (n == 0)
		return 0;

	unsigned int mod = 1000000007;
	unsigned long long pri[2][2] = {{1,1},{1,0}};

	matrixPower(pri, n);
	unsigned int total = (pri[0][0] % mod + pri[0][1] % mod) % mod;
	return total;
}

int main()
{
	int t;
	unsigned long long n;

	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<calcBitstrings(n)<<endl;
	}
	return 0;
}