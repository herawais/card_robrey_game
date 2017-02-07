#pragma once
struct Desk_List
{
	char value;
	Desk_List *next;
};
class Desk_handler {
private:
	Desk_List *newNode, *temp, *top, *curr, *curr1;
	int count;
public:
	
	Desk_handler();

	void InsertCard(char input);

	void DelCard(char InVal);

	void print_desk();

	bool Is_exists(char inval);

	int getLeangth();

	bool is_empty();

	char RetriveCard(char incard);

	Desk_List * Get_top_ptr();

};
struct User_List {
	char value;
	char Type;
	User_List *next;
};
class User_List_Handler {
private:
	User_List *newNode, *top, *temp, *curr;
	int Length;
public:
	

	User_List_Handler();

	int getLength();

	char RetriveCard(char incard);

	void DelCard(char InVal);

	bool Is_Exists(char vall);

	void Insert_Card(char input);

	bool is_empty();

	char GetNxtVal();

	User_List * get_top_ptr();

	char Pop();

	char Throw();

	void print_list();

};