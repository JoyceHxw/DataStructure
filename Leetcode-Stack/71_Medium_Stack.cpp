#include <iostream>
using namespace std;
#include <vector>

// 字符串的拆分，栈的使用
class Solution {
public:
    string simplifyPath(string path) {
        // 使用lambda函数定义字符串拆分方法
        auto split = [](const string& s, char delim) -> vector<string> { //使用auto关键字声明变量split，编译器会根据Lambda函数的定义推导出适当的类型。
            vector<string> ans;
            string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(move(cur)); //使用move()函数可以将cur的内容移动（move）到结果向量中，而不是进行拷贝操作。移动语义可以避免不必要的拷贝操作，从而提高程序的性能。
                    cur.clear();
                }
                else {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };

        vector<string> names = split(path, '/');
        vector<string> stack;
        for (string& name: names) {
            cout<<name<<endl;
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else if (!name.empty() && name != ".") {
                stack.push_back(move(name));
            }
        }
        string ans;
        if (stack.empty()) {
            ans = "/";
        }
        else {
            for (string& name: stack) {
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    s.simplifyPath("/a/./b/../../c/");
}