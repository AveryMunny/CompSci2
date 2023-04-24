#ifndef CHARLIST_HPP
#define CHARLIST_HPP
class charList
{
private:
	struct ListNode
	{
		char data;
		ListNode* next;
	};
	ListNode *head;

public:
	void displayList() const; //displaying the list
	charList(); //constructor 
	~charList(); //deconstructor
	void appendNode(double n); //adding items
	void insertNode(double n); //inserting an item
	void deleteNode(double n); //deleting items 



};






#endif //CHARLIST_HPP
