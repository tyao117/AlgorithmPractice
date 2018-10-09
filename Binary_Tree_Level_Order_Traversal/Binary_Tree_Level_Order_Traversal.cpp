/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> >  result;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            auto l = q.size();
            vector<int> tmp;
            for (int i = 0; i < l; ++i)
            {
                TreeNode *t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
