#include <stdio.h>
#define MAX 100

int hashTable[MAX];
int m;

/* Insert key using linear probing */
void insert(int key) {
    int index = key % m;

    if (hashTable[index] == -1) {
        hashTable[index] = key;
        printf("Key %d inserted at address %d\n", key, index);
    } else {
        printf("Collision occurred for key %d at address %d\n", key, index);
        int i = 1;
        while (i < m) {
            int newIndex = (index + i) % m;
            if (hashTable[newIndex] == -1) {
                hashTable[newIndex] = key;
                printf("Key %d inserted at address %d using linear probing\n",
                       key, newIndex);
                return;
            }
            i++;
        }
        printf("Hash table is full. Cannot insert key %d\n", key);
    }
}

/* Display hash table */
void display() {
    int i;
    printf("\nHash Table:\n");
    printf("Address\tKey\n");
    for (i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("%d\t%d\n", i, hashTable[i]);
        else
            printf("%d\t-\n", i);
    }
}

int main() {
    int n, key, i;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    /* Initialize hash table */
    for (i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
