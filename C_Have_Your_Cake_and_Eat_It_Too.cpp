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

