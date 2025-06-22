class Solution {
public:
    int maxDistance(string s, int k) {
        auto cal=[&](int a,int b){
            int ans=0,mx=0,cnt=0;
            for(char c:s){
                if(c==a||c==b){
                    mx++;
                }
                else if(cnt<k){
                    mx++;
                    cnt++;
                }
                else{
                    mx--;
                }
                ans=max(mx,ans);
            }
            return ans;
        };

        int a=cal('S','E');
        int b=cal('S','W');
        int c=cal('N','E');
        int d=cal('N','W');

        return max({a,b,c,d});
    }
};
