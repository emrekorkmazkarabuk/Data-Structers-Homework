#include <stdio.h>
#include <ctype.h>

int prec(char c) { return (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : -1; }

int main() {
    char exp[100], stack[100];
    int top = -1, i = 0;
    printf("Infix: "); scanf("%s", exp);
    while (exp[i]) {
        if (isalnum(exp[i])) printf("%c", exp[i]);
        else if (exp[i] == '(') stack[++top] = exp[i];
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') printf("%c", stack[top--]);
            top--;
        } else {
            while (top != -1 && prec(exp[i]) <= prec(stack[top])) printf("%c", stack[top--]);
            stack[++top] = exp[i];
        }
        i++;
    }
    while (top != -1) printf("%c", stack[top--]);
    return 0;
}
