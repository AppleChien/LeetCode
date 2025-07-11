class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>cnt;
        for(int a:answers)++cnt[a];

        int ans=0;
        for(auto&[x,v]:cnt){
            int group=x+1;
            ans+=(v+group-1)/group*group;
        }
        return ans;
    }
};
