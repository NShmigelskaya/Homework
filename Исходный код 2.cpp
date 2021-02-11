#include <iostream>

int main() {

	float A, B, C, D;
	std::cin >> A >> B >> C;
	D = (B*B) - (4 * A*C);
	if (A == 0) {

		if (B == 0) {

			if (C != 0) {

				std::cout << "NO ROOTS" << "\n";
				std::cout << "Number of roots = 0";
			}

			else {

				std::cout << "INFINITY" << "\n";
			}
		}
		else {

			if (C == 0) {

				std::cout << 0 << "\n";
			}

			else {

				std::cout << -C / B << "\n";
			}

		}

			}

	else {

		if (D < 0) {

			std::cout << "NO ROOTS" << "\n";
			std::cout << "Number of roots = 0";
		}

		else if (D == 0) {

			std::cout << (-B / (2 * A)) << "\n";
			std::cout << "Number of roots = 1";
		}

		else {

			std::cout << (-B + sqrt(D)) / (2 * A) << "\n";
			std::cout << (-B - sqrt(D)) / (2 * A) << "\n";
			std::cout << "Number of roots = 2";
		}
	}
	return 0;
}