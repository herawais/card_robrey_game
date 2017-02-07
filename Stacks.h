#pragma once
struct bundle_Stack {
	char value;
	bundle_Stack *next;
};
class Deck_handler {

	bundle_Stack *newNode, *top, *temp;
public:
	Deck_handler();
	void Push(char input);

	char Pop();

	bool is_empty();

	char get_top();

	

};
struct User_Mini_Stack
{
	char value;
	char Type;
	User_Mini_Stack *next;
};
class User_mini_stack_handler
{
public:
	void Push(char input);
	char Pop();
	bool is_empty();
	char GetTop();
	User_mini_stack_handler();
	void print();
private:
	User_Mini_Stack *newNode, *temp, *top;
	
	
};