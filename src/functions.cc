#include <functions/functions.h>

using namespace std;
using namespace list;

string list::generateRandomString(int length) {
	random_device rd;
	uniform_int_distribution<int> distribution(97, 122); // диапазон символов a-z
	string randomString;
	for (int i = 0; i < length; i++) {
		randomString += static_cast<char>(distribution(rd));
	}
	return randomString;
}

int list::generateRandomNumber(int min, int max) {
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
void DoublyLinkedList::boom() {
	while (head) {
		tail = head->_next;
		delete head;
		head = tail;
	}
}
DoublyLinkedList::~DoublyLinkedList() {
	boom();
}
void DoublyLinkedList::print() {
	Node* temp = head;
	while (temp) {
		cout << temp->_data<<endl;
		temp = temp->_next;
	}
}
size_t  DoublyLinkedList::get_count() {
	return count;
}