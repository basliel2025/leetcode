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
class Solution {
private:
    TreeNode* myFirst;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* myLast;
private:
    void inorder(TreeNode* root) {
        if (root==NULL) return;
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val)) {
            if (myFirst==NULL) {
                myFirst=prev;
                middle=root;
            }
            else  myLast=root;
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        myFirst= middle=myLast=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if (myFirst&&myLast) swap(myFirst->val,myLast->val);
    }
};
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.