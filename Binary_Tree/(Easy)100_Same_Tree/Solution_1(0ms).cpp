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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return dfs(p, q);
    }

  private:
    bool dfs(TreeNode *tree1, TreeNode *tree2)
    {
        if (tree1 == nullptr && tree2 == nullptr)
            return true;
        else if (tree1 != nullptr && tree2 != nullptr)
        {
            // * compare the node;
            if (tree1->val != tree2->val)
                return false;
            return dfs(tree1->left, tree2->left) && dfs(tree1->right, tree2->right);
        }
        else
            return false;
    }
};
int main(void)
{
    Solution solution;
    array<const int *, 3> tree = {new int(1), new int(2), new int(3)};
    TreeNode *node_p;
    TreeNode *node_q;
    TreeNode **root_p = &node_p;
    TreeNode **root_q = &node_q;
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

    bfs_queue = queue<TreeNode **>();
    bfs_queue.push(&node_q);
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

    print_queue = queue<TreeNode *>();
    print_queue.push(*root_q);
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

    bool is_same = solution.isSameTree(*root_p, *root_q);
    cout << is_same << endl;
}