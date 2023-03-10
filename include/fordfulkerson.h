#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include <datatype.h>

class FordFulkerson
{
    private:
        Graph g;
        int source;
        int dest;
    public:
        FordFulkerson()
        {
        }
        FordFulkerson(int _source, int _dest)
        {
            source = _source;
            dest = _dest;
        }

        int EdmondsKarp()
        {
            //Set Flow Zero f(u,v) <-- 0 for all edges(u,v)
            g.SetFlowZero();
            g.CreateResidual();
            //g.PrintEdge();
            int iter = 0;
            while(true){
                //While there is a path P from s to t in Gf, such that cf(u,v) > 0 for all edges (u,v) E p
                auto path = g.BFS(source, dest);
                if(path.size() == 0){
                    break;
                }
                //1. Find cf(p) = min{cf(u,v): (u,v) E p}
                double cf = DBL_MAX;
                for(int i = 1; i < static_cast<int>(path.size()); ++i){
                    if(g.GetResidual(path.at(i-1), path.at(i)) < cf){
                        cf = g.GetResidual(path.at(i-1), path.at(i));
                    }
                }
                //2. For each edge (u,v) E p
                for(int i = 1; i < static_cast<int>(path.size()); ++i){
                    //2a. f(u,v) <--  f(u,v) + cf(p) (Send flow along the path)
                    g.UpdateFlow(path.at(i-1), path.at(i), cf);
                    //2b. f(v,u) <--  f(v,u) - cf(p) (The flow might be "returned" later)  
                    g.UpdateFlow(path.at(i), path.at(i-1), -cf);
                }
                iter += 1;
            }
            return 1;
        }   

        void SetSource(int _source)
        {
            this->source = _source;
        }
        void SetDest(int _dest)
        {
            this->dest = _dest;
        }
        void AddEdge(int a, int b, int capacity = 1.)
        {
            g.AddEdge(a,b, capacity);
        }

        int GetFlow(int source, int dest)
        {
            return g.GetFlow(source, dest);
        }

        std::vector<int> GetForwardNeighborFlow(int source)
        {
            return g.GetForward(source);
        }

        std::vector<int> GetBackwardNeighborFlow(int dest)
        {

        }
        void Print()
        {
            g.PrintEdge();
        }

        ~FordFulkerson()
        {
        }
};

#endif