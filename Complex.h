// Written by Matthew Zeilbeck sometime in 2018 or 2019
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex {
public:
	Complex(double re_in);
	explicit Complex(double re_in, double im_in);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	double re() const;
	double im() const;
	void redef(double re_in, double im_in);
	double modulus() const;
	double phase() const;
	Complex conjugate() const;
	Complex operator-() const;
	Complex operator+(double rhs) const;
	Complex operator-(double rhs) const;
	Complex operator*(double rhs) const;
	Complex operator/(double rhs) const;
	void operator+=(double rhs);
	void operator-=(double rhs);
	void operator*=(double rhs);
	void operator/=(double rhs);
	Complex operator+(const Complex& rhs) const;
	Complex operator-(const Complex& rhs) const;
	Complex operator*(const Complex& rhs) const;
	Complex operator/(const Complex& rhs) const;
	void operator+=(const Complex& rhs);
	void operator-=(const Complex& rhs);
	void operator*=(const Complex& rhs);
	void operator/=(const Complex& rhs);
	friend Complex operator+(double lhs, const Complex& rhs);
	friend Complex operator-(double lhs, const Complex& rhs);
	friend Complex operator*(double lhs, const Complex& rhs);
	friend Complex operator/(double lhs, const Complex& rhs);
	Complex exp(const Complex& arg);
private:
	double real;
	double imaginary;
};

#endif