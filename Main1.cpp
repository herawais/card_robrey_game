#include "Main1.h"
#include"Lists.h"
#include"Stacks.h"
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<conio.h>
using namespace std;
Main1::Main1()
{

	//Shifting cards to initial array with 13 VALUES 
	values_13[0] = '9';
	values_13[1] = '3';
	values_13[2] = 'Q';
	values_13[3] = 'X';
	values_13[4] = '6';
	values_13[5] = 'J';
	values_13[6] = 'A';
	values_13[7] = '2';
	values_13[8] = '5';
	values_13[9] = '7';
	values_13[10] = '4';
	values_13[11] = 'K';
	values_13[12] = '8';
	//shifting 52 cards to deck stack
	for (int j = 0; j <= 3; j++) {
		for (int i = 0; i <= 12; i++) {
			OurMainDeck.Push(values_13[i]);
		}
	}
	//here must be a shuffler of the deck stack//


	//giving cards to users// and Desk
	for (int i = 0; i < 4; i++)
	{
		Computer.Insert_Card(OurMainDeck.Pop());
		User.Insert_Card(OurMainDeck.Pop());
		Desk.InsertCard(OurMainDeck.Pop());
	}


} // end of constructor

bool Main1::User_Turn() {
	
	if (OurMainDeck.is_empty()) {
		return false;
	}
	else {
		User.Insert_Card(OurMainDeck.Pop());
		cout << "Card is given to User\n";
		return true;
	}
}
bool Main1::User_Turn(char Throw) {
	
	if (User.Is_Exists(Throw)) {
		if (Desk.Is_exists(Throw)) {
			User_mini.Push(Desk.RetriveCard(Throw));
			
			User_mini.Push(User.RetriveCard(Throw));
			cout << "done line 64\n";
			//return true;
		}
		else if (Computer_mini.GetTop() == Throw) {
			User_mini.Push(Computer_mini.Pop());
			for (int i = 0; i <= 1; i++) {
				if (Computer_mini.GetTop() == Throw) {
					User_mini.Push(Computer_mini.Pop());
				}
			}
			//return true;
		}
		else {
			Desk.InsertCard(User.RetriveCard(Throw));
			return false;
		}

	}
	else
	{
		cout << "Your value cant be found..\n";
		return false;
	}

}
bool Main1::give_crd_cmptr()
{
	if (!OurMainDeck.is_empty()) {
		Computer.Insert_Card(OurMainDeck.Pop());
		cout << "Card is given to Computer\n";
		return true;
	}
	return false;
}
//HOW TO THROW A CARD??
//i mean that throwing a card from his(computer or user) to the desk...


