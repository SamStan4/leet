#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:

    bool get_path(TreeNode* cur_ptr, string& path_str, int target)
    {
        if (!cur_ptr) return false;

        if (cur_ptr->val == target) return true;

        path_str.push_back('L');

        if (this->get_path(cur_ptr->left, path_str, target))
        {
            return true;
        }

        path_str.back() = ('R');

        if (this->get_path(cur_ptr->right, path_str, target))
        {
            return true;
        }

        path_str.pop_back();

        return false;
    }


public:
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        string start_path, dest_path, directions;
        int n = 0, i = 0;

        this->get_path(root, start_path, startValue);
        this->get_path(root, dest_path, destValue);

        n = min((int)(start_path.size()), (int)(dest_path.size()));

        for (; (i < n) && (start_path[i] == dest_path[i]); ++i);

        n = start_path.size();

        for (int j = i; j < n; ++j)
        {
            directions.push_back('U');
        }

        n = dest_path.size();

        for (int j = i; j < n; ++j)
        {
            directions.push_back(dest_path[j]);
        }

        return directions;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();