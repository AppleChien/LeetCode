class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[510];
        memset(cnt,0,sizeof(cnt));
        for(int x:arr)++cnt[x];

        int ans=-1;
        for(int i=1;i<510;i++){
            if(cnt[i]==i)ans=i;
        }

        return ans;
    }
};
