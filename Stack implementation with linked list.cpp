#include <iostream>
using namespace std;
template < typename T > struct TOP {
    T date;
    struct TOP* next;
};
template < typename T > class stack {
private:
    TOP<T>* Top;
    int sz;
public:
    stack() {
        Top->next = NULL;
        sz = 0;
    }
    void push(T date) {
        TOP<T>* tamp = new TOP<T>;
        tamp->date = date;
        tamp->next = Top;
        Top = tamp;
        sz++;
    }
    T top() {
        if (Top->next == NULL || sz == 0)
            exit(0);
        return Top->date;
    }
    void pop() {
        if (sz == 0)exit(0);
        TOP<T>* tamp = new TOP<T>;
        tamp = Top;
        Top = Top->next;
        free(tamp);
        sz--;
    }
    bool empty() {
        return sz == 0;
    }
    int size() {
        return sz;
    }
    int* Traverse() {
        TOP<T>* tampTop = Top;
        T* arr = new T[sz];
        int x = 0;
        while (tampTop != NULL) {
            arr[x] = tampTop->date;
            tampTop = tampTop->next;
            x++;
        }
        return arr;
    }
};
int main() {
    stack<string> sk;

    return 0;
}
