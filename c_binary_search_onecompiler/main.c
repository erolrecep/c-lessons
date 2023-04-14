#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left =node->right= NULL;
    return node;
}

// Function to insert a node in the binary search tree
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to find the minimum node in a tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to print the level order traversal of the binary search tree
void printLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->key);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

// Driver code
int main() {
  struct Node *root = NULL;
  int n;

  /* User input:
    6
    50 30 20 40 70 60
    60
   */
    scanf("%d",&n);
    int *array=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
        root = insert(root, array[i]);
    }
  int k;
  scanf("%d",&k);
  printLevelOrder(root);
  root = deleteNode(root, k);
  printf("\n");
  printLevelOrder(root);
    return 0;
}
