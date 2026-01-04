#include <stdio.h>
int main() {
int n, i, low, high, mid, key;
int roll[100];
printf("Enter number of students: ");
scanf("%d", &n);
printf("Enter the roll numbers in sorted order:\n");
for (i = 0; i < n; i++) {
scanf("%d", &roll[i]);
}
printf("Enter the roll number to search: ");
scanf("%d", &key);
low = 0;
high = n - 1;
// Binary Search
while (low <= high) {
mid = (low + high) / 2;
if (roll[mid] == key) {
printf("Roll number %d found at position %d.\n", key, mid + 1);
return 0;
}
else if (key < roll[mid]) {
high = mid - 1;
}
else {
low = mid + 1;
}
}
printf("Roll number %d not found in the list.\n", key);
getch();
}


// 2

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
typedef struct Node {
int v;
struct Node *next;
} Node;
Node* adj[20];
int visited[20];
int path[20];
void addEdge(int u, int v)
{
Node *p;
/* Add edge u -> v */
p = (Node*)malloc(sizeof(Node));
p->v = v;
p->next = adj[u];
adj[u] = p;
/* Add edge v -> u (undirected) */
p = (Node*)malloc(sizeof(Node));
p->v = u;
p->next = adj[v];
adj[v] = p;
}
void dfs(int u, int dest, int pathlen)
{
Node *t;
visited[u] = 1;
path[pathlen] = u;
pathlen++;
/* destination found */
if (u == dest) {
int i;
for (i = 0; i < pathlen; i++)
printf("%d ", path[i]);
printf("\n");
}
else {
t = adj[u];
while (t != NULL) {
if (!visited[t->v]) {
dfs(t->v, dest, pathlen);
}
t = t->next;
}
}
visited[u] = 0; /* backtracking */
}
int main()
{
int n, e, i;
int u, v, src, dest;
clrscr();
/* initialize adjacency list */
for (i = 0; i < 20; i++) {
adj[i] = NULL;
visited[i] = 0;
}
printf("Enter number of stations: ");
scanf("%d", &n);
printf("Enter number of connections: ");
scanf("%d", &e);
printf("Enter each connection (u v):\n");
for (i = 0; i < e; i++) {
scanf("%d %d", &u, &v);
addEdge(u, v);
}
printf("Enter source station: ");
scanf("%d", &src);
printf("Enter destination station: ");
scanf("%d", &dest);
printf("All paths from %d to %d:\n", src, dest);
dfs(src, dest, 0);
getch();
return 0;
}