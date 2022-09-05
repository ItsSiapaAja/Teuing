#include "parse.h"

using namespace std;

void Parse::regularSyntaxInBlock(int beginNum) {
	smatch m, value;
	map<string, int>::iterator it;
	integerStorage["nnn"] = beginNum;
	if(regex_search(this->text, m, addKey))
	{
		if(m[1] == "text" && regex_search(this->text, value, textVal))
		{
			for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
			{
				if(m[2] == itr->first)
				{
					itr->second += value[1];
				}
			}
		}
		else if(m[1] == "integer" && regex_search(this->text, value, integerVal))
		{
			for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
			{
				if(m[2] == itr->first)
				{
					itr->second += stoi(value[1]);
				}
			}
		}
	}
	else if(regex_search(this->text, m, minKey))
	{
		if(regex_search(this->text, value, integerVal))
		{
			for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
			{
				if(m[1] == itr->first)
				{
					itr->second -= stoi(value[1]);
				}
			}
		}
	}
	else if(regex_search(this->text, m, mulKey))
	{
		if(regex_search(this->text, value, integerVal))
		{
			for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
			{
				if(m[1] == itr->first)
				{
					itr->second *= stoi(value[1]);
				}
			}
		}
	}
	else if(regex_search(this->text, m, divKey))
	{
		if(regex_search(this->text, value, integerVal))
		{
			for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
			{
				if(m[1] == itr->first)
				{
					itr->second /= stoi(value[1]);
				}
			}
		}
	}
	else if(regex_search(this->text, m, changeKey))
	{
		if(m[1] == "text" && regex_search(this->text, value, textVal))
		{
			for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
			{
				if(m[2] == itr->first)
				{
					itr->second = value[1];
				}
			}
		}
		else if(m[1] == "integer" && regex_search(this->text, value, integerVal))
		{
			for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
			{
				if(m[2] == itr->first)
				{
					itr->second = stoi(value[1]);
				}
			}
		}
		else if(m[1] == "bool" && regex_search(this->text, value, boolVal))
		{
			for(auto itr = boolStorage.begin(); itr != boolStorage.end(); ++itr)
			{
				if(m[2] == itr->first && value[1] == "true")
				{
					itr->second = true;
				}
				else if(m[2] == itr->first && value[1] == "false")
				{
					itr->second = false;
				}
			}
		}
	}
	else if(regex_search(this->text, m, eraseKey))
	{
		if(m[1] == "text")
		{
			stringStorage.erase(m[2]);
		}
		else if(m[1] == "integer")
		{
			integerStorage.erase(m[2]);
		}
		else if(m[1] == "bool")
		{
			boolStorage.erase(m[2]);
		}
	}
	else if(regex_search(this->text, m, printKey))
	{
		if(m[1] == "text")
		{
			for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
			{
				if(m[2] == itr->first)
				{
					cout << itr->second << endl;
				}
			}
		}
		else if(m[1] == "integer")
		{
			for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
			{
				if(m[2] == itr->first)
				{
					cout << itr->second << endl;
				}
			}
		}
		else if(m[1] == "bool")
		{
			for(auto itr = boolStorage.begin(); itr != boolStorage.end(); ++itr)
			{
				if(itr->first == m[2])
				{
					cout << itr->second << endl;
				}
			}
		}
	}
	else if(regex_search(this->text, m, printSpaceKey))
	{
		if(m[1] == "text")
		{
			for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
			{
				if(m[2] == itr->first)
				{
					cout << itr->second << " ";
				}
			}
		}
		else if(m[1] == "integer")
		{
			for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
			{
				if(m[2] == itr->first)
				{
					cout << itr->second << " ";
				}
			}
		}
		else if(m[1] == "bool")
		{
			for(auto itr = boolStorage.begin(); itr != boolStorage.end(); ++itr)
			{
				if(itr->first == m[2])
				{
					cout << itr->second << " ";
				}
			}
		}
	}

	it = integerStorage.find("nnn");
	integerStorage.erase(it);
}