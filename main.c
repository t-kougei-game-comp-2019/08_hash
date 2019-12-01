#include <stdio.h>
#include <string.h>

#define STR_MAX 256
#define HASH_MAX 10
void HashFn(char *str,char Hash[][STR_MAX])
{
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		if (str[i] == '\n')
			str[i] = '\0';
		sum += str[i];
	}
	int HashNum = sum % 10;
	for (; strcmp(Hash[HashNum], "\0") == 0; HashNum=(HashNum+1)%HASH_MAX)
	{}
	strcpy(Hash[HashNum], str);
}
int main(int argc, char *argv[])
{
	char Hash[10][STR_MAX] = {};
	char str[STR_MAX];
	while (fgets(str, sizeof(str), stdin))
	{
		int sum = 0;
		if (strcmp(str, "\0") != 0)
			HashFn(str, Hash);
		
		
	}
	
	return 0;
}
