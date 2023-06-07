// بسم الله الرحمن الرحيم
#include <bits/stdc++.h>

using namespace std;
template < typename T > class CircularQueue {
private:
    struct node {
        T info;
        node* next;
        node() { next = NULL; }
        node(T data) { info = data;  next = NULL; }
    };
    node* head;
    int sz;
public:
    CircularQueue() {
        head = NULL;
        sz = 0;
    }
    void insert(T item, int pos = -1) { // -1 for push back
        if (pos > sz)exit(0);
        sz++;
        node* newNode = new node(item);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }
        node* temp = head;
        if (pos == 1) {
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        else if (pos == -1) {
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
        }
        else {
            for (int i = 1;i < pos - 1;i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void erase(T data) {
        if (head == NULL)exit(0);
        node* temp = head;
        if (head->info == data) {
            sz--;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            node* del = head;
            head = head->next;
            delete del;
            return;
        }
        while (temp->next->info != data) {
            temp = temp->next;
            if (temp->next == head)exit(0);
        }
        sz--;
        node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    vector< T > Traverse() {
        vector< T >ele(sz);
        node* temp = head;
        for (int i = 0;i < sz; i++) {
            ele[i] = temp->info;
            temp = temp->next;
        }
        return ele;
    }
    T front() {
        if (head == NULL) exit(0);
        return head->info;
    }
    T back() {
        if (head == NULL) exit(0);
        node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        return temp->info;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
};
int main() {
    CircularQueue<int> cq;
    cq.insert(1);
    cq.insert(2);
    cq.insert(3, 1);
    cq.insert(4);
    cq.insert(5);
    cq.insert(5, 2);
    auto ele = cq.Traverse();
    for (auto i : ele)cout << i << ' ';
    cout << '\n';
    cq.erase(5);
    cq.erase(2);
    ele = cq.Traverse();
    for (auto i : ele)cout << i << ' ';
    cout << '\n';
    cout << cq.front() << ' ' << cq.back() << '\n';
    return 0;
}
