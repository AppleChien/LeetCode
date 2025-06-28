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
class Solution {
private:
    TreeNode* build(vector<int>&pre,int prebegin,int preend,vector<int>&post,int postbegin,int postend){
        if(prebegin>=preend)return NULL;
        auto node=new TreeNode(pre[prebegin]);

        if(prebegin+1<preend){
            int leftval=pre[prebegin+1];
            int postmid=find(post.begin()+postbegin,post.begin()+postend-1,leftval)-post.begin();
            int postleftlength=postmid-postbegin+1;

            node->left=build(pre,prebegin+1,prebegin+1+postleftlength,post,postbegin,postmid+1);
            node->right=build(pre,prebegin+1+postleftlength,preend,post,postmid+1,postend-1);
        }
        return node;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder,0,preorder.size(),postorder,0,postorder.size());
    }
};
