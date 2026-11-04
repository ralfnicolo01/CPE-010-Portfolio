#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template<typename T>
class queueArr{
private:
    T *q_arr;
    size_t q_capacity;
    size_t q_size;
    size_t q_front;
    size_t q_back;

public:
    queueArr(size_t capacity);
    ~queueArr();

    bool isEmpty();
    size_t size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T newData);
    void Dequeue();

    queueArr(const queueArr& other);
    queueArr& operator=(const queueArr& other);
};

//constructor
template<typename T>
queueArr<T>::queueArr(size_t capacity){
    //define capcity of the array
    q_capacity = capacity;
    q_arr = new T[q_capacity];
    // set the size to 0
    q_size = 0;
    q_front = 0;
    q_back = capacity - 1;
}

//destructor
template<typename T>
queueArr<T>::~queueArr(){
    delete[] q_arr;
}

//check if empty
template<typename T>
bool queueArr<T>::isEmpty(){
    return q_size == 0;
}

//check the size
template<typename T>
size_t queueArr<T>::size(){
    return q_size;
}

//clear the queue
template<typename T>
void queueArr<T>::Clear(){
    q_size = 0;
    q_front = 0;
    q_back = q_capacity - 1;
}

//check the front
template<typename T>
T queueArr<T>::Front(){
    if(isEmpty()) return T();
    return q_arr[q_front];
}

//check the back
template<typename T>
T queueArr<T>::Back(){
    if(isEmpty()) return T();
    return q_arr[q_back];
}

//enqueue
template<typename T>
void queueArr<T>::Enqueue(T newData){
    if(q_size == q_capacity){
        std::cout << "Queue is Full" << std::endl;
        return;
    }
    q_back = (q_back + 1) % q_capacity;
    q_arr[q_back] = newData;
    q_size++;
}

//dequeue
template<typename T>
void queueArr<T>::Dequeue(){
    if(isEmpty()) return;
    q_front = (q_front + 1) % q_capacity;
    q_size--;
}

//copy constructor
template<typename T>
queueArr<T>::queueArr(const queueArr& other){
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_arr = new T[q_capacity];
    for(size_t i = 0; i < q_capacity; i++){
        q_arr[i] = other.q_arr[i];
    }
}

//copy assignment operator
template<typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other){
    if(this == &other){
        return *this;
    }
    delete[] q_arr;
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_arr = new T[q_capacity];
    for(size_t i = 0; i < q_capacity; i++){
        q_arr[i] = other.q_arr[i];
    }
    return *this;
}

#endif