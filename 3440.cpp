class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const auto &topk=[&](int k){
            vector<pair<int,int>>topk(k,pair(numeric_limits<int>::min(),numeric_limits<int>::min()));
            for(int i=0;i<size(startTime);i++){
                auto x=pair(startTime[i]-endTime[i],endTime[i]);
                for(auto &y:topk){
                    if(x>y)swap(x,y);
                }
            }

            return topk;
        };

        startTime.emplace_back(eventTime);
        endTime.emplace(begin(endTime),0);

        const auto &top3=topk(3);
        int ans=0;

        for(int i=0,current=0;i+1<size(startTime);i++){
            int l=0;
            
            for(const auto &[mx,e]:top3){
                if(e!=endTime[i]&&e!=endTime[i+1]&&endTime[i+1]-startTime[i]<=mx){
                    l=endTime[i+1]-startTime[i];
                    break;
                }
            }

            ans=max(ans,(startTime[i]-endTime[i])+startTime[i+1]-endTime[i+1]+l);
        }

        return ans;
    }
};
