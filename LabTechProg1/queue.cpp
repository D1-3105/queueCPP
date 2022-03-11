#include "queue.h"
Queue::Queue(int* datas, int len) {
    this->tail = nullptr;
    
    for (int i = 0; i < len; i++) {
        this->push(datas[i]);
    }

}

Queue::Queue() {
    this->tail = nullptr;
    this->size = 0;
}


void Queue::push(int data)
{
    Container* newCont = new Container;
    newCont->data = data;
    newCont->next = this->tail;
    this->tail = newCont;
    this->size++;
}

int Queue::pop()
{
    Container* ptr = this->tail;
    Container* prev = ptr;
    while (ptr->next != nullptr) {
        prev = ptr;
        ptr = ptr->next;
    }

    int val = ptr->data;
    delete ptr;
    ptr = nullptr;
    prev->next = nullptr;
    this->size--;
    return val;
}

int Queue::get()
{
    Container* ptr = this->tail;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    return ptr->data;
}

std::string Queue::toString()
{
    
    std::string ans = "{";
    Container* cont = this->tail;
    for (int i = 0; i < this->size; i++, cont=cont->next) {
        ans += " "+std::to_string(cont->data);
    }
    ans += "}";
    return ans;
}

void Queue::copy(Queue& q)
{
    int* qarr = q.toArr();
    for (int i = 0; i < q.get_size(); i++) {
        this->push(qarr[i]);
    }
}

void Queue::merge(Queue& q) {
    this->copy(q);
    std::cout << this->toString();
}

int* Queue::toArr()
{
    int* datas = new int[this->size];
    Container* c = this->tail;
    for (int i = 0; i < this->size; i++, c=c->next) {
        datas[i] = c->data;
    }

    return datas;
}

Queue::~Queue()
{
    while(size>0) {
        Container* tmp = this->tail;
        this->tail = this->tail->next;
        delete tmp;
        size--;
    }
}

Container* Queue::get_last()
{
    return this->tail;
}