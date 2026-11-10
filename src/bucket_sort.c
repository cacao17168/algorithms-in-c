#include <stddef.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *bucket_insertion_sort(struct node *head) {
    if(!head) return NULL;

    struct node *sorted = NULL;
    struct node *cur = head;
    while(cur != NULL) {
        struct node *next = cur->next;
        if(sorted == NULL || sorted->val > cur->val) {
            cur->next = sorted;
            sorted = cur;
        } else {
            struct node *temp = sorted;
            while(temp->next != NULL && temp->next->val < cur->val) {
                temp = temp->next;
            }
            cur->next = temp->next;
            temp->next = cur;
        }
        cur = next;
    }
    return sorted;
}

void bucket_sort(int arr[], size_t n) {
    if(!arr) return;
    if(n <= 1) return;

    int min = arr[0], max = arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    struct node **buckets = (struct node **)calloc(n, sizeof(struct node *));
    if(!buckets) return;

    double range = (double)max - (double)min + 1.0;
    for(size_t i = 0; i < n; i++) {
        size_t bi = (size_t)(((double)arr[i] - (double)min) / range * (double)n);
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if(!new_node) continue;
        new_node->val = arr[i];
        new_node->next = buckets[bi];
        buckets[bi] = new_node;
    }

    size_t index = 0;
    for(size_t i = 0; i < n; i++) {
        buckets[i] = bucket_insertion_sort(buckets[i]);
        struct node *cur = buckets[i];
        while(cur != NULL) {
            arr[index++] = cur->val;
            struct node *temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(buckets);
}
