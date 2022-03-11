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
	void merge(Queue& q);
	void copy(Queue& q);
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
