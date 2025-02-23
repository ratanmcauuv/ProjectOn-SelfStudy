/*************************************
TODO:
    Functionality not working
*************************************/
#include <stdio.h>
#include <string.h>

struct Strings
{
    char s[20];
    int len;
};
struct Strings StringCollection[20];

void subStringNonRepeation(char *s)
{
    for(int idx = 0; idx != strlen(s); idx++)
    {
        int F[26] = {0};
        int i = idx;
        for(; i != strlen(s); i++)
        {
            F[s[i]-'a']++;
            if(F[s[i]-'a'] > 1)
                break;
        }
        char ss[20];
        strncpy(ss, s+idx, i);
        strcpy(StringCollection[idx].s, ss); 
        StringCollection[idx].len = i;
        memset(F, 0, sizeof(F));
    }    
}

int main()
{
    char s[] = "mountainer";
    subStringNonRepeation(s);
    
    for(int i = 0; i < 5; i++)
        printf("%s - %d\n", StringCollection[i].s, StringCollection[i].len);
    
    return 0;
}