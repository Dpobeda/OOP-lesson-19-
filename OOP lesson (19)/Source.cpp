#include <iostream>
#include <exception>
#include <string>

#include <format> // Позволяет создавать форматированые строки.

// noexcept - это решение которое принимаеться по конкретной функции, выяляет где не нужно исключение.
int NoexeptSumm(int a, int b) noexcept
{
	throw 1;
	return a + b;
}

int ExeptDivide(int a, int b)
{
	if (!b)
	{
		throw 1;
	}

	return a / b;
}

void FO0(int a)
{
	std::string word {"qwertyuiop"};
	if (a < 0)
	{
		throw std::range_error("ar \a*\* mas less then 0");
	}

	int* p = new int[a];

	if (true)
	{
		delete[]p;

		throw std::exception(std::string("message").c_str());
	};
}

int main() {
	setlocale(LC_ALL, "Russian");

	try {
		FO0(-1);
	}

	catch (int &val)
	{
		std::cerr << " someting wrong error code " << val << "\n";
	}

	catch (std::range_error& ex)
	{
		std::cerr << ex.what();
	}

	catch (std::exception& ex)
	{
		std::cerr << ex.what();
	}

	catch (...)
	{
		std::cerr << " someting wrong";
	}

	return {};
}