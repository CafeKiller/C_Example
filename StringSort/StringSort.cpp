#include<stdio.h>
#include<string.h>
#include<math.h>

void _strcooy_(char* str1, char* str2);


void sort(char(*s)[101])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (strcmp(s[j], s[j + 1]) > 0)
			{
				char t = '\0';
				/*t = (*s)[j];
				(*s)[j] = (*s)[j + 1];
				(*s)[j + 1] = t;*/

				_strcooy_(&t, s[j]);
				_strcooy_(s[j], s[j + 1]);
				_strcooy_(s[j+1], &t);
			}
		}
	}
}
int main()
{
	char s[10][101];
	for (int i = 0; i < 10; i++)
	{
		scanf("%s", s[i]);
	}
	sort(s);
	for (int i = 0; i < 10; i++)
	{
		printf("%s ", s[i]);
	}
	return 0;
}

/// <summary>
///		仿strcopy, 自定义字符交换
/// </summary>
/// <param name="dest">输入字符</param>
/// <param name="src">输出字符</param>
void _strcooy_(char* dest, char* src) {

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}