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
#define pni pair<TreeNode*,int>
    pni  myLCA(TreeNode * current){
        if (!current) return make_pair(nullptr,0);
        pni left = myLCA(current->left);
        pni right = myLCA(current->right);
        if (left.second==right.second) return make_pair(current,1+left.second);
        else if (left.second>right.second) return make_pair(left.first,1+left.second);
        return make_pair(right.first,1+right.second);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pni result=myLCA(root);
        return result.first;
    }
};


// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.