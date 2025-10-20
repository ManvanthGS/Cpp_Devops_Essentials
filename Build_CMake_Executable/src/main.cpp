#include "main.h"

int main() {
	// Prompt and read input
	std::cout << "Project: " << PROJECT_NAME << " Version: " << PROJECT_VERSION << '\n';
	std::cout << "Enter a number: ";
	double x;
	if (!(std::cin >> x)) {
		std::cerr << "Invalid input. Please enter a numeric value.\n";
		return 1;
	}

	// Compute square root (real or complex)
	if (x >= 0.0) {
		double r = std::sqrt(x);
		std::cout << std::fixed << std::setprecision(10);
		std::cout << "Square root (real): " << r << '\n';
	} else {
		std::complex<double> z(x, 0.0);
		std::complex<double> s = std::sqrt(z);
		std::cout << std::fixed << std::setprecision(10);
		std::cout << "Square root (complex): " << s.real() << (s.imag() >= 0 ? " + " : " - ") 
		          << std::abs(s.imag()) << "i\n";
	}

	return 0;
}
