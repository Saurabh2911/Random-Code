/* ----- Code By Nilesh Gupta -----*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mod 1000000009
#define vi vector<ll>
#define pp pair<ll, ll>
#define ff first
#define ss second
#define all(n) n.begin(),n.end()

using namespace std;

void init()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

vi vec_n(ll n)
{
	vi v(n+1);
	for(ll i=1; i<=n; i++)
		cin>>v[i];
	return v;
}

ll choice[3001][3001] = {0};
void LCS(string s1, string s2, ll n, ll m)
{
	ll dp[n+1][m+1];
	for(ll i=0; i<n; i++)
		for(ll j=0; j<m; j++)
			dp[i][j] = 0;

	if(s1[0] == s2[0])
	{
		choice[0][0] = 2;
		dp[0][0] = 1;
	}

	for(ll i=0; i<n; i++)
	{
		for(ll j=0; j<m; j++)
		{
			if(s1[i] == s2[j])
			{
				ll ans=1;
				if(i>0 && j>0)
					ans = 1 + dp[i-1][j-1];
				if(ans > dp[i][j]){
					dp[i][j] = ans;
					choice[i][j] = 2;
				}
			}
			
			if(i>0 && dp[i][j] < dp[i-1][j])
			{
				dp[i][j] = dp[i-1][j];
				choice[i][j] = 0;
			}
			if(j>0 && dp[i][j] < dp[i][j-1])
			{
				dp[i][j] = dp[i][j-1];
				choice[i][j] = 1;
			}
			
		}
	}
	return;
}

int main()
{
	init();

	string s1, s2;
	cin>>s1>>s2;

	LCS(s1, s2, s1.length(), s2.length());
	string str="";
	ll i=s1.length()-1, j=s2.length()-1;
	
	while(i>=0 && j>=0)
	{
		if(choice[i][j] == 2)
		{
			str.pb(s1[i]);
			i--;
			j--;
		}
		else if(choice[i][j] == 1)
			j--;
		else
			i--;
	}
    
    reverse(all(str));
	cout<<str;
}