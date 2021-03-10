#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "settings.h"

template <class T>
class linkedList;

template <class T>
class LNode {
	friend class linkedList<T>;
private:
	T data;				//������
	LNode<T>* next;		//ָ����
public:
	LNode() :next(NULL) {}
	LNode(T& tmp) :data(tmp), next(NULL) {}
};

template <class T>
class linkedList {
	LNode<T>* head;		//ָ��ͷ����ָ��
	size_t size;		//���������
public:
	linkedList() : head(new LNode<T>), size(0) {}
	~linkedList() {
		while ( head != NULL ) {
			LNode<T>* p = head->next;
			delete head;
			head = p;
		}
	}
	bool isEmpty() const {	//�����Ƿ�Ϊ��
		return size == 0;
	}
	void push(T tmp) {		//ĩβ�����Ԫ��
		LNode<T>* p = head;
		while ( p->next != NULL ) {
			p = p->next;
		}
		p->next = new LNode<T>(tmp);
		size++;
	}
	T pop() {				//ɾ��ĩβԪ��
		LNode<T>* tmp, p = head;
		while ( p->next != NULL ) {
			tmp = p;
			p = p->next;
		}
		if ( p == head ) {//����Ϊ��
			cerr << "Linked list is emply." << endl;
			exit(1);
		}
		T tmpReturn = p->data;
		delete p;	//p��tmp->next;
		tmp->next = NULL, size--;
		return tmpReturn;
	}
	T Delete(const int index) {	//���±�ɾ��Ԫ�أ�����ɾ����ֵ��
		if ( index >= size ) {
			cerr << "The index is out of range!" << endl;
			exit(1);
		}
		int i = -1;
		LNode<T> *p = head, *tmp = head;
		while ( i != index ) {
			tmp = p;
			p = p->next;
			i++;
		}
		T tmpReturn = p->data;
		tmp->next = p->next;
		delete p;
		return tmpReturn;
	}
	void clear() {				//�������
		LNode<T>* p = head->next;
		while ( head->next != NULL ) {
			head->next = p->next;
			delete p;
			p = head->next;
		}
		size = 0;
	}
	size_t len() const {		//����������
		return size;
	}
	T& operator[](int index) const {
		if ( index >= size ) {
			cerr << "The index is out of range!" << endl;
			exit(1);
		}
		int i = -1;
		LNode<T>* p = head;
		while ( i != index ) {
			p = p->next;
			i++;
		}
		return p->data;
	}
	bool isUnique(const T& t) const {	//����Ƿ����ظ�Ԫ��
		if ( head->next == NULL )
			return true;
		const LNode<T>* p = head->next;
		while ( p != NULL ) {
			if ( t == p->data ) {
				return false;
			}
			p = p->next;
		}
		return true;
	}
};

#endif
