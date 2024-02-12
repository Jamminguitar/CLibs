enum RopeType
{
    leafNode = 0,
    treeNode = 1
};

typedef struct
{
    RopeType type;
    int weight;
} RopeNode;

/*
This struct holds the data for strings held inside
the rope.
*/
typedef struct
{
    RopeNode head;
    char value[8];

} LeafNode;

/*
This struct holds the data for non-leaf nodes
held inside the rope.
*/
typedef struct
{
    RopeNode head;
    RopeNode *left;
    RopeNode *right;
} BranchNode;

/*
This struct holds the data for the entire
rope.
*/
typedef struct 
{
    RopeNode *head;
} Rope;

/*
This method adds char information to the rope.
*/
int addData(int position, char data[8])
{
    return 0;
}

/*
This method takes in a rope and concatenates the chars
beneath it together
*/
char* combineData(RopeNode *current)
{
    if (current->type == leafNode)
    {
        LeafNode *current_leaf = (LeafNode*) current;
        return current_leaf->value;
    } else {
        BranchNode *current_branch = (BranchNode*) current;
        if (getTotalSize(current) > 8) {
            //return a char of the left and right sides
            //added together
        }
        //read the left and right chars, combine them,
        //and free the child data

    }
}

/*
This method gets the size of the current node
*/
int getTotalSize(RopeNode *current) {
    //TODO
}