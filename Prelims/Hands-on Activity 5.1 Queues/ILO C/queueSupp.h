#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include <iostream>
#include <string>

class Job {
public:
    int id;
    std::string user;
    int pages;

    Job() : id(0), user(""), pages(0) {}
    Job(int jobId, std::string jobUser, int jobPages)
        : id(jobId), user(jobUser), pages(jobPages) {}
};

template <typename T>
class qNode {
public:
    T data;
    qNode<T>* next;
};

template <typename T>
qNode<T>* new_node(T newData) {
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {
    qNode<T>* newNode = new_node(newData);

    if ((*frontPtr == nullptr) && (*backPtr == nullptr)) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
    if (*frontPtr == nullptr) {
        std::cout << "Queue is empty, cannot dequeue.\n";
        return;
    }

    qNode<T>* deleteNode = *frontPtr;

    if ((*frontPtr)->next == nullptr) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}

template <typename T>
bool isEmpty(qNode<T>* frontPtr) {
    return frontPtr == nullptr;
}

class Printer {
private:
    qNode<Job>* front;
    qNode<Job>* back;

public:
    Printer() : front(nullptr), back(nullptr) {}

    void addJob(Job newJob) {
        enqueue(newJob, &front, &back);
        std::cout << "Job " << newJob.id << " submitted by " << newJob.user
                   << " (" << newJob.pages << " pages) added to queue.\n";
    }

    void processOne() {
        if (isEmpty(front)) {
            std::cout << "No jobs to process.\n";
            return;
        }
        Job current = front->data;
        std::cout << "Processing Job " << current.id << " for " << current.user
                   << " (" << current.pages << " pages)...\n";
        dequeue(&front, &back);
    }

    void processAll() {
        if (isEmpty(front)) {
            std::cout << "No jobs to process.\n";
            return;
        }

        while (!isEmpty(front)) {
            Job current = front->data;
            std::cout << "Processing Job " << current.id << " for " << current.user
                       << " (" << current.pages << " pages)...\n";
            dequeue(&front, &back);
        }
        std::cout << "All jobs processed.\n";
    }
};

#endif