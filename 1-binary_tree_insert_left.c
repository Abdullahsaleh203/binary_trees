#include <stdlib.h>

typedef struct binary_tree_node {
    int value;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} binary_tree_t;

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {
    if (parent == NULL) {
        return NULL;
    }

    binary_tree_t *new_node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
        return NULL;
    }

    binary_tree_t *old_left_child = parent->left;
    parent->left = new_node;
    new_node->value = value;
    new_node->left = old_left_child;
    new_node->right = NULL;

    return new_node;
}
