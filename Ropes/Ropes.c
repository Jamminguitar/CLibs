#include "Ropes.h"
#include <stdlib.h>

/*
 * Checks whether the given node is a leaf
 */
int isLeaf(RopeNode *current) {
    return (current->left == NULL) && (current->right == NULL);
}

/*
 * Checks the actual weight of the current node
 */
uint64_t checkWeights(RopeNode *current) {
    // Return the weight of the left subnode
    if (current->left) {
        RopeNode *leftChild = current->left;
        uint64_t weight = checkWeights(leftChild);
        // Ensure we have the entire left weight of the node
        if (leftChild->right) {
            weight += checkWeights(leftChild->right);
        }
        return weight;
    } else {
    	return current->weight;
    }
    return 0;

}

/*
 * This method takes in a rope and concatenates the chars
 * beneath it together, as well as removing its child
 * nodes from the list.
 *
 * PARAMETERS: 
 *
 * RopeNode *current: The current node in the Rope
 *
 * RETURNS: 0 if the operation completed successfully, 1 otherwise
 */
int combineBelowData(RopeNode *current)
{
	// If node is already a leaf, no work needs to be done
    if (isLeaf(current)) {
        return 0;
    }
    // Make sure the left node is a leaf node, or return null if this is impossible
    if (current->left && !isLeaf(current->left) && !combineBelowData(current->left)) {
    	return 1;
    }
    // Make sure the right node is a leaf node, or return null if this is impossible
    if (current->right && !isLeaf(current->right) && !combineBelowData(current->right)) {
    	return 1;
    }
    // TODO: Combine data into current node, and then
    // remove both of the other nodes from the list
    // Check again that they're both leaf nodes
    // Then check to make sure the size of both ends is <= 8
    // if unable to combine, return an empty char array
    int combinedSize = current->left->size + current->right->size;
	if (combinedSize > 8) {
		return 1;
	}
	for (int i = 0; i < current->left->size; i++) {
		current->chars[i] = current->left->chars[i];
	}
	for (int i = current->left->size; i < combinedSize; i++) {
		current->chars[i] = current->right->chars[i - current->left->size];
	}
	free(current->left);
	free(current->right);
	current->left = NULL;
	current->right = NULL;
    return 0;
}

/*
 * This method adds char information to the rope.
 * TODO: Create method, try to fit in existing node if
 * possible, and otherwise split the node into child nodes.
 */
int addData(uint64_t position, char data)
{
    return 0;
}

//TODO: Remove data method that must rebalance the tree if it removes a node
//Probably adds a single 


//TODO: Rebalance the tree from a node: check only nodes that are not leaves,
// greater than 1 difference in depths
