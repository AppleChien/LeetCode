class Solution {
public:
    int maxScore(string s) {
        int ans=0;
        for(int i=1;i<s.size();i++){
            int t=0;
            for(int j=0;j<i;j++)t+=s[j]=='0';
            for(int j=i;j<s.size();j++)t+=s[j]=='1';

            ans=max(ans,t);
        }
        return ans;
    }
};
