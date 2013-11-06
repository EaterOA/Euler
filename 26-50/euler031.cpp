#include <iostream>

#define C 8
#define N 200

int main()
{
	int currency[] = {1,2,5,10,20,50,100,200}, ways[N+1] = {0};
	ways[0] = 1;
	for (int c = 0; c < C; c++)
		for (int n = 0; n + currency[c] <= N; n++)
			ways[n+currency[c]] += ways[n];
	std::cout << ways[N] << "\n";
}