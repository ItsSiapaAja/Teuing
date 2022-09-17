/*
	Teuing Language
	Version 0.0.6
	Since 2022

	Main file, everything is start here (console), then parse the .teu file into parse.h
*/

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "parse.h"

using namespace std;

string input, args[100];

void readFile(string fileName)
{
	fstream file;
	string textBuffer;
	Parse* parse = new Parse();

	if(!fileName.empty())
	{
		if(fileName.substr(fileName.find_last_of('.') + 1) == "teu")
		{
			file.open(fileName);

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

	file.close();
	delete parse;
}

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

int main(int argc, char** argv)
{
	if(argc == 2 && strncmp(argv[1], "--c", 3) == 0)
	{
		console();
		system("cls");
		system("color 0f");
	}
	else if(argc == 3 && strncmp(argv[1], "--r", 3) == 0)
	{
		readFile(argv[2]);
	}
	else if(argc == 2 && strncmp(argv[1], "--v", 3) == 0)
	{
		cout << version << endl;
		cout << "Created by ItsSiapaAja" << endl;
	}
	else
	{
		cout << "TEUING INTERPRETER" << endl;
		cout << "\t[--r][file_name]for running a spesific program" << endl;
		cout << "\t[--c][-n | -i]  for open a console (-n for the old console, and -i for input console)" << endl;
		cout << "\t[--v]           for showing a interpreter version" << endl;
		cout << "\t[--h]           for running a console" << endl;
	}
	
	return 0;
}
