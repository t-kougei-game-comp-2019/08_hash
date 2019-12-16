#include <stdio.h>
#include <string.h>

#define STR_MAX 255
#define HASH_MAX 10
void HashFn(char str[], char Hash[][STR_MAX])
{
	int sum = 0;
	char tmp[STR_MAX] = {};
	strncpy(tmp, str, STR_MAX);

	for (int i = 0; i < STR_MAX; i++)
	{
		if (tmp[i] == '\n')
		{
			break;
		}
		sum += tmp[i];
	}
	int HashNum = sum % 10;
	while (Hash[HashNum][0] != '\n')
	{
		HashNum = (HashNum + 1) % HASH_MAX;
	}
	strncpy(Hash[HashNum], tmp, STR_MAX);
}
void ShowHash(char Hash[][STR_MAX])
{
	for (size_t i = 0; i < HASH_MAX; i++)
	{
		if (Hash[i] != NULL)
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
	//HashFn("a\n", Hash);
	while (fgets(str, sizeof(str), stdin))
	{
		if (str[0] != '\n')
			HashFn(str, Hash);
		else
			ShowHash(Hash);
	}
	return 0;
}
