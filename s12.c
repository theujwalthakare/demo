Q1. Implement DFS to find paths in a city’s metro rail system using an adjacency list.
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
Q2. Implement a music playlist where songs can be played forward and backward using a doubly linked list.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char song[50];
    struct node *next, *prev;
} *head=NULL, *tail=NULL;
void addSong(char *name) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    strcpy(n->song, name);
    n->next = NULL;
    n->prev = tail;
    if (!head) head = n;
    else tail->next = n;
    tail = n;
}
void playForward() {
    struct node *t = head;
    if (!t) { printf("Playlist empty!\n"); return; }
    while (t) { printf("%s -> ", t->song); t = t->next; }
    printf("END\n");
}
void playBackward() {
    struct node *t = tail;
   if (!t) { printf("Playlist empty!\n"); return; }
    while (t) { printf("%s -> ", t->song); t = t->prev; }
    printf("START\n");
}
void main() {
    int ch;
    char name[50];
    clrscr();
    while (1) {
        printf("\n1.Add Song 2.Play Forward 3.Play Backward 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter song name: ");
                scanf("%s", name);
                addSong(name);
                break;
            case 2: playForward(); break;
            case 3: playBackward(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }}}

