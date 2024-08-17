#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
 
        string s, t;
        cin >> s >> t;
 
        vector<vector<int>> cntS(26, vector<int>(n + 1, 0));
        vector<vector<int>> cntT(26, vector<int>(n + 1, 0));
 
        auto getCount = [&] (vector<vector<int>> &cnt, int idx, int l, int r) {
            return cnt[idx][r + 1] - cnt[idx][l];
        };
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                cntS[j][i + 1] = cntS[j][i];
                cntT[j][i + 1] = cntT[j][i];
            }
            cntS[s[i] - 'a'][i + 1]++;
            cntT[t[i] - 'a'][i + 1]++;
        }
 
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
 
            int diff = 0;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                int idx = ch - 'a';
                diff += abs(getCount(cntS, idx, l, r) - abs(getCount(cntT, idx, l, r)));
            }
 
            cout << diff / 2 << "\n";
        }
    }
    
    return 0;
}