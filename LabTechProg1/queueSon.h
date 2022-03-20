#pragma once
#include "queue.h"

class publicSon : public Queue {
public:
	int count() {
		int count = 0;
		Container* c = this->get_last();
		for (int i = 0; i < this->get_size(); i++, c=c->next) {
			if (c->data % 2 == 0)
				count++;
		}
		return count;
	}
	publicSon() :Queue() {};
	publicSon(int* l, int len) : Queue(l, len) {};

};

class protectedSon : protected Queue {
public:
	int count();
	void push(int data);
	int pop();
	int get();
	std::string toString();
	void merge(protectedSon& q1, protectedSon& q2);
	void copy(protectedSon& q);
	bool isEmpty();
	protectedSon() :Queue() {};
	protectedSon(int* l, int len) : Queue(l, len) {};
};

class privateSon : private Queue {
public:
	int count();
	void push(int data);
	int pop();
	int get();
	std::string toString();
	void merge(privateSon& q1, privateSon& q2);
	void copy(privateSon& q);
	bool isEmpty();
	privateSon() :Queue() {};
	privateSon(int* l, int len) : Queue(l, len) {};
};