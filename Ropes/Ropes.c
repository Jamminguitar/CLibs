#include "Ropes.h"
#include <stdlib.h>

/*
 * Creates two child nodes from a leaf node
 */
 int createChildNodes(RopeNode *current) {
 	return 0;
 }

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
    // Make sure the left node is a leaf node, or return failure if this is impossible
    if (current->left && !isLeaf(current->left) && !combineBelowData(current->left)) {
    	return 1;
    }
    // Make sure the right node is a leaf node, or return failure if this is impossible
    if (current->right && !isLeaf(current->right) && !combineBelowData(current->right)) {
    	return 1;
    }

    // Return failure if the combined size is too large
    int combinedSize = current->left->size + current->right->size;
	if (combinedSize > 8) {
		return 1;
	}
	// Add the left node to the current node
	for (int i = 0; i < current->left->size; i++) {
		current->chars[i] = current->left->chars[i];
	}
	// Add the right node to the current node
	for (int i = current->left->size; i < combinedSize; i++) {
		current->chars[i] = current->right->chars[i - current->left->size];
	}
	// Delete the child nodes
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
int addData(RopeNode *current, uint64_t position, char data)
{
	// Return failure if the node is null
	if (!current) {
		return 1;
	}
	int success;
	// If not a leaf, recurse down the tree
	if (!isLeaf(current)) {
		// Recurse right
		if (position > current->weight) {
			success = addData(current->right, position - current->weight, data);
		// Recurse left
		} else {
			success = addData(current->left, position, data);
			if (success) {
				current->weight += 1;
			}
		}
	// This is a leaf node, try and fit inside node
	} else {
		if (current->size < 8) {
			for (int i = 7; i > position; i--) {
				current->chars[i] = current->chars[i-1];
			}
			current->chars[position] = data;
			current->size += 1;
			success = 0;
		} else {
			createChildNodes(current);
			success = addData(current, position, data);
		}
	}
    return success;
}

//TODO: Remove data method that must rebalance the tree if it removes a node
//Probably adds a single 


//TODO: Rebalance the tree from a node: check only nodes that are not leaves,
// greater than 1 difference in depths
