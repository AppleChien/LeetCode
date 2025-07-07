class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int,vector<int>>day;
        int i=INT_MAX,j=0;
        for(auto& e:events){
            int start=e[0],end=e[1];
            day[start].push_back(end);
            i=min(i,start);
            j=max(j,end);
        }

        priority_queue<int,vector<int>,greater<int>>q;
        int ans=0;

        for(int s=i;s<=j;s++){
            while(q.size()&&q.top()<s)q.pop();

            for(int d:day[s])q.push(d);

            if(q.size()){
                ++ans;
                q.pop();
            }
        }
        return ans;
    }
};
