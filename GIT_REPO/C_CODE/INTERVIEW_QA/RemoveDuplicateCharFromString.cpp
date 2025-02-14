#include <iostream>
#include <cstring>
using namespace std;

//aaasssaasssasaaabbbbabababababababababa
void removeDuplicatesFromString(char *s)
{
    int len = strlen(s);
    int idx = 0;
    
    for(int i = 0; i < len; i++)
    {
        int j = 0;
        for(; j < i; j++)
        {
            if(s[i] == s[j])
                break;
        }
        if(i == j) //All the Elements traversed
            s[idx++] = s[i];
    }
    s[idx] = '\0';
}

int main()
{
    char S[] = "aaasssaasssasaaabbbbabababababababababa";
    std::cout << "S :::: " << S << std::endl;
    
    removeDuplicatesFromString(S);
    std::cout << "After remove the duplicates, S :::: " << S << std::endl;
    
    return 0;
}

/***************************************

OUTPUT :-
S :::: aaasssaasssasaaabbbbabababababababababa
After remove the duplicates, S :::: asb

*****************************************/
