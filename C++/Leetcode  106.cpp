#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* Helper(vector<int>& Inor, vector<int>& Post, int st1, int ed1, int st2, int ed2)
    {
        if (st1 == ed1 || st2 == ed2)
        {
            return new TreeNode(Inor[st1]);
        }

        if (st1 > ed1 || st2 >  ed2)
        {
            return NULL;
        }

        int root_value = Post[ed2];
        int index = find(Inor.begin(),Inor.end(),root_value) - Inor.begin();

        TreeNode* Root = new TreeNode(root_value);
        int left_length = index - 1 - st1;
        Root -> left = Helper(Inor, Post, st1, index-1, st2 , st2 + left_length);
        Root -> right = Helper(Inor, Post, index + 1, ed1, st2 + left_length + 1, ed2 - 1);
        return Root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Helper(inorder, postorder, 0, inorder.size()-1, 0 , postorder.size()-1);
    }
};