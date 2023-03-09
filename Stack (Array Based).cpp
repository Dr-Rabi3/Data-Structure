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
  sk.Push(5);
  sk.Push(4);
  sk.Push(3);
  sk.Push(2);
  sk.Push(1);
  cout << sk.Size() << '\n';
  cout << sk.Top() << '\n';
  cout << sk.Pop() << '\n';
  sk.Pop();
  cout << sk.Top() << '\n';
  sk.Pop();
  cout << sk.Top() << '\n';
  sk.Pop();
  sk.Pop();
  sk.Pop();
  cout << sk.isEmpty();
  /*
  5
  1
  1
  3
  4
  Stack Already Empty.
  1
*/
}
