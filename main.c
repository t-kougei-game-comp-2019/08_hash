#include <stdio.h>
#include <string.h>

#define  _CRT_SECURE_NO_WARNINGS

#define STR_MAX 258
#define HASH_MAX 10
int IsHashEmpty[HASH_MAX];
void HashFn(int HashNum, char Hash[][STR_MAX]) {
	while (IsHashEmpty[HashNum] != 0)
	{
		HashNum = (HashNum + 1) % HASH_MAX;
	}
	//strncpy(Hash[HashNum], tmp, STR_MAX);
	IsHashEmpty[HashNum] = 1;
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
	char Hash[HASH_MAX][STR_MAX];
	char str[STR_MAX];
	for (int i = 0; i<HASH_MAX; i++)
		IsHashEmpty[i] = 0;
	while (fgets(str, sizeof(str), stdin))
	{
		if (str[0] != '\n')
		{
			int sum = 0;
			for (int i = 0; i < STR_MAX; i++)
			{
				if (str[i] == '\n')
				{
					str[i] = '\0';
					break;
				}
				sum += str[i];
				sum %= HASH_MAX;
			}
			int HashNum = sum;
			int hashCount = 0;
			while (IsHashEmpty[HashNum] != 0) {
				HashNum = (HashNum + 1) % HASH_MAX;
				hashCount++;
				if (hashCount > HASH_MAX)break;
			}
				strncpy(Hash[HashNum], sizeof(Hash[HashNum]), str, STR_MAX);
			IsHashEmpty[HashNum] = 1;
		}
		else
		{
			for (size_t i = 0; i < HASH_MAX; i++)
			{
				if (IsHashEmpty[i] != 0)
					printf("%s", Hash[i]);
				if (i + 1 == 10)
					printf("\n");
				else
					printf(",");
			}
		}
	}
	return 0;
}
