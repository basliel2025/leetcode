#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//SUM OF NODES WITH EVEN VALUED GRANDPARENTS
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }

private:
    int dfs(TreeNode* node, TreeNode* parent, TreeNode* grandparent) {
        if (!node){ return 0;}
        int sum = 0;
        if (grandparent && (grandparent->val % 2 == 0)) {
            sum += node->val;
        }
        sum += dfs(node->left, node, parent);
        sum += dfs(node->right, node, parent);
        return sum;

    }
};
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.