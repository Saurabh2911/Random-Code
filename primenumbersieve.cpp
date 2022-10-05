#include<bits/stdc++.h>
using namespace std;  
void prime_sieve(int p[],int n)
{
	// first mark all odd number's is prime	
	for (int i = 3; i <= n; i += 2)
	{
		p[i] = 1;
	}
	// sieve
	for(int i = 3;i <= n;i += 2)
	{
		if (p[i] == 1)
		{
			//mark all the number's multiples of i as not prime
			for(int j = i*i;j <= n; j = j + i)
			{
				p[j] = 0;
			}
		}
	}
	p[2]=1;
	p[1]=p[0]=0;
}
int main()  
{ 
		int n;
		cin >> n;

		int p[n] = {0};
		prime_sieve(p,n);
		// lets print prime upto range n
		for (int i = 0; i <=n; ++i)
		{
			if (p[i] == 1)
			{
				cout << i << " ";
			}
		}		
	return 0;
}








