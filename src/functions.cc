#include <functions/functions.h>

using namespace std;
using namespace list;

string generateRandomString(int length) {
	random_device rd;
	uniform_int_distribution<int> distribution(97, 122); // диапазон символов a-z
	string randomString;
	for (int i = 0; i < length; i++) {
		randomString += static_cast<char>(distribution(rd));
	}
	return randomString;
}

int generateRandomNumber(int min, int max) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(mt);
}

DoublyLinkedList::DoublyLinkedList() {
	head = new Node;
	tail = new Node;
	head->_next = tail;
	tail->_prev = head;
	count = 0;
}
void DoublyLinkedList::push_tail(const string& data) {
	if (count == 0) {
		head->_data = data;
		count++;
	}
	else if (count == 1) {
		tail->_data = data;
		count++;
	}
	else if (count > 1) {
		Node* temp = new Node;
		temp->_data = data;
		tail->_next = temp;
		temp->_prev = tail;
		tail = temp;
		count++;
	}
}
void DoublyLinkedList::push_tail(const DoublyLinkedList& other) {
		Node* temp = other.head;
		while (temp) {
			push_tail(temp->_data);
			temp = temp->_next;
		}
}
void DoublyLinkedList::push_head(const string& data) {
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
		Node* temp = new Node;
		temp->_data = data;
		temp->_next = head;
		head->_prev = temp;
		head = temp;
		count++;
	}
}
void DoublyLinkedList::push_head(const DoublyLinkedList& other) {
	DoublyLinkedList copy(other);
	Node* temp = head;
	while (temp) {
		copy.push_tail(temp->_data);
		temp = temp->_next;
	}
	swap(copy);
}
void DoublyLinkedList::pop_tail() {
	if (count != 0) {
		if (count > 2) {
			Node* temp = tail;
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
void DoublyLinkedList::pop_head() {
	if (count != 0) {
		if (count > 2) {
			Node* temp = head;
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
void DoublyLinkedList::delete_node(const string& data) {
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
				Node* delete_node = temp->_prev;
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
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other) {
	head = new Node;
	tail = new Node;
	head->_next = tail;
	tail->_prev = head;
	count = 0;
	Node* temp = other.head;
	while (temp) {
		push_tail(temp->_data);
		temp = temp->_next;
	}
}
void DoublyLinkedList::swap(DoublyLinkedList& other) {
	std::swap(head, other.head);
	std::swap(tail, other.tail);
	std::swap(count, other.count);
}
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other) {
	DoublyLinkedList copy(other);
	swap(copy);
	return *this;
}
DoublyLinkedList::DoublyLinkedList(size_t value, size_t len_from, size_t len_to) {
	head = new Node;
	tail = new Node;
	head->_next = tail;
	tail->_prev = head;
	count = 0;
	for (int i = 0; i < value; i++) {
		push_tail(generateRandomString(generateRandomNumber(len_from, len_to)));
	}
};
string DoublyLinkedList::operator[](size_t index) {
	if (index > count-1)
		throw std::invalid_argument("index is out of range");
	int temp_size = 0;
	Node* temp = head;
	while (temp) {
		if (temp_size == index)
			return temp->_data;
		temp = temp->_next;
		temp_size++;
	}
}
void DoublyLinkedList::del_list() {
	while (head) {
		tail = head->_next;
		delete head;
		head = tail;
	}
}
DoublyLinkedList::~DoublyLinkedList() {
	del_list();
}
void DoublyLinkedList::print() {
	Node* temp = head;
	while (temp) {
		if (temp->_data.size())
			cout << temp->_data << endl;
		temp = temp->_next;
	}
}
void DoublyLinkedList::print_as_file() {
	Node* temp = head;
	while (temp) {
		if (temp->_data.size())
			cout << temp->_data << "/";
		temp = temp->_next;
	}
}
size_t  DoublyLinkedList::size() {
	return count;
}