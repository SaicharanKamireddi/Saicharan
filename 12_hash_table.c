#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct KeyValue {
    int key;
    int value;
    struct KeyValue* next;
};

struct HashTable {
    struct KeyValue* table[TABLE_SIZE];
};

// Initialize the hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Hash function
int hashCode(int key) {
    return key % TABLE_SIZE;
}

// Insert key-value pair into the hash table
void insert(struct HashTable* hashTable, int key) {
    int index = hashCode(key);
    struct KeyValue* newNode = (struct KeyValue*)malloc(sizeof(struct KeyValue));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = NULL;

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        struct KeyValue* temp = hashTable->table[index];
        while (temp->next != NULL) {
            if (temp->key == key) {
                temp->value++;
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Remove key-value pair from the hash table
void removeElement(struct HashTable* hashTable, int key) {
    int index = hashCode(key);
    struct KeyValue* current = hashTable->table[index];
    struct KeyValue* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                hashTable->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key %d not found\n", key);
}

// Display the contents of the hash table
void display(struct HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        struct KeyValue* current = hashTable->table[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

// Get the size of the hash table
int sizeOfHashTable(struct HashTable* hashTable) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct KeyValue* current = hashTable->table[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }
    return count;
}

int main() {
    struct HashTable* hashTable = createHashTable();
    int choice, key, c;

    do {
        printf("\nImplementation of Hash Table in C\n\n");
        printf("MENU:\n");
        printf("1. Insert item into the hash table\n");
        printf("2. Remove item from the hash table\n");
        printf("3. Check the size of the hash table\n");
        printf("4. Display the hash table\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nInserting element into the hash table\n");
                printf("Enter key: ");
                scanf("%d", &key);
                insert(hashTable, key);
                break;
            case 2:
                printf("\nDeleting element from the hash table\n");
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                removeElement(hashTable, key);
                break;
            case 3:
                printf("\nSize of the hash table is: %d\n", sizeOfHashTable(hashTable));
                break;
            case 4:
                printf("\nDisplaying the hash table\n");
                display(hashTable);
                break;
            default:
                printf("\nWrong input\n");
        }

        printf("\nDo you want to continue? (1 for yes): ");
        scanf("%d", &c);
    } while (c == 1);

    return 0;
}

/*Observations
THis program is to understand the different types of hash functions and its use*/
