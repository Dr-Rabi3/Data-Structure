#include <iostream>
#include <list>
#include <cstring>
using namespace std;
class HashTable {
private:
  static const int HashGroups = 10;
  list<pair<int, string>>table[HashGroups];
public:
  bool isEmpty() const;
  int HashFunction(int);
  void insertItem(int, string);
  void removeItem(int);
  string searchItem(string);
  void printTable()const;
};
bool HashTable::isEmpty() const{
  int sum = 0;
  for (auto i : table) {
    sum += i.size();
  }
  return (!sum ? true : false);
}
int HashTable::HashFunction(int key) {
  return key % HashGroups;
}
void HashTable::insertItem(int key, string val) {
  int hashVal = HashFunction(key);
  auto& cell = table[hashVal];
  bool keyExist = false;
  for (auto& k : cell) {
    if (k.first == key) {
      keyExist = true;
      k.second = val;
      break;
    }
  }
  if (!keyExist) {
    cell.emplace_back(key, val);
  }
}
void HashTable::removeItem(int key) {
  int hashVal = HashFunction(key);
  auto& cell = table[hashVal];
  bool keyExist = false;
  for (auto k = cell.begin(); k != cell.end();k++) {
    if (k->first == key) {
      keyExist = true;
      cell.erase(k);
      break;
    }
  }
}
void HashTable::printTable()const {
  for (int i = 0;i < HashGroups;i++) {
    for (auto k : table[i]) {
      cout << "Key: " << k.first << " Value: " << k.second << '\n';
    }
  }
}
int main() {
  HashTable HT;
  if (HT.isEmpty())cout << "Hash Table is Empty\n";
  else cout << "Hash Table is not Empty\n";
  HT.insertItem(100, "a");
  HT.insertItem(200, "b");
  HT.insertItem(300, "c");
  HT.insertItem(400, "d");
  HT.insertItem(500, "e");
  HT.printTable();
  HT.removeItem(200);
  HT.printTable();
  HT.removeItem(20);
  HT.printTable();
  if (HT.isEmpty())cout << "Hash Table is Empty\n";
  else cout << "Hash Table is not Empty\n";

  return 0;
}

/*
Hash Table is Empty
Key: 100 Value: a
Key: 200 Value: b
Key: 300 Value: c
Key: 400 Value: d
Key: 500 Value: e
Key: 100 Value: a
Key: 300 Value: c
Key: 400 Value: d
Key: 500 Value: e
Key: 100 Value: a
Key: 300 Value: c
Key: 400 Value: d
Key: 500 Value: e
Hash Table is not Empty
*/
