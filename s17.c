//Q1. Implement a stack-based text editor feature that supports undo/redo operations.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 10
#define SIZE 100
char undoStack[MAX][SIZE];
char redoStack[MAX][SIZE];
int undoTop = -1, redoTop = -1;
char text[SIZE] = "";
/* Push to undo stack */
void pushUndo(char str[]) {
    if (undoTop < MAX - 1) {
        undoTop++;
        strcpy(undoStack[undoTop], str);
    }
}
/* Push to redo stack */
void pushRedo(char str[]) {
    if (redoTop < MAX - 1) {
        redoTop++;
        strcpy(redoStack[redoTop], str);
    }
}
/* Pop from undo stack */
int popUndo(char str[]) {
    if (undoTop >= 0) {
        strcpy(str, undoStack[undoTop]);
        undoTop--;
        return 1;
    }
    return 0;
}
/* Pop from redo stack */
int popRedo(char str[]) {
    if (redoTop >= 0) {
        strcpy(str, redoStack[redoTop]);
        redoTop--;
        return 1;
    }
    return 0;
}
/* Clear redo stack after new edit */
void clearRedo() {
    redoTop = -1;
}
void main() {
    int choice;
    char newText[SIZE];
    clrscr();
    while (1) {
        printf("\n--- Stack Based Text Editor ---\n");
        printf("Current Text: \"%s\"\n", text);
        printf("1. Edit Text\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                pushUndo(text);   /* Save current state */
                clearRedo();      /* Clear redo after edit */
                printf("Enter new text: ");
                scanf("%s", newText);
                strcpy(text, newText);
                break;
            case 2:
                if (popUndo(newText)) {
                    pushRedo(text);
                    strcpy(text, newText);
                    printf("Undo successful.\n");
                } else {
                    printf("Nothing to undo.\n");
                }
                break;
            case 3:
                if (popRedo(newText)) {
                    pushUndo(text);
                    strcpy(text, newText);
                    printf("Redo successful.\n");
                } else {
                    printf("Nothing to redo.\n");
                }
                break;
            case 4:
                getch();
                return;
            default:
                printf("Invalid choice!\n");
        }}}
//Q2. Use the stack ADT to check whether parentheses in an arithmetic expression are balanced.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50
char stack[MAX];
int top = -1;
/* Push operation */
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}
/* Pop operation */
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}
void main() {
    char exp[MAX];
    int i, flag = 1;
    clrscr();
    printf("Enter expression: ");
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push('(');
        } else if (exp[i] == ')') {
            if (top == -1) {
                flag = 0;
                break;
            }
            pop();
        }}
    if (top != -1)
        flag = 0;
    if (flag)
        printf("Parentheses are BALANCED\n");
    else
        printf("Parentheses are NOT BALANCED\n");
    getch();}

