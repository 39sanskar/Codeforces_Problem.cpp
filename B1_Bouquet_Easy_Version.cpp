// B1. Bouquet (Easy Version)
// time limit per test1.5 seconds
// memory limit per test512 megabytes
// This is the easy version of the problem. The only difference is that in this version, the flowers are specified by enumeration.

// A girl is preparing for her birthday and wants to buy the most beautiful bouquet. There are a total of n
//  flowers in the store, each of which is characterized by the number of petals, and a flower with k
//  petals costs k
//  coins. The girl has decided that the difference in the number of petals between any two flowers she will use in her bouquet should not exceed one. At the same time, the girl wants to assemble a bouquet with the maximum possible number of petals. Unfortunately, she only has m
//  coins, and she cannot spend more. What is the maximum total number of petals she can assemble in the bouquet?

// Input
// Each test consists of several test cases. The first line contains a single integer t
//  (1≤t≤10000
// ) — the number of test cases. This is followed by descriptions of the test cases.

// The first line of each test case contains two integers n
// , m
//  (1≤n≤2⋅105,1≤m≤1018
// ) — the number of flowers in the store and the number of coins the girl possesses, respectively. The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤109
// ), where ai
//  is the number of petals of the i
// -th flower in the store.

// The sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output a single integer — the maximum possible number of petals in the bouquet that the girl can assemble while meeting all the conditions listed above.

// Example
// InputCopy
// 5
// 5 10
// 1 1 2 2 3
// 8 20
// 4 2 7 5 6 1 1 1
// 8 100000
// 239 30 610 122 24 40 8 2
// 11 13
// 2 4 11 1 1 2 3 5 4 3 2
// 8 1033
// 206 206 206 207 207 207 207 1000
// OutputCopy
// 7
// 13
// 610
// 13
// 1033
// Note
// In the first test case, you can assemble a bouquet with (1,1,2,2),(2,2,3),(1,1),(2,2)
// . The maximum over all valid bouquets not greater than 10
//  is 7
//  for (2,2,3)
// . In the third test case, you can assemble a bouquet with only one flower of any type, so the answer is 610
// . In the fourth test case, you can assemble a bouquet with (4,4,5)
// , which gives you 13
//  petals, and it is the maximum amount of petals that the girl can buy.
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
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    sort(all(v));
    vector<ll>pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+v[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll temp=(i==0 ? 0:pre[i-1])+m;
        ll idx1=upper_bound(all(v),v[i]+1)-v.begin();
        idx1--;
        ll idx2=upper_bound(all(pre),temp)-pre.begin();
        idx2--;
        if(idx2<i)continue;
        if(idx2<=idx1){
            ans=max(ans,pre[idx2]-(i==0 ? 0:pre[i-1]));
        }
        else{
            ans=max(ans,pre[idx1]-(i==0 ? 0:pre[i-1]));
        }
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
