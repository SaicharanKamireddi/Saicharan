#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* left;
    struct node* right;
} Node;

// Stack node structure
typedef struct stackNode {
    Node* data;
    struct stackNode* next;
} StackNode;

// Stack structure
typedef struct stack {
    StackNode* top;
} Stack;

// Initialize an empty stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Push a node onto the stack
void push(Stack* stack, Node* data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop a node from the stack
Node* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return NULL;
    }
    StackNode* temp = stack->top;
    Node* popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

// Inorder traversal using iterative method
void inorderTraversalIterative(Node* root) {
    if (root == NULL)
        return;

    Stack* stack = createStack();
    Node* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d -> ", current->item);
        current = current->right;
    }
}

// Preorder traversal using iterative method
void preorderTraversalIterative(Node* root) {
    if (root == NULL)
        return;

    Stack* stack = createStack();
    push(stack, root);

    while (!isEmpty(stack)) {
        Node* current = pop(stack);
        printf("%d -> ", current->item);

        if (current->right != NULL)
            push(stack, current->right);
        if (current->left != NULL)
            push(stack, current->left);
    }
}

// Postorder traversal using iterative method
void postorderTraversalIterative(Node* root) {
    if (root == NULL)
        return;

    Stack* stack1 = createStack();
    Stack* stack2 = createStack();
    push(stack1, root);

    while (!isEmpty(stack1)) {
        Node* current = pop(stack1);
        push(stack2, current);

        if (current->left != NULL)
            push(stack1, current->left);
        if (current->right != NULL)
            push(stack1, current->right);
    }

    while (!isEmpty(stack2)) {
        Node* current = pop(stack2);
        printf("%d -> ", current->item);
    }
}

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node on the left of the parent node
void insertLeft(Node* parent, int value) {
    parent->left = createNode(value);
}

// Insert a node on the right of the parent node
void insertRight(Node* parent, int value) {
    parent->right = createNode(value);
}

int main() {
    Node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);

    printf("Inorder traversal (Iterative): \n");
    inorderTraversalIterative(root);

    printf("\nPreorder traversal (Iterative): \n");
    preorderTraversalIterative(root);

    printf("\nPostorder traversal (Iterative): \n");
    postorderTraversalIterative(root);

    return 0;
}

/* Output
Inorder traversal (Iterative): 
4 -> 2 -> 1 -> 3 -> 
Preorder traversal (Iterative): 
1 -> 2 -> 4 -> 3 -> 
Postorder traversal (Iterative): 
4 -> 2 -> 3 -> 1 -> 
*/
