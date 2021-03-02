
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, tot_hour = 0, tot_minute = 0, num, tim;
		cin >> n >> tim;
		for (int i = 1; i <= n; i++)
		{
			int start_hour, start_minute, end_hour, end_minute;
			scanf("%d:%d %d:%d", &start_hour, &start_minute, &end_hour, &end_minute);
			//cin >> start_hour >> start_minute >> end_hour >> end_minute;

			if (end_minute >= start_minute) tot_minute += end_minute - start_minute;
			else tot_minute += 60 + end_minute - start_minute, end_hour = end_hour - 1;

			tot_hour += end_hour - start_hour;
		}
		tot_hour += tot_minute / 60;
		if (tot_hour >= tim) printf("YES\n");
		else printf("NO\n");

	}
}
