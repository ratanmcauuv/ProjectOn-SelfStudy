#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::vector<int> intVector = {12,23,34,45,56,67,78,89,90};
    std::sort(intVector.begin(), intVector.end(), [](int i, int j){
        return i > j;
    });

    std::for_each(intVector.begin(), intVector.end(), [](int n){
        std::cout << n << " ";
    });
    std::cout << "\n";
    return 0;
}
