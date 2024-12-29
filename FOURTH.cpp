''''#include <iostream>
#include <vector>

bool isRectangleOverlap(const std::vector<int>& rec1, const std::vector<int>& rec2) {
  int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
  int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];

  if (x2 <= x3  x1 >= x4  y2 <= y3 || y1 >= y4) {
    return false;
  }
  return true;
}

int main() {
  std::vector<int> rec1(4), rec2(4);

  std::cout << "Enter (x1, y1, x2, y2): ";
  for (int i = 0; i < 4; ++i) {
    std::cin >> rec1[i];
  }

  std::cout << "Enter (x3, y3, x4, y4): ";
  for (int i = 0; i < 4; ++i) {
    std::cin >> rec2[i];
  }

  bool result = isRectangleOverlap(rec1, rec2);
  if (result) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;
}