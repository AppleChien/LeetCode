/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> st;
        TreeNode* cur = root, * pre = nullptr;
        int val = 0;
        while (cur || !st.empty()) {
            while (cur) {
                st.push_back(cur);
                val += cur->val;
                cur = cur->left;
            }
            cur = st.back();
            if (!cur->left && !cur->right && val == sum) {
                vector<int> v;
                for (auto& a : st) v.push_back(a->val);
                res.push_back(v);
            }
            if (cur->right && cur->right != pre) {
                cur = cur->right;
            }
            else {
                pre = cur;
                val -= cur->val;
                st.pop_back();
                cur = nullptr;
            }
        }
        return res;
    }
};
