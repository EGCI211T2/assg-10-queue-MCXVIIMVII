#ifndef queue_h
#define queue_h

#include "Node.h"
#include <iostream>

class Queue {
    NodePtr headPtr, tailPtr;
    int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
    bool isEmpty();
};

void Queue::enqueue(int x) {
    NodePtr new_node = new NODE(x);
    if (isEmpty()) {
        headPtr = new_node;
        tailPtr = new_node;
    } else {
        tailPtr->set_next(new_node);
        tailPtr = new_node;
    }
    size += 1;
}

int Queue::dequeue() {
    if (headPtr != NULL) {
        NodePtr t = headPtr;
        int value = t->get_value();
        headPtr = headPtr->get_next();
        if (headPtr == NULL) tailPtr = NULL;
        size -= 1;
        delete t;
        return value;
    }
    std::cout << "Empty queue" << std::endl;
    return -1;
}

Queue::Queue() {
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
}

Queue::~Queue() {
    std::cout << "Clearing queue (call destructor)" << std::endl;
    while (size > 0) std::cout << "Dequeing " << dequeue() << std::endl;
}

bool Queue::isEmpty() {
    return headPtr == nullptr;
}

#endif
