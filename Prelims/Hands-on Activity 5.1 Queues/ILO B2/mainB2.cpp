#include <iostream>
#include "queueArr.h"

int main(){
    queueArr<int> q(5);
    std::cout << "Check if the Queue is empty: " << q.isEmpty() << ", size: " << q.size() << std::endl;

    std::cout << "\nEnqueue 6, 9, 7:" << std::endl;
    q.Enqueue(6);
    q.Enqueue(9);
    q.Enqueue(7);
    std::cout << "size: " << q.size() << ", Front: " << q.Front() << ", Back: " << q.Back() << std::endl;

    std::cout << "\nDequeue once:" << std::endl;
    q.Dequeue();
    std::cout << "size: " << q.size() << ", Front: " << q.Front() << ", Back: " << q.Back() << std::endl;

    std::cout << "\nEnqueue 3, 8, 4 (fills to capacity):" << std::endl;
    q.Enqueue(3);
    q.Enqueue(8);
    q.Enqueue(4);
    std::cout << "size: " << q.size() << ", Front: " << q.Front() << ", Back: " << q.Back() << std::endl;

    std::cout << "\nEnqueue while full:" << std::endl;
    q.Enqueue(1); 
    std::cout << "size is still: " << q.size() << std::endl;

    std::cout << "\nClear the queue:" << std::endl;
    q.Clear();
    std::cout << "isEmpty: " << q.isEmpty() << ", size: " << q.size() << std::endl;

    std::cout << "\nRefill with 6, 9, 7:" << std::endl;
    q.Enqueue(6);
    q.Enqueue(9);
    q.Enqueue(7);
    std::cout << "size: " << q.size() << ", Front: " << q.Front() << ", Back: " << q.Back() << std::endl;

    std::cout << "\nCopy constructor (q2 = q):" << std::endl;
    queueArr<int> q2 = q;
    std::cout << "size: " << q2.size() << ", Front: " << q2.Front() << ", Back: " << q2.Back() << std::endl;

    std::cout << "\nCopy assignment (q3 = q):" << std::endl;
    queueArr<int> q3(9);
    q3.Enqueue(1);
    q3.Enqueue(2);
    q3 = q;
    std::cout << "size: " << q3.size() << ", Front: " << q3.Front() << ", Back: " << q3.Back() << std::endl;

    return 0;
}