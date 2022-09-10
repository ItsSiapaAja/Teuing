/*
	Teuing Language
	Version 0.0.6-b1
	Since 2022

	Main file, everything is start here (console), then parse the .teu file into parse.h
*/

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include "parse.h"

using namespace std;

string input, args[100];

bool backConsole()
{
	fstream file;
	string textBuffer;
	Parse* parse = new Parse();

	if(input == "run")
	{
		if(!args[0].empty())
		{
			if(args[0].substr(args[0].find_last_of('.') + 1) == "teu")
			{
				file.open(args[0]);

				if(!file)
				{
					cout << "Cannot open the file" << endl << endl;
				}

				while(getline(file, textBuffer))
				{
					parse->setText(textBuffer);
					parse->start();
				}

				cout << endl;
			}
			else
			{
				cout << "There's no file named as you typed" << endl << endl;
			}
		}
	}
	else if(input == "exit")
	{
		if(args[0] == "yes")
		{
			cout << "Goodbye\n" << endl;
			Sleep(1000);
			system("cls");
			system("color 0f");
			file.close();
			return true;
		}
	}
	else if(input == "clear")
	{
		if(args[0] == "yes")
		{
			system("cls");
		}
	}

	file.close();
	delete parse;
	return false;
}

void mainConsole()
{
	bool exit;
	system("cls");
	system("color 1f");
	cout << version << endl;
	while(exit != true)
	{
		cout << "[1] >> ";
		cin >> input;
		cout << "[2] >> ";
		cin >> args[0];
		exit = backConsole();
	}
}

void console()
{
	mainConsole();
}

int main()
{
	console();
	system("cls");
	system("color 0f");
	return 0;
}
