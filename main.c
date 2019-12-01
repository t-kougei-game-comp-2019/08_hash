#include <stdio.h>
#include <string.h>

#define STR_MAX 255
#define HASH_MAX 10
void HashFn(char *str, char Hash[][STR_MAX])
{
	int sum = 0;
	for (int i = 0; i < STR_MAX; i++)
	{
		if (str[i] == '\n')
			str[i] = '\0';
		sum += str[i];
	}
	int HashNum = sum % STR_MAX;
	int count;
	for (; strcmp(Hash[HashNum], "\0") != 0; HashNum = (HashNum + 1) % HASH_MAX)
	{
		count++;
		if(count>HASH_MAX)
			break;
	}
	if(count<HASH_MAX)
		strcpy(Hash[HashNum], str);
}
void ShowHash(char Hash[][STR_MAX])
{
	for (size_t i = 0; i < STR_MAX; i++)
	{
		printf("%s", Hash[i]);
		if (i + 1 == 10)
			printf("\n");
		else
			printf(",");
	}
}
int main(int argc, char *argv[])
{
	char Hash[10][STR_MAX] = {};
	char str[STR_MAX];
	while (fgets(str, sizeof(str), stdin))
	{
		if (strcmp(str, "\0") != 0)
			HashFn(str, Hash);
		else
			ShowHash(Hash);
	}

	return 0;
}
