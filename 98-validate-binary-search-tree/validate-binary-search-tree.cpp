class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

private:
    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;

        // Check current node's value against the valid range
        if ((minNode && node->val <= minNode->val) || 
            (maxNode && node->val >= maxNode->val)) {
            return false;
        }

        // Recursively validate left and right subtrees
        return validate(node->left, minNode, node) && 
               validate(node->right, node, maxNode);
    }
};