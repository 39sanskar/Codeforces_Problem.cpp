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



