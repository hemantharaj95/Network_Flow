#ifndef MATCHING_H
#define MATCHING_H

#include <fordfulkerson.h>

/**
 * Source Node id = 0 and Destination Node id = -1 reserved
*/
class Matching : public FordFulkerson
{
private:
    /* data */
    std::unordered_map<int,int> left;
    std::unordered_set<int> right;
public:
    Matching(/* args */);
    ~Matching();
    //Bipartile Matching:
    void AddRightNode(int id)
    {
       right.insert(id);
    }

    void AddLeftNode(int id)
    {
        left[id] = -100;
    }

    void Add(int _left, int _right)
    {
        auto itr = left.find(_left);
        if(itr == left.end()){
            return;
        }

        auto iter = right.find(_right);
        if(iter == right.end()){
            return;
        }

        this->AddEdge(_left, _right, 1);
    }

    bool BipartileMatching()
    {
        //Add new Source Node & { Edge from S to every vertex in Left}
        for(auto &left_node: left){
            this->AddEdge(0, left_node.first, 1);
        }
        //Add new Target Node & { Edge from everty vertex in Right to T}
        for(auto &right_node: right){
            this->AddEdge(right_node, -1, 1);
        }
        //Solve Ford-Fulkerson
        this->SetSource(0);
        this->SetDest(-1);
        this->EdmondsKarp();
        //Return result
        for(auto &left_node: left){
            std::vector<int> assign = this->GetForwardNeighborFlow(left_node.first);
            if(assign.size() > 0){
                left_node.second = assign.at(0);
                std::cout << "Left " << left_node.first << " assign " << assign.at(0)<< std::endl;
            }
        }
    }
    //Node cover Problem:
    //Assignment Problem: Hungarian
};
 Matching::Matching(/* args */)
{
}
Matching::~Matching()
{
}

#endif