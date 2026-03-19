// Write a recursive function int index_of(string s, string t) that returns
// the starting position of the first substring of s that matches t.
//
// Rules and Specifications:
// 1) Use recursion to search for the first occurrence of t inside s.
// 2) If the beginning of s matches t, return the current starting position.
// 3) Otherwise, remove the first character of s and continue searching in the
//    remaining substring.
// 4) Keep track of how far the current substring is from the beginning of s.
// 5) Use a helper function parameter to store the current index.
// 6) If t does not occur in s, return -1.
//
// Example:
// int n = s.index_of("Mississippi!", "sip");  // Returns 6
