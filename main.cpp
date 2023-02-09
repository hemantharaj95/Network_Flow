#include <matching.h>

int main()
{
    Matching mat = Matching();
    mat.AddLeftNode(1);
    mat.AddLeftNode(2);
    mat.AddLeftNode(3);
    mat.AddRightNode(4);
    mat.AddRightNode(5);

    mat.Add(1,4);
    mat.Add(1,5);
    mat.Add(2,4);
    mat.Add(2,5);
    mat.Add(3,5);

    mat.BipartileMatching();
}