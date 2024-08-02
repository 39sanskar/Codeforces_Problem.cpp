// A. Diagonals
// time limit per test1 second
// memory limit per test256 megabytes
// Vitaly503 is given a checkered board with a side of n
//  and k
//  chips. He realized that all these k
//  chips need to be placed on the cells of the board (no more than one chip can be placed on a single cell).

// Let's denote the cell in the i
// -th row and j
// -th column as (i,j)
// . A diagonal is the set of cells for which the value i+j
//  is the same. For example, cells (3,1)
// , (2,2)
// , and (1,3)
//  lie on the same diagonal, but (1,2)
//  and (2,3)
//  do not. A diagonal is called occupied if it contains at least one chip.

// Determine what is the minimum possible number of occupied diagonals among all placements of k
//  chips.

// Input
// Each test consists of several sets of input data. The first line contains a single integer t
//  (1≤t≤500
// ) — the number of sets of input data. Then follow the descriptions of the sets of input data.

// The only line of each set of input data contains two integers n
// , k
//  (1≤n≤100,0≤k≤n2
// ) — the side of the checkered board and the number of available chips, respectively.

// Output
// For each set of input data, output a single integer — the minimum number of occupied diagonals with at least one chip that he can get after placing all k
//  chips.

// Example
// InputCopy
// 7
// 1 0
// 2 2
// 2 3
// 2 4
// 10 50
// 100 239
// 3 9
// OutputCopy
// 0
// 1
// 2
// 3
// 6
// 3
// 5
// Note
// In the first test case, there are no chips, so 0 diagonals will be occupied. In the second test case, both chips can be placed on diagonal (2,1),(1,2)
// , so the answer is 1. In the third test case, 3 chips can't be placed on one diagonal, but placing them on (1,2),(2,1),(1,1)
//  makes 2 diagonals occupied. In the 7th test case, chips will occupy all 5 diagonals in any valid placing.
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