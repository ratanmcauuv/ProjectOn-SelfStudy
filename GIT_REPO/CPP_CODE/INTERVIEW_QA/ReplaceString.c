#include <stdio.h>
#include <stdlib.h>

int strLen(char *S) {
	int l = 0;
	while(*S++ != '\0') {
		l++;
	}
	return l;
}

//Welcome to GainWell
//Space
char *replaceSpaceWithString(char *S)
{
	int len = strLen(S) + strLen("GainWell");
	char *ReplacedString = (char *)malloc(len);
	int idx = 0;

    if(ReplacedString != NULL) 
    {
    	while(*S != '\0')
    	{
    		char SS[] = "Space";
    		if(*S == '\t' || *S == ' ') {
    		    int j = 0;
    			while(SS[j] != '\0') {
    			    ReplacedString[idx++] = SS[j++];
    			}
    		}
    		else
    		{
    			ReplacedString[idx++] = *S;
    		}
    		S++;
    	}
    	ReplacedString[idx] = '\0';
    }
	return ReplacedString;
}

int main()
{
    char Sentence[] = "Welcome to GainWell";
    char *repSentence = replaceSpaceWithString(Sentence);
    printf("Sentence ::: %s\n", Sentence);
    printf("Edited Sentence ::: %s\n", repSentence);
    
    return 0;
}