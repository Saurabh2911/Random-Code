/* ----- Code By Nilesh Gupta -----*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mod 998244353
#define vi vector<ll>
#define pp pair<ll, ll>
#define ff first
#define ss second
#define all(n) n.begin(),n.end()
#define INF 1e9

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
	vi v(n);
	for(ll i=0; i<n; i++)
		cin>>v[i];
	return v;
}

ll dp[1000][1000];
ll lcsubstr(string s1, string s2, ll i, ll j)
{
	for(ll i=1; i<=s1.size(); i++)
		for(ll j=1; j<=s2.size(); j++)
			if(s1[i-1] == s2[j-1])	dp[i][j] = dp[i-1][j-1] + 1;

	ll maxi=0;
	for(ll i=0; i<=s1.size(); i++)
		for(ll j=0; j<=s2.size(); j++)
			maxi = max(maxi, dp[i][j]);

	return maxi;
}

int main()
{
	init();
	memset(dp, 0, sizeof dp);
	ll t=1;
	//cin>>t;
	while(t--)
	{
		string s1, s2;
		cin>>s1>>s2;
		cout<<lcsubstr(s1, s2, 0, 0);
	}
}