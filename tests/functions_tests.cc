#include <gtest/gtest.h>

#include <functions/functions.h>

using namespace std;
using namespace list;

TEST(test_1, test) {
	//DoublyLinkedList a;
	//a.push_tail("suu");
	//a.push_tail("suu");
	//a.push_tail("suu");
	//a.print();
	//cout << a.size()<<endl;
	//DoublyLinkedList b(a);
	//b.print();
	//cout << b.size() << endl;
	//DoublyLinkedList c(5, 4, 10);
	//c.print();
	//cout << c.size() << endl;
	//c.swap(a);
	//a.print();
	//DoublyLinkedList suu;
	//suu = a;
	//suu.print();
	/*DoublyLinkedList a;
	a.push_tail("1");
	a.push_tail("2");
	a.push_tail("3");
	a.print();
	DoublyLinkedList b;
	b.push_tail("11");
	b.push_tail("22");
	b.push_tail("33");
	b.print();
	a.push_head(b);
	cout << "\n";
	a.print();*/
	/*DoublyLinkedList b;
	b.push_tail("11");
	b.push_tail("22");
	b.push_tail("33");
	try {
		cout << b[3];
	}
	catch(std::invalid_argument e) {
		cout << e.what();
	}*/
	/*DoublyLinkedList b;
	b.push_tail("1");
	b.pop_head();
	b.push_tail("2");
	b.print();*/
	/*DoublyLinkedList b;
	b.push_tail("1");
	b.push_tail("2");
	b.push_tail("3");
	b.delete_node("2");
	b.print();*/
	DoublyLinkedList b;
	b.push_tail("first");
	b.push_tail("seco::nd");
	b.push_tail("third");
	cout << b.remake_as_file();
}