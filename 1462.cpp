class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bool f[numCourses][numCourses];
        memset(f,false,sizeof(f));
        for(auto&p:prerequisites){
            f[p[0]][p[1]]=true;
        }

        for(int k=0;k<numCourses;k++){
            for(int i=0;i<numCourses;i++){
                for(int j=0;j<numCourses;j++){
                    f[i][j]|=(f[i][k]&&f[k][j]);
                }
            }
        }

        vector<bool>ans;
        for(auto&q:queries){
            ans.push_back(f[q[0]][q[1]]);
        }

        return ans;
    }
};
