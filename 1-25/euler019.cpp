#include <iostream>

int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int count = 0, day = 2;
	for (int y = 1901; y < 2001; y++) {
		for (int m = 0; m < 12; m++) {
			if (day == 0)
				count++;
			day = (day + (m==1 && y%4==0 && y%400!=0 ? 29 : days[m])) % 7;
		}
	}
	std::cout << count << "\n";
}