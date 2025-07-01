class Solution {
public:
    int possibleStringCount(string word) {
        int w=1;
        for(int i=1;i<word.size();i++){
            w+=word[i]==word[i-1];
        }
        return w;
    }
};
