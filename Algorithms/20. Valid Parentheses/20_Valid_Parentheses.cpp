#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (auto c : s) {
            if (c == '(' ||c == '['|| c ==  '{' ) {
                stack.push(c);
            }
            else {
                char peak = stack.top();
                if (stack.empty() || 
                    (peak == '[' && c != ']') || 
                    (peak == '(' && c != ')') || 
                    (peak == '{' && c != '}')) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};
