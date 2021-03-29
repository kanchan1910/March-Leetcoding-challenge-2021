
class Solution {
public:
    int i = 0;
    bool dfs(TreeNode* root , vector<int>& voyage, vector<int>& ans)
    {
        if(root == NULL)
        {
            return true;
        }
        // if root node is not matching then the expected preorder traversal can't be created
        if(root->val != voyage[i])
        {
            return false;
        }
        else
        {
            i++;
        }
        // this is the case when flipping is done
        if(root->left != NULL && root->left->val != voyage[i])
        {
            ans.push_back(root->val);
            return dfs(root->right, voyage, ans) && dfs(root->left, voyage, ans);
        }
        else
        {// this is the case when no flipping is done and normal dfs is applied
            return dfs(root->left, voyage, ans) && dfs(root->right, voyage, ans);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
    {
        vector<int>ans;
        if(dfs(root, voyage, ans) == true)
        {
            return ans;
        }
        return {-1};
    }
};
// tc o(n)

// sc o(logn) (resursion stac till height of binary tree)
