#include <iostream>
using namespace std;
template < typename T > struct Node {
    T date;
    struct Node* next;
};
template < typename T > class queue {
private:
    Node<T>* Front;
    Node<T>* Rear;
    int sz;
public:
    queue() {
        Front = NULL;
        Rear = NULL;
        sz = 0;
    }
    T front() {
        if (sz == 0)exit(0);
        return Front->date;
    }
    T back() {
        if (sz == 0)exit(0);
        return Rear->date;
    }
    void push(T date) {
        Node<T>* tamp = new Node<T>;
        tamp->date = date;
        tamp->next = NULL;
        if (sz == 0) {
            Front = tamp;
            Rear = tamp;
        }
        else {
            Rear->next = tamp;
            Rear = tamp;
        }
        sz++;
    }
    void pop() {
        if (sz == 0)exit(0);
        Node<T>* tamp = Front;
        Front = Front->next;
        free(tamp);
        sz--;
    }
    bool empty() {
        return sz == 0;
    }
    int size() {
        return sz;
    }
    T* Traverse() {
        Node<T>* tamp = Front;
        T* arr = new T[sz];
        int x = 0;
        while (tamp != NULL) {
            arr[x] = tamp->date;
            tamp = tamp->next;
            x++;
        }
        return arr;
    }
};
int main() {
    queue<int>q;
    return 0;
}
