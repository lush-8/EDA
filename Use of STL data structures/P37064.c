#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char word[100];
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
    size_t size;
} Set;

Node* create_node(const char* word) {
    
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->word, word);
    node->left = node->right = NULL;
    return node;
}

Set* create_set() {

    Set* s = (Set*)malloc(sizeof(Set));
    s->root = NULL;
    s->size = 0;
    return s;
}

Node* insert_node(Node* root, const char* word, Node** inserted) {

    if (!root) {
        *inserted = create_node(word);
        return *inserted;
    }
    if (strcmp(word, root->word) < 0) {
        root->left = insert_node(root->left, word, inserted);
    }
    else if (strcmp(word, root->word) > 0) {
        root->right = insert_node(root->right, word, inserted);
    }
    return root;
}

void insert(Set* s, const char* word, Node** inserted) {

    s->root = insert_node(s->root, word, inserted);
    s->size++;
}

Node* find_min(Node* node) {

    while (node->left != NULL) node = node->left;
    return node;
}

Node* find_max(Node* node) {

    while (node->right != NULL) node = node->right;
    return node;
}

Node* find_successor(Set* s, Node* current) {

    if (current->right) return find_min(current->right);
    Node* successor = NULL;
    Node* ancestor = s->root;

    while (ancestor != current) {
        if (strcmp(current->word, ancestor->word) < 0) {
            successor = ancestor;
            ancestor = ancestor->left;
        } 
        else ancestor = ancestor->right;
    }
    return successor;
}

Node* find_predecessor(Set* s, Node* current) {

    if (current->left) return find_max(current->left);
    Node* predecessor = NULL;
    Node* ancestor = s->root;

    while (ancestor != current) {
        if (strcmp(current->word, ancestor->word) > 0) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } 
        else ancestor = ancestor->left;
    }
    return predecessor;
}

int main() {

    Set* s = create_set();
    Node* median = NULL;
    char w[100];
    scanf("%s", w);

    while (strcmp(w, "END") != 0) {
        Node* inserted = NULL;
        insert(s, w, &inserted);

        if (!median) {
            median = inserted;
        }
        else if (s->size % 2 == 0 && strcmp(w, median->word) < 0) {
            median = find_predecessor(s, median);
        }
        else if (s->size % 2 != 0 && strcmp(w, median->word) > 0) {
            median = find_successor(s, median);
        }
        printf("%s\n", median->word);
        scanf("%s", w);
    }
    return 0;
}