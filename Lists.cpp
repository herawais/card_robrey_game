#include"Lists.h"
#include<iostream>
using namespace std;
Desk_handler::Desk_handler() {
	newNode = temp = top = NULL;
	curr = top;
	count = 0;
}

void Desk_handler::InsertCard(char input) {
	newNode = new Desk_List;
	if (top == NULL) {
		top = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = top;
		top = newNode;
	}

	top->value = input;
	count++;
}
void Desk_handler::DelCard(char InVal) {
	if (top->value == InVal) {
		top = top->next;
		count--;
	}
	else {
		temp = top;
		curr1 = temp;
		while (temp->next != NULL) {
			if (temp->value == InVal) {
				curr1->next = temp->next;
				count--;
				break;
			}
			else {
				curr1 = temp;
				temp = temp->next;
			}
		}
	}
}
void Desk_handler::print_desk() {
	temp = top;
	if (top == NULL) {
		cout << "The Desk is Empty";
	}
	else
	{


		while (temp->next != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << temp->value;
	}
}
bool Desk_handler::Is_exists(char inval) {
	temp = top;
	if (temp==NULL) {
		return false;
	}
	while (temp->next != NULL) {
		if (temp->value == inval) {
			return true;
		}
		temp = temp->next;
	}
	if (temp->value == inval) {
		return true;
	}
	else
	return false;
}
int  Desk_handler::getLeangth() {
	temp = top;
	count = 0;
	if (top == NULL) {
		return count;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
	//	count++;
		return count;
	}
}
bool Desk_handler::is_empty() {
	return(top == NULL);
}
char Desk_handler::RetriveCard(char incard) {
	temp = top;
	curr = temp;
	char Tempp;
	if (top->value == incard) {
		Tempp = top->value;
		top = top->next;
		count--;
		return Tempp;
	}
	else {
		while (temp->next != NULL)
		{
			if (temp->value == incard) {
				Tempp = temp->value;
				curr->next = temp->next;
				count--;
				return Tempp;
			}
			curr = temp;
			temp = temp->next;
		}
	}
	if (temp->value == incard) {
		Tempp = temp->value;
		curr->next = NULL; 
		count--;
		return Tempp;
	}

}
Desk_List * Desk_handler::Get_top_ptr() {
	if (top == NULL)
		return NULL;
	else
		return top;
}
User_List_Handler::User_List_Handler() {
	newNode = top = temp = NULL;
	curr = NULL;
	Length = 0;
}
int User_List_Handler::getLength() {
	int count;
	temp = top;
	count = 0;
	if (top == NULL) {
		return count;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
			count++;
		return count;
	}
}
char User_List_Handler::RetriveCard(char incard) {
	temp = top;
	curr = temp;
	char Tempp;
	if (top->value == incard) {
		Tempp = top->value;
		top = top->next;
		return Tempp;
	}
	else {
		while (temp->next != NULL)
		{
			if (temp->value == incard) {
				Tempp = temp->value;
				curr->next = temp->next;
				return Tempp;
			}
			curr = temp;
			temp = temp->next;
		}
		if (temp->value == incard) {
			Tempp = temp->value;
			curr->next = NULL;
			return Tempp;
		}
	}
	Length--;
}
void User_List_Handler::DelCard(char InVal) {
	temp = top;
	curr = temp;
	while (temp->next != NULL)
	{
		if (temp->value == InVal) {
			curr->next = temp->next;
			break;
		}
	}
}
bool User_List_Handler::Is_Exists(char vall) {
	temp = top;
	while (temp->next != NULL) {
		if (temp->value == vall) {
			return true;
		}
		temp = temp->next;

	}
	if (temp->value == vall) {
		return true;
	}
	else
	return false;
}
void User_List_Handler::Insert_Card(char input) {
	newNode = new User_List;
	if (top == NULL) {
		top = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
	top->value = input;
	Length++;
}

bool User_List_Handler::is_empty() {
	return(top == NULL);
}
char User_List_Handler::GetNxtVal() {
	if (curr == NULL) {
		curr = top;
	}
	else {
		curr = curr->next;
		return curr->value;

	}
}
User_List* User_List_Handler::get_top_ptr() {
	if (top == NULL)
		return NULL;
	else
		return top;
}
char User_List_Handler::Pop() {
	if (top != NULL) {
		char TEmP;
		TEmP = top->value;
		top = top->next;
		return TEmP;
	}
}
void User_List_Handler::print_list() {
	temp = top;
	if (top == NULL) {
		cout << "Player have nothing\n";
	}
	else {
		while (temp->next != NULL) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << temp->value;
	}
}