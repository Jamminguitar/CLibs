/*
This struct holds the data in a single rope.
*/
typedef struct
{
    char chars[8]; // A buffer for the characters in this rope
    int size; // The number of chars currently in the buffer
    int weight; // The weight of every node to the left of it
    RopeNode *left; // Child ropes
    RopeNode *right;
} RopeNode;

/*
This struct holds the data for the entire
rope.
*/
typedef struct 
{
    RopeNode *head;
} Rope;
