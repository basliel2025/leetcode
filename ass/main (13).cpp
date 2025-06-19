#include <iostream>
#include <vector>
#include<queue>
#include<set>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    map<TreeNode* , TreeNode*> ancestor;
    queue<TreeNode*> value;
    value.push(root);
    while(value.size()>0){
        TreeNode* main = value.front();
        value.pop();
        if(main->left != nullptr){
            ancestor[main->left] = main;
            value.push(main->left);
        }
        if(main->right != nullptr){
            ancestor[main->right] = main;
            value.push(main->right);
        }
    }
    set<TreeNode* > seen;
    vector<int> output;
    value.push(target);
    seen.insert(target);
    int d = 0;
    while(value.size()>0 && d<k){
        int x =0;
        int s= value.size();
        while(x<s){
            TreeNode* main = value.front();
            value.pop();
            if(main->left != nullptr && !seen.count(main->left)){
                seen.insert(main->left);
                value.push(main->left);
            }
            if(main->right != nullptr && !seen.count(main->right)){
                seen.insert(main->right);
                value.push(main->right);
            }
            if(ancestor.count(main) && !seen.count(ancestor[main])){
                seen.insert(ancestor[main]);
                value.push(ancestor[main]);
            }
            x= x+1;
        }
        d=d+1;
    }
    int v = value.size();
    for(int i=0; i<v;i++){
        TreeNode* hold = value.front();
        value.pop();
        output.push_back(hold->val);
    }
    return output;

};
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.