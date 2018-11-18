#include <iostream>
#include <cassert>

#define ASSERT_EQUAL(a,b) if (a!=b)                                  \
							{                                        \
							std::cout << a << "!=" << b << std::endl;\
                            assert(a == b);                          \
                            }
#define ASSERT_NOT_EQUAL(a,b) if (a==b)                              \
							{                                        \
							std::cout << a << "=" << b << std::endl; \
							assert(a!=b);                            \
                            }                                        
#define ASSERT_TRUE(a) if (a==0)                                     \
                           {                                         \
                           std::cout << a << "> 0" << std::endl;     \
                           assert(a != 0);                           \
                           }
#define ASSERT_FALSE(b) if (b!=0)                                    \
							{                                        \
                            std::cout << b << "= 0" << std::endl;    \
                            assert (b==0);                           \
                            }
void AssertEqual(float a, float b)
{
	if (a != b)
	{
		std::cout << a << "!=" << b << std::endl;
		assert(a == b);

		}
}
void AssertNotEqual(float a, float b)
{
	if (a == b) 
	{
		std::cout << a << "=" << b << std::endl;
		assert(a != b);
	}
}
void AssertTrue(float a)
{
	if (a == 0)
	{
		std::cout << a << "> 0" << std::endl;
		assert(a == 0);
	}
}
void AssertFalse(float b)
{
	if (b != 0)
	{
		std::cout << b << "!=0" << std::endl;
		assert(b != 0);
	}
}
int main()
	{
	float a;
	float b;
	int c;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	switch (c) {
	case 1:
		AssertEqual(a, b);
		ASSERT_EQUAL(a, b);
		break;
	case 2:
		AssertNotEqual(a, b);
		ASSERT_NOT_EQUAL(a, b);
		break;
	case 3:
		AssertTrue(a);
		ASSERT_TRUE(a);
		break;
	case 4:
		AssertFalse(b);
		ASSERT_FALSE(b);
	 	break;
	}
	system("pause");
	return 0;
	}
