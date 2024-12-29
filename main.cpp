''''#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex) {
  std::vector<int> row = {1};
  for (int i = 1; i <= rowIndex; ++i) {
    std::vector<int> newRow(i + 1, 1);
    for (int j = 1; j < i; ++j) {
      newRow[j] = row[j - 1] + row[j];
    }
    row = newRow;
    }
  return row;
}

int main() {
  int rowIndex;
  std::cin >> rowIndex;
  std::vector<int> result = getRow(rowIndex);
  std::cout << "[";
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result[i];
    if (i != result.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
  return 0;
}