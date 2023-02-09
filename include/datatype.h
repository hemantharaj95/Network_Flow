#ifndef NETWORKFLOW_DATATYPE_H_
#define NETWORKFLOW_DATATYPE_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <float.h>

struct Node
{
    long long id;
    long long capacity{0};
    long long flow{0};
    Node(long long _id, long long _capacity = 0, long long _flow = 0)
    {
        id = _id;
        capacity = _capacity;
        flow = _flow;
    }
};

class Graph
{
    private:
        std::unordered_map<int, std::vector<Node>> adjacency_list;        
    public:
        Graph()
        {
        }

        void SetFlowZero()
        {
            for(auto &edge: adjacency_list){
                for(int i = 0; i < edge.second.size(); ++i){
                    edge.second.at(i).flow = 0.;
                }
            }
        }

        void CreateResidual()
        {
            std::vector<std::vector<long long>> residual;
            for(auto &edge: adjacency_list){
                for(int i = 0; i < edge.second.size(); ++i){
                    residual.push_back(std::vector<long long>{(long long)edge.first,(long long)edge.second.at(i).id, edge.second.at(i).capacity});
                }
            }
            for(auto &edge: residual){
                this->AddEdge(edge.at(1),edge.at(0), edge.at(2), edge.at(2));
            }
        }

        void AddEdge(long long a, long long b, long long _capacity = 0, long long _flow = 0)
        {
            auto itr = adjacency_list.find(a);
            if(itr == adjacency_list.end()){
                adjacency_list[a] = std::vector<Node>{Node(b,_capacity, _flow)};
                return;
            }
            
            bool found = false;
            for(int i = 0; i < itr->second.size(); ++i){
                if(itr->second.at(i).id == b){
                    found = true;
                    break;
                }
            }

            if(found){
                return;
            }
            itr->second.push_back(Node(b,_capacity, _flow));
        }

        std::vector<int> BFS(int source, int dest)
        {
            std::unordered_set<int> visited;
            std::unordered_map<int,int> parent;
            int curr_node = source;
            parent[curr_node] = -100;
            std::queue<int> open_list;
            open_list.push(curr_node);  
            visited.insert(curr_node);
            bool found = false;
            while(not open_list.empty()){
                curr_node = open_list.front();
                open_list.pop();
                //For all neighbor
                auto itr = adjacency_list.find(curr_node);
                if(itr == adjacency_list.end()){
                    continue;
                }
                for(auto neigh: itr->second){
                    if((neigh.capacity - neigh.flow) <= 0){
                        continue;
                    }        
                    if(visited.insert(neigh.id).second == true){
                        open_list.push(neigh.id);
                        parent[neigh.id] = curr_node;
                        if(neigh.id == dest){
                            found = true;
                            break;
                        }
                    }
                }

                if(found){
                    break;
                }
            }

            std::vector<int> path;
            path.clear();
            if(not found){
                return path;
            }
            curr_node = dest;
            while(parent[curr_node] != -100){
                path.push_back(curr_node);
                curr_node = parent[curr_node];
            }
            path.push_back(curr_node);
            std::reverse(path.begin(), path.end());
            return path;
        }

        int GetResidual(int source, int dest)
        {
            auto itr = adjacency_list.find(source);
            if(itr == adjacency_list.end()){
                return 0.;
            }
            for(int i = 0; i < itr->second.size(); ++i){
                if(dest == itr->second.at(i).id){
                    return (itr->second.at(i).capacity - itr->second.at(i).flow);
                }
            }
        }

        int GetFlow(int source, int dest)
        {
            auto itr = adjacency_list.find(source);
            if(itr == adjacency_list.end()){
                return 0.;
            }
            for(int i = 0; i < itr->second.size(); ++i){
                if(dest == itr->second.at(i).id){
                    return  itr->second.at(i).flow;
                }
            }
        }

        void UpdateFlow(int source, int dest, double inc_flow)
        {
            auto itr = adjacency_list.find(source);
            if(itr == adjacency_list.end()){
                return ;
            }
            for(int i = 0; i < itr->second.size(); ++i){
                if(dest == itr->second.at(i).id){
                    itr->second.at(i).flow += inc_flow;
                    return;
                }
            }
        }

        std::vector<int> GetForward(int node)
        {
            auto itr = adjacency_list.find(node);

            if(itr == adjacency_list.end()){
                return std::vector<int>{};
            }

            std::vector<int> positive_flow;

            for(auto &n: itr->second){
                if(n.flow > 0){
                    positive_flow.push_back(n.id);
                }
            }

            return positive_flow;
        }

        void PrintEdge()
        {
            for(auto edges: adjacency_list){
                for(int i = 0; i < edges.second.size(); ++i){
                    std::cout << edges.first <<"->" << edges.second.at(i).id << " F: " << edges.second.at(i).flow << " C:" << edges.second.at(i).capacity << std::endl;
                }
            }
        }
};

#endif 