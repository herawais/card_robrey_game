#pragma once
#include"Lists.h"
#include"Stacks.h"
class Main1
{
public:
	Main1();
	bool User_Turn();
	bool User_Turn(char Throw);
	bool give_crd_cmptr();
	void Computer_Turn();
	void run1();
	void display();
	void loading();
	char validateInput();
	void welcome();
	
private:
	Deck_handler OurMainDeck;
	User_List_Handler Computer, User;
	User_List *Computer_Top_ptr, *User_Top_ptr;
	Desk_List *Table_top_ptr;
	Desk_handler Desk;
	User_mini_stack_handler Computer_mini, User_mini;
	int DskLen1, CmputrLen, UsrLen, temp_rand;
	char valOfComputer, user_mini_top, temp_Rand;
	char usr_input;
	char values_13[13];

};