class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n);
        vector<int>cnta(n+1),cntb(n+1);

        for(int i=0;i<n;i++){
            cnta[A[i]]++;
            cntb[B[i]]++;

            for(int j=1;j<=n;j++){
                ans[i]+=min(cnta[j],cntb[j]);
            }
        }
        return ans;
    }
};
