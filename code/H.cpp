#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, surface_area;
		cin >> surface_area;
		
		int edge = (int)sqrt(surface_area/6); 
		printf("%d\n", edge);

	}
}
