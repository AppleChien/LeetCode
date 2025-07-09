class Solution {
public:
    int countLargestGroup(int n) {
        int cnt[40]{};
        int ans=0,mx=0;
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=i;j;j/=10)sum+=j%10;

            ++cnt[sum];

            if(mx<cnt[sum]){
                mx=cnt[sum];
                ans=1;
            }
            else if(mx==cnt[sum])++ans;

        }
        
        return ans;
    }
};
