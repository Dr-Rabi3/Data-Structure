// بسم الله الرحمن الرحيم
#include <bits/stdc++.h>

using namespace std;
template < typename T > class CircularQueue {
private:
    T* data;
    int front;
    int rear;
    int sz;
public:
    CircularQueue(int MaxSz) {
        front = -1;
        rear = -1;
        sz = MaxSz;
        data = new T[MaxSz];
    }
    void insert(T item) {
        rear = (rear + 1) % sz;
        if (front == rear)
            exit(0);
        if (front == -1)
            front = 0, rear = 0;
        data[rear] = item;
    }
    void erase() {
        if (front == -1)
            exit(0);
        T item = data[front];
        if (front == rear)
            front = rear = -1;
        front = (front + 1) % sz;
    }
    vector< T > Traverse() {
        if (front == -1)exit(0);
        vector< T >ele(abs(rear - front) + 1);
        int i = 0, st = front;
        while (st != rear) {
            ele[i] = data[st];
            st = (st + 1) % sz;
            i++;
        }
        ele[i] = rear;
        return ele;
    }
    T Front() {
        if (front == -1) exit(0);
        return data[front];
    }
    T back() {
        if (front == -1) exit(0);
        return data[rear];
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
};
int main() {
    CircularQueue<int> cq(10);
    cq.insert(1);
    cq.insert(2);
    cq.insert(3);
    cq.insert(4);
    cq.insert(5);
    cq.insert(5);
    auto ele = cq.Traverse();
    for (auto i : ele)cout << i << ' ';
    cout << '\n';
    cq.erase();
    cq.erase();
    ele = cq.Traverse();
    for (auto i : ele)cout << i << ' ';
    cout << '\n';
    cout << cq.Front() << ' ' << cq.back() << '\n';
    return 0;
}
