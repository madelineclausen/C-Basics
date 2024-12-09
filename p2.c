#include <stdio.h>

int main()
{
	char userstring[75];
	fgets(userstring, 75, stdin);
	for (int i=0; userstring[i] != 0; i++)
	{
		if (userstring[i] == 9 || userstring[i] == 32)
		{
			printf("\n");
		}
		else
		{
			printf("%c", userstring[i]);
		}
	}
	printf("%s", userstring);
	return 0;
}
