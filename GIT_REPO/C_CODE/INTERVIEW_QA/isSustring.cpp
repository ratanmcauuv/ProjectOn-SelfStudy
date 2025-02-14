#include <iostream>
#include <cstring>
using namespace std;

int checkIfSubstring(char *S, char *SS)
{
	bool isFound = false;
	for(int i = 0; i < strlen(S); i++)
	{
		int j = 0;
		for(; j < strlen(SS); j++)
		{
			if(S[i] == SS[j])
				i++;
			else
				break;
		}
		//If all element traversed
		if(j == strlen(SS)) {
			isFound = true;
		}
	}
	return isFound;
}

int main()
{
	char s[] = "HeIIllo II aIIm heIIre II .";
	char ss[] = "II";

	if(checkIfSubstring(s, ss))
		std::cout << "FOUND\n";
	else
		std::cout << "Not FOUNT !!\n";

	return 0;
}