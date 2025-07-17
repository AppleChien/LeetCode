class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int cnt[26]={0};
        int t[26];
        for(auto &w:words2){
            memset(t,0,sizeof(t));
            for(auto &c:w)t[c-'a']++;

            for(int i=0;i<26;i++){
                cnt[i]=max(cnt[i],t[i]);
            }
        }

        vector<string>ans;
        for(auto &w:words1){
            memset(t,0,sizeof(t));
            for(auto &c:w)t[c-'a']++;

            bool ok=true;
            for(int i=0;i<26;i++){
                if(cnt[i]>t[i]){
                    ok=false;
                    break;
                }
                
            }
            if(ok)ans.emplace_back(w);
        }

        return ans;
    }
};
