#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(char c) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = c;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

// Function to calculate the size of the tree
int sizeOfTree(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

// Function to calculate the height of the tree
int heightOfTree(struct Node* root) {
    if (root == NULL)
        return -1;
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the level of a given node
int levelOfNode(struct Node* root, char target, int level) {
    if (root == NULL)
        return -1;
    if (root->data == target)
        return level;
    int leftLevel = levelOfNode(root->left, target, level + 1);
    if (leftLevel != -1)
        return leftLevel;
    return levelOfNode(root->right, target, level + 1);
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf(" %c - ", root->data);
    }
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf(" %c - ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf(" %c - ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root;
    root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    
    printf("\nThe InOrder(Left Root Right) Traversal:");
    inOrderTraversal(root);
    
    printf("\nThe PreOrder(Root Left Right) Traversal:");
    preOrderTraversal(root);
    
    printf("\nThe PostOrder(Left Right Root) Traversal:");
    postOrderTraversal(root);
    
    printf("\n\nSize of the Tree: %d", sizeOfTree(root));
    printf("\nHeight of the Tree: %d", heightOfTree(root));
    
    char target = 'E';
    int level = levelOfNode(root, target, 0);
    if (level != -1)
        printf("\nLevel of node '%c': %d\n", target, level);
    else
        printf("\nNode '%c' not found in the tree\n", target);
    
    return 0;
}