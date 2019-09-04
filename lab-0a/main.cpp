#include "module1.h"
#include "module2.h"
#include "module3.h"
#include <iostream>

int main(int argc, char** argv) {
	std::cout << "Hello, World" << "\n";

	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";

	using namespace Module1;
	std::cout << getMyName() << "\n"; // (A)
	std::cout << Module2::getMyName() << "\n";

	//using namespace Module2; // (B)
	//std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

	using Module2::getMyName;
	std::cout << getMyName() << "\n"; // (B)
}

/*
3. В строке A выводится возвращаемое значение функции getMyName из Module1, в строке D из Module2
4. Ошибка происходит из-за того, что появляются две функции с одинаковыми именами. Можно либо назвать их по-разному, либо не использовать using namespace, а прописывать каждый раз нужное пространство имен.
6. Можно написать using namespace std;
*/
