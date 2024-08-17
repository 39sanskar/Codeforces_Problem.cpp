#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long > pll;
typedef vector<pair<ll,ll>> vpll;
#define F first
#define S second
#define EB emplace_back
#define pb push_back
#define endl "\n"
const ll MOD=1e9+7;
 
 
void solve(){
	string s;
	cin>>s;
	int n=s.length();
	if(n<=2){
		cout<<"NO"<<endl;
		return;
	}
	if(s[0]=='1'&&s[1]=='0'){
		string s1="";
		for(int i=2;i<n;i++){
			s1+=s[i];
		}
		if(s1=="1"||s1[0]=='0'){
			cout<<"NO"<<endl;
			return;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	else{
		cout<<"NO"<<endl;
		return;
	}
	
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int countdigits(ll x){
	ll y=x;
	int c=0;
	while(y>0){
		c++;
		y=y/10;
	}
	return c;
}
int binarysearch(ll a[],ll x,int n){
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid = (s+e)/2;
		if(a[mid]==x){
			return mid;
 
		}
		else if(a[mid]>x){
			e=mid-1;
		}
		else
			s=mid+1;
	}
	return -1;
 
}	 
