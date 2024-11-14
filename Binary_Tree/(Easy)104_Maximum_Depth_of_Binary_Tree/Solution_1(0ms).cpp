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
    int maxDepth(TreeNode *root)
    {
        return dfs(root, 0);
    }

  private:
    int dfs(TreeNode *node, int depth) // * ptr can be null
    {
        if (node == nullptr)
            return depth;
        else
            return max(dfs(node->left, depth + 1), dfs(node->right, depth + 1));
    }
};
int main(void)
{
    Solution solution;
    array<const int *, 7> tree = {new int(3), new int(9), new int(20), nullptr, nullptr, new int(15), new int(7)};
    TreeNode *node;
    TreeNode **root = &node;
    queue<TreeNode **> bfs_queue;
    bfs_queue.push(&node);
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
    print_queue.push(*root);
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

    int depth = solution.maxDepth(*root);
    cout << depth << endl;
}