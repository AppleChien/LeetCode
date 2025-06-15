class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        const auto& check=[&](int x){
            int cnt=0;
            for(int i=0;i+1<size(nums)&&cnt<p;i++){
                if(nums[i+1]-nums[i]<=x){
                    i++;
                    cnt++;
                }
            }
            return cnt==p;
        };

        sort(begin(nums),end(nums));
        int l=0,r=nums.back()-nums.front();
        while(l<=r){
            const int m=l+(r-l)/2;
            if(check(m)){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};
