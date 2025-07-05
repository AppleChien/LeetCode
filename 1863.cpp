class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<1<<n;i++){//2^n子集
            int sum=0;
            for(int j=0;j<n;j++){
                if(i>>j&1)sum^=nums[j];//看哪位是1
            }
            ans+=sum;
        }

        return ans;
    }
};
