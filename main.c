#include <stdio.h>
#include <string.h>

#define STR_MAX 255
#define HASH_MAX 10
bool IsHashEmpty[HASH_MAX];
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
	while (IsHashEmpty[HashNum]!= true)
	{
		HashNum = (HashNum + 1) % HASH_MAX;
	}
	strncpy(Hash[HashNum], tmp, STR_MAX);
        IsHashEmpty[HashNum]= true;
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
	char Hash[HASH_MAX][STR_MAX] = {};
	char str[STR_MAX];
	for(int i=0;i<HASH_MAX)
            IsHashEmpty[i]=true;
	while (fgets(str, sizeof(str), stdin))
	{
		if (str[0] != '\n')
			HashFn(str, Hash);
		else
			ShowHash(Hash);
	}
	return 0;
}
