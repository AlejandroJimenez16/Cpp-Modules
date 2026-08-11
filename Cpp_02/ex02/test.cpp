#include "Fixed.hpp"

int main( void )
{
	std::cout << "-----------------------------" << std::endl;
	// Comparaciones
	std::cout << "Comparaciones: " << std::endl;
	Fixed a(2);
	Fixed b(3);

	std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << "-----------------------------" << std::endl;
	
	// Operaciones
	std::cout << "Operaciones: " << std::endl;
	Fixed sum = a + b;
	Fixed rest = a - b;
	Fixed mult = a * b;
	Fixed div = a / b;
	
	std::cout << "a + b: " << sum << std::endl;
	std::cout << "a - b: " << rest << std::endl;
	std::cout << "a * b: " << mult << std::endl;
	std::cout << "a / b: " << div << std::endl;

	std::cout << "-----------------------------" << std::endl;

	// Incrementos/Decrementos
	std::cout << "Incremento/Decremento: " << std::endl;
	Fixed c;
	Fixed d;

	std::cout << "c: " << c << std::endl;
	std::cout << "++c: " << ++c << std::endl;
	std::cout << "c++: " << c++ << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "d: " << d << std::endl;
	std::cout << "--d: " << --d << std::endl;
	std::cout << "d--: " << d-- << std::endl;
	std::cout << "d: " << d << std::endl;

	std::cout << "-----------------------------" << std::endl;

	// Min/Max
	
	std::cout << "Min/Max: " << std::endl;
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	
	std::cout << "\nmin(a, b): " << Fixed::min(a , b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a , b) << std::endl;
	
	std::cout << "-----------------------------" << std::endl;
	
	return (0);
}
