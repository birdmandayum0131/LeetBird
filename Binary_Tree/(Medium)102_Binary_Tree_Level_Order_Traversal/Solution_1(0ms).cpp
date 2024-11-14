#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // * sovle it with bfs (dfs also work)
        vector<vector<int>> traversal;
        queue<tuple<TreeNode *, int>> node_queue; // * (node, level)
        node_queue.push({root, 0});
        while (node_queue.size() > 0)
        {
            TreeNode *node;
            int level;
            tie(node, level) = node_queue.front();
            if (node != nullptr)
            {
                // * check level exist
                if (traversal.size() < level + 1) // * level not exist
                    traversal.push_back(vector<int>());
                traversal[level].push_back(node->val);
                node_queue.push({node->left, level + 1}); // * left first is required
                node_queue.push({node->right, level + 1});
            }
            node_queue.pop();
        }
        return traversal;
    }
};
int main(void)
{
    Solution solution;
    array<const int *, 7> tree = {new int(3), new int(9), new int(20), nullptr, nullptr, new int(15), new int(17)};
    TreeNode *node_p;
    TreeNode **root_p = &node_p;
    queue<TreeNode **> bfs_queue;
    bfs_queue.push(&node_p);
    for (auto tree_node : tree)
    {
        TreeNode **target = bfs_queue.front();
        if (tree_node != nullptr)
        {
            *target = new TreeNode(*tree_node);
            bfs_queue.push(&((*target)->left));
            bfs_queue.push(&((*target)->right));
        }
        bfs_queue.pop();
    }
    queue<TreeNode *> print_queue;
    print_queue.push(*root_p);
    cout << "[";
    while (print_queue.size() > 0)
    {
        TreeNode *iter = print_queue.front();
        if (iter == nullptr)
            cout << "null, ";
        else
        {
            cout << iter->val << ", ";
            print_queue.push(iter->left);
            print_queue.push(iter->right);
        }
        print_queue.pop();
    }
    cout << "\b\b]" << endl;

    vector<vector<int>> traversal = solution.levelOrder(*root_p);
    cout << "[";
    for (auto row : traversal)
    {
        cout << "[";
        for (auto col : row)
            cout << col << ", ";
        cout << "\b\b], ";
    }
    cout << "\b\b]";
}