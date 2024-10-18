#include <stdio.h>
#include <stdlib.h>

// #define TABLE_SIZE 10

void initializeTable(int table[], int table_size) {
    for (int i = 0; i < table_size; i++) {
        table[i] = -1;
    }
}

int hashFunction(int key, int table_size) {
    return key % table_size;
}

void linearProbing(int table[], int key, int table_size) {
    int index = hashFunction(key, table_size);
    int i = 0;
    while (table[(index + i) % table_size] != -1) {
        printf("Calculation:table[(%d + %d) mod %d] == %d.      Linear Probe %d. Collision found.\n",index, i, table_size,table[(index + i) % table_size], (i));
        i++;
        
    }
    printf("Calculation:table[(%d + %d) mod %d] == %d    Sucess. Key inserted at %d.\n",index, i, table_size,table[(index + i) % table_size] , (index + i) % table_size);
    table[(index + i) % table_size] = key;
    
}

// Second hash function for double hashing
int hashFunction2(int key, int table_size) {
    return  5 - (key % 5); 
}

void doubleHashing(int table[], int key, int table_size) {
    int index1 = hashFunction(key, table_size);
    int index2 = hashFunction2(key, table_size);
    int i = 0;
    while (table[(index1 + i * index2) % table_size] != -1) {
        printf("Double Hash Probe %d. Collision found.\n", (i));
        i++;
    }
    table[(index1 + i * index2) % table_size] = key;
    printf("Sucess. Key inserted at %d.\n", (index1 + i * index2) % table_size);
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
    int choice, key, n;

  
    
    
    // Input choice for probing technique
    printf("Choose collision handling method:\n");
    printf("1. Linear Probing\n");
    
    printf("2. Double Hashing\n");
    scanf("%d", &choice);

    
    
    

    initializeTable(table, table_size);

    printf("Enter the keys (-1 to stop): \n");
    while (1) {
        scanf("%d", &key);
        if (key == -1) break;  // Stop if key is -1

        switch (choice) {
            case 1:
                linearProbing(table, key, table_size);
                break;
            case 2:
                doubleHashing(table, key, table_size);
                break;
            default:
                printf("Invalid choice!\n");
                return 1;
        }
    }

    // Display the hash table after all insertions
    printf("\nHash Table:\n");
    displayTable(table, table_size);

    return 0;
}




