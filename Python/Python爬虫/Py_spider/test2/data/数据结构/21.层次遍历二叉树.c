#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree {
    Node *root;
    int n;
}Tree;

typedef struct Stack {
    Node **data;
    int top, size;
} Stack;


Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Stack *init_stack(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

Node *top(Stack *s) {
    return s->data[s->top];
}

int push(Stack *s, Node *val) {
    if(s == NULL) return 0;
    if(s->top == s->size - 1) return 0;
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}
void clear_stack(Stack *s);
Node *build(char *str, int *node_num) {
    Node *temp = NULL, *p = NULL;
    Stack *s = init_stack(strlen(str));
    int flag = 0;
    while(str[0]) {
        switch(str[0]) {
            case '(' :
                   push(s, temp);
                   flag = 0;
                   temp = NULL;
                   break;
            case ')' :
                   p = top(s);
                   pop(s);
                   break;
            case ',' :
                   flag = 1;
                   temp = NULL;
                   break;
            case ' ' :
                   break;
            default  :
                   temp = getNewNode(str[0]);
                   if(!empty(s)&& flag == 0){
                   top(s) ->lchild = temp; 
                   } else if(!empty(s)&&flag == 1) {
                   top(s) ->rchild = temp;
                   }
                   ++(*node_num);
            break;
        }
        ++str;
    }
    clear_stack(s);
    if(temp && !p) p = temp;
    return p;
}
typedef struct Queue {
    Node **data;
    int head, tail;
}Queue;

Queue *initq() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Node **)malloc(sizeof(Node *) * 1500);
    q->head  = q->tail = 0;
    return q;
}

int emptyq(Queue *q) {
    return q->head ==  q->tail;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

void pushq(Queue *q, Node *val) {
    if(q == NULL) return;
    q->data[q->tail] = val;
     q->tail++;
}

int popq(Queue *q) {
    if(emptyq(q)) return 0;
    q->head ++;
    return 1;
}



void clear_node(Node *node) {
    if(node == NULL) return ;
    clear_node(node->lchild);
    clear_node(node->rchild);
    return;
}



void clearq(Queue *q) {
    if(q == NULL)return;
    free(q->data);
    free(q);
    return;
}

void clear_tree(Tree *tree) {
    if(tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return ;
}

void clear_stack(Stack *s) {
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return;
}

void bfs(Node *root) {
    if(root == NULL) return;
    Node *element, *temp;
    Queue *queue = initq();
    pushq(queue, root);
    while(!emptyq(queue)) {
        element = front(queue);
        popq(queue);
        printf("%c", element->data);
        if(element->lchild != NULL) {
            temp = element->lchild;
            pushq(queue, temp);
        }
        if(element->rchild != NULL) {
            temp = element->rchild;
            pushq(queue, temp);
        }
        if(!emptyq(queue))printf(" ");
    }
    clearq(queue);
}

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    int node_num = 0;
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);
    tree->n = node_num;
    bfs(tree->root);
   //in_order(tree), printf("\n");
    clear_tree(tree);
return 0;
}
