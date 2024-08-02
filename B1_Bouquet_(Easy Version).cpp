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

