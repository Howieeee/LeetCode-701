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
public:
    TreeNode* search_pos(TreeNode* prev, TreeNode* node, bool& found, int val){
        if(node == NULL){
            TreeNode* it;
            if(val < prev->val){//在left tree
                prev->left = new TreeNode(val);
                it = prev->left;
            }
            else{
                prev->right = new TreeNode(val);
                it = prev->right;
            }
            return it;
        }
        
        if(val > node->val)
            return search_pos(node,node->right,found,val);
        else if(val < node->val)
            return search_pos(node,node->left,found,val);
        
        
        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto ptr = root;
        
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        
        bool found = false;
        TreeNode* pos ;
        pos = search_pos(root,root,found,val);
        
        return root;
    }
};
