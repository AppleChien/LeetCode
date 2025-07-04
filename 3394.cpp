class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        const auto &check=[&](int idx){
            int cnt=0;
            int current=rectangles[0][idx+2];

            for(const auto &r:rectangles){
                cnt+=current<=r[idx]?1:0;
                current=max(current,r[idx+2]);
            }
            return cnt>=2;
        };

        for(int i=0;i<2;i++){
            sort(begin(rectangles),end(rectangles),[&](const auto &a,const auto &b){
                return a[i]<b[i];
            });

            if(check(i))return true;
        }

        return false;
    }
};
