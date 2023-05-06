// بسم الله الرحمن الرحيم
#include <iostream>
#include <vector>
using namespace std;
template < typename T , int sz = 100000 > class queue {
private:
    int front, rear;
    vector< T > Data;
public:
    queue() {
        front = -1;
        rear = -1;
        Data.resize(sz);
    }
    T Front() {
        if (front == -1)exit(0);
        return Data[front];
    }
    T Back() {
        if (front == -1)exit(0);
        return Data[rear - 1];
    }
    void Push(T item) {
        if (rear == sz - 1)exit(0);
        if (front == -1) front = rear = 0;
        Data[rear] = item;
        rear = rear + 1;
    }
    void Pop() {
        if (front == -1)exit(0);
        front = front + 1;
        if (front == rear)
            front = rear = -1;
    }
    bool Empty() {
        return front == -1;
    }
    int Size() {
        if (front == -1)return 0;
        return rear - front;
    }
    T* Traverse() {
        T* arr = new T[Size()];
        int st = front, i = 0;
        while (st != rear) {
            arr[i] = Data[st];
            st++;
            i++;
        }
        return arr;
    }
};
int main() {
    queue<int>q;
    
    return 0;
}
