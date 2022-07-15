#include <iostream>
#include <stack>

using namespace std;

/* 
Problem Description:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
*/

class Solution {
public:
    char getOpposite(char c) {
        switch(c) {
            case ')' : 
                return '(';
            case ']' :
                return '[';
            case '}' : 
                return '{';
        }
        return '0';
    }
    
    bool isValid(string s) { 
        stack<char> myStack;
        int len = s.size();
        char curr;
        char first = s[0];
        
        if (len <= 1 || first == ')' || first == ']' || first == '}') 
            return false;
        
        for (auto i : s) {
            
            if (i == '(' || i == '[' || i == '{' ) {
                myStack.push(i);
            }
            
            else {
                if (myStack.empty()) {
                    return false;
                }
                
                char opp = getOpposite(i);
                if (myStack.top() == opp) {
                    myStack.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        return myStack.empty();
    }
};