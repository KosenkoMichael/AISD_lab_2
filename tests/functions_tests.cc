#include <gtest/gtest.h>

#include <functions/functions.h>

using namespace std;
using namespace list;

TEST(test_1, test) {
	DoublyLinkedList a;
	a.push_tail("suu");
	a.push_tail("suu");
	a.push_tail("suu");
	a.print();
	cout << a.get_count()<<endl;
	DoublyLinkedList b(a);
	b.print();
	cout << b.get_count() << endl;
	DoublyLinkedList c(5, 4, 10);
	c.print();
	cout << c.get_count() << endl;
}