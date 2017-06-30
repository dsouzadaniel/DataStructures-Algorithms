// #007 
//
// Reverse digits of an integer.
//
// Example1: x = 123, return 321
// Example2: x = -123, return -321


class Solution {
public:
    int reverse(int x) {
    long long ans=0;
    while(x){
        ans = ans*10+x%10;
        x=x/10;
    }
    return (ans< INT_MIN || ans>INT_MAX)?0:ans;
        }
};
