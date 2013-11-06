#include <iostream>

int arr[20];

long long getLCM(long long n1, long long n2)
{
	long long lowest = std::min(n1, n2);
	int factor = 1;
	for (int n = 2; n <= lowest; n++)
		while (n1 % (factor*n) == 0 && n2 % (factor*n) == 0)
			factor *= n;
	return n1 * n2 / factor;
}

long long getArrLCM(int left, int right)
{
	if (right - left <= 1)
		return getLCM(arr[left], arr[right]);
	int mid = (left + right) / 2;
	return getLCM(getArrLCM(left, mid), getArrLCM(mid + 1, right));
}

int main()
{
	for (int n = 0; n < 20; n++)
		arr[n] = n + 1;
	std::cout << getArrLCM(0, 19) << "\n";
}