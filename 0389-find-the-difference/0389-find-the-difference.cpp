class Solution {
public:
    char findTheDifference(string s, string t) {
        char remainingElement = 0;
        
        for(char c : s){
            remainingElement ^= c;
        }
        for(char c : t){
            remainingElement ^= c;
        }
        
        return remainingElement;
    }
};