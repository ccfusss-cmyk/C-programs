#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Block {
    int start_address;
    int size;
    int is_free;
    struct Block* prev;
    struct Block* next;
};

struct Block* head = NULL;

struct Block* create_block(int start, int size, int is_free) {
    struct Block* new_block = (struct Block*)malloc(sizeof(struct Block));
    new_block->start_address = start;
    new_block->size = size;
    new_block->is_free = is_free;
    new_block->next = NULL;
    new_block->prev = NULL;
    return new_block;
}

void add_block(int start, int size, int is_free) {
    struct Block* new_block = create_block(start, size, is_free);

    if (head == NULL) {
        head = new_block;
        return;
    }

    struct Block* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_block;
    new_block->prev = temp;
}

void display_memory() {
    struct Block* temp = head;
    printf("\nMemory Blocks:\n");
    printf("------------------------------\n");
    while (temp != NULL) {
        printf("Start: %d, Size: %d, Status: %s\n",
            temp->start_address,
            temp->size,
            temp->is_free ? "Free" : "Used");
        temp = temp->next;
    }
    printf("------------------------------\n");
}

void garbage_collection() {
    struct Block* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->is_free && temp->next->is_free) {

            temp->size += temp->next->size;
            struct Block* to_delete = temp->next;
            temp->next = to_delete->next;

            if (to_delete->next != NULL) {
                to_delete->next->prev = temp;
            }

            free(to_delete);
        } else {
            temp = temp->next;
        }
    }
}

void compaction() {
    struct Block* new_head = NULL;
    struct Block* last_used = NULL;
    int current_address = 1000;

    struct Block* temp = head;
    while (temp != NULL) {
        if (!temp->is_free) {
            struct Block* new_block = create_block(current_address, temp->size, 0);
            current_address += temp->size;

            if (new_head == NULL) {
                new_head = new_block;
                last_used = new_head;
            } else {
                last_used->next = new_block;
                new_block->prev = last_used;
                last_used = new_block;
            }
        }
        temp = temp->next;
    }

    int free_size = 0;
    temp = head;
    while (temp != NULL) {
        if (temp->is_free) {
            free_size += temp->size;
        }
        temp = temp->next;
    }

    if (free_size > 0) {
        struct Block* free_block = create_block(current_address, free_size, 1);
        if (new_head == NULL) {
            new_head = free_block;
        } else {
            last_used->next = free_block;
            free_block->prev = last_used;
        }
    }

    temp = head;
    while (temp != NULL) {
        struct Block* next = temp->next;
        free(temp);
        temp = next;
    }

    head = new_head;
}

int main() {

    add_block(1000, 200, 0);
    add_block(1200, 150, 1);
    add_block(1350, 300, 0);
    add_block(1650, 100, 1);
    add_block(1750, 200, 1);

    printf("\nBefore Garbage Collection and Compaction:");
    display_memory();

    garbage_collection();
    printf("\nAfter Garbage Collection:");
    display_memory();

    compaction();
    printf("\nAfter Compaction:");
    display_memory();

    return 0;
}
