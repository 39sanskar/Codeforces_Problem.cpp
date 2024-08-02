// B2. Bouquet (Hard Version)
// time limit per test1.5 seconds
// memory limit per test256 megabytes
// This is the hard version of the problem. The only difference is that in this version, instead of listing the number of petals for each flower, the number of petals and the quantity of flowers in the store is set for all types of flowers.

// A girl is preparing for her birthday and wants to buy the most beautiful bouquet. There are a total of n
//  different types of flowers in the store, each of which is characterized by the number of petals and the quantity of this type of flower. A flower with k
//  petals costs k
//  coins. The girl has decided that the difference in the number of petals between any two flowers she will use to decorate her cake should not exceed one. At the same time, the girl wants to assemble a bouquet with the maximum possible number of petals. Unfortunately, she only has m
//  coins, and she cannot spend more. What is the maximum total number of petals she can assemble in the bouquet?

// Input
// Each test consists of several test cases. The first line contains a single integer t
//  (1≤t≤10000
// ) — the number of test cases. This is followed by descriptions of the test cases.

// The first line of each test case contains two integers n
// , m
//  (1≤n≤2⋅105,1≤m≤1018
// ) — the number of types of flowers in the store and the number of coins the girl possesses, respectively. The second line of each test case contains n
//  different integers a1,a2,…,an
//  (1≤ai≤109
// ), where ai
//  is the number of petals of the i
// -th flower type in the store (for different indexes i≠j
// , it must be ai≠aj
// ). The third line of each test case contains n
//  integers c1,c2,…,cn
//  (1≤ci≤109
// ), where ci
//  is the quantity of the i
// -th flower type in the store.

// The sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, print one integer — the maximum possible number of petals in a bouquet that a girl can collect, observing all the conditions listed above.

// Example
// InputCopy
// 7
// 3 10
// 1 2 3
// 2 2 1
// 3 1033
// 206 207 1000
// 3 4 1
// 6 20
// 4 2 7 5 6 1
// 1 2 1 3 1 7
// 8 100000
// 239 30 610 122 24 40 8 2
// 12 13123 112 1456 124 100 123 10982
// 6 13
// 2 4 11 1 3 5
// 2 2 1 2 2 1
// 8 10330
// 206 210 200 201 198 199 222 1000
// 9 10 11 12 13 14 15 16
// 2 10000000000
// 11 12
// 87312315 753297050
// OutputCopy
// 7
// 1033
// 19
// 99990
// 13
// 10000
// 9999999999
// Note
// In the first test case, some valid bouquets are (1,1,2,2),(2,2,3),(1,1),(2,2)
// . The maximum over all valid bouquets not greater than 10
//  is 7
//  for (2,2,3)
// . In the second test case, you can assemble a valid bouquet with (206,206,207,207,207)
//  with a sum of 1033
// , which is the maximum number of petals the girl can buy. In the third test case, you can assemble a valid bouquet with (5,5,5,4)
//  with a sum of 19
// . It can be seen that no valid bouquet can have 20
//  petals.
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
#define fr(i,n) for (ll i=0;i<n;i++)
#define pb push_back
#define sz(x) x.size()
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
// #define mod (ll)(1e9+7)
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#pragma GCC optimize("unroll-loops,O3,Ofast") //even 10^8+ also works with this
#pragma GCC target("avx2,avx,fma,bmi,bmi2,lzcnt,popcnt")
 
int knightx[8]={-1,-2,-2,-1,1,2,2,1};
int knighty[8]={-2,-1,1,2,2,1,-1,-2};
 
//...............................................................................................................................................
 
// lambda dfs------------->
// function<int(int,int)> dfs = [&](int node,int par){
 
// };
// dfs(0,-1);
// ---------------------------------------------------------------------------------------
// //__builtin_popcount(a) number of set bits for int
// //__builtin_popcountll(a) number of set bits for long long
// //<<left shift *2
// //>>Right shift /2
// //char a='A'|(1<<5); in uppercase 5th bit is not set and in lower case 5th bit is set
// //char a='A'|' ';
// //char A='a'&(~(1<<5)); unset the 5th bit
// //char A='a'& '_';
// //if(n&(n-1)==0) then number is power of two
//..................................................................................................
 
 
 
void solve(){
    ll n,m;
    cin>>n>>m;
    map<ll,ll>mp;
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        mp[v[i]]=a;
    }
    sort(all(v));
    ll ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,min((m/v[i]),mp[v[i]])*v[i]);
    }
    for(int i=0;i<n-1;i++){
        if(v[i+1]-v[i]!=1)continue;
        ll temp=m;
        ll smaller=min((m/v[i]),mp[v[i]]);
        temp-=smaller*v[i];
        ll larger=min(temp/v[i+1],mp[v[i+1]]);
        temp-=larger*v[i+1];
        ll c=min({temp,mp[v[i+1]]-larger,smaller});
        ans=max(ans,m-temp+c);
    }
    cout<<ans<<endl;
    
}
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
#endif
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
} 
