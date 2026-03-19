// Write a recursive function bool find(string s, string t) that tests
// whether the string t is contained in the string s.
//
// Rules and Specifications:
// 1) Use recursion to determine whether t appears anywhere inside s.
// 2) If the beginning of s matches t, return true.
// 3) Otherwise, remove the first character of s and try again on the
//    remaining substring.
// 4) If there are no characters left in s that can begin a match, return false.
// 5) The function should return true if t is a substring of s, and false
//    otherwise.
//
// Example:
// bool b = s.find("Mississippi!", "sip");  // Returns true
