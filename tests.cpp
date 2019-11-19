#include "Complex.h"
#include <iostream>
#include <cassert>
#include <cmath>
#define ASSERT_ALMOST(l, r) assert(fabs(l - r) < 1e-4)
using namespace std;

void basic_tests() {
	Complex c1(3, 4);
	ASSERT_ALMOST(c1.re(), 3);
	ASSERT_ALMOST(c1.im(), 4);
	ASSERT_ALMOST(c1.modulus(), 5);
	ASSERT_ALMOST(c1.phase(), .9273);
	bool errored = false;
	try {
		Complex(0, 0).phase();
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
		errored = true;
	}
	assert(errored);
}


int main() {
	basic_tests();
	return 0;
}