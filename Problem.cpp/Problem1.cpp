#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
 
        int cows = n / 4;
        int chicken = n % 4 != 0;
 
        cout << cows + chicken << "\n";
    };
    
    return 0;
}