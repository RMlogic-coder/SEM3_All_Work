#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int key;
    char name[31];
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key, char name[])
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
        exit(1);
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int key, char name[])
{
    if (root == NULL)
        return createNode(key, name);
    if (key < root->key)
        root->left = insert(root->left, key, name);
    else if (key > root->key)
        root->right = insert(root->right, key, name);
    return root;
}

void kth(struct Node *root, int k, int *found)
{
    if (root == NULL || *found)
        return;
    kth(root->left, k - 1, found);

    if (k == 0)
    {
        printf(" %s, %d\n",
               root->name, root->key);
        *found = 1;
        return;
    }
    kth(root->right, k - 1, found);
}

struct Node *findMin(struct Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

struct Node *purgeRange(struct Node *root, int L, int R)
{
    if (root == NULL)
        return NULL;
    root->left = purgeRange(root->left, L, R);
    root->right = purgeRange(root->right, L, R);

    if (root->key >= L && root->key <= R)
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            // printf("%d\t%s\n", root->key, root->name);
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            // printf("%d\t%s\n", root->key, root->name);
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        temp->left = root->left;
        struct Node *newRoot = root->right;
        free(root);
        return newRoot;
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d : %s\n", root->key, root->name);
    inorder(root->right);
}

void freeTree(struct Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    int data;
    char name[50];
    struct Node *root = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        scanf("%s", name);

        root = insert(root, data, name);
    }
    int k;
    int found = 0;
    scanf("%d", &k);

    kth(root, k, &found);

    int s;
    int e;

    scanf("%d", &s);
    scanf("%d", &e);

    root = purgeRange(root, s, e);

    printf("Post-Purge Vault Records :\n");

    if (root == NULL)
        printf("VAULT_EMPTY\n");
    else
        inorder(root);

    freeTree(root);
    return 0;
}

//                 100
//        50              150
//    25    75

// 5
// 100 Cipher 50 Ghost 150 Spectre 25 Shadow 75 Viper 1