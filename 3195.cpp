class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int x1=m,y1=n,x2=0,y2=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    x1=min(i,x1);
                    y1=min(j,y1);
                    x2=max(i,x2);
                    y2=max(j,y2);
                }    
            }
        }

        return (x2-x1+1)*(y2-y1+1);
    }
};
