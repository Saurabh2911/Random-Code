/* ----- Code By Nilesh Gupta -----*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mod 1000000009
#define mp make_pair
#define vi vector<ll>
#define ppi pair<ll, ll>
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

ll n, c;
ll w[101], v[101];
ll dp[101][100001];
bool vis[101][100001];

ll knapsack(ll idx, ll cap_remaining)
{
	if(idx == n)
		return 0;

	if(vis[idx][cap_remaining]) {
		return dp[idx][cap_remaining];
	}

	vis[idx][cap_remaining] = true;

	ll ans=0;
	if(cap_remaining - w[idx] >= 0)
		ans = max(ans, knapsack(idx+1, cap_remaining-w[idx]) + v[idx]);

	ans = max(ans, knapsack(idx+1, cap_remaining));


	dp[idx][cap_remaining] = ans;
	return ans;
}

int main()
{
	init();

	cin>>n>>c;

	for(ll i=0; i<n; i++)
		cin>>w[i]>>v[i];

	ll ans = knapsack(0, c);
	cout<<ans;
}
