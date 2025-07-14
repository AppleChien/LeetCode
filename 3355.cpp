class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int d[n+1];
        memset(d,0,sizeof(d));

        for(const auto&q:queries){
            int l=q[0],r=q[1];
            ++d[l];
            --d[r+1];
        }
        for(int i=0,sum=0;i<n;i++){
            sum+=d[i];
            if(nums[i]>sum)return false;
        }
        return true;
    }
};
