// D. Swap Dilemma
// time limit per test1 second
// memory limit per test256 megabytes
// Given two arrays of distinct positive integers a
//  and b
//  of length n
// , we would like to make both the arrays the same. Two arrays x
//  and y
//  of length k
//  are said to be the same when for all 1≤i≤k
// , xi=yi
// .

// Now in one move, you can choose some index l
//  and r
//  in a
//  (l≤r
// ) and swap al
//  and ar
// , then choose some p
//  and q
//  (p≤q
// ) in b
//  such that r−l=q−p
//  and swap bp
//  and bq
// .

// Is it possible to make both arrays the same?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤2⋅104
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (1≤n≤105
// ) — the length of the arrays a
//  and b
// .

// The second line of each test case contains n
//  distinct integers a1,a2,a3,…,an
//  (1≤ai≤2⋅105
// ) — the integers in the array a
// .

// The third line of each test case contains n
//  distinct integers b1,b2,b3,…,bn
//  (1≤bi≤2⋅105
// ) — the integers in the array b
// .

// It is guaranteed that the sum of n
//  over all test cases does not exceed 105
// .

// Output
// For each testcase, print "YES" if the arrays a
//  and b
//  can be made the same. Otherwise, print "NO". can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// InputCopy
// 6
// 4
// 1 2 3 4
// 1 2 3 4
// 5
// 1 3 4 2 5
// 7 1 2 5 4
// 4
// 1 2 3 4
// 4 3 2 1
// 3
// 1 2 3
// 1 3 2
// 5
// 1 5 7 1000 4
// 4 1 7 5 1000
// 3
// 1 4 2
// 1 3 2
// OutputCopy
// YES
// NO
// YES
// NO
// NO
// NO
// Note
// In the first testcase, you don't need to perform any operations since the arrays are same.

// In the second testcase, it can be proven there exists no way to make the arrays same.

// In the third testcase, one of the ways to make the arrays same is to first choose l=1
// , r=3
// , p=1
// , q=3
//  then choose l=1
// , r=2
// , p=3
// , q=4
// .
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
struct segmenttree {
    int n;
    vector<int> st;
 
    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }
 
    int comb(int a, int b)
    {
        return a + b;
    }
 
    void build(int start, int ending, int node, vector<int> &v) {
        if (start == ending) {
            st[node] = v[start]; return;
        }
 
        int mid = (start + ending) / 2;
 
        build(start, mid, 2 * node + 1, v);
 
        build(mid + 1, ending, 2 * node + 2, v);
 
        st[node] = comb(st[node * 2 + 1], st[node * 2 + 2]);
    }
 
    int query(int start, int ending, int l, int r, int node) {
        if (start > r || ending < l) {
            return 0;
        }
 
        if (start >= l && ending <= r) {
            return st[node];
        }
 
        int mid = (start + ending) / 2;
 
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
 
        return comb(q1, q2);
    }
 
    void update(int start, int ending, int node, int index, int value) {
        if (start == ending) {
            st[node] = value;
            return;
        }
 
        int mid = (start + ending) / 2;
        if (index <= mid) {
            update(start, mid, 2 * node + 1, index, value);
        }
        else {
            update(mid + 1, ending, 2 * node + 2, index, value);
        }
 
        st[node] = comb(st[node * 2 + 1], st[node * 2 + 2]);
 
        return;
    }
 
    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }
 
    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }
 
    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tt; cin >> tt;
 
    while(tt--) {
        int n; cin >> n;
 
        vector<int>a(n), b(n);
 
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
 
        auto equal = [&](vector<int>a, vector<int>b) {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            return a == b;
        };
 
        auto compress = [&](vector<int>&arr) {
            vector<int>srt = arr;
            sort(srt.begin(), srt.end());
            for(auto &i : arr) i = lower_bound(srt.begin(), srt.end(), i) - srt.begin();
        };
 
        auto inversions = [&](vector<int>&arr) {
            segmenttree tree; tree.init(n + 1);
            long long inv = 0;
 
            for(auto &i : arr) {
                inv += tree.query(i + 1, n);
                tree.update(i, 1);
            }
 
            return inv;
        };
 
        if(!equal(a, b)) {
            cout << "NO\n";
            continue;
        }
 
        compress(a); compress(b);
 
        cout << (inversions(a) % 2 == inversions(b) % 2 ? "YES\n" : "NO\n");
    }
}


