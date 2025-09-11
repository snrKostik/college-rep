#pragma once

#include <chrono>
#include <print>

using namespace std;

void Insertion(vector<int> arr);
void Selection(vector<int> arr);

int StepCount = 0;
bool Trust = true; // !!!ОБРАТИТЕ ВНИМАНИЕ. Переключите значение если не
                   // верите работе алгоритма

void Sort(vector<int> arr) {
  chrono::steady_clock::time_point start = chrono::steady_clock::now();

  Insertion(arr);
  chrono::steady_clock::time_point end = chrono::steady_clock::now();
  println("{} ns elapsed\n",
          chrono::duration_cast<chrono::nanoseconds>(end - start).count());

  chrono::steady_clock::time_point start1 = chrono::steady_clock::now();
  Selection(arr);
  chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
  println("{} ns elapsed\n",
          chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count());
}

inline void Insertion(vector<int> arr) {
  print("Insertion:\t");
  vector<int> arr1 = arr;

  StepCount = 0;
  for (int i{0}; i < arr1.size(); i++) {
    int key = arr1[i];
    int j = i - 1;
    while (j >= 0 && arr1[j] > key) {
      arr1[j + 1] = arr1[j];
      j = j - 1;
      StepCount++;
    }
    arr1[j + 1] = key;
    StepCount++;
  }
  if (Trust) {
    for (int i = 0; i < arr1.size(); i++) {
      print("{}\t", arr1[i]);
    }
    println();
  }
  println("{} steps for {} elements", StepCount, arr1.size());
}

inline void Selection(vector<int> arr) {
  print("Selection:\t");
  StepCount = 0;
  vector<int> arr1 = arr;

  for (int i = 0; i < arr1.size() - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < arr1.size(); ++j) {
      if (arr1[j] < arr1[minIdx])
        minIdx = j;
    }
    swap(arr1[i], arr1[minIdx]);
    StepCount++;
  }
  if (Trust) {
    for (int i = 0; i < arr1.size(); i++) {
      print("{}\t", arr1[i]);
    }
    println();
  }

  println("{} steps for {} elements", StepCount, arr1.size());
}
