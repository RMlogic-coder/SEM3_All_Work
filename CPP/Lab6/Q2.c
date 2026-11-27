#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    int height;
    struct Node *left, *right;
};

int sr = 0;
int dr = 0;

int height(struct Node *n)
{
    return n == NULL ? -1 : n->height;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getbalance(struct Node *n)
{
    return n == NULL ? 0 : height(n->left) - height(n->right);
}

struct Node *createnode(int key)
{
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL)
        exit(1);
    n->key = key;
    n->height = 0;
    n->left = n->right = NULL;
    return n;
}

struct Node *rightrotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

struct Node *leftrotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return createnode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getbalance(root);

    if (balance > 1 && key < root->left->key)
    {
        sr++;
        return rightrotate(root);
    }
    if (balance < -1 && key > root->right->key)
    {
        sr++;
        return leftrotate(root);
    }
    if (balance > 1 && key > root->left->key)
    {
        dr++;
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && key < root->right->key)
    {
        dr++;
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

void preorderaudit(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d (H:%d, BF:%d)\n", root->key, root->height, getbalance(root));
    preorderaudit(root->left);
    preorderaudit(root->right);
}

int main()
{
    int N, key;
    scanf("%d", &N);
    struct Node *root = NULL;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &key);
        root = insert(root, key);
    }
    printf("Single Rotations (LL/RR): %d\n", sr);
    printf("Double Rotations (LR/RL): %d\n", dr);
    printf("Pre-Order Telemetry Audit:\n");
    preorderaudit(root);
    return 0;
}