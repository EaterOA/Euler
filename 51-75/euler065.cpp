#include <iostream>

using namespace std;

//Quick hack of a BigInteger class
struct StaticBigInt {
	typedef unsigned short baseType;
	StaticBigInt(int d) {
		D = d;
		arr = (baseType*)calloc(sizeof(baseType), D);
	}
	~StaticBigInt() {
		delete arr;
	}
	void lea(StaticBigInt &other, int scale) {
		for (unsigned int i = 0; i < D && i < other.D; i++) arr[i] += other.arr[i] * scale;
		normalize3();
	}
	void add(int num) {
		for (unsigned int i = 0; num > 0; i++, num /= 10) arr[i] += num % 10;
		normalize3();
	}
	void normalize3() {
		for (unsigned int i = 0; i < D-2; i++) {
			if (arr[i] < 10) continue;
			arr[i+2] += arr[i]/100%10;
			arr[i+1] += arr[i]/10%10;
			arr[i] %= 10;
		}
	}
	int sumDigits() {
		int sum = 0;
		for (unsigned int i = 0; i < D; i++) sum += arr[i];
		return sum;
	}
	void swap(StaticBigInt &other) {
		std::swap(D, other.D);
		std::swap(arr, other.arr);
	}
	unsigned int D;
	baseType* arr;
};

#define N 100

int main()
{
	StaticBigInt num(60), den(60);
	den.add(1);
	for (int n = N; n > 0; n--) {
		int val = (n%3?1:2*(n/3));
		if (n == 1) val = 2;
		num.lea(den, val);
		num.swap(den);
	}
	cout << den.sumDigits() << "\n";
}