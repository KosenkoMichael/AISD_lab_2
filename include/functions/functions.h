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
	template<typename T>
	struct Node {
		Node* _prev;
		T _data;
		Node* _next;
		Node() : _prev(nullptr), _data(), _next(nullptr) {};
	};
	template<typename T>
	class DoublyLinkedList {
	private:
		Node<T>* head;
		Node<T>* tail;
		size_t count;
		void del_list();
	public:
		DoublyLinkedList();
		DoublyLinkedList(size_t value, size_t len_from, size_t len_to);
		~DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList<T>& other);
		void swap(DoublyLinkedList<T>& other);
		DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);
		void push_tail(const string& data);
		void push_tail(const DoublyLinkedList<T>& other);
		void push_head(const string& data);
		void push_head(const DoublyLinkedList<T>& other);
		void pop_head();
		void pop_tail();
		void delete_node(const string& data);
		string& operator[](size_t index);
		void print();
		string remake_as_file(string header_str, string footer_str);
		size_t size();
	};
	template<typename T>
	ostream& operator<<(ostream& stream, DoublyLinkedList<T>& list) {
		list.print();
		return stream;
	}
}