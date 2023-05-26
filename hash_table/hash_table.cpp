#include <iostream>
using namespace std;
#define hashTableSize 27
string hashTable[hashTableSize];

int hashFunc(string s) {
    return s[0] - 'a';
}

void insert(string s) {
    int index = hashFunc(s);
    while (hashTable[index] != "") {
        index = (index + 1) % hashTableSize;
    }
    hashTable[index] = s;
}

int search(string s) {
    int index = hashFunc(s);
    while (hashTable[index] != s) {
        if (hashTable[index] == "")
            return -1;
        index = (index + 1) % hashTableSize;
    }
    return index;
}

int main() {

    insert("strawberry");
    insert("banana");
    insert("mango");
    insert("watermelon");
    insert("apple");
    insert("grapes");
    insert("kiwi");
    insert("coconut");
    insert("cantaloupe");
    insert("melon");
    insert("cherry");

    cout << search("kiwi") << endl;
    cout << search("mango") << endl;
    cout << search("melon") << endl;
    cout << search("chery") << endl;
    cout << search("cherry") << endl;
    cout << search("coconut") << endl;
    cout << search("cantaloupe") << endl;
    
    return 0;
}