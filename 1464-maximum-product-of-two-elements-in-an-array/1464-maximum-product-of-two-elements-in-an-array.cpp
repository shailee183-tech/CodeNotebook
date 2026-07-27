class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0;
        int j = 0;
        for(int num:nums){
            if(num > i){
                j = i;
                i = num;
            } else if (num > j){
                j = num;
            }
        }
        return (i-1)*(j-1);
    }
};