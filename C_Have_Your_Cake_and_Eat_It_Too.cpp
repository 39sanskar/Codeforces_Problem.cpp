// C. Have Your Cake and Eat It Too
// time limit per test2 seconds
// memory limit per test256 megabytes
// Alice, Bob and Charlie want to share a rectangular cake cut into n
//  pieces. Each person considers every piece to be worth a different value. The i
// -th piece is considered to be of value ai
//  by Alice, bi
//  by Bob and ci
//  by Charlie.

// The sum over all ai
// , all bi
//  and all ci
//  individually is the same, equal to tot
// .

// Given the values of each piece of the cake for each person, you need to give each person a contiguous slice of cake. In other words, the indices at the left and right ends of these subarrays (the slices given to each person) can be represented as (la,ra)
// , (lb,rb)
//  and (lc,rc)
//  respectively for Alice, Bob and Charlie. The division needs to satisfy the following constraints:

// No piece is assigned to more than one person, i.e., no two subarrays among [la,…,ra]
// , [lb,…,rb]
//  and [lc,…,rc]
//  intersect.
// ∑rai=laai,∑rbi=lbbi,∑rci=lcci≥⌈tot3⌉
// .
// Here, the notation ⌈ab⌉
//  represents ceiling division. It is defined as the smallest integer greater than or equal to the exact division of a
//  by b
// . In other words, it rounds up the division result to the nearest integer. For instance ⌈103⌉=4
//  and ⌈153⌉=5
// .

// Input
// The first line contains an integer t
// , the number of testcases, (1≤t≤104
// )

// For each testcase:

// The first line contains the integer n
//  (3≤n≤2⋅105
// ).

// The following three lines contain n
//  integers each:

// One line with n
//  integers a1,a2,…,an
//  represents the values for Alice (1≤ai≤106
// ).

// The next line with n
//  integers b1,b2,…,bn
//  represents the values for Bob (1≤bi≤106
// ).

// The next line with n
//  integers c1,c2,…,cn
//  represents the values for Charlie (1≤ci≤106
// ).

// It is guaranteed that ∑ni=1ai=∑ni=1bi=∑ni=1ci
// .

// The sum of n
//  over all testcases does not exceed 2⋅105
// .

// Output
// For each testcase, output −1
//  if the required condition is impossible.

// Otherwise, output six numbers – la,ra,lb,rb,lc,rc
// , the respective starting and ending indices (1
// -indexed) of the subarrays for Alice, Bob and Charlie, respectively.

// Example
// InputCopy
// 10
// 5
// 5 1 1 1 1
// 1 1 5 1 1
// 1 1 1 1 5
// 6
// 1 2 3 4 5 6
// 5 6 1 2 3 4
// 3 4 5 6 1 2
// 4
// 4 4 4 4
// 4 4 4 4
// 4 4 4 4
// 5
// 5 10 5 2 10
// 9 6 9 7 1
// 10 7 10 2 3
// 3
// 4 5 2
// 6 1 4
// 1 8 2
// 3
// 10 4 10
// 8 7 9
// 10 4 10
// 7
// 57113 65383 19795 53580 74452 3879 23255
// 12917 16782 89147 93107 27365 15044 43095
// 33518 63581 33565 34112 46774 44151 41756
// 6
// 6 3 1 8 7 1
// 10 2 6 2 2 4
// 10 9 2 1 2 2
// 5
// 5 5 4 5 5
// 1 6 3 8 6
// 2 4 1 9 8
// 10
// 1 1 1 1 1001 1 1 1001 1 1
// 1 1 1 1 1 1 2001 1 1 1
// 1 1 1 1 1 1001 1 1 1 1001
// OutputCopy
// 1 1 2 3 4 5 
// 5 6 1 2 3 4 
// -1
// -1
// 1 1 3 3 2 2 
// -1
// 1 2 3 4 5 7 
// 3 6 1 1 2 2 
// 1 2 3 4 5 5 
// 1 5 6 7 8 10 
// Note
// In the first testcase, the sum of either of the three arrays is 9
// . Each person needs a cake slice corresponding to a subarray with a total value of at least ⌈93⌉=3
// .

// If we assign the subarray (1
// ,1
// ) to Alice, its total value to her is 5
// , which is ≥3
// ; the subarray (2
// ,3
// ) to Bob, its total value to him is 1+5=6
// , which is ≥3
// ; and the subarray (4
// ,5
// ) to Charlie, its total value to him 1+5=6
// , which is also ≥3
// . Each person gets their own separate pieces of the cake, and no piece is common to two or more people.

// It can be shown that for the third test case, it is not possible to give slices of the cake in a way that satisfies the given constraints.
#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tt; cin >> tt;
 
    while(tt--) {
        int n; cin >> n;
 
        vector<int>a(n), b(n), c(n);
 
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        for(auto &i : c) cin >> i;
 
        int sum = accumulate(a.begin(), a.end(), 0ll);
 
        auto solve = [&](vector<int>&a, vector<int>&b, vector<int>&c) {
 
            // a comes first, b ecomes second, c comes third
 
            int A = 0, B = 0, C = 0;
            vector<int>partitions;
 
            for(int i = 0; i < n; i++) {
                A += a[i], B += b[i], C += c[i];
 
                if(partitions.size() == 0 && A >= (sum + 2) / 3) {
                    partitions.push_back(i + 1);
                    A = 0, B = 0, C = 0;
                }
                else if(partitions.size() == 1 && B >= (sum + 2) / 3) {
                    partitions.push_back(i + 1);
                    A = 0, B = 0, C = 0;
                }
                else if(partitions.size() == 2 && C >= (sum + 2) / 3) {
                    partitions.push_back(i + 1);
                    A = 0, B = 0, C = 0;
                }
            }
 
            // size is 3
 
            return partitions;
        };
 
        if(solve(a, b, c).size() == 3) {
            vector<int>ans = solve(a, b, c);
            cout << 1 << " " << ans[0] << " " << ans[0] + 1 << " " << ans[1] << " " << ans[1] + 1 << " " << n << "\n";
        }
        else if(solve(a, c, b).size() == 3) {
            vector<int>ans = solve(a, c, b);
            cout << 1 << " " << ans[0] << " " << ans[1] + 1 << " " << n << " " << ans[0] + 1 << " " << ans[1] << "\n";
        }
        else if(solve(b, a, c).size() == 3) {
            vector<int>ans = solve(b, a, c);
            cout << ans[0] + 1 << " " << ans[1] << " " << 1 << " " << ans[0] << " " << ans[1] + 1 << " " << n << "\n";
        }
        else if(solve(b, c, a).size() == 3) {
            vector<int>ans = solve(b, c, a);
            cout << ans[1] + 1 << " " << n << " " << 1 << " " << ans[0] << " " << ans[0] + 1 << " " << ans[1] << "\n";
        }
        else if(solve(c, a, b).size() == 3) {
            vector<int>ans = solve(c, a, b);
            cout << ans[0] + 1 << " " << ans[1] << " " << ans[1] + 1 << " " << n << " " << 1 << " " << ans[0] << "\n";
        }
        else if(solve(c, b, a).size() == 3) {
            vector<int>ans = solve(c, b, a);
            cout << ans[1] + 1 << " " << n << " " << ans[0] + 1 << " " << ans[1] << " " << 1 << " " << ans[0] << "\n";
        }
        else cout << -1 << "\n";
    }
}
