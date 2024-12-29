exercose2 : ''' #include <iostream>
#include <stdexcept>
#include <cmath>
#include <initializer_list>

class Vector {
 private:
  double * elements;
  size_t length;

 public:
  Vector(): elements(nullptr),
  length(0) {}

  explicit Vector(size_t size): length(size) {
    elements = new double[size]();
  }

  Vector(const std::initializer_list < double > & initList): length(initList.size()) {
    elements = new double[length];
    size_t i = 0;
    for (double val: initList) {
      elements[i++] = val;
    }
  }

  Vector(const Vector & other): length(other.length) {
      elements = new double[length];
      for (size_t i = 0; i < length; ++i) {
        elements[i] = other.elements[i];
      }
    }

    ~Vector() {
      delete[] elements;
    }

  Vector & operator = (const Vector & other) {
    if (this != & other) {
      delete[] elements;
      length = other.length;
      elements = new double[length];
      for (size_t i = 0; i < length; ++i) {
        elements[i] = other.elements[i];
      }
    }
    return * this;
  }

  double get(size_t index) const {
    if (index >= length) {
      throw std::out_of_range("Index out of range");
    }
    return elements[index];
  }

  void set(size_t index, double value) {
    if (index >= length) {
      throw std::out_of_range("Index out of range");
    }
    elements[index] = value;
  }

  size_t size() const {
    return length;
  }

  Vector & operator += (const Vector & other) {
    if (length != other.length) {
      throw std::invalid_argument("Vector sizes must match for addition");
    }
    for (size_t i = 0; i < length; ++i) {
      elements[i] += other.elements[i];
    }
    return * this;
  }

  Vector & operator -= (const Vector & other) {
    if (length != other.length) {
      throw std::invalid_argument("Vector sizes must match for subtraction");
    }
    for (size_t i = 0; i < length; ++i) {
      elements[i] -= other.elements[i];
    }
    return * this;
  }

  Vector & operator *= (double scalar) {
    for (size_t i = 0; i < length; ++i) {
      elements[i] *= scalar;
    }
    return * this;
  }

  Vector operator + (const Vector & other) const {
    Vector result( * this);
    result += other;
    return result;
  }

  Vector operator - (const Vector & other) const {
    Vector result( * this);
    result -= other;
    return result;
  }

  Vector operator * (double scalar) const {
    Vector result( * this);
    result *= scalar;
    return result;
  }

  double operator * (const Vector & other) const {
    if (length != other.length) {
      throw std::invalid_argument("Vector sizes must match for dot product");
    }
    double result = 0.0;
    for (size_t i = 0; i < length; ++i) {
      result += elements[i] * other.elements[i];
    }
    return result;
  }

  friend std::ostream & operator << (std::ostream & os,
    const Vector & vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
      os << vec.elements[i];
      if (i < vec.size() - 1) {
        os << ", ";
      }
    }
    os << "]";
    return os;
  }

  friend std::istream & operator >> (std::istream & is, Vector & vec) {
    size_t size;
    std::cout << "Enter vector size: ";
    is >> size;
    delete[] vec.elements;
    vec.length = size;
    vec.elements = new double[size];
    std::cout << "Enter " << size << " elements: ";
    for (size_t i = 0; i < size; ++i) {
      is >> vec.elements[i];
    }
    return is;
  }
};

int main() {
  Vector v1({
    1,
    2,
    3
  });
  Vector v2({
    4,
    5,
    6
  });

  std::cout << "v1: " << v1 << "\n";
  std::cout << "v2: " << v2 << "\n";

  Vector v3 = v1 + v2;
  std::cout << "v1 + v2: " << v3 << "\n";

  Vector v4 = v1 - v2;
  std::cout << "v1 - v2: " << v4 << "\n";

  Vector v5 = v1 * 2.0;
  std::cout << "v1 * 2.0: " << v5 << "\n";

  double dotProduct = v1 * v2;
  std::cout << "v1 * v2 (dot product): " << dotProduct << "\n";

  std::cin >> v1;
  std::cout << "Updated v1: " << v1 << "\n";

  return 0;
}