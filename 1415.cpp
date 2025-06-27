class Solution {
public:
    vector<string>ans;

    void dfs(string str,int n){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }

        for(int c='a';c<='c';c++){
            if(str.size()&&str.back()==c)continue;
            str.push_back(c);
            dfs(str,n);
            str.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        dfs("",n);
        return ans.size()<k?"":ans[k-1];
    }
};
