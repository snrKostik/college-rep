#include "../../../../../.mylibs/lifeEasier.hpp"

class DynamicArray {
private:
  int _size = 0;
  int *array = nullptr;

public:
  DynamicArray(int size) {
    _size = size;
    array = new int[_size];
    for (int i{0}; i < _size; i++) {
      array[i] = 0;
    }
  }
  DynamicArray(DynamicArray const &obj) {
    print << "copying size\n";
    _size = obj._size;
    print << "copying array\n";
    array = obj.array;
    print << "adding for each element 1\n";
    for (int i{0}; i < _size; i++) {
      obj.array[i] += 1;
    }
  }

  ~DynamicArray() { delete[] array; }

  int getEl(int el) { return array[el]; }
  void setEl(int el, int what) { array[el] = what; }
  void PrintArr() {
    for (int i{0}; i < _size; i++) {
      print << array[i] << " ";
    }
    print << e;
  }
};

int main() {
  DynamicArray asf(12);
  asf.setEl(0, 5);
  print << asf.getEl(0) << " " << asf.getEl(1) << e;

  DynamicArray eee(asf);
  asf.PrintArr();
  eee.setEl(4, 12);
  eee.PrintArr();
}