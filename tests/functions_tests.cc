#include <gtest/gtest.h>

#include <functions/functions.h>

using namespace std;
using namespace list;

TEST(test_1, test) {
	DoublyLinkedList b;
	b.push_tail("Users");
	b.push_tail("79379");
	b.push_tail("Desktop");
	b.push_tail("aisd_lab_2");
	string file_end = "CUR_FILE.txt";
	cout << b.remake_as_file("C:\\")+file_end<<endl;
	create_file(b.remake_as_file("C:\\") + file_end);
	get_random_file_path("D:\\", "file.txt");
}