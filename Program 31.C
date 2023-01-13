#include <stdio.h>

#define MAX_PAGES 10

int pages[MAX_PAGES];
int front = 0, rear = -1;
int page_faults = 0;

void enqueue(int page) {
    if (rear == MAX_PAGES - 1) {
        rear = -1;
    }
    pages[++rear] = page;
}

int dequeue() {
    int page = pages[front++];
    if (front == MAX_PAGES) {
        front = 0;
    }
    return page;
}

void page_reference(int page) {
    int i;
    for (i = 0; i <= rear; i++) {
        if (pages[i] == page) {
            return;
        }
    }
    page_faults++;
    if (rear < MAX_PAGES - 1) {
        enqueue(page);
    } else {
        dequeue();
        enqueue(page);
    }
}

int main() {
    int i;
    int reference_string[] = {1,8,6,5,2,3,4,9,7,5,6,2,3,4,8,5};
    int n = sizeof(reference_string) / sizeof(reference_string[0]);
    for (i = 0; i < n; i++) {
        page_reference(reference_string[i]);
    }
    printf("Number of page faults: %d\n", page_faults);
    return 0;
}
