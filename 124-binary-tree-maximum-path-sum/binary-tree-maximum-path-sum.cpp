#include <climits>
using namespace std;
class Solution {
public:
    int max_sum = INT_MIN;

    int max_gain(TreeNode* node) {
        if (!node) return 0;

        // Maximum gain from left and right subtrees
        int left_gain = max(max_gain(node->left), 0);
        int right_gain = max(max_gain(node->right), 0);

        // Price of the new path
        int price_new_path = node->val + left_gain + right_gain;

        // Update global max_sum if the new path is better
        max_sum = max(max_sum, price_new_path);

        // Return the max gain if the path continues through the parent
        return node->val + max(left_gain, right_gain);
    }

    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};