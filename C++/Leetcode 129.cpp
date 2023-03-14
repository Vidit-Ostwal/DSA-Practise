#include <stdio.h>
#include <bits/stdc++.h>
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
    int Helper(TreeNode* root,string temp)
    {
        if (root->left == NULL && root -> right == NULL)
        {
            // Leaf Node
            return stoi(temp + to_string(root -> val));
        }

        int total_value = 0;

        if (root -> left != NULL)
        {
            total_value += Helper(root -> left, temp + to_string(root -> val));
        }

        if (root -> right != NULL)
        {
            total_value += Helper(root -> right, temp + to_string(root -> val));
        }
        return total_value;
    }
public:
    int sumNumbers(TreeNode* root) {
        return Helper(root,"");
    }
};