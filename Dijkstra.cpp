
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

using namespace std;

int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){
    //if the start and end node arent there just quit
    if (!g->IsPresent(start) || !g->IsPresent(end)) {
        return -1; 
    }

    //keeps track of the distance from each node to start
    unordered_map<nodekey_t, int> dist;
    set<nodekey_t> visited;
    BetterPriorityQueue pq;

    set<nodekey_t> nodeSet = g->GetNodes();
    for (const nodekey_t& node : nodeSet){
        dist[node] = INT_MAX;
    }

    // Set distance to the starting node as 0, and add it to the queue
    dist[start] = 0;
    pq.push(BPQNode{start, 0});

    while(!pq.empty()){

        // Get node with lowest current distance 
        BPQNode current = pq.top();
        pq.pop();
        nodekey_t u = current.gnode;


        if (visited.count(u)) {
            continue;
        }
        visited.insert(u);

        if (u == end){
            return dist[end];
        }

        //all outgoing edges from node
        set<const GraphEdge*> edges = g->GetOutwardEdgesFrom(u);
        for (const GraphEdge* edge : edges) {
            nodekey_t v = edge->to;      // Neighbor node
            int weight = edge->weight;

            if (visited.count(v)){
                continue;
            }

            //path through this node
            int alt = dist[u] + weight;

            if (alt < dist[v]){
                dist[v] = alt;

                BPQNode neighbor{v, alt};

                if (pq.Contains(neighbor)){
                    pq.Update(neighbor);
                } else {
                    pq.push(neighbor);
                }
            }
        }

    }
    return -1; //not found
}
