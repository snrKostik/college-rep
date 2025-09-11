#include <algorithm>
#include <iostream>
#include <print>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> arr = {0, 1, 2, 3, 4, -2, 6, 7, 8, 9, 10};
  int left = 0;
  int right = arr.size() - 1;
  int goal = 3;
  int mid = 0;

  print("search\n");
  // while (left <= right) {
  //   mid = (right - left) / 2;
  //
  //   if (arr[mid] == goal) {
  //     std::println("{}", goal);
  //     break;
  //   } else if (arr[mid] < goal) {
  //     left = mid + 1;
  //   } else if (arr[mid] > goal) {
  //     right = mid - 1;
  //   }
  // }

  print("\n\nsort\n");
  for (int i = 1; i < arr.size(); i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }

  for (int i = 0; i < arr.size(); i++) {
    print("{} ", arr[i]);
  }

  return 0;
}
