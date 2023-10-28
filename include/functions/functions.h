#pragma once

#include <string>
#include <stdio.h>
#include <iostream>
#include <random>
#include <exception>

using namespace std;

namespace list {
	string generateRandomString(int length);
	int generateRandomNumber(int min, int max);
	struct Node {
		Node* _prev;
		string _data;
		Node* _next;
		Node() : _prev(nullptr), _data(), _next(nullptr) {};
	};
	class DoublyLinkedList {
	private:
		Node* head;
		Node* tail;
		size_t count;
	public:
		DoublyLinkedList();
		DoublyLinkedList(size_t value, size_t len_from, size_t len_to);
		~DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList& other);
		void swap(DoublyLinkedList& other);
		DoublyLinkedList& operator=(const DoublyLinkedList& other);
		void push_tail(const string& data);
		void push_tail(const DoublyLinkedList& other);
		void push_head(const string& data);
		void push_head(const DoublyLinkedList& other);
		void pop_head();
		void pop_tail();
		void delete_node(const string& data);
		string operator[](size_t index);
		void print();
		void print_as_file();
		size_t size();
		void del_list();
	};
}