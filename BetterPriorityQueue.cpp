#include "BetterPriorityQueue.h"
#include <iostream>
#include <vector>

using namespace std;

bool BetterPriorityQueue::Contains(const BPQNode& node) const{
    for (size_t i = 0; i < this->c.size(); i++) {
        if (this->c[i] == node) {
            return true;
        }
    }
    return false;
}

bool BetterPriorityQueue::Update(const BPQNode& node){
    for (size_t i = 0; i < this->c.size(); i++){
        if (this->c[i] == node && node.pri < this->c[i].pri){
            this->c[i].pri = node.pri;
            make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
    }
    return false;
}

string BetterPriorityQueue::ToString() const {
    vector<BPQNode> temp = this->c;
    sort(temp.begin(), temp.end(), this->comp);
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < temp.size(); ++i) {
        ss << BPQNodeToString(temp[i]);
        if (i != temp.size() - 1) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

string BetterPriorityQueue::BPQNodeToString(const BPQNode& node) {
    stringstream ss;
    ss << "(" << node.gnode << ", pri: " << node.pri << ")";
    return ss.str();
}