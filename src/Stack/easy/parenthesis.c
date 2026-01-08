/* Valid Parentheses in an Expression
Given a string s containing three types of brackets {}, () and []. Determine whether the Expression are balanced or not.
An expression is balanced if each opening bracket has a corresponding closing bracket of the same type, the pairs are properly ordered and no bracket closes before its matching opening bracket.

Balanced: "[()()]{}" → every opening bracket is closed in the correct order.
Not balanced: "([{]})" → the ']' closes before the matching '{' is closed, breaking the nesting rule.

Example:
Input: s = "[{()}]"
Output: true
Explanation:  All the brackets are well-formed.

Input:  s = "([{]})"
Output: false
Explanation: The expression is not balanced because there is a closing ']' before the closing '}'.

Website: https://www.geeksforgeeks.org/dsa/check-for-balanced-parentheses-in-an-expression/

*/

#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(const char *string);

int main(void) {
    const char *s = "[()()]{}{}";
    printf(isValid(s)?"YEEE!!\n":"NOPE\n");
    return 0;
}

bool isValid(const char *string) {
    Stack stack;
    size_t len = strlen(string);
    stack.len = len;
    if (stack_d_init(&stack, len) != 0) return false;
    for(size_t i = 0; i < len; ++i) {
        char ch = string[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            d_push(&stack, def_char(ch));
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if(d_isEmpty(&stack)) {
                d_free_stack(&stack);
                return false;
            }
            StackValue peekVal = d_peek(&stack);
            char top = peekVal.of.c;
            if((top == '(' && ch != ')') ||
               (top == '{' && ch != '}') ||
               (top == '[' && ch != ']')) {
                d_free_stack(&stack);
                return false;
            }
            d_pop(&stack);
        }
    }
    bool good = d_isEmpty(&stack);
    d_free_stack(&stack);
    return good;
}
