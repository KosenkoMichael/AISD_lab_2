#include <gtest/gtest.h>

#include <functions/functions.h>

using namespace std;
using namespace list;

//TEST(test_1, test) {
//	DoublyLinkedList b;
//	b.push_tail("2");
//	b.push_tail("3");
//	b.push_tail("3");
//	b.push_tail("3");
//	b.push_head("1");
//	b.push_head("3");
//	b.push_tail("4");
//	b.push_tail("3");
//	cout << b << endl;
//	b.delete_node("3");
//	b[0] = "SUUUUUUUUUUUUUU";
//	cout << b<<endl;
//
//	DoublyLinkedList c(b);
//	DoublyLinkedList d(b);
//
//	b.push_head(c);
//	b.push_tail(d);
//
//	cout << b.size()<< " "<< b[1];
//
//}

TEST(test_2, test) {
	DoublyLinkedList<string> b;
	b.push_tail("Us!??++ers");
	b.push_tail("Aspire 7");
	b.push_tail("Desktop");
	b.push_tail("AISD_lab_2");
	string file_end = "CUR_FILE.txt";
	cout << b.remake_as_file("C:\\", file_end)<<endl;
	create_file(b.remake_as_file("C:\\",file_end));
	get_random_file_path("D:\\", "file.txt");
}