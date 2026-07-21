constexpr int N = 1e5 + 1;
int segment[N] = {0};

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        char prev = '@';
        int count = 0, active = 0, j=0;
        for(char& c:s){
            active += c =='1';
            j += (prev != c && c == '0');
            segment[j] += c == '0';
            prev = c;
        }
        int adj = 0;
        for(int i=1;i<j;i++){
            adj = max(adj,segment[i]+segment[i+1]);
        }
        memset(segment,0,(j+1)*sizeof(int));
        return adj + active;
    }
};