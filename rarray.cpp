#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define fi              first
#define se              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define FastIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main()
{
	FastIO;
	int n;
	cin>>n;
	ll sum =0;
	vector<ll> arr;
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	    sum+=arr[i];
	}
	int q;
	cin>>q;
	vector<int> qu;
	for(int j=0;j<q;j++)
	{
	   cin>>qu[j];
	}
	for(int k=0;k<q;k++)
	{
	    sum*=2;
	    cout<<sum<<"\n";
	}   
	return 0;
}