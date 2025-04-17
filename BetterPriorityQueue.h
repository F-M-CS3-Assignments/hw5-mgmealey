#ifndef BETTER_PRIORITY_QUEUE_H
#define BETTER_PRIORITY_QUEUE_H

#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

#define nodekey_t unsigned long long int
#define INVALID_NODE_KEY ULLONG_MAX

struct BPQNode {
    nodekey_t gnode = INVALID_NODE_KEY; // Node key, used for identifying a vertex
    nodekey_t pri = INT_MAX;// Priority value (smaller = higher priority in queue)

    BPQNode() = default;
    BPQNode(nodekey_t n, int p) : gnode(n), pri(p) {}

    // For min-heap: node with lower 'pri' should come first
    bool operator>(const BPQNode& other) const {
        return this->pri > other.pri;
    }
    
    bool operator==(const BPQNode& other) const{
        return this->gnode == other.gnode;
    }
};

class BetterPriorityQueue : public priority_queue<BPQNode, vector<BPQNode>, greater<BPQNode>> {
public:
    using Base = priority_queue<BPQNode, vector<BPQNode>, greater<BPQNode>>;

    //takes a BPQNode and returns true if that BPQNode is in the queue
    bool Contains(const BPQNode& node) const;

    // takes a BPQNode and uses the values in that BPQNode to change the priority of a
    //matching BPQNode in the queue. It returns true if any change is actually made.
    bool Update(const BPQNode& node);

    //returns a string representation of the queue like those shown above including []s
    //and commas etc. as necessary.
    string ToString() const;

    //takes a BPQNode struct and returns a string
    //representation like those shown above (each item in the queue).
    static string BPQNodeToString(const BPQNode& node);
};

#endif 
