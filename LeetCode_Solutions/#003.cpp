// #003
//
// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<string>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> dict(256,-1);
    int start=-1,len=0;
    for(int i=0; i<s.length(); i++){
        if(dict[s[i]]>start) start = dict[s[i]];
        dict[s[i]] = i;
        len = max(len, i-start);
    }
    return len;
    }
};
