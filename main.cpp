#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct node
{
    int id;
    double capacity{1.0};
    double flow{0.0};
    node(int _id, double _capacity = 1.0, double _flow = 0.)
    {
        id = _id;
        capacity = _capacity;
        flow = _flow;
    }
};

class Graph
{
    private:
        std::unordered_map<int, std::vector<node>> adjacency_list;        
    public:
        Graph()
        {
        }
        void add_edge(int a, int b, double _capacity = 1.)
        {
            auto itr = adjacency_list.find(a);
            if(itr == adjacency_list.end()){
                adjacency_list[a] = std::vector<node>{node(b,_capacity)};
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
            itr->second.push_back(node(b,_capacity));
        }
};



int main()
{
    Graph g;

    g.add_edge(0,1,16);
    g.add_edge(0,2,13);
    g.add_edge(1,3,12);
    g.add_edge(1,2,10);
    g.add_edge(2,1,4);
    g.add_edge(2,4,14);
    g.add_edge(3,2,9);
    g.add_edge(3,5,20);
    g.add_edge(4,3,7);
    g.add_edge(4,5,4);
}