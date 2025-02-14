#include <iostream>
#include <memory>
using namespace std;

int main()
{
    /* Demo of Memory Leak with Raw Pointer */
    int *iPtr = new int(100);
    std::cout << "Value of iPtr :: " << *iPtr  << std::endl;
    delete iPtr;

    /* Demo of Memory Leak with Smart Pointer */
    std::shared_ptr<int> SPtr = std::make_shared<int>(200);
    std::cout << "Value of SPtr :: " << *SPtr  << std::endl;

    return 0;
}