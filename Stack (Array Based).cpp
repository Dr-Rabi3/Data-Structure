#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e6;
template < typename T > class Stack {
private:
  vector<T>StackEntry;
  int top;
  int size;
public:
  Stack() {
    top = -1;
    size = 0;
    StackEntry.resize(MAX);
  }
  T Top() {
    if (this->top == -1) {
      return cout << "Stack Empty.\n", NULL;
    }
    return StackEntry[this->top];
  }
  bool isEmpty() {
    return size == 0;
  }
  void Push(T value) {
    if (top == MAX - 1)
      return void(cout << "NO Space.\n");
    StackEntry[++this->top] = value;
    ++size;
  }
  T Pop() {
    if (this->top == -1)
      return cout << "Stack Already Empty.\n", NULL;
    T tamp = StackEntry[this->top];
    --size;
    top--;
    return tamp;
  }
  int Size() {
    return this->size;
  }
};
int main() {
  Stack<int>sk;
}
