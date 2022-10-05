#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Time Complexity=O(2^n) and Space Complexity=O(n*W);
int KnapSack(int W, vector<int> val, vector<int> wt, int n) 
{
	int K[n+1][W+1];
	memset(K,-1,sizeof(K));
	if(n==0 || W==0)
	{
		return 0;
	}
	if(K[n][W]!=-1)
	{
		return K[n][W];
	}
	if(wt[n-1]<=W)
	{
		return K[n][W]=max(val[n-1]+KnapSack(W-wt[n-1],val,wt,n-1),KnapSack(W,val,wt,n-1));
	}
	else
	{
		return K[n][W]=KnapSack(W,val,wt,n-1);
	}
}

// Time Complexity=O(n*W) and Space Complexity=O(n*W);
int DpKnapSack(int W, vector<int> val, vector<int> wt, int n) 
{
	int K[n+1][W+1];
	for (int i = 0; i <= n; i++) 
	{
		for (int w = 0; w <= W; w++) 
		{
			if (i == 0 || w == 0)
			{
				K[i][w] = 0;
			}
			else if (wt[i - 1] <= w)
			{
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			}
			else
			{
				K[i][w] = K[i - 1][w];
			}
		}
	}
	return K[n][W];
}
int main() 
{
	int n, Capas;
	cout <<"Enter the number of items and bag capacity : "<<endl;
	cin >> n >> Capas;
	vector<int> Values(n);
	vector<int> Weights(n);
	int Temp;
	cout <<"Enter the Value of items : "<<endl;
	for (size_t i = 0; i < n; i++) 
	{
		cin >> Temp;
		Values[i]=Temp;
	}
	cout <<"Enter the Weight of items : "<<endl;
	for (size_t i = 0; i < n; i++) 
	{
		cin >> Temp;
		Weights[i]=Temp;
	}
	cout <<"Maximum profit earned : "<< KnapSack(Capas, Values, Weights, n) << endl;
	cout <<"Maximum profit earned : "<< DpKnapSack(Capas, Values, Weights, n) << endl;
	return 0;
}
