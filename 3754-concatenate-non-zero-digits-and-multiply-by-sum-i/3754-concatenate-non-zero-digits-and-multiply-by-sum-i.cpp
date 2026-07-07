class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);

        long long x=0;
        long long sum=0;

        for (char c:s){
            int digit = c-'0';
            if (digit !=0){
                x=x*10 + digit;
                sum = sum + digit;
            }
        }
        return x*sum;

    }
};