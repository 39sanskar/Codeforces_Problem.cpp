#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
 
        long long ans = 0;
 
        for (int first = 1; first <= n; first++) {
            for (int second = 1; 1LL * first * second <= n; second++) {
                ans += max(0LL, min(1LL * x - first - second,
                       (n - 1LL * first * second) / (first + second)));
            }
        }
 
        cout << ans << "\n";
    }
    
    return 0;
}