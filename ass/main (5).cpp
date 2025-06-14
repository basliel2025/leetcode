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
//SUM ROOT TO LEAF NUMBERS
class Solution {
 void sumNumbers(TreeNode* root, int& total_sum, int curr_sum, int num_negatives) {
         if (root == nullptr)
             return;
         curr_sum = (curr_sum * 10) + abs(root->val);
       if (root->val < 0)
           num_negatives++;
      if (root->left == nullptr && root->right == nullptr) {
            int sign = num_negatives % 2 == 1 ? -1 : 1;
             total_sum += curr_sum * sign;
            return;
         }
     sumNumbers(root->left, total_sum, curr_sum, num_negatives);
        sumNumbers(root->right, total_sum, curr_sum, num_negatives);
  }
public:
    int sumNumbers(TreeNode* root) {
       int total_sum = 0;
        int curr_sum = 0;
       int num_negatives = 0;
         sumNumbers(root, total_sum, curr_sum, num_negatives);
        return total_sum;
   }
};
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.