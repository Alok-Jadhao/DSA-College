#include<stdio.h>

#define MAX 10

void initializeTable(int table[], int table_size) {
    for (int i = 0; i < table_size; i++)
    {
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
    while (table[(index + i) % table_size] != -1)
    {
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
    while (table[(index + i * index2) % table_size] != -1)
    {
        printf("Calculation: table[(%d + %d) mod %d] == %d.      Linear Probe %d. Collision found.\n", index, i, table_size, table[(index + i * index2) % table_size], i);
        i++;
    }
    printf("Calculation: table[(%d + %d) mod %d] == %d.    Success. Key inserted at %d.\n", index, i, table_size, table[(index + i * index2) % table_size], (index + i) % table_size);
    table[(index + i * index2) % table_size] = key;
     
}

void quadraticProbing(int table[], int table_size, int key) {
    int index = hashFunction(key, table);
    int i = 0;
    while (table[(index + i*i) % table_size] != -1)
    {
        printf("Calculation: table[(%d + %d) mod %d] == %d.      Linear Probe %d. Collision found.\n", index, i, table_size, table[(index + i*i) % table_size], i);
        i++;
    }
    printf("Calculation: table[(%d + %d) mod %d] == %d.    Success. Key inserted at %d.\n", index, i, table_size, table[(index + i*i) % table_size], (index + i*i) % table_size);
    table[(index + i*i) % table_size] = key;
     
}



void displayTable(int table[], int table_size) {
    printf("Hash Table\n");
    for (int i = 0; i < table_size; i++)
    {
        if(table[i] == -1) {
            printf("table[%d]: EMPTY", i, table[i]);
        } else {
            printf("table[%d]: %d", i, table[i]);
        }
    }
    
}


