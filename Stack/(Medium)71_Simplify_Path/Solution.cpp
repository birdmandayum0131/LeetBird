#include <stack>
#include <iostream>
class Solution
{
public:
    std::string simplifyPath(std::string path)
    {
        //* stack to store directory hierarchy
        std::stack<std::string> dirStack;

        //* extract path into stack
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/') //* ignore all slash in the path (one or consecutive)
                continue;
            std::string tmp;
            //* extract one dir name to temp
            while (i < path.size() && path[i] != '/')
            {
                tmp += path[i];
                i++;
            }
            //* Deal with "." or ".." (ignore three or more)
            if (tmp == ".")
                continue;
            else if (tmp == "..")
            {
                if (!dirStack.empty())
                    dirStack.pop();
            }
            else
                dirStack.push(tmp);
        }

        //* form result from stack
        if (dirStack.empty())
            return "/";

        std::string result;
        while (!dirStack.empty())
        {
            result = "/" + dirStack.top() + result;
            dirStack.pop();
        }
        return result;
    }
};
int main(void)
{
    Solution solution;
    std::string path = "/../";
    std::string result = solution.simplifyPath(path);
    std::cout << result << std::endl;
}