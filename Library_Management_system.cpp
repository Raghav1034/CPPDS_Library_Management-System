#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable {
    long int capacity; // Capacity of the hash table
    list<pair<long int, long int>> *table; // Hash table to store data 
    //This is a pointer to an array of linked lists, representing the hash table.
public:
    long int loc = 0; // Location tracker
    string books[10] = {
        // Array of book names
        "The Girl with All the Gifts",
        "Dark Matter",
        "Altered Carbon",
        "The Andromeda Strain",
        "Persopolis Rising",
        "Leviathan Wakes",
        "Dune",
        "Knock At The Cabin",
        "The Lord Of The Rings",
        "Do Androids Dream of Electronic Sheep?"
    };
    long int book_id[10] = {
        // Array of book IDs
        101,
        102,
        103,
        104,
        105,
        106,
        107,
        108,
        109,
        110
    };
    HashTable(long int V); // Constructor
    void insertItem(long int key, long int data); // To Insert a key-value pair
    void deleteItem(long int key); // Delete an item by key
    long int searchKey(long int key); // Search for a key
    long int checkPrime(long int n); // Check if a number is prime
    long int getPrime(long int n); // Get the next prime number if the number is not prime
    long int hashFunction(long int key); // Hash function to determine index
    void displayHash(); // Display the hash table
    void displayBooks(); // Display available books
    long int bookThere(long int id); // Check if a book is available by ID
};

HashTable::HashTable(long int c) {
    long int size = getPrime(c);
    this->capacity = size;
    table = new list<pair<long int, long int>>[capacity];
}

void HashTable::insertItem(long int key, long int data) {
    long int index = hashFunction(key);
    table[index].push_back(make_pair(key, data));
}

void HashTable::deleteItem(long int key) {
    long int index = hashFunction(key);
    long int found_item = searchKey(key);
    if (found_item != -1) {
        list<pair<long int, long int>>& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                cout << "Book returned: " << books[loc] << endl;
                return;
            }
        }
    } else {
        cout << "There were no books issued under this PRN." << endl;
        return;
    }
}

long int HashTable::searchKey(long int key) {
    long int index = hashFunction(key);
    list<pair<long int, long int>>& bucket = table[index];
    for (const pair<long int, long int>& item : bucket) {
        if (item.first == key) {
            return item.second;
        }
    }
    return -1; // Key not found
}

void HashTable::displayHash() {
    for (long int i = 0; i < capacity; ++i) {
        cout << "table[" << i << "]";
        for (const pair<long int, long int>& item : table[i]) {
            cout << " --> Key: " << item.first << ", Value: " << item.second;
        }
        cout << endl;
    }
}

long int HashTable::checkPrime(long int n) {
    long int i;
    if (n == 1 || n == 0) {
        return 0;
    }
    for (i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

long int HashTable::getPrime(long int n) {
    if (n % 2 == 0) {
        n++;
    }
    while (!checkPrime(n)) {
        n += 2;
    }
    return n;
}

long int HashTable::hashFunction(long int key) {
    return (key % capacity);
}

void HashTable::displayBooks() {
    long int count = sizeof(book_id) / sizeof(long int);
    for (long int i = 0; i < count; i++) {
        cout << books[i] << " - ID: " << book_id[i] << endl;
    }
    return;
}

long int HashTable::bookThere(long int id) {
    long int found = 0;
    long int count = sizeof(book_id) / sizeof(long int);
    for (long int i = 0; i < count; i++) {
        if (id == book_id[i]) {
            found = 1;
            loc = i;
        }
    }
    if (found == 1) {
        cout << "Book Issued: " << books[loc] << endl;
        return 1;
    } else {
        cout << "Book Not Found" << endl;
        return 0;
    }
}

int main() {
    HashTable h(7);

    while (true) {
        long int choice;
        cout << "*--------------------Library Management System--------------------*\n";
        cout << "1. Display Books\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search for Student\n";
        cout << "5. Display Hash Table\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            h.displayBooks();
        } else if (choice == 2) {
            long int key;
            long int value, found;
            cout << "Enter Student PRN: ";
            cin >> key;
            cout << "Enter Book ID: ";
            cin >> value;
            found = h.bookThere(value);
            if (found == 1) {
                h.insertItem(key, value);
            }
        } else if (choice == 3) {
            long int key;
            cout << "Enter PRN: ";
            cin >> key;
            h.deleteItem(key);
        } else if (choice == 4) {
            long int key;
            cout << "Enter PRN to Search: ";
            cin >> key;
            long int foundValue = h.searchKey(key);
            if (foundValue != -1) {
                cout << "Student found. \nIssued Book ID: " << foundValue << endl;
            } else {
                cout << "Student not found." << endl;
            }
        } else if (choice == 5) {
            h.displayHash();
        } else if (choice == 6) {
            break; // Exit the loop and program
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

