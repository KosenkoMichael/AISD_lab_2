#include <functions/functions.h>

using namespace std;
using namespace list;

string generate_random_string(int length) {
	random_device rd;
	uniform_int_distribution<int> distribution(97, 122); // диапазон символов a-z
	string randomString;
	for (int i = 0; i < length; i++) {
		randomString += static_cast<char>(distribution(rd));
	}
	return randomString;
}

int generate_random_number(int min, int max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);
}

bool create_file(string str) {
	ofstream file(str);
	if (file.is_open()) {
		file.close();
		return true;
	}
	else {
		return false;
	}
}

void get_random_file_path(string header, string file_path) {
	int count = generate_random_number(1, 10);
	DoublyLinkedList<string> list;
	for (int i = 0; i < count; i++) {
		list.push_tail(generate_random_string(generate_random_number(1, 10)));
	}
	cout << list.remake_as_file(header, file_path);
}
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = new Node<T>;
	tail = new Node<T>;
	head->_next = tail;
	tail->_prev = head;
	count = 0;
}
template<typename T>
void DoublyLinkedList<T>::push_tail(const string& data) {
	if (count == 0) {
		head->_data = data;
		count++;
	}
	else if (count == 1) {
		tail->_data = data;
		count++;
	}
	else if (count > 1) {
		Node<T>* temp = new Node<T>;
		temp->_data = data;
		tail->_next = temp;
		temp->_prev = tail;
		tail = temp;
		count++;
	}
}
template<typename T>
void DoublyLinkedList<T>::push_tail(const DoublyLinkedList& other) {
		Node<T>* temp = other.head;
		while (temp) {
			push_tail(temp->_data);
			temp = temp->_next;
		}
}
template<typename T>
void DoublyLinkedList<T>::push_head(const string& data) {
	if (count == 0) {
		head->_data = data;
		count++;
	}
	else if (count == 1) {
		tail->_data = head->_data;
		head->_data = data;
		count++;
	}
	else if (count > 1) {
		Node<T>* temp = new Node<T>;
		temp->_data = data;
		temp->_next = head;
		head->_prev = temp;
		head = temp;
		count++;
	}
}
template<typename T>
void DoublyLinkedList<T>::push_head(const DoublyLinkedList& other) {
	DoublyLinkedList<T> copy(other);
	Node<T>* temp = head;
	while (temp) {
		copy.push_tail(temp->_data);
		temp = temp->_next;
	}
	swap(copy);
}
template<typename T>
void DoublyLinkedList<T>::pop_tail() {
	if (count != 0) {
		if (count > 2) {
			Node<T>* temp = tail;
			tail = tail->_prev;
			tail->_next = nullptr;
			delete temp;
			count--;
		}
		else if (count == 2) {
			tail->_data = "";
			count--;
		}
		else if (count == 1) {
			head->_data = "";
			count--;
		}
	}
}
template<typename T>
void DoublyLinkedList<T>::pop_head() {
	if (count != 0) {
		if (count > 2) {
			Node<T>* temp = head;
			head = head->_next;
			head->_prev = nullptr;
			delete temp;
			count--;
		}
		else if (count == 2) {
			head->_data = tail->_data;
			tail->_data = "";
			count--;
		}
		else if (count == 1) {
			head->_data = "";
			count--;
		}
	}
}
template<typename T>
void DoublyLinkedList<T>::delete_node(const string& data) {
	Node* temp = head;
	while (temp) {
		if (temp->_data == data) {
			if (temp->_prev == nullptr) {
				temp = temp->_next;
				pop_head();
			}
			else if (temp->_next == nullptr) {
				temp = temp->_next;
				pop_tail();
			}
			else {
				temp = temp->_next;
				Node<T>* delete_node = temp->_prev;
				(delete_node->_prev)->_next = delete_node->_next;
				(delete_node->_next)->_prev = delete_node->_prev;
				delete delete_node;
				count--;
			}
		}
		else
			temp = temp->_next;
	}
}
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) {
	head = new Node<T>;
	tail = new Node<T>;
	head->_next = tail;
	tail->_prev = head;
	count = 0;
	Node<T>* temp = other.head;
	while (temp) {
		push_tail(temp->_data);
		temp = temp->_next;
	}
}
template<typename T>
void DoublyLinkedList<T>::swap(DoublyLinkedList& other) {
	std::swap(head, other.head);
	std::swap(tail, other.tail);
	std::swap(count, other.count);
}
template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other) {
	DoublyLinkedList copy(other);
	swap(copy);
	return *this;
}
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(size_t value, size_t len_from, size_t len_to) {
	head = new Node<T>;
	tail = new Node<T>;
	head->_next = tail;
	tail->_prev = head;
	count = 0;
	for (int i = 0; i < value; i++) {
		push_tail(generate_random_string(generate_random_number(len_from, len_to)));
	}
};
template<typename T>
string& DoublyLinkedList<T>::operator[](size_t index) {
	if (index > count-1)
		throw invalid_argument("index is out of range");
	int temp_size = 0;
	Node<T>* temp = head;
	while (temp) {
		if (temp_size == index)
			return temp->_data;
		temp = temp->_next;
		temp_size++;
	}
}
template<typename T>
void DoublyLinkedList<T>::del_list() {
	while (head) {
		tail = head->_next;
		delete head;
		head = tail;
	}
}
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	del_list();
}
template<typename T>
void DoublyLinkedList<T>::print() {
	Node<T>* temp = head;
	while (temp) {
		cout << temp->_data << endl;
		temp = temp->_next;
	}
}
template<typename T>
string DoublyLinkedList<T>::remake_as_file(string header_str, string footer_str) {
	string str = "";
	string valid_str = "";
	Node<T>* temp = head;
	while (temp) {
		str += temp->_data + "\\";
		temp = temp->_next;
	}

	// создаем список символов, которые нужно игнорировать
	string ignoreChars = "!#+/*?:";

	// перебираем символы в исходной строке
	for (char c : str) {
		// провер€ем, €вл€етс€ ли текущий символ игнорируемым
		if (ignoreChars.find(c) == string::npos) {
			// символ не €вл€етс€ игнорируемым, добавл€ем его в новую строку
			valid_str += c;
		}
	}
	return header_str + valid_str + footer_str;
}
template<typename T>
size_t  DoublyLinkedList<T>::size() {
	return count;
}