#include <iostream>

using namespace std;

long long Gcd(long long a, long long b) {
	while (b != 0) {
		long long temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main() {
	long long A, B;
	cin >> A >> B;

	long long result = A * B / Gcd(A, B);

	cout << result << "\n";

	return 0;
}