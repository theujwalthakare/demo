// Q1. Implement DFS to find paths in a city’s metro rail system using an adjacency list.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
struct node {
    int vertex;
    struct node *next;
};
struct node *adj[MAX];
int visited[MAX];
/* Create adjacency list node */
struct node* createNode(int v) {
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->vertex = v;
    n->next = NULL;
    return n;
}
/* Add edge (undirected graph) */
void addEdge(int src, int dest) {
    struct node *n;
    n = createNode(dest);
    n->next = adj[src];
    adj[src] = n;

    n = createNode(src);
    n->next = adj[dest];
    adj[dest] = n;
}
/* DFS traversal */
void DFS(int v) {
    struct node *temp;
    visited[v] = 1;
    printf("Station %d -> ", v);
    temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }}
void main() {
    int vertices, edges, i, src, dest, start;
    clrscr();
    printf("Enter number of stations: ");
    scanf("%d", &vertices);
    for (i = 0; i < vertices; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    printf("Enter number of connections: ");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++) {
        printf("Enter connection (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }
    printf("Enter starting station: ");
    scanf("%d", &start);
    printf("\nDFS Path:\n");
    DFS(start);
    getch();}
// Q1. Implement binary search to find whether a given roll number exists in a sorted list.
#include <stdio.h>
#include <conio.h>
void main() {
    int roll[10], n, key;
    int low, high, mid, i;
    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter roll numbers in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }
    printf("Enter roll number to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (roll[mid] == key) {
            printf("Roll number %d FOUND at position %d\n", key, mid + 1);
            getch();
            return;
        }
        else if (roll[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Roll number %d NOT FOUND\n", key);
    getch();}


