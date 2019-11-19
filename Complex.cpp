// Written by Matthew Zeilbeck sometime in 2018 or 2019
#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

constexpr double PI = 3.141592653589793238462643383279502884;

Complex::Complex(double re_in) : real{ re_in }, imaginary{ 0 } {}

Complex::Complex(double re_in, double im_in) : real{ re_in },
imaginary{ im_in } {}

ostream& operator<<(ostream& os, const Complex& c) {
	os << c.real << ' ';
	if (c.imaginary >= 0) {
		os << "+ i" << c.imaginary;
	}
	else {
		os << "- i" << -c.imaginary;
	}
	return os;
}

double Complex::re() const {
	return real;
}

double Complex::im() const {
	return imaginary;
}

void Complex::redef(double re_in, double im_in) {
	real = re_in;
	imaginary = im_in;
}

double Complex::modulus() const {
	return sqrt(real * real + imaginary * imaginary);
}

double Complex::phase() const {
	// On the axes
	// Consider removing since real and imaginary are floats
	if (real == 0 && imaginary == 0) {
		throw runtime_error("ERROR: Undefined phase at origin");
	}
	else if (real == 0) {
		if (imaginary > 0) {
			return PI / 2;
		}
		return -PI / 2;
	}
	else if (imaginary == 0) {
		if (real > 0) {
			return 0;
		}
		return PI;
	}
	// Quadrant I or IV
	if ((real > 0 && imaginary > 0) || (real > 0 && imaginary < 0)) {
		return atan(imaginary / real);
	}
	// Quadrant II or III, doesn't need to be explicitly checked for
	return PI + atan(imaginary / real);
}

Complex Complex::conjugate() const {
	return Complex(real, -imaginary);
}

Complex Complex::operator-() const {
	return Complex(-real, -imaginary);
}

Complex Complex::operator+(double rhs) const {
	return Complex(real + rhs, imaginary);
}

Complex Complex::operator-(double rhs) const {
	return Complex(real - rhs, imaginary);
}

Complex Complex::operator*(double rhs) const {
	return Complex(real * rhs, imaginary * rhs);
}

Complex Complex::operator/(double rhs) const {
	return Complex(real / rhs, imaginary / rhs);
}

void Complex::operator+=(double rhs) {
	real += rhs;
}

void Complex::operator-=(double rhs) {
	real -= rhs;
}

void Complex::operator*=(double rhs) {
	real *= rhs;
	imaginary *= rhs;
}

void Complex::operator/=(double rhs) {
	real /= rhs;
	imaginary /= rhs;
}

Complex Complex::operator+(const Complex& rhs) const {
	return Complex(real + rhs.real, imaginary + rhs.imaginary);
}

Complex Complex::operator-(const Complex& rhs) const {
	return Complex(real - rhs.real, imaginary - rhs.imaginary);
}

Complex Complex::operator*(const Complex& rhs) const {
	double r = real * rhs.real - imaginary * rhs.imaginary;
	double i = real * rhs.imaginary + imaginary * rhs.real;
	return Complex(r, i);
}

Complex Complex::operator/(const Complex& rhs) const {
	return *this * rhs.conjugate() / (rhs.modulus() * rhs.modulus());
}

void Complex::operator+=(const Complex& rhs) {
	*this = *this + rhs;
}

void Complex::operator-=(const Complex& rhs) {
	*this = *this - rhs;
}

void Complex::operator*=(const Complex& rhs) {
	*this = *this * rhs;
}

void Complex::operator/=(const Complex& rhs) {
	*this = *this / rhs;
}

Complex operator+(double lhs, const Complex& rhs) {
	return rhs + lhs;
}

Complex operator-(double lhs, const Complex& rhs) {
	return -rhs + lhs;
}

Complex operator*(double lhs, const Complex& rhs) {
	return rhs * lhs;
}

Complex operator/(double lhs, const Complex& rhs) {
	return lhs * rhs.conjugate() / (rhs.modulus() * rhs.modulus());
}

Complex Complex::cexp(const Complex& arg) {
	return Complex(cos(arg.real), sin(arg.imaginary));
}

Complex Complex::csqrt(double arg) {
	return arg < 0 ? Complex(0, sqrt(arg)) : Complex(sqrt(arg), 0);
}