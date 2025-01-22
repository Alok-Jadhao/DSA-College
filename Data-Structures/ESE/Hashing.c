#include <stdio.h>

#define MAX 10

void initializeTable(int table[], int table_size) {
    for (int i = 0; i < table_size; i++) {
        table[i] = -1;
    }
}

int hashFunction(int key, int table_size) {
    return key % table_size;
}

int secondfunction(int key) {
    return 7 - (key % 7);
}

void linearProbing(int table[], int table_size, int key) {
    int index = hashFunction(key, table_size);
    int i = 0;
    while (table[(index + i) % table_size] != -1) {
        printf("Calculation: table[(%d + %d) mod %d] == %d.      Linear Probe %d. Collision found.\n", index, i, table_size, table[(index + i) % table_size], i);
        i++;
    }
    printf("Calculation: table[(%d + %d) mod %d] == %d.    Success. Key inserted at %d.\n", index, i, table_size, table[(index + i) % table_size], (index + i) % table_size);
    table[(index + i) % table_size] = key;
}

void DoubleHashing(int table[], int table_size, int key) {
    int index = hashFunction(key, table_size);
    int index2 = secondfunction(key);
    int i = 0;
    while (table[(index + i * index2) % table_size] != -1) {
        printf("Calculation: table[(%d + %d) mod %d] == %d.      Double Hash Probe %d. Collision found.\n", index, i, table_size, table[(index + i * index2) % table_size], i);
        i++;
    }
    printf("Calculation: table[(%d + %d) mod %d] == %d.    Success. Key inserted at %d.\n", index, i, table_size, table[(index + i * index2) % table_size], (index + i * index2) % table_size);
    table[(index + i * index2) % table_size] = key;
}

void quadraticProbing(int table[], int table_size, int key) {
    int index = hashFunction(key, table_size);
    int i = 0;
    while (table[(index + i * i) % table_size] != -1) {
        printf("Calculation: table[(%d + %d^2) mod %d] == %d.      Quadratic Probe %d. Collision found.\n", index, i, table_size, table[(index + i * i) % table_size], i);
        i++;
    }
    printf("Calculation: table[(%d + %d^2) mod %d] == %d.    Success. Key inserted at %d.\n", index, i, table_size, table[(index + i * i) % table_size], (index + i * i) % table_size);
    table[(index + i * i) % table_size] = key;
}

void displayTable(int table[], int table_size) {
    printf("Hash Table\n");
    for (int i = 0; i < table_size; i++) {
        if (table[i] == -1) {
            printf("table[%d]: EMPTY\n", i);
        } else {
            printf("table[%d]: %d\n", i, table[i]);
        }
    }
}

// Search for a key using Linear Probing
int searchLinear(int table[], int table_size, int key) {
    int index = hashFunction(key, table_size);
    int i = 0;
    while (table[(index + i) % table_size] != -1) {
        if (table[(index + i) % table_size] == key) {
            return (index + i) % table_size; // Key found
        }
        i++;
        if (i == table_size) break; // Avoid infinite loops
    }
    return -1; // Key not found
}

// Search for a key using Quadratic Probing
int searchQuadratic(int table[], int table_size, int key) {
    int index = hashFunction(key, table_size);
    int i = 0;
    while (table[(index + i * i) % table_size] != -1) {
        if (table[(index + i * i) % table_size] == key) {
            return (index + i * i) % table_size; // Key found
        }
        i++;
        if (i == table_size) break; // Avoid infinite loops
    }
    return -1; // Key not found
}

// Search for a key using Double Hashing
int searchDoubleHashing(int table[], int table_size, int key) {
    int index = hashFunction(key, table_size);
    int index2 = secondfunction(key);
    int i = 0;
    while (table[(index + i * index2) % table_size] != -1) {
        if (table[(index + i * index2) % table_size] == key) {
            return (index + i * index2) % table_size; // Key found
        }
        i++;
        if (i == table_size) break; // Avoid infinite loops
    }
    return -1; // Key not found
}

// Main function
int main() {
    int table[MAX];
    initializeTable(table, MAX);

    // Insert keys
    linearProbing(table, MAX, 12);
    linearProbing(table, MAX, 22);
    linearProbing(table, MAX, 32);

    displayTable(table, MAX);

    // Search for a key using Linear Probing
    int key = 22;
    int index = searchLinear(table, MAX, key);
    if (index != -1) {
        printf("Key %d found at index %d using Linear Probing.\n", key, index);
    } else {
        printf("Key %d not found using Linear Probing.\n", key);
    }

    return 0;
}
