// B. Corner Twist
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two grids of numbers a
//  and b
// , with n
//  rows and m
//  columns. All the values in the grid are 0
// , 1
//  or 2
// .

// You can perform the following operation on a
//  any number of times:

// Pick any subrectangle in the grid with length and width ≥2
// . You are allowed to choose the entire grid as a subrectangle.
// The subrectangle has four corners. Take any pair of diagonally opposite corners of the chosen subrectangle and add 1
//  to their values modulo 3
// .
// For the pair of corners not picked, add 2
//  to their values modulo 3
// .
// Note that the operation only changes the values of the corners of the picked subrectangle.

// Is it possible to convert the grid a
//  into grid b
//  by applying the above operation any number of times (possibly zero)?

// Input
// The first line contains an integer t
// , the number of testcases (1≤t≤250
// ).

// For each testcase:

// The first line contains two integers n
//  and m
// , the number of rows and columns in the grid (2≤n,m≤500
// ).

// Each of the next n lines contain m characters — the j
// -th character of the i
// -th line represents ai,j
// .

// Each of the next n lines contain m characters — the j
// -th character of the i
// -th line represents bi,j
//  (0≤ai,j,bi,j≤2
// ).

// It is guaranteed that the sum of n
//  over all test cases and the sum of m
//  over all test cases do not exceed 500
// .

// Output
// For each test case print "YES" (without quotes) if it is possible to convert grid a
//  into grid b
//  and "NO" (without quotes) otherwise.

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// InputCopy
// 7
// 3 3
// 000
// 000
// 000
// 111
// 111
// 111
// 4 4
// 0000
// 0000
// 0000
// 0000
// 2100
// 1200
// 0012
// 0021
// 4 4
// 1020
// 1200
// 1210
// 0000
// 0000
// 1200
// 2200
// 0000
// 3 3
// 012
// 012
// 012
// 010
// 111
// 011
// 8 8
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 10000000
// 00000000
// 01200000
// 02010000
// 00102000
// 00020100
// 00001020
// 00000210
// 10000000
// 2 7
// 0000000
// 0000000
// 2220111
// 0111222
// 2 7
// 0000000
// 0100010
// 2220111
// 1210202
// OutputCopy
// YES
// YES
// YES
// NO
// YES
// NO
// YES
// Note
// In the first testcase, grid a
//  can be converted into b
//  in the following manner:

// 000000000⇒102000201⇒102012222⇒111000222⇒111102120⇒111111111
// Here, in each operation, the top-right and bottom-left corners highlighted by a box are incremented by 2
//  modulo 3
// , while the top-left and bottom-right corners are incremented by 1
//  modulo 3
// .

// In the fourth testcase, it can be proven that it is not possible to convert grid a
//  into grid b
//  using the above-mentioned operations any number of times.

