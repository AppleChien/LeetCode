class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans=LONG_MAX;
        int n=grid[0].size();
        long long s1=0,s2=0;
        for(int &v:grid[0])s1+=v;

        for(int i=0;i<n;i++){
            s1-=grid[0][i];
            ans=min(ans,max(s1,s2));
            s2+=grid[1][j];
        }
    }
};
