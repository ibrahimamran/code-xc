'''''#include <iostream>
#include <string>
#include <algorithm>

std::string addBinary(const std::string& a, const std::string& b) {
  std::string result = "";
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;

  while (i >= 0  j >= 0  carry > 0) {
    int sum = carry;
    
    if (i >= 0) {
      sum += a[i] - '0';
      i--;
    }

    if (j >= 0) {
      sum += b[j] - '0';
      j--;
    }

    result += (sum % 2) + '0';
    carry = sum / 2;
  }
  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  std::string binary1, binary2;

  std::cout << "Enter first binary: ";
  std::cin >> binary1;

  std::cout << "Enter second binary: ";
  std::cin >> binary2;

  std::string sum = addBinary(binary1, binary2);

  std::cout << sum << std::endl;

  return 0;
}