#include <stdio.h>
#include <stdlib.h>

void initializeTable(int table[], int table_size) {
    for (int i = 0; i < table_size; i++) {
        table[i] = -1;
    }
}

// Hash function using modulo operation
int hashFunction(int key, int table_size) {
    return key % table_size;
}

// Linear Probing
void linearProbing(int table[], int key, int table_size) {
    int index = hashFunction(key, table_size);
    int i = 0;
    while (table[(index + i) % table_size] != -1) {
        printf("Calculation: table[(%d + %d) mod %d] == %d.      Linear Probe %d. Collision found.\n", index, i, table_size, table[(index + i) % table_size], i);
        i++;
    }
    printf("Calculation: table[(%d + %d) mod %d] == %d.    Success. Key inserted at %d.\n", index, i, table_size, table[(index + i) % table_size], (index + i) % table_size);
    table[(index + i) % table_size] = key;
}

// Second hash function for double hashing
int hashFunction2(int key, int table_size) {
    return 5 - (key % 5); 
}

// Double Hashing
void doubleHashing(int table[], int key, int table_size) {
    int index1 = hashFunction(key, table_size);
    int index2 = hashFunction2(key, table_size);
    int i = 0;
    while (table[(index1 + i * index2) % table_size] != -1) {
        printf("Calculation: table[(%d + %d * %d) mod %d] == %d.      Double Hash Probe %d. Collision found.\n", index1, i, index2, table_size, table[(index1 + i * index2) % table_size], i);
        i++;
    }
    printf("Calculation: table[(%d + %d * %d) mod %d] == %d.    Success. Key inserted at %d.\n", index1, i, index2, table_size, table[(index1 + i * index2) % table_size], (index1 + i * index2) % table_size);
    table[(index1 + i * index2) % table_size] = key;
}

// Quadratic Probing
void quadraticProbing(int table[], int key, int table_size) {
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
    for (int i = 0; i < table_size; i++) {
        if (table[i] == -1)
            printf("table[%d]: EMPTY\n", i);
        else
            printf("table[%d]: %d\n", i, table[i]);
    }
}

int main() {
    int table_size;
    printf("Enter table size: ");
    scanf("%d", &table_size);

    int table[table_size];
    int choice, key, keys[100], num_keys = 0;

    // Storing keys first
    printf("Enter the keys (-1 to stop): \n");
    while (1) {
        scanf("%d", &key);
        if (key == -1) break;  // Stop if key is -1
        keys[num_keys++] = key;
    }

    while (1) {
        initializeTable(table, table_size);  // Reinitialize the table for each trial

       
        printf("\nChoose collision handling method:\n");
        printf("1. Linear Probing\n");
        printf("2. Double Hashing\n");
        printf("3. Quadratic Probing\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;  
        }

     
        for (int i = 0; i < num_keys; i++) {
            switch (choice) {
                case 1:
                    linearProbing(table, keys[i], table_size);
                    break;
                case 2:
                    doubleHashing(table, keys[i], table_size);
                    break;
                case 3:
                    quadraticProbing(table, keys[i], table_size);
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }
        }

        // Display the hash table after all insertions
        printf("\nHash Table:\n");
        displayTable(table, table_size);
    }

    return 0;
}
