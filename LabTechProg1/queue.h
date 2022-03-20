#pragma once
#include <string>
#include <iostream>
struct Container {
	Container* next;
	int data;
};

class Queue {
private:
	Container* tail;
protected:
	int size;

public:
	Queue();
	Queue(int* datas, int len);
	void push(int data);
	int pop();
	int get();
	std::string toString();
	void merge(Queue& q1, Queue& q2);
	void copy(Queue& q, int force=1);
	int* toArr();
	int get_size() {
		return this->size;
	}
	~Queue();
	bool isEmpty() {
		return size == 0;
	}
	Container* get_last();
};
