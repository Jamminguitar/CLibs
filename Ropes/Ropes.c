#include "Ropes.h"

/*
 * Checks whether the given node is a leaf
 */
int isLeaf(RopeNode *current) {
    return (current->left == ((void *) 0)) && (current->right == ((void *) 0));
}

/*
 * Checks the weight of the current node
 */
int checkWeights(RopeNode *current) {
    // Return weight if already a leaf
    if (isLeaf(current)) {
        return current->weight;
    }
    // Return the weight of the left subnode
    if (current->left) {
        RopeNode *leftChild = current->left;
        int size = checkWeights(leftChild);
        // Ensure we have the entire left weight of the node
        if (leftChild->right) {
            size += checkWeights(leftChild->right);
        }
        return size;
    }
    return 0;

}

/*
 * This method takes in a rope and concatenates the chars
 * beneath it together, as well as removing its child
 * nodes from the list.
 */
char* combineData(RopeNode *current)
{
    if (isLeaf(current)) {
        return current->chars;
    }
    int newData[8];
    int currIndex = 0;
    // Ensuring both nodes are leaf nodes (if they exist)
    if (current->left && !isLeaf(current->left)) {
        current->left->chars = combineData(current->left);
    }
    if (current->right && !isLeaf(current->right)) {
        current->right->chars = combineData(current->right);
    }
    // TODO: Combine data into current node, and then
    // remove both of the other nodes from the list
}

/*
 * This method adds char information to the rope.
 * TODO: Create method, try to fit in existing node if
 * possible, and otherwise split the node into child nodes.
 */
int addData(int position, char data)
{
    return 0;
}

//TODO: Remove data method that must rebalance the tree if it removes a node
//Probably adds a single 


//TODO: Rebalance the tree from a node: check only nodes that are not leaves,
// greater than 1 difference in depths