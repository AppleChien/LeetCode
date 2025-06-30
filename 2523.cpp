class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int cnt=0;
        bool s[right + 1];
        memset(s,0,sizeof s);
        int prime[right+1];

        for(int i=2;i<=right;i++){
            if(!s[i])prime[cnt++]=i;

            for(int j=0;prime[j]<=right/i;j++){
                s[prime[j]*i]=true;

                if(i%prime[j]==0)break;
            }
        }

        int i=-1,j=-1;
        for(int k=0;k<cnt;k++){
            if(prime[k]>=left&&prime[k]<=right){
                if(i==-1)i=k;
                j=k;
            }
        }

        vector<int>ans={-1,-1};
        if(i==j||i==-1)return ans;
        int m=1<<30;
        for(int k=i;k<j;k++){
            int d=prime[k+1]-prime[k];
            if(d<m){
                m=d;
                ans[0]=prime[k];
                ans[1]=prime[k+1];
            }
        }

        return ans;
    }
};
