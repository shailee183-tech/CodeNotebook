class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while (n != 1 && s.find(n) == s.end()) {
            s.insert(n);

            int sum = 0;

            while(n>0){
                int d= n%10;
                sum += d*d;
                n = n/10;
            }
            n = sum;
        }
        return n==1;
    }
};