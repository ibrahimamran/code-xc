''''''#include <iostream>
#include <vector>

std::vector<std::vector<int>> SpiralMatrix(int m, int n, const std::vector<int>& head) {
  std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));
  int top = 0, bottom = m - 1, left = 0, right = n - 1;
  int index = 0;

  while (top <= bottom && left <= right && index < head.size()) {
    for (int i = left; i <= right && index < head.size(); i++) {
      matrix[top][i] = head[index++];
    }
    top++;

    for (int i = top; i <= bottom && index < head.size(); i++) {
      matrix[i][right] = head[index++];
    }
    right--;

    for (int i = right; i >= left && index < head.size(); i--) {
      matrix[bottom][i] = head[index++];
    }
    bottom--;

    for (int i = bottom; i >= top && index < head.size(); i--) {
      matrix[i][left] = head[index++];
    }
    left++;
  }

  return matrix;
}

int main() {
  int m, n;
  std::cin >> m >> n;

  int num;
  std::vector<int> head;
  std::cout << "Enter elements (enter any non-integer to end input): ";
  while (std::cin >> num) {
    head.push_back(num);
  }

  std::vector<std::vector<int>> result = SpiralMatrix(m, n, head);
  for (const auto& row : result) {
    for (int val : row) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}