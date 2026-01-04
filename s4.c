#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define SIZE 100
#define MAX_TEXT 100
typedef struct
{
char items[SIZE][MAX_TEXT];
int top;
} Stack;
void initstack(Stack *s)
{
s->top = -1;
}
int isfull(Stack *s)
{
return s->top == SIZE - 1;
}
int isempty(Stack *s)
{
return s->top == -1;
}
void push(Stack *s, const char *text)
{
if (isfull(s))
{
printf("Stack is full\n");
return;
}
strcpy(s->items[++(s->top)], text);
}
int *pop(Stack *s)
{
if (isempty(s))
{
printf("Stack is empty\n");
return ;
}
return s->items[(s->top)--];
}
int peek(Stack *s)
{
if (isempty(s))
{
printf("Stack is empty\n");
return -1;
}
return s->items[s->top];
}
int main()
{
Stack undoStack, redoStack;
char currentText[MAX_TEXT] = "";
char input[MAX_TEXT];
int choice;
initstack(&undoStack);
initstack(&redoStack);
while (1)
{
printf("\nCurrent Text: %s\n", currentText);
printf("1. Type Text\n2. Undo\n3. Redo\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
getchar(); // to consume newline character
switch (choice)
{
case 1:
push(&undoStack, currentText);
initstack(&redoStack); // Clear redo stack
printf("Enter text to append: ");
fgets(input, MAX_TEXT, stdin);
input[strcspn(input, "\n")] = 0; // Remove newline character
strcat(currentText, input);
break;
case 2:{
if (isempty(&undoStack))
{
printf("Nothing to undo\n");
}
else
{
push(&redoStack, currentText);
strcpy(currentText, pop(&undoStack));
}
break;
}
case 3:
if (isempty(&redoStack))
{
printf("Nothing to redo\n");
}
else
{
push(&undoStack, currentText);
strcpy(currentText, pop(&redoStack));
}
break;
case 4:
exit(0);
default:
printf("Invalid choice\n");
}
}
getch();
return 0;
}


// 2
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 100
typedef struct
{
char items[MAX];
int top;
} Stack;
void initstack(Stack *s)
{
s->top = -1;
}
int isfull(Stack *s)
{
return s->top == MAX - 1;
}
int isempty(Stack *s)
{
return s->top == -1;
}
void push(Stack *s, char c)
{
if (isfull(s ))
{
printf("Stack is full\n");
return;
}
s->items[++(s->top)] = c;
}
char pop(Stack *s)
{
if (isempty(s))
{
printf("Stack is empty\n");
return NULL;
}
return s->items[(s->top)--];
}
int matching(char open, char close)
{
return (open == '(' && close == ')') ||
(open == '{' && close == '}') ||
(open == '[' && close == ']');
}
int balanced(const char *expr)
{
Stack s;
int i;
char popped;
initstack(&s);
for ( i = 0; expr[i] != '\0'; i++)
{
char c = expr[i];
if (c == '(' || c == '{' || c == '[')
{
push(&s, c);
}
else if (c == ')' || c == '}' || c == ']')
{
if (isempty(&s) )
{
return 0; // Not balanced
}
popped = pop(&s);
if (!matching(popped, c))
{
return 0; // Not balanced
}
}
}
return isempty(&s); // Balanced if stack is empty
}
int main()
{
char expr[MAX];
printf("Enter an arithmetic expression: ");
scanf("%s", expr);
// Remove newline character if present
if (balanced(expr))
{
printf("The parentheses are balanced.\n");
}
else
{
printf("The parentheses are not balanced.\n");
}
getch();
return 0;
}
