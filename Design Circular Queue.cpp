class MyCircularQueue {
private:
    vector<int> data;
    int head;     // index of the front element
    int tail;     // index where the next element will be inserted
    int size;     // current number of elements
    int capacity; // maximum capacity k

public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        tail = 0;
        size = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        // tail points to the next free slot, so step back by 1 with wrap-around
        return data[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};