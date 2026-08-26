class Solution {
public:
    int maxsum;
    int solve(TreeNode* root){
        if(root == NULL){
        return 0;
        }

        int left_side_se = solve(root->left);
        int right_side_se = solve(root->right);

        maxsum=max(maxsum ,  left_side_se + right_side_se + root->val);

        int mx= max( right_side_se  ,left_side_se);

        int abhi_tak_max= max(root->val , root->val + mx);

         maxsum=max(maxsum ,  abhi_tak_max);

        return  abhi_tak_max;
        
        
        
    }

    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum; 
    }
};