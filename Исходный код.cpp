#include <iostream>
int main(){							// Вот на этой строчке Enter очень обиделся. Надеюсь справедливость воссторжествует и include и main будут разделены пустой строкой.
	int A, B, C, D;						// А если все таки придется считать уравнение с нецелочисленными коэфициентами, придется скачивать DLC за 49$?) А как же float?)
	std::cin >> A >> B >> C;
	D = (B*B) - (4 * A*C);
	if (D < 0)
	{							// Здесь произошло смешение кодстайла. В случае с мэин у вас скобка шла на той же строчке а здесь уже на другой.
		std::cout << "NO ROOTS" << "\n";
		std::cout << "Number of roots = 0";

	}
	else if (D == 0)
	{
		std::cout << (-B / (2 * A)) << "\n";		// А если A будет равно 0? как тогда жить? Мы получим самое настоящее деление на ноль.
		std::cout << "Number of roots = 1";
	}
	else{
		std::cout << (-B + sqrt(D)) / (2 * A) << "\n";
		std::cout << (-B - sqrt(D)) / (2 * A) << "\n";
		std::cout << "Number of roots = 2";
	}
	return 0;
	       }						// Надеюсь 2 таба случайно были нажаты)

// Что жеать если пользователь введет вообще все коэфициенты равные 0? корней тогда будет бесконечно много.
// Что делать если коэфициенты A == 0 и B == 0 а C != 0, тогда решений вообще быть не может.
