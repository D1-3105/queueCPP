#include "queueSon.h"

int privateSon::count()
{
	{
		int count = 0;
		Container* c = this->get_last();
		for (int i = 0; i < this->get_size(); i++, c = c->next) {
			if (c->data % 2 == 0)
				count++;
		}
		return count;
	}
}

void privateSon::push(int data)
{
	return Queue::push(data);
}

int privateSon::pop()
{
	return Queue::pop();
}

int privateSon::get()
{
	return Queue::get();
}

std::string privateSon::toString()
{
	return Queue::toString();
}

void privateSon::merge(Queue& q)
{
	return Queue::merge(q);
}

void privateSon::copy(Queue& q)
{
	return Queue::copy(q);
}

bool privateSon::isEmpty()
{
	return Queue::isEmpty();
}

int protectedSon::count()
{
	if(!this->isEmpty())
	{
		int count = 0;
		Container* c = this->get_last();
		for (int i = 0; i < this->get_size(); i++, c = c->next) {
			if (c->data % 2 == 0)
				count++;
		}
		return count;
	}
}

void protectedSon::push(int data)
{
	return Queue::push(data);
}

int protectedSon::pop()
{
	return Queue::pop();
}

int protectedSon::get()
{
	return Queue::get();
}

std::string protectedSon::toString()
{
	return Queue::toString();
}

void protectedSon::merge(Queue& q)
{
	return Queue::merge(q);
}

void protectedSon::copy(Queue& q)
{
	return Queue::copy(q);
}

bool protectedSon::isEmpty()
{
	return Queue::isEmpty();
}
