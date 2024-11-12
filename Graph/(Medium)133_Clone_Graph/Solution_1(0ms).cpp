#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
class Node
{
  public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution
{
  public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        queue<Node *> node_queue;
        unordered_map<int, Node *> node_visit;
        Node *first_node = new Node(node->val);
        node_visit[first_node->val] = first_node;
        node_queue.push(node);
        // * BFS
        while (node_queue.size() > 0)
        {
            Node *current_node = node_queue.front();
            Node *clone_node = node_visit[current_node->val];
            for (auto neightbor : current_node->neighbors)
            {
                Node *clone_neighbor;
                auto iter = node_visit.find(neightbor->val);
                if (iter != node_visit.end())
                    clone_neighbor = (*iter).second;
                else
                {
                    clone_neighbor = new Node(neightbor->val);
                    node_visit[neightbor->val] = clone_neighbor;
                    node_queue.push(neightbor);
                }
                clone_node->neighbors.push_back(clone_neighbor);
            }
            node_queue.pop();
        }
        return first_node;
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> edges = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
    // ! test this question on leetcode
    // Node *output = solution.cloneGraph(edges);
    // cout << output << endl;
}