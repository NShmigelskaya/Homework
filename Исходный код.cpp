#include <iostream>
int main(){
	int A, B, C, D;
	std::cin >> A >> B >> C;
	D = (B*B) - (4 * A*C);
	if (D < 0)
	{
		std::cout << "NO ROOTS" << "\n";
		std::cout << "Number of roots = 0";

	}
	else if (D == 0)
	{
		std::cout << (-B / (2 * A)) << "\n";
		std::cout << "Number of roots = 1";
	}
	else{
		std::cout << (-B + sqrt(D)) / (2 * A) << "\n";
		std::cout << (-B - sqrt(D)) / (2 * A) << "\n";
		std::cout << "Number of roots = 2";
	}
	return 0;
	       }