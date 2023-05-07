// بسم الله الرحمن الرحيم
#include <iostream>
using namespace std;
template < typename T > struct node {
    T data;
    struct node* left;
    struct node* right;
    node() {
        left = NULL;
        right = NULL;
    }
};
template < typename T > class list {
private:
    node< T >* head;
    int sz;
public:
    list() { head = NULL;sz = 0; }
    T Front() {
        if (head == NULL)exit(0);
        return head->data;
    }
    T Back() {
        if (head == NULL)exit(0);
        node < T >* temp = head;
        while (temp->right != NULL) temp = temp->right;
        return temp->data;
    }
    void Push_back(T item) {
        sz++;
        node < T >* newNode = new node< T >;
        newNode->data = item;
        if (head == NULL) {
            head = newNode;
            return;
        }
        node < T >* temp = head;
        while (temp->right != NULL) temp = temp->right;
        temp->right = newNode;
        newNode->left = temp;
    }
    void Push_front(T item) {
        sz++;
        node < T >* newNode = new node< T >;
        newNode->data = item;
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->right = head;
        head->left = newNode;
        head = newNode;
    }
    void Insert(T item, int pos) {
        if (pos - 1 > sz)exit(0);
        if (pos == 1) {
            Push_front(item);
            return;
        }
        if (pos == sz + 1) {
            Push_back(item);
            return;
        }
        node < T >* temp = head;
        for (int i = 1;i <= pos - 1;i++){
            temp = temp->right;
        }
        node < T >* newNode = new node< T >;
        node < T >* temp2 = temp->left;
        newNode->data = item;
        newNode->left = temp2;
        newNode->right = temp;
        temp2->right = newNode;
        temp->left = newNode;
        sz++;
    }
    void Pop_back() {
        if (head == NULL)
            exit(0);
        sz--;
        node < T >* temp = head;
        while (temp->right != NULL) temp = temp->right;
        temp->left->right = NULL;
        delete temp;
    }
    void Pop_font() {
        if (head == NULL)
            exit(0);
        sz--;
        node < T >* temp = head;
        head = head->right;
        delete temp;
    }
    void Erase(int pos) {
        if (head == NULL || pos > sz)
            exit(0);
        if (pos == 1) {
            Pop_font();
            return;
        }
        if (pos == sz) {
            Pop_back();
            return;
        }
        node < T >* temp = head;
        for (int i = 1;i <= pos - 1;i++) {
            temp = temp->right;
        }
        temp->left->right = temp->right;
        temp->right->left = temp->left;
        delete temp;
        sz--;
    }
    void Clear() {
        if (head == NULL)
            exit(0);
        sz = 0;
        while (head != NULL)
            head = head->right;
    }
    bool Empty() {
        return head == NULL;
    }
    int Size() {
        return sz;
    }
    T* Traverse() {
        T* arr = new T[sz];
        node < T >* temp = head;
        int i = 0;
        while (temp != NULL) {
            arr[i++] = temp->data;
            temp = temp->right;
        }
        return arr;
    }
};
int main() {
    list<int>l;
    l.Push_back(1);
    l.Push_back(2);
    l.Push_back(3);
    cout << l.Front() << '\n';
    cout << l.Back() << '\n';
    l.Push_front(5);
    l.Push_front(6);
    l.Push_front(7);
    cout << l.Front() << '\n';
    cout << l.Back() << '\n';
    l.Insert(10, 1);
    l.Insert(11, 2);
    l.Insert(12, 2);
    cout << l.Front() << '\n';
    cout << l.Back() << '\n';
    l.Insert(13, 4);
    int* arr = l.Traverse();
    cout << l.Size() << '\n';
    for (int i = 0;i < l.Size();i++)cout << arr[i] << ' ';
    cout << '\n';
    l.Pop_back();
    cout << l.Back() << '\n';
    l.Pop_back();
    cout << l.Back() << '\n';
    l.Pop_font();
    cout << l.Front() << '\n';
    l.Pop_font();
    cout << l.Front() << '\n';
    arr = l.Traverse();
    cout << l.Size() << '\n';
    for (int i = 0;i < l.Size();i++)cout << arr[i] << ' ';
    cout << '\n';
    l.Erase(2);
    arr = l.Traverse();
    cout << l.Size() << '\n';
    for (int i = 0;i < l.Size();i++)cout << arr[i] << ' ';
    cout << '\n';
    l.Erase(4);
    arr = l.Traverse();
    cout << l.Size() << '\n';
    for (int i = 0;i < l.Size();i++)cout << arr[i] << ' ';
    cout << '\n';
    cout << l.Empty() << '\n';
    l.Clear();
    cout << l.Empty() << '\n';
    return 0;
}
