#pragma once

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <random>
#include <exception>
#include <filesystem>

using namespace std;
	bool create_file(string str);
	string generate_random_string(int length);
	int generate_random_number(int min, int max);
	void get_random_file_path(string header, string file_path);
namespace list {
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
		string remake_as_file(string header_str);
		size_t size();
		void del_list();
	};
	ostream& operator<<(ostream& stream, DoublyLinkedList list) {
		list.print();
		return stream;
	}
}