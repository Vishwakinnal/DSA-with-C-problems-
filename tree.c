#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

/* Create Node */
NODE create(int ele)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Insert into BST */
NODE insert(NODE root, int ele)
{
    if (root == NULL)
        return create(ele);

    if (ele < root->data)
        root->left = insert(root->left, ele);
    else if (ele > root->data)
        root->right = insert(root->right, ele);

    return root;
}

/* Inorder Traversal */
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder Traversal */
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search in BST */
void search(NODE root, int key)
{
    if (root == NULL)
    {
        printf("Key not found\n");
        return;
    }
    if (key == root->data)
    {
        printf("Key found\n");
        return;
    }
    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

/* Main Function */
int main()
{
    NODE root = NULL;
    int ch, key, flag=1;
    int a[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = 12;
    printf("\n1.Create BST\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit\n");
    while (flag)
    {
        printf("\n1.Create BST\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            root = NULL;
            for (int i = 0; i < n; i++)
                root = insert(root, a[i]);
            printf("BST Created\n");
            break;

        case 2:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Enter key: ");
            scanf("%d", &key);
            search(root, key);
            break;

        case 6:
            exit(0);
            break;
        default:
            flag=0;
            break;
        }

    }
}
