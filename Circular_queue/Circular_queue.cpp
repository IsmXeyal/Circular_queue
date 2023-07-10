#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class CircleQueue {
private:
    int _capacity = 10;
    T* _arr = new T[_capacity];
    int _front = -1;
    int _rear = -1;

public:
    bool isEmpty();
    bool isFull();
    void append(T newItem);
    T popFront();
    T peek();
    void clear();

    template<class T>
    friend ostream& operator<<(ostream& print, CircleQueue<T>& queue);

    ~CircleQueue();
};

template<class T>
bool CircleQueue<T>::isFull() {
    if (_front == 0 && _rear == _capacity - 1) {
        return true;
    }
    if (_front == _rear + 1) {
        return true;
    }
    return false;
}

template<class T>
bool CircleQueue<T>::isEmpty() {
    return (_front == -1);
}

template<class T>
void CircleQueue<T>::append(T newItem) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }

    if (_front == -1)
        _front = 0;
    _rear = (_rear + 1) % _capacity;
    _arr[_rear] = newItem;
}

template<class T>
T CircleQueue<T>::popFront() {
    if (isEmpty()) {
        assert(!"Queue is empty");
    }
    T a = _arr[_front];
    if (_front == _rear) {
        _front = -1;
        _rear = -1;
    }
    else
        _front = (_front + 1) % _capacity;

    return a;
}

template<class T>
T CircleQueue<T>::peek() {
    if (isEmpty()) {
        assert(!"Queue is empty");
    }
    return _arr[_front];
}

template<class T>
void CircleQueue<T>::clear() {
    _front = -1;
    _rear = -1;
}

template<class T>
ostream& operator<<(ostream& print, CircleQueue<T>& queue) {
    if (queue.isEmpty()) {
        print << "Queue is empty.";
        return print;
    }
    int i = queue._front;
    while (i != queue._rear) {
        print << queue._arr[i] << " ";
        i = (i + 1) % queue._capacity;
    }
    print << queue._arr[queue._rear] << " ";
    return print;
}

template<class T>
CircleQueue<T>::~CircleQueue() {
    delete[] _arr;
}