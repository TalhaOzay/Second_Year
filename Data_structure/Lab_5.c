#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

char pop(struct Stack* stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}

char peek(struct Stack* stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top];
    } else {
        return '\0';
    }
}

void check_parentheses(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    struct Stack stack;
    initStack(&stack);

    int line_number = 1;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (is_empty(&stack)) {
                printf("Error: Extra closing parenthesis '%c' at line %d\n", ch, line_number);
            } else {
                char top = pop(&stack);
                if (!((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}'))) {
                    printf("Error: Mismatched parenthesis at line %d\n", line_number);
                }
            }
        } else if (ch == '\n') {
            line_number++;
        }
    }

    while (!is_empty(&stack)) {
        char top = pop(&stack);
        printf("Error: Unclosed parenthesis '%c' at the end of file\n", top);
    }

    fclose(file);
}

int main() {
    const char* file_path = "example_code.txt";  // Your file path here
    check_parentheses(file_path);

    return 0;
}
