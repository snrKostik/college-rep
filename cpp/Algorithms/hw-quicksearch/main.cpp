#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

void printarr(std::vector<int> arr)
{
    for (size_t i = 0; i <= std::size(arr) - 1; i++) {
        std::cout << arr[i] << "\n";
    }
}

int quicksearch(std::vector<int>& arr, int searchfor)
{
    int left = 0;
    int middle = (std::size(arr) - 1) / 2;
    int right = (std::size(arr) - 1);

    while (arr[middle] != searchfor) {
        if (searchfor < arr[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
        middle = (left + right) / 2;
    }
    if (middle == searchfor) {
        return middle;
    }
    return -1;
}

int main()
{
    std::vector<int> arr;
    for (int i = 0; i < 100; i++) {
        arr.push_back(i);
    }
    printarr(arr);

    int target = quicksearch(arr, 50);
    std::cout << "\n---\n";
    std::cout << target << "\n";
    target = quicksearch(arr, 75);
    std::cout << target << "\n";
    target = quicksearch(arr, 90);
    std::cout << target << "\n";
    target = quicksearch(arr, 10);
    std::cout << target << "\n";
}
