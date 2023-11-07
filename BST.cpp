#include <iostream>
#include <queue>
using namespace std;

template < typename T > struct node {
  T data;
  node<T>* right;
  node<T>* left;
  node() : data(0), right(NULL), left(NULL) {}
  node(T d) : data(d), right(NULL), left(NULL) {}
  node(T d, node<T>* r, node<T>* l) : data(d), right(r), left(l) {}
};
template < typename T > class BST {
  node <T>* root;
  int sz;
  void print(node<T>* temp, int par, char d) {
    if (temp == NULL) return;
    cout << par << " -> " << temp->data << ' ' << d << '\n';
    print(temp->left, temp->data, 'L');
    print(temp->right, temp->data, 'R');
  }
public:
  BST() : root(NULL), sz(0) {}
  void insert(T item) {
    if (root == NULL) { // fist element
      root = new node<T>(item);
      sz++;
      return;
    }
    node<T>* curr = root;// don't move root 
    while (curr != NULL) {
      if (item < curr->data) {// go to left side
        if (curr->left == NULL) {
          curr->left = new node<T>(item);
          sz++;
          return;
        }
        curr = curr->left;
      }
      else {
        if (curr->right == NULL) {
          curr->right = new node<T>(item);
          sz++;
          return;
        }
        curr = curr->right;
      }
    }
  }
  void remove(T item) {
    if (!search(item)) return;
    --sz;
    deleteNode(root, item);
  }
  node<T>* deleteNode(node<T>* curr, int item) {
    if (curr == NULL) return curr;

    if (curr->data > item) {
      curr->left = deleteNode(curr->left, item);
      return curr;
    }
    else if (curr->data < item) {
      curr->right = deleteNode(curr->right, item);
      return curr;
    }
    if (curr->left == NULL) {
      auto temp = curr->right;
      delete curr;
      return temp;
    }
    else if (curr->right == NULL) {
      auto temp = curr->left;
      delete curr;
      return temp;
    }

    else {
      auto par = curr;
      auto temp = curr->right;
      while (temp->left != NULL) {
        par = temp;
        temp = temp->left;
      }
      if (par != curr)
        par->left = temp->right;
      else
        par->right = temp->right;
      curr->data = temp->data;

      delete temp;
      return curr;
    }
  }
  bool search(T item) {
    if (root == NULL) exit(1); // runtime error (Tree empty)
    node<T>* curr = root;
    while (curr != NULL) {
      if (item == curr->data) return true; // found
      if (item < curr->data) { // go to left side
        if (curr->left == NULL) return false; // not found this element
        curr = curr->left;
      }
      else {
        if (curr->right == NULL) return false; // not found this element
        curr = curr->right;
      }
    }
    return false;
  }
  T getMax() {
    if (root == NULL) exit(1); // runtime error (Tree empty)
    node<T>* curr = root;
    while (curr->right != NULL) curr = curr->right;
    return curr->data;
  }
  T getMin() {
    if (root == NULL) exit(1); // runtime error (Tree empty)
    node<T>* curr = root;
    while (curr->left != NULL) curr = curr->left;
    return curr->data;
  }
  void display() {
    cout << "P -> C D\n";
    print(root, 0, 'M');
  }
  int depth(node<T>* tamp) {
    if (tamp == NULL) return 0;
    return max(depth(tamp->left), depth(tamp->right)) + 1;
  }
  int height() {
    return depth(root);
  }
  int size() {
    return sz;
  }
  bool isEmpty() {
    return root == NULL;
  }
  void clear() {
    if (root == NULL) return;
    queue<node<T>*>q;
    q.push(root);
    while (!q.empty()) {
      auto curr = q.front();
      if (curr->left != NULL) q.push(curr->left);
      if (curr->right != NULL) q.push(curr->right);
      delete curr;
      q.pop();
    }
    root = NULL;
    sz = 0;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  BST<int>bst;
  for (int i = 0;i < n;i++) {
    int x;cin >> x;
    bst.insert(x);
  }
  bst.display();
  // cout << bst.search(5) << '\n';
  // cout << bst.search(20) << '\n';
  // cout << bst.getMax() << '\n';
  // cout << bst.getMin() << '\n';
  // cout << bst.height() << '\n';
  // cout << bst.size() << '\n';
  // cout << bst.isFull() << '\n';
  // cout << bst.isEmpty() << '\n';
  // bst.clear();
  // cout << bst.isFull() << '\n';
  // cout << bst.isEmpty() << '\n';
  // bst.remove(90);
  // bst.display();
  return 0;
}
