''''#include <iostream>
#include <numeric>
#include <stdexcept>

class Fraction {
  private: int numerator;
  int denominator;
  void simplify() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }

  public: Fraction(int num = 0, int denom = 1) {
    if (denom == 0) {
      throw std::invalid_argument("Denominator cannot be zero.");
    }
    numerator = num;
    denominator = denom;
    simplify();
  }
  int getNumerator() const {
    return numerator;
  }
  int getDenominator() const {
    return denominator;
  }
  void setNumerator(int num) {
    numerator = num;
    simplify();
  }
  void setDenominator(int denom) {
    if (denom == 0) {
      throw std::invalid_argument("Denominator cannot be zero.");
    }
    denominator = denom;
    simplify();
  }
  double toDouble() const {
    return static_cast < double > (numerator) / denominator;
  }
  Fraction operator + (const Fraction & other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
  }
  Fraction operator - (const Fraction & other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
  }
  Fraction operator * (const Fraction & other) const {
    int num = numerator * other.numerator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
  }
  Fraction operator / (const Fraction & other) const {
    if (other.numerator == 0) {
      throw std::invalid_argument("Division by zero.");
    }
    int num = numerator * other.denominator;
    int denom = denominator * other.numerator;
    return Fraction(num, denom);
  }

  Fraction & operator += (const Fraction & other) {
    * this = * this + other;
    return * this;
  }

  Fraction & operator -= (const Fraction & other) {
    * this = * this - other;
    return * this;
  }

  Fraction & operator *= (const Fraction & other) {
    * this = * this * other;
    return * this;
  }

  Fraction & operator /= (const Fraction & other) {
    * this = * this / other;
    return * this;
  }

  Fraction & operator = (const Fraction & other) {
    if (this != & other) {
      numerator = other.numerator;
      denominator = other.denominator;
    }
    return * this;
  }

  friend std::ostream & operator << (std::ostream & out,
    const Fraction & fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
  }

  friend std::istream & operator >> (std::istream & in, Fraction & fraction) {
    int num, denom;
    char slash;

    in >> num >> slash >> denom;

    if (slash != '/' || denom == 0) {
      throw std::invalid_argument("Invalid fraction input.");
    }

    fraction = Fraction(num, denom);
    return in;
  }
};

int main() {
  try {
    Fraction f1(3, 4);
    Fraction f2(2, 5);

    std::cout << "f1: " << f1 << "\n";
    std::cout << "f2: " << f2 << "\n";

    std::cout << "f1 + f2 = " << f1 + f2 << "\n";
    std::cout << "f1 - f2 = " << f1 - f2 << "\n";
    std::cout << "f1 * f2 = " << f1 * f2 << "\n";
    std::cout << "f1 / f2 = " << f1 / f2 << "\n";

    f1 += f2;
    std::cout << "After f1 += f2, f1 = " << f1 << "\n";

    f1 -= f2;
    std::cout << "After f1 -= f2, f1 = " << f1 << "\n";

    f1 *= f2;
    std::cout << "After f1 *= f2, f1 = " << f1 << "\n";

    f1 /= f2;
    std::cout << "After f1 /= f2, f1 = " << f1 << "\n";

    std::cout << "f1 as double: " << f1.toDouble() << "\n";

    Fraction f3;
    std::cout << "Enter a fraction (format: a/b): ";
    std::cin >> f3;
    std::cout << "You entered: " << f3 << "\n";
  } catch (const std::exception & e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}