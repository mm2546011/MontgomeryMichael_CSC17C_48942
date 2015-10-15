#include "SimpleLinkedList.h"
#include <string>
struct Test
{
	int temp;
	string name;
};

int main()
{
	Test temp;
	temp.temp = 12;
	temp.name = "Hello World";
	LinkedList<Test> test1(temp);
	Test temp2 = test1.getLast();	
	cout << temp2.name << "|" << temp2.temp << endl;


	/*LinkedList<int> test1(5);
	LinkedList<int> test2(test1);
	test1.append(6);
	test2.append(78);
	cout << test1.getLast() << endl;
	cout << test1.getFirst() << endl;
	test1.prepend(1);
	cout << test1.getFirst() << endl;
	int amt = test1.extract(6);
	cout << test1.getLast() <<" found it "<<amt<< " times"<< endl;
	test1.insertAfter(7, 2);
	cout << test1.getLast() << endl;
	test1.insertBefore(9, 1);
	cout << test1.getFirst() << endl;
	test2 = test1;
	cout << test2.getLast() << endl;
	cout << test2.getFirst() << endl;*/


	system("Pause");
	return 0;
}