#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;


char author[120];
char title[120];
char journal[120];
char year[120];
char volume[120];
char number[120];
char pages[120];

int ai = 0, ti = 0, ji = 0, yi = 0, vi = 0, ni = 0, pi = 0;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		getchar();
		for (int i = 0; i < n; i++)
		{
			char x[150];
			for (int j = 0; j < 10; j++)
			{
				gets_s(x);
				int len = strlen(x);
				int flag = 0;
				if (x[0] == 'a')
				{
					for (int k = 0; k < len; k++)
					{
						if (!flag&&x[k] >= 'A'&&x[k] <= 'Z')
						{
							author[ai++] = x[k];
							author[ai++] = x[++k];
							author[ai++] = '.';
							author[ai++] = ' ';
							flag = 1;
						}
						else if (flag&&x[k] >= 'A'&&x[k] <= 'Z')
						{
							author[ai++] = x[k];
							flag = 0;
							author[ai++] = ',';
							author[ai++] = ' ';
						}
					}
					author[ai - 1] = '\0';
					author[ai - 2] = '.';
				}
				else if (x[0] == 't')
				{
					for (int k = 0; k < len; k++)
					{
						if (x[k] == '}')
							break;
						if (x[k] == '{')
						{
							flag = 1;
						}
						else if (flag)
						{
							title[ti++] = x[k];
						}
					}
					title[ti++] = '.';
				}
				else if (x[0] == 'j')
				{
					for (int k = 0; k < len; k++)
					{
						if (x[k] == '}')
							break;
						if (x[k] == '{')
						{
							flag = 1;
						}
						else if (flag)
						{
							journal[ji++] = x[k];
						}
					}
					journal[ji++] = '.';
				}
				else if (x[0] == 'y')
				{
					for (int k = 0; k < len; k++)
					{
						if (x[k] == '}')
							break;
						if (x[k] == '{')
						{
							flag = 1;
						}
						else if (flag)
						{
							year[yi++] = x[k];
						}
					}
					year[yi++] = ';';
				}
				else if (x[0] == 'v')
				{
					for (int k = 0; k < len; k++)
					{
						if (x[k] == '}')
							break;
						if (x[k] == '{')
						{
							flag = 1;
						}
						else if (flag)
						{
							volume[vi++] = x[k];
						}
					}
				}
				else if (x[0] == 'n')
				{
					for (int k = 0; k < len; k++)
					{
						if (x[k] == '}')
							break;
						if (x[k] == '{')
						{
							flag = 1;
						}
						else if (flag)
						{
							number[ni++] = x[k];
						}
					}
				}
				else if (x[0] == 'p'&&x[1] == 'a')
				{
					for (int k = 0; k < len; k++)
					{
						if (x[k] == '}')
							break;
						if (x[k] == '{')
						{
							flag = 1;
						}
						else if (flag)
						{
							pages[pi++] = x[k];
						}
					}
				}
			}
			cout << author << " " << title << " " << journal << " " << year <<
				volume << '(' << number << "):" << pages << '.' << endl;

			ai = 0, ti = 0, ji = 0, yi = 0, vi = 0, ni = 0, pi = 0;
			memset(author, 0, sizeof(author));
			memset(title, 0, sizeof(title));
			memset(journal, 0, sizeof(journal));
			memset(year, 0, sizeof(year));
			memset(volume, 0, sizeof(volume));
			memset(number, 0, sizeof(number));
			memset(pages, 0, sizeof(pages));

		}

	}
	return 0;
}

