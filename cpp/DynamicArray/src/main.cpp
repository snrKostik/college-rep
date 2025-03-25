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
  DynamicArray(DynamicArray &obj) {
    _size = obj._size;
    array = obj.array;
  }

  ~DynamicArray() {}

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
  DynamicArray eee(asf);
  print << asf.getEl(0) << " " << asf.getEl(1) << e;
  eee.setEl(4, 12);
  asf.PrintArr();
  eee.PrintArr();
}