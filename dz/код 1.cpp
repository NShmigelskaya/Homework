#include <iostream>
#include <math.h>

int main() {

	float a = 0, b = 0, c = 0, d = 0;
	std::cin >> a >> b >> c;
	d = (b*b) - (4 * a*c);
	if (abs(a) < 0.000001) {

		if (abs(b) < 0.000001) {
			if ( abs(c) < 0.000001) {
				std::cout << "INFINITY" << std::endl;
			}
			else {
				std::cout << "NO ROOTS" << std::endl;
				std::cout << "Number of roots = 0";
			}
		}
		else {
			if (abs(c) < 0.000001) {
				std::cout << 0 << std::endl;
			}
			else {
				std::cout << -c / b << std::endl;
			}
		}
	}
	else {
		if (abs(b) < 0.000001){

			if (abs(c) < 0.000001){
				std::cout << 0 << std::endl;
			}
			else if (c > 0){
				std::cout << "NO ROOTS" << std::endl;
				std::cout << "Number of roots = 0" << std::endl;
			}
			else {
				std::cout << sqrt(-c / a) << std::endl;
			}
		}
		else if (d < 0) {

			std::cout << "NO ROOTS" << std::endl;
			std::cout << "Number of roots = 0";
		}
		else if (abs(d) < 0.000001) {

			std::cout << (-b / (2 * a)) << std::endl;
			std::cout << "Number of roots = 1";
		}

		else if (d > 0) {

			std::cout << (-b + sqrt(d)) / (2 * a) << std::endl;
			std::cout << (-b - sqrt(d)) / (2 * a) << std::endl;
			std::cout << "Number of roots = 2";
		}
	}
	return 0;
}
