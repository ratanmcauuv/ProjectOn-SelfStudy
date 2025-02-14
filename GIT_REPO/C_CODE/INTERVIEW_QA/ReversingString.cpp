#include <iostream>
#include <cstring>
using namespace std;

//ratan kumar pradhan
void reverseString(char *S)
{
    int len = strlen(S);
    char *begin = S;
    char *end = begin + len - 1;
    
    while(begin <= end)
    {
        char T;
        T = *begin;
        *begin = *end;
        *end = T;
        
        begin++, end--;
    }
}

int main()
{
    char s[] = "ratan kumar pradhan";
    std::cout << "s ::: " << s << std::endl;
    
    reverseString(s);
    std::cout << "After reverse, s ::: " << s << std::endl;
    
    return 0;
}

/*OUTPUT :- 
s ::: ratan kumar pradhan
After reverse, s ::: nahdarp ramuk natar
*/