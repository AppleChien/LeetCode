class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>ban(banned.begin(),banned.end());
        int ans=0,sum=0;
        for(int i=1;i<=n&&sum+i<=maxSum;i++){
            if(!ban.count(i)){
                ++ans;
                sum+=i;
            }
        }

        return ans;
    }
};
