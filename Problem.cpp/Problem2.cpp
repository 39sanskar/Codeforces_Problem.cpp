#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
 
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
 
        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < n; j += k) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    
    return 0;
}