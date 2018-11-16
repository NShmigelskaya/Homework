#include <iostream>
#include <cassert>

#define ASSERT_EQUAL(val1,val2) assert (val1==val2); std::cout<<val1<<std::endl; std::cout<<val2<<std::endl;
#define ASSERT_NEQUAL(val1,val2) assert(val1!=val2); std::cout<<val1<<std::endl; std::cout<<val2<<std::endl;
#define ASSERT_TRUE(val1) assert(val1); std::cout<<val1<<std::endl;
#define ASSERT_FALSE(val2) assert(!val2); std::cout<<val2<<std::endl;
void Function(int val1, int val2) {
	if (val1 == val2) {
		std::cout << val1 << std::endl;
		std::cout << val2 << std::endl;
	}
	if (val1 != val2) {
		std::cout << val1 << std::endl;
		std::cout << val2 << std::endl;
	}
	if (val1) {
		std::cout << val1<<std::endl;
	}
	if (!val2) {
		std::cout << val2 << std::endl;
	}
}
int main()
{
	int val1,val2;
	std::cin >> val1;
	std::cin >> val2;
	ASSERT_EQUAL(val1, val2);
	ASSERT_NEQUAL(val1, val2);
	ASSERT_TRUE(val1);
	ASSERT_FALSE(val2);
	Function(val1,val2);
	system("pause");
	return 0;

}

