class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(int &n:nums2)++cnt[n];
    }
    
    void add(int index, int val) {
        int old=nums2[index];
        --cnt[old];
        ++cnt[old+val];
        nums2[index]+=val;
    }
    
    int count(int tot) {
        int ans=0;
        for(int &n:nums1)ans+=cnt[tot-n];

        return ans;
    }

private:
    vector<int>nums1;
    vector<int>nums2;
    unordered_map<int,int>cnt;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
