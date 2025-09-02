//Implement the iterative and recursive Binary search tree and compare their performance.
# include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};
struct Node*createNode(int value){
   struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data =value;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode; 
}
struct Node*insert(struct Node*root , int value){
    struct Node*newNode = createNode(value);
    if (root == NULL)
    return newNode;
    struct Node*parent = NULL;
    struct Node*current=root;
    while (current != NULL){
        parent = current;
        if(value <current->data)
            current = current ->left;

        else if (value > current -> data)
        current =current-> right;
        else
        return root;
    }
    if (value < parent->data)
    {
        parent->left = newNode;
    }
    else if (value > parent->data)
    {
        parent->right = newNode;
    }
return root;
}



struct Node*insertRecursive(struct Node*root,int value){
    if (root==NULL){
        return createNode(value);}
    if (value<root->data){
        root ->left = insertRecursive(root ->left, value);}
    else if(value>root->data){
        root ->right = insertRecursive(root ->right, value);}
    
    
    return root ;
}

struct Node* search(struct Node* root, int value) {
    struct Node* current = root;
    while (current != NULL) {
        if (value == current->data)
            return current;
        else if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }
return NULL;
}

struct Node*searchRecursive(struct Node*root,int value){
    if (root == NULL || root->data == value)
    return root;
    if (value < root->data)
        return searchRecursive(root->left, value);
    else
        return searchRecursive(root->right, value);
}
 void inorder(struct Node*root) {
    if (root!= NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
 }

 int main (){
    struct Node* rootRecursive = NULL;
    struct Node* rootIterative = NULL;
    int n, value, key;
    printf("Vanshika, 59001372\n");
    // Take number of nodes from user
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    // Insert values into both trees
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        rootRecursive = insertRecursive(rootRecursive, value);
        rootIterative = insert(rootIterative, value);
    }

    // Display both trees
    printf("\nRecursive BST Inorder: ");
    inorder(rootRecursive);

    printf("\nIterative BST Inorder: ");
    inorder(rootIterative);

    // Search in both trees
    printf("\n\nEnter value to search: ");
    scanf("%d", &key);

    if (searchRecursive(rootRecursive, key)){
        printf("Found %d in Recursive BST\n", key);}
    else{
        printf("%d not found in Recursive BST\n", key);}

    if (search(rootIterative, key)){
        printf("Found %d in Iterative BST\n", key);}
    else{
        printf("%d not found in Iterative BST\n", key);}

    return 0;
 }
