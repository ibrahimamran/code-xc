"""" #include <iostream>
#include <vector>
#include <string>

std::string kDistinct_String(std::vector<std::string>& arr, int k) {
  std::vector<int> counts(arr.size(), 0);
  std::vector<std::string> distinct_strings;
  for (int i = 0; i < arr.size(); i++) {
    int count = 0;
    for (int j = 0; j < arr.size(); j++) {
      if (arr[i] == arr[j]) {
        count++;
      }
    }
    counts[i] = count;
  }
  for (int i = 0; i < arr.size(); i++) {
    if (counts[i] == 1) {
      distinct_strings.push_back(arr[i]);
    }
  }
  if (k <= distinct_strings.size()) {
    return distinct_strings[k - 1];
  } else {
    return "";
  }
}

int main() {
  int k;
  std::cin >> k;
  std::vector<std::string> arr;
  std::string input;
  std::cout << "Enter the strings (type 'end' to finish input):" << std::endl;
  while (true) {
    std::cin >> input;
    if (input == "end") {
      break;
    }
    arr.push_back(input);
  }
  std::string result = kDistinct_String(arr, k);
  if (result.empty()) {
    std::cout << "" << std::endl;
  } else {
    std::cout << result << std::endl;
  }
  return 0;
}