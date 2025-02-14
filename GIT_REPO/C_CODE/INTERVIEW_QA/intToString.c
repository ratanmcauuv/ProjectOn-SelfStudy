//TODO :
// To check Overflow condition

#include <string.h>

char *intToString(int a[], int n) 
{
    static char S[1000];
    char ss[10];
    
    for(int i = 0; i < n; i++) {
        sprintf(ss, "%d", a[i]);
        strcat(S,ss);
    }
    return S;
}

int main()
{
    int a[] = {12,23,45,56,54,78,89};
    char *s = intToString(a, sizeof(a)/sizeof(a[0]));
    printf("%s", s);
    printf("Length Of String :: %lu\n", strlen(s));
    
    return 0;
}