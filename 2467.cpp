class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>>g(n);
        for(auto &e:edges){
            int a=e[0],b=e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }

        vector<int>test(n,n);
        function<bool(int i,int f,int t)>dfs1=[&](int i,int f,int t)->bool{
            if(i==0){
                test[i]=t;
                return true;
            }

            for(int j:g[i]){
                if(j!=f&&dfs1(j,i,t+1)){
                    test[j]=min(test[j],t+1);
                    return true;
                }
            }
            return false;
        };
        dfs1(bob,-1,0);
        test[bob]=0;
        
        int ans=INT_MIN;
        function<void(int i,int f,int t,int v)>dfs2=[&](int i,int f,int t,int v){
            if(t==test[i])v+=amount[i]>>1;
            else if(t<test[i])v+=amount[i];

            if(g[i].size()==1&&g[i][0]==f){
                ans=max(ans,v);
                return;
            }

            for(int j:g[i]){
                if(j!=f)dfs2(j,i,t+1,v);
            }
        };

        
        dfs2(0,-1,0,0);
        return ans;
    }
};