void Main1::Computer_Turn() {
	
	user_mini_top = User_mini.GetTop();
	//New Logic
	if (Computer.Is_Exists(user_mini_top) && Desk.Is_exists(user_mini_top)) {
		Computer_mini.Push(Computer.RetriveCard(user_mini_top));
		Computer_mini.Push(Desk.RetriveCard(user_mini_top));
		Computer_mini.Push(User_mini.Pop());
		for (int i = 0; i < 3; i++)
		{
			if (user_mini_top == User_mini.GetTop()) {
				Computer_mini.Push(User_mini.Pop());
			}

		}
		goto line150;
	}
	else if (Computer.Is_Exists(user_mini_top) && !(Desk.Is_exists(user_mini_top))) {
		Computer_mini.Push(User_mini.Pop());
		for (int i = 0; i < 3; i++)
		{
			if (user_mini_top == User_mini.GetTop()) {
				Computer_mini.Push(User_mini.Pop());
			}

		}
		goto line150;
	}
	//New Logic end
	//if (User_mini.is_empty()||!(Computer.Is_Exists(user_mini_top))) {  // ya phir is k top k equal na ho..
	//	cout << "\t\t\tCondition 1: ran\n";
	//	
	//	if (Computer.Is_Exists(user_mini_top)) {
	//		Computer_mini.Push(Computer.RetriveCard(user_mini_top));
	//		Computer_mini.Push(User_mini.Pop());
	//		for (int i = 0; i <= 1; i++) {
	//			if (user_mini_top == User_mini.GetTop()) {
	//				Computer_mini.Push(User_mini.Pop());
	//			}
	//		}
	//	}
	//}
	else //if(1) // <---
	{
		Computer_Top_ptr = Computer.get_top_ptr();
		while (Computer_Top_ptr != NULL)
		{
			if (Desk.Is_exists(Computer_Top_ptr->value)) {
				Computer_mini.Push(Desk.RetriveCard(Computer_Top_ptr->value));
				Computer_mini.Push(Computer.RetriveCard(Computer_Top_ptr->value));
				goto line150;
				break;
			}
			else
			{
				Computer_Top_ptr = Computer_Top_ptr->next;
			}
		}
		
	}

	/*
	else {                   //if (!User_mini.is_empty())
		cout << "\t\t\tCondition 2: ran\n";
		Computer_Top_ptr = Computer.get_top_ptr();
		while (Computer_Top_ptr != NULL) {
			Table_top_ptr = Desk.Get_top_ptr();
			while (Table_top_ptr!= NULL)
			{
				if (Computer_Top_ptr->value == Table_top_ptr->value) {
					Computer_mini.Push(Computer.RetriveCard(Computer_Top_ptr->value));
					Computer_mini.Push(Desk.RetriveCard(Table_top_ptr->value));
					//agar mil jaty hain to hamari 1 or baari banti ha na...
						break;
						break;
					}
				}

				Table_top_ptr = Table_top_ptr->next;
			}
			Computer_Top_ptr = Computer_Top_ptr->next;
		}*/
	
	// here a code to throw a card to table ...
	 
	if (!Computer.is_empty()) {
		Desk.InsertCard(Computer.Pop());
	}
line150:
	if (true)
	{
		//cout << "\n Computer turn done\n";

	}
}
void Main1::run1() {
	welcome();
	system("cls");
	while (true) {
		give_crd_cmptr();
		display();
		cout << "\t\t\tComputer is Doing Its Turn:\n";
		loading();
		Computer_Turn();
		display();
		User_Turn();
		cout << "Enter value to throw\n";
		re_enter:
		usr_input=validateInput();
		
		if (User.Is_Exists(usr_input)) {
			User_Turn(usr_input);
		}
		else
		{
			goto re_enter;
		}
		display();
		//break;
		system("cls");
	}
}

void Main1::display()
{
	int cmptr_lenth;
	cout << "These are Computer's cards:\tThis is our Table:\tThese are Your cards:\n";
	//cout << "Computer have " << Computer.getLength() << "Cards";
	/*for (int i = 0; i < Computer.getLength(); i++) {
		cout << "*";
	}*/
	cmptr_lenth=Computer.getLength();
	cout <<"Computer have "<< cmptr_lenth<<" Cards ";
	cout << setw(17);
	//cout << "                            ";
	Desk.print_desk();
	cout << setw(20);
	User.print_list();
	cout << "\nYour stack: ";
	User_mini.print();
	cout << "\n";
	cout << "Computer stack: ";
	Computer_mini.print();
	cout << "\n-------------------------------------------------------------------------------\n";
	
}

void Main1::loading()
{
	char a = 177, b = 219;
	cout << "\t\t\t\t";
	for (int i = 0; i <= 15; i++)
		cout << a;
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i <= 15; i++)
	{
		cout << b;
		for (int j = 0; j <= 1e7; j++); //You can also use sleep function instead of for loop
	}
	cout << endl;
}

char Main1::validateInput()
{
	char num;
	while (1) {
		num = _getch();
		if (num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7' || num == '8' 
			           || num == '9' || num == 'X' || num == 'K' || num == 'Q' || num == 'A'|| num == 'J') {
			return num;
		}
		
	}
}

void Main1::welcome()
{
	cout << "PRESENTED BY: -->Muhammad Awais    15091519-022<--\n\n";
	cout << "Welcome to This Card Robbery game\n";
	cout << "This is a simple game whose rules are as following\n";
	cout << "->.you have 4 cards initially\n";
	cout << "->.Four cards are given to Computer also\n";
	cout << "->.Four Cards are also thrown on the TABLE \n";
	cout << "1.you have to pick a card from the table if card is matching fromm you and from the table\n";
	cout << "2.If nothing is matching then throw a card on the table\n";
	cout << "3.Computer have first turn\n";
	cout << "The winner player is that which collected more cards\n\n";
	cout << "\t\t\t\tThanks\n";
	cout << "\t\t\tPress Anything to Play the game\n";
	_getch();
	//cin.ignore();
}
