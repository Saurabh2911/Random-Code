#include <bits/stdc++.h>
using namespace std;
// class Node
// {
// private:
//     /* data */
// public:
//     string key;
//     int value;
//     Node(string k,int v){
//         key=k;
//         value=v;
//     }
// };
// class Cache
// {
// private:
//     /* data */
// public:
//     int maxSize;
//     ~Cache();
// };

// Cache::Cache(/* args */)
// {
// }

// Cache::~Cache()
// {
// }
// inline long long int pow(long long int a, long long int n, long long int mod)
// {
//     long long int ans = 1;
//     while (n)
//     {
//         if (n & 1)
//         {
//             ans = (ans * a) % mod;
//         }
//         a = (a * a) % mod;
//         n = n / 2;
//     }
//     return ans % mod;
// }
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int j = s[i] - 'A';
        arr[j] = arr[j] + 1;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2 == 1)
            odd++;
    }
    if (odd > 1)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] % 2 == 0)
            {
                char temp = i + 'A';
                for (int j = 0; j < arr[i] / 2; j++)
                {
                    cout << temp;
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] % 2 == 1)
            {
                char temp = i + 'A';
                for (int j = 0; j < arr[i]; j++)
                {
                    cout << temp;
                }
            }
        }
        for (int i = 25; i >= 0; i--)
        {
            if (arr[i] % 2 == 0)
            {
                char temp = i + 'A';
                for (int j = 0; j < arr[i] / 2; j++)
                {
                    cout << temp;
                }
            }
        }
    }

    // long long int t;
    // cin >> t;
    // //  cout << pow(2, n, 1000000007);
    // while (t--)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     if ((a + b) % 3 == 0 && (max(a, b) / 2 <= min(a, b)))
    //     {
    //         cout << "YES" << endl;
    //     }
    //     else
    //     {
    //         cout << "NO" << endl;
    //     }
    // }
    return 0;
}
// long long int n;
// cin >> n;
// int base = 5;
// int temp = 0;
// int sum = 0;
// while (1)
// {
//     temp = n / base;
//     sum = sum + temp;
//     base = base * 5;
//     if (temp == 0)
//     {
//         break;
//     }
// }
// cout << sum;
//     int n;
//     cin>>n;
//     int num=n*(n+1)/2;
//     if(num%2==1){
//         cout<<"NO";
//     }
//     else{
//         cout<<"YES";
//         if(n%2==0){
//            cout<<n/2;
//            int k=n/2;
//            int t1=1;t2=n;
//            while(k--){
//                cout<<t1<<" "<<t2<<" ";
//                t1=t1+2;
//                t2=t2-2;
//            }
//            k=n/2
//            t1=2;
//            t2=n-1;
//            while (k--)
//            {
//                cout << t1 << " " << t2 << " ";
//                t1 = t1 + 2;
//                t2 = t2 - 2;
//            }
//         }
//     }

// int n;
// cin >> n;
// for (long long int k = 1; k <= n; k++)
// {
//     cout << (k * k) * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2) << endl;
// }

// int t;
// cin >> t;
// while (t--)
// {
//     long long int y, x;
//     cin >> y >> x;
//     long long int l = max(y, x);
//     if (l % 2 == 1)
//     {
//         if (x > y)
//         {
//             cout << l * l - y + 1 << endl;
//         }
//         else
//         {
//             cout << (l - 1) * (l - 1) + x << endl;
//         }
//     }
//     else
//     {
//         if (x > y)
//         {
//             cout << (l - 1) * (l - 1) + y << endl;
//         }
//         else
//         {
//             cout << l * l - x + 1 << endl;
//         }
//     }
// }

// if (n == 1)
// {
//     cout << "1"
//          << " ";
// }
// else if (n == 2 || n == 3)
// {
//     cout << "NO SOLUTION";
// }
// else if (n == 4)
// {
//     cout << "2 4 1 3";
// }
// else
// {
//     for (int i = 1; i <= n; i = i + 2)
//     {
//         cout << i << " ";
//     }
//     for (int i = 2; i <= n; i = i + 2)
//     {
//         cout << i << " ";
//     }
// }

// answer4
//  long long int n;
//  cin >> n;
//  long long int count = 0;
//  long long int maxi = INT_MIN;
//  for (int i = 1; i <= n; i++)
//  {
//      long long int temp;
//      cin >> temp;

//     if (temp >= maxi)
//     {
//         maxi = max(maxi, temp);
//         continue;
//     }
//     else
//     {
//         count = count + (maxi - temp);
//     }
// }
// cout << count << endl;
// 3answer
//  string str;
//  cin >> str;
//  int maxi = INT_MIN;
//  int temp = 1;
//  for (int i = 0; i < str.size() - 1; i++)
//  {
//      if (str[i] == str[i + 1])
//      {
//          temp = temp + 1;
//      }
//      else
//      {
//          temp = 1;
//      }
//      maxi = max(maxi, temp);
//  }
//  maxi = max(maxi, temp);

// cout << maxi << endl;
// your code goes here
// 1question
// long long int n;
// cin >> n;
// while (n != 1)
// {
//     cout << n << " ";
//     if (n % 2 == 0)
//     {
//         n = n / 2;
//     }
//     else
//     {
//         n = (n * 3) + 1;
//     }
// }
// cout << n << endl;

// long long int n;
// cin >> n;
// long long int sum = 0;
// for (int i = 1; i <= n - 1; i++)
// {
//     long long int t;
//     cin >> t;
//     sum = sum + t;
// }
// long long int dis = n * (n + 1) / 2;
// cout << dis - sum;
//     return 0;
// }
