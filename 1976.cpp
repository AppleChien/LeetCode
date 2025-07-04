typedef long long ll;

class Solution {
public:
    const ll INF=LLONG_MAX/2;
    const int MOD=1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<ll>>g(n,vector<ll>(n,INF));
        vector<ll>dist(n,INF);
        vector<ll>w(n);
        vector<bool>visit(n);

        for(auto &r:roads){
            int u=r[0],v=r[1],t=r[2];
            g[u][v]=t;
            g[v][u]=t;
        }
        g[0][0]=0;
        dist[0]=0;
        w[0]=1;

        for(int i=0;i<n;i++){
            int t=-1;
            for(int j=0;j<n;j++){
                if(!visit[j]&&(t==-1||dist[t]>dist[j]))t=j;
            }
            visit[t]=true;

            for(int j=0;j<n;j++){
                if(t==j)continue;
                ll neww=dist[t]+g[t][j];
                if(dist[j]>neww){
                    dist[j]=neww;
                    w[j]=w[t];
                }
                else if(dist[j]==neww)w[j]=(w[j]+w[t])%MOD;
            }
        }
        return w[n-1];
    }
};
