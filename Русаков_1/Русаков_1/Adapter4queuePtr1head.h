#pragma once
#include "QueuePtr1head.h"

class Adapter4queuePtr1head
{
	QueuePtr1head* qu;
public:
	Adapter4queuePtr1head() {
		//cout << "\nОбычный конструктор\n";
		qu = new QueuePtr1head();
	}
	//adapter4QueuePtr(const adapter4QueuePtr& obj)
	//{
	//	cout << "\nКонструктор копирования\n";
	//}
	void Display() {
		qu->Display();
	}
	void push(int num) {
		qu->push(num);
	}
	void pop() {
		qu->pop();
	}
	int size() {
		return qu->size();
	}
	int front() {
		return qu->front();
	}
	int getElement(int ind) {
		int size = qu->size();
		int element = -1;
		if ((ind >= 0) and (ind < size)) {
			QueuePtr1head* queTmp1 = new QueuePtr1head();
			for (int i = 0; i <= ind; i++) {
				queTmp1->push(front());
				element = front();
				pop();
			}
			for (int i = ind + 1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
		}
		return element;
	}
	void  setElement(int ind, int element) {
		int size = qu->size();
		if ((ind >= 0) and (ind < size)) {
			QueuePtr1head* queTmp1 = new QueuePtr1head();
			for (int i = 0; i < ind; i++) {
				queTmp1->push(front());
				pop();
			}
			queTmp1->push(element);
			pop();
			for (int i = ind + 1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
		}
	}
	Adapter4queuePtr1head* copy() {
		Adapter4queuePtr1head* queTmp1 = new Adapter4queuePtr1head();
		int size = qu->size();
		for (int i = 0; i < size; i++) {
			queTmp1->push(front());
			pop();
		}
		return queTmp1;
	}
	void example_work_quickSort() {
		Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
		for (int n = 10; n <= 100; n += 5)
		{
			//int n = 300;
			for (int i = 0; i < n; i++)
				q1->push(rand());
			int size = q1->size();
			//cout << "Size of queue: " << size << endl;
			//cout << endl; q1->display();
			const clock_t begin_time = clock();
			// do something
			mergeSort4queuePtr1head(q1, 0, size - 1);
			//cout << endl; q1->display();
			//cout << endl << " n = " << n << " time (ms): ";
			cout << endl;
			cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
			for (int i = 0; i < n; i++)
				q1->pop();
		}
};