
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
     vector<double>ans;
        if(root == NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            long long sum = 0;
            for(int i = 0 ; i < n ; i++)
            {
                TreeNode* front = q.front();
                sum += front->val;
                q.pop();
                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            ans.push_back(sum * 1.0/ n);
        }
        return ans;
    }
};
// tc o(n)
// sc o(n)
