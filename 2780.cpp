class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x=0,cnt=0;
        unordered_map<int,int>freq;
        for(int n:nums){
            ++freq[n];
            if(freq[n]>cnt){
                cnt=freq[n];
                x=n;
            }
        }

        int current=0;
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]==x){
                ++current;
                if(current*2>i&&(cnt-current)*2>nums.size()-i)return i-1;
            }
        }
        return -1;       
    }
};
