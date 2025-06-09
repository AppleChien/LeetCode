class Solution {
public:

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> arr(26);
        iota(begin(arr), end(arr), 0);
        function<int(int)> find = [&](int x) {
            return arr[x] == x ? x : arr[x] = find(arr[x]);
        };
        for (int i = 0; i < s1.length(); ++i) {
            int r1 = find(s1[i] - 'a');
            int r2 = find(s2[i] - 'a');
            if (r2 < r1) swap(r1, r2);
            arr[r2] = r1;
        }
    
        string ans(baseStr);
        for (int i = 0; i < baseStr.length(); ++i) {
            ans[i] = find(baseStr[i] - 'a') + 'a';
        }
        return ans;
  
    }  
    
};
