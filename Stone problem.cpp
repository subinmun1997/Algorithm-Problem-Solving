#include <iostream>
using namespace std;

bool func(const int m, const int n)
{
	if (m == 1 || n == 1)	return true;
	else if (m % 2 == 0 && n % 2 == 0)	return false;

	return func(m - 1, n) | func(m, n - 1) | func(m - 1, n - 1);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int m, n;
	cin >> m >> n;

	if(func(m, n)) cout << "¿µÈñ°¡ ¹«Á¶°Ç ÀÌ±é´Ï´Ù.\n";
	else cout << "Ã¶¼ö°¡ ¹«Á¶°Ç ÀÌ±é´Ï´Ù. \n";
}

