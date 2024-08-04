/*
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

Solution:递归判断
*/
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
    bool judge(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr&&subRoot==nullptr){
            return true;
        }
        if((root==nullptr&&subRoot!=nullptr)||(root!=nullptr&&subRoot==nullptr)||(root->val!=subRoot->val)){
            return false;
        }
        return judge(root->left,subRoot->left)&&judge(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        return judge(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};