#include <stdint.h>

#define NULL ((void *) 0)

/*
This struct holds the data in a single rope.
*/
typedef struct RopeNode
{
    char chars[8]; // A buffer for the characters in this rope
    int size; // The number of chars currently in the buffer
    uint64_t weight; // The weight of every node to the left of it
    struct RopeNode *left; // Child ropes
    struct RopeNode *right;
} RopeNode;

/*
This struct holds the data for the entire
rope.
*/
typedef struct 
{
    RopeNode *head;
} Rope;
