// B. Make Three Regions
// time limit per test2 seconds
// memory limit per test256 megabytes
// There is a grid, consisting of 2
//  rows and n
//  columns. Each cell of the grid is either free or blocked.

// A free cell y
//  is reachable from a free cell x
//  if at least one of these conditions holds:

// x
//  and y
//  share a side;
// there exists a free cell z
//  such that z
//  is reachable from x
//  and y
//  is reachable from z
// .
// A connected region is a set of free cells of the grid such that all cells in it are reachable from one another, but adding any other free cell to the set violates this rule.

// For example, consider the following layout, where white cells are free, and dark grey cells are blocked:


// There are 3
//  regions in it, denoted with red, green and blue color respectively:


// The given grid contains at most 1
//  connected region. Your task is to calculate the number of free cells meeting the following constraint:

// if this cell is blocked, the number of connected regions becomes exactly 3
// .
// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of test cases.

// The first line of each test case contains a single integer n
//  (1≤n≤2⋅105
// ) — the number of columns.

// The i
// -th of the next two lines contains a description of the i
// -th row of the grid — the string si
// , consisting of n
//  characters. Each character is either . (denoting a free cell) or x (denoting a blocked cell).

// Additional constraint on the input:

// the given grid contains at most 1
//  connected region;
// the sum of n
//  over all test cases doesn't exceed 2⋅105
// .
// Output
// For each test case, print a single integer — the number of cells such that the number of connected regions becomes 3
//  if this cell is blocked.

// Example
// InputCopy
// 4
// 8
// .......x
// .x.xx...
// 2
// ..
// ..
// 3
// xxx
// xxx
// 9
// ..x.x.x.x
// x.......x
// OutputCopy
// 1
// 0
// 0
// 2
// Note
// In the first test case, if the cell (1,3)
//  is blocked, the number of connected regions becomes 3
//  (as shown in the picture from the statement).
