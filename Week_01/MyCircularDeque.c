
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
	int head;
	int tail;
	int size;
} MyCircularDeque;

bool myCircularDequeIsFull(MyCircularDeque* obj);
bool myCircularDequeIsEmpty(MyCircularDeque* obj);

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *obj = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    obj->head = 0;
    obj->tail = 0;
    obj->size = k + 1;
    obj->arr = (int *)malloc(sizeof(int) * (k + 1));
    return obj;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
	int pos = (obj->head + obj->size - 1) % obj->size;
	obj->arr[pos] = value;
	obj->head = pos;
	return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->arr[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->size;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->head = (obj->head + 1) % obj->size;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->tail = (obj->size + obj->tail - 1) % obj->size;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->arr[obj->head];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    int pos = (obj->tail - 1 + obj->size) % obj->size;
    return obj->arr[pos];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->head == obj->tail) ? true : false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return ((obj->head - 1 + obj->size) % obj->size == obj->tail) ? true : false;
}

int myCircularDequeLength(MyCircularDeque* obj) {
    if (obj->tail > obj->head) {
        return obj->tail - obj->head;
    } else {
        return obj->tail - obj->head + obj->size;
    }
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
	free(obj);
	return;
}

void PrintDeque(MyCircularDeque *obj);

int main(int argc, const char *argv[]) {
    MyCircularDeque *obj = myCircularDequeCreate(5);
    myCircularDequeInsertFront(obj, 10);
    myCircularDequeInsertFront(obj, 20);
    myCircularDequeInsertFront(obj, 30);
    myCircularDequeInsertLast(obj, 0);
    myCircularDequeInsertLast(obj, 1);
    myCircularDequeDeleteLast(obj);
    int front = myCircularDequeGetFront(obj);
    int rear = myCircularDequeGetRear(obj);
    printf("front=%d, rear=%d\n", front, rear);
    PrintDeque(obj);
    return 0;
}

// 打印
void PrintDeque(MyCircularDeque *obj) {
    printf("head=%d, tail=%d, size=%d\n", obj->head, obj->tail, obj->size);
    printf("arr=[");
    int length = myCircularDequeLength(obj);
    int max = obj->head + length;
    for (int i = obj->head; i < max; i++) {
        printf("%d", obj->arr[i % obj->size]);
        if (i != max - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}