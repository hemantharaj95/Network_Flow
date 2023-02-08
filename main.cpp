#include <fordfulkerson.h>

class Matching : public FordFulkerson
{
private:
    /* data */
public:
    Matching(/* args */);
    ~Matching();
};
 Matching::Matching(/* args */)
{
}
Matching::~Matching()
{
}

int main()
{
    FordFulkerson f(0,5);
    // f.add_edge(0,1,16);
    // f.add_edge(0,2,13);
    // f.add_edge(1,3,12);
    // f.add_edge(1,2,10);
    // f.add_edge(2,1,4);
    // f.add_edge(2,4,14);
    // f.add_edge(3,2,9);
    // f.add_edge(3,5,20);
    // f.add_edge(4,3,7);
    // f.add_edge(4,5,4);
    f.AddEdge(0,1,7);
    f.AddEdge(0,4,4);
    f.AddEdge(1,2,5);
    f.AddEdge(1,3,3);
    f.AddEdge(2,5,8);
    f.AddEdge(3,2,3);
    f.AddEdge(3,5,5);
    f.AddEdge(4,1,3);
    f.AddEdge(4,3,2);

    f.Print();
    std::cout << "----------------------------------\n";
    f.EdmondsKarp();

//     std::cout << "Flow " << f.get_flow(0,1) << std::endl;
//     std::cout << "Flow " << f.get_flow(0,2) << std::endl;
//     std::cout << "Flow " << f.get_flow(1,3) << std::endl;
//     std::cout << "Flow " << f.get_flow(1,2) << std::endl;
//     std::cout << "Flow " << f.get_flow(2,1) << std::endl;
//     std::cout << "Flow " << f.get_flow(2,4) << std::endl;
//     std::cout << "Flow " << f.get_flow(3,2) << std::endl;
//     std::cout << "Flow " << f.get_flow(3,5) << std::endl;
//     std::cout << "Flow " << f.get_flow(4,3) << std::endl;
//     std::cout << "Flow " << f.get_flow(4,5) << std::endl;

    std::cout << "Flow 0 - 1 " << f.GetFlow(0,1) << std::endl;
    std::cout << "Flow 0 - 4 " << f.GetFlow(0,4) << std::endl;
    std::cout << "Flow 1 - 2 " << f.GetFlow(1,2) << std::endl;
    std::cout << "Flow 1 - 3 " << f.GetFlow(1,3) << std::endl;
    std::cout << "Flow 2 - 5 " << f.GetFlow(2,5) << std::endl;
    std::cout << "Flow 3 - 2 " << f.GetFlow(3,2) << std::endl;
    std::cout << "Flow 3 - 5 " << f.GetFlow(3,5) << std::endl;
    std::cout << "Flow 4 - 1 " << f.GetFlow(4,1) << std::endl;
    std::cout << "Flow 4 - 3 " << f.GetFlow(4,2) << std::endl;
}