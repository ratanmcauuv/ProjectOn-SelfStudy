#include <stdio.h>
#include <string.h>

void repOfDigits(int n)
{
    int r = 0;
    int F[10] = {0};
    while(n > 0){
        r = n % 10;
        n = n / 10;
        F[r]++;
    }
    for(int i = 0; i <= 9; i++) {
        if(F[i] > 0)
            printf("%d --- %d\n", i, F[i]);
    }
}

void repOfChar(char *s) 
{
    int F[52] = {0};
    for(int i = 0; i != strlen(s); i++) 
    {
        F[s[i]-'a']++;
    }
    for(int i = 0; i < 52; i++) {
        if(F[i] > 0) {
            printf("%c -- %d\n", i + 'a', F[i]);
        }
    }    
}

int main()
{
    char s[] = "aaabbbbccccccc";
    repOfChar(s);
    
    printf("---------\n");
    int n = 32222432;
    repOfDigits(n);
    
    return 0;
}