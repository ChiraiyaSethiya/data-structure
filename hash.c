#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;
int *ht, index;
int count = 0;

void insert(int k) {
    index = k % m;
    while (ht[index] != -1) {
        index = (index + 1) % m;
    }
    ht[index] = k;
    count++;
}

void display() {
    int i;
    if (count == 0) {
        printf("\nHash Table is empty\n");
        return;
    }
    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++) {
        if (ht[i] != -1) {
            printf("Index %d: %d\n", i, ht[i]);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

void main() {
    int i;
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    printf("\nEnter the two-digit memory locations (m) for hash table: ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));
    if (ht == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }

    for (i = 0; i < m; i++) {
        ht[i] = -1;
    }

    printf("\nEnter the four-digit key values (K) for N Employee Records:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key[i]);
    }

    for (i = 0; i < n; i++) {
        if (count == m) {
            printf("\nHash table is full. Cannot insert the record with key %d\n", key[i]);
            break;
        }
        insert(key[i]);
    }

    display();

    free(ht); // Free allocated memory
}
