#include"Stacks.h"
#include<iostream>
using namespace std;
Deck_handler::Deck_handler() {
	newNode = top = temp = NULL;
}
void Deck_handler:: Push(char input) {
	newNode = new bundle_Stack;
	if (top == NULL) {
		top = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
	top->value = input;
}
char Deck_handler::Pop() {
	if (top == NULL) {
		cout << "The Stack is empty! line 25\n";
		return 0;
	}
	else {
		char Temp; temp = top;
		Temp = top->value;
		top = top->next;
		delete temp;
		return Temp;
	}
}
bool Deck_handler::is_empty() {
	return(top == NULL);
}
char Deck_handler::get_top() {
	return top->value;
}
User_mini_stack_handler::User_mini_stack_handler()
{
	newNode = temp = top = NULL;
}
void User_mini_stack_handler::print()
{
	if (top == NULL) {
		cout << "Player have nothing";
	}
	else
	{
		temp = top;
		while (temp->next != NULL)
		{
			cout << temp->value<<" " ;
			temp = temp->next;
		}
		cout << temp->value;

	}
	//cout << "print fun ok\n";
}
void User_mini_stack_handler::Push(char input) {
	newNode = new User_Mini_Stack;
	if (top == NULL) {
		top = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
	top->value = input;
}
char User_mini_stack_handler::Pop() {
	if (top == NULL) {
		cout << "Error: The user mini Stack is empty! line 171\n";
	}
	else {
		char Temp; temp = top;
		Temp = top->value;
		top = top->next;
		delete temp;
		return Temp;
	}
}
bool User_mini_stack_handler::is_empty() {
	return(top == NULL);
}
char User_mini_stack_handler::GetTop() {
	if (top == NULL) {
		return NULL;
	}
	else {
		return top->value;
	}
}