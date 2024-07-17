/* Nesse exemplo, a função createNode cria um novo nó e a função 
insert insere um novo nó na árvore, seguindo as regras de uma 
árvore binária de busca. A função inOrder percorre a árvore em ordem, 
imprimindo os valores dos nós. A função main cria a árvore binária de 
busca e realiza um percurso em ordem para imprimi-la.*/


#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    cout << "Inorder traversal of the binary search tree is: ";
    inOrder(root);
    return 0;
}
