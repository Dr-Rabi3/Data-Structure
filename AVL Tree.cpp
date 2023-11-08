#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

template < typename T > struct node {
  int height = 0;
  T data;
  node<T>* right;
  node<T>* left;
  node() : data(0), right(NULL), left(NULL), height(1) {}
  node(T d) : data(d), right(NULL), left(NULL), height(1) {}
  node(T d, node<T>* r, node<T>* l, int h) : data(d), right(r), left(l), height(h) {}
};

template < typename T > class AVL {
  node<T>* root;
  int sz;
  
  void print(node<T>* temp, int par, char d) {
    if (temp == NULL) return;
    cout << par << " -> " << temp->data << ' ' << d << '\n';
    print(temp->left, temp->data, 'L');
    print(temp->right, temp->data, 'R');
  }

  int mxHeight(node<T>* Node) {
    int cnt = 1;
    if (Node->left) cnt = max(cnt, mxHeight(Node->left) + 1);
    if (Node->right) cnt = max(cnt, mxHeight(Node->right) + 1);
    return cnt;
  }

  int height(node<T>* temp) {
    if (temp == NULL)
      return 0;
    return temp->height;
  }
  // Rotate right
  node<T>* rightRotate(node<T>* temp) {
    node<T>* leftEle = temp->left;
    node<T>* rlEle = leftEle->right;
    leftEle->right = temp;
    temp->left = rlEle;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    leftEle->height = max(height(leftEle->left), height(leftEle->right)) + 1;
    return leftEle;
  }
  // Rotate left
  node<T>* leftRotate(node<T>* temp) {
    node<T>* rightEle = temp->right;
    node<T>* lrEle = rightEle->left;
    rightEle->left = temp;
    temp->right = lrEle;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    rightEle->height = max(height(rightEle->left), height(rightEle->right)) + 1;
    return rightEle;
  }

  int getBalanceFactor(node<T>* temp) {
    if (temp == NULL)
      return 0;
    return height(temp->left) - height(temp->right);
  }
  // Insert a node
  node<T>* insertNode(node<T>* Node, int item) {
    if (Node == NULL)
      return new node<T>(item);
    if (item < Node->data)
      Node->left = insertNode(Node->left, item);
    else if (item > Node->data)
      Node->right = insertNode(Node->right, item);
    else
      return Node;
    Node->height = 1 + max(height(Node->left), height(Node->right));
    int balanceFactor = getBalanceFactor(Node);
    if (balanceFactor > 1) {
      if (item < Node->left->data) {
        return rightRotate(Node);
      }
      else if (item > Node->left->data) {
        Node->left = leftRotate(Node->left);
        return rightRotate(Node);
      }
    }
    if (balanceFactor < -1) {
      if (item > Node->right->data) {
        return leftRotate(Node);
      }
      else if (item < Node->right->data) {
        Node->right = rightRotate(Node->right);
        return leftRotate(Node);
      }
    }
    return Node;
  }

  node<T>* findMin(node<T>* Node) {
    if (Node == NULL) exit(1); // runtime error (Tree empty)
    node<T>* curr = Node;
    while (curr->left != NULL) curr = curr->left;
    return curr;
  }

  node<T>* findMax(node<T>* Node) {
    if (Node == NULL) exit(1); // runtime error (Tree empty)
    node<T>* curr = Node;
    while (curr->right != NULL) curr = curr->right;
    return curr;
  }
  // Delete a node
  node<T>* deleteNode(node<T>* Node, int item) {
    if (Node == NULL)
      return Node;
    if (item < Node->data)
      Node->left = deleteNode(Node->left, item);
    else if (item > Node->data)
      Node->right = deleteNode(Node->right, item);
    else {
      sz--;
      if ((Node->left == NULL) || (Node->right == NULL)) {
        node<T>* temp = Node->left ? Node->left : Node->right;
        if (temp == NULL) {
          temp = Node;
          Node = NULL;
        }
        else
          *Node = *temp;
        delete temp;
      }
      else {
        node<T>* temp = findMin(Node->right);
        Node->data = temp->data;
        Node->right = deleteNode(Node->right, temp->data);
      }
    }

    if (Node == NULL)
      return Node;

    Node->height = 1 + max(height(Node->left),
      height(Node->right));
    int balanceFactor = getBalanceFactor(Node);
    if (balanceFactor > 1) {
      if (getBalanceFactor(Node->left) >= 0) {
        return rightRotate(Node);
      }
      else {
        Node->left = leftRotate(Node->left);
        return rightRotate(Node);
      }
    }
    if (balanceFactor < -1) {
      if (getBalanceFactor(Node->right) <= 0) {
        return leftRotate(Node);
      }
      else {
        Node->right = rightRotate(Node->right);
        return leftRotate(Node);
      }
    }
    return Node;
  }
public:
  AVL() : root(NULL), sz(0) {}

  void insert(int item) {
    sz++;
    root = insertNode(root, item);
  }

  void remove(int item) {
    root = deleteNode(root, item);
  }

  bool isEmpty() {
    return root == NULL;
  }

  int size() {
    return sz;
  }

  void display() {
    cout << "P -> C D\n";
    print(root, 0, 'R');
  }

  T getMax() {
    node<T>* curr = findMax(root);
    return curr->data;
  }
  
  T getMin() {
    node<T>* curr = findMin(root);
    return curr->data;
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

  int depth() {
    return mxHeight(root);
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
  AVL<int>bst;
  for (int i = 0;i < n;i++) {
    int x;cin >> x;
    bst.insert(x);
  }
  bst.display();
  // cout << bst.search(5) << '\n';
  // cout << bst.search(20) << '\n';
  // cout << bst.getMax() << '\n';
  // cout << bst.getMin() << '\n';
  // cout << bst.depth() << '\n';
  // cout << bst.size() << '\n';
  // cout << bst.isEmpty() << '\n';
  // bst.clear();
  // cout << bst.isEmpty() << '\n';
  // bst.remove(1);
  // bst.display();
  return 0;
}
