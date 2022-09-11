#include "parse.h"

using namespace std;

void Parse::regularSyntaxInBlock(int beginNum) {
	smatch m, value;
	map<string, int>::iterator it;
	integerStorage["nnn"] = beginNum;
	if(regex_search(this->text, m, addKey))
				{
					addKeyword(this->text, m[1], m[2], value);
				}
				else if(regex_search(this->text, m, minKey))
				{
					minKeyword(this->text, m[1], m[2], value);
				}
				else if(regex_search(this->text, m, mulKey))
				{
					mulKeyword(this->text, m[1], m[2], value);
				}
				else if(regex_search(this->text, m, divKey))
				{
					divKeyword(this->text, m[1], m[2], value);
				}
				else if(regex_search(this->text, m, changeKey))
				{
					changeKeyword(this->text, m[1], m[2], value);
				}
				else if(regex_search(this->text, m, eraseKey))
				{
					eraseKeyword(this->text, m[1], m[2]);
				}
				else if(regex_search(this->text, m, deleteKey))
				{
					deleteKeyword(this->text, m[1]);
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
					else if(m[1] == "float")
					{
						for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								cout << itr->second << endl;
							}
						}
					}
					else if(m[1] == "double")
					{
						for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
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
					else if(m[1] == "float")
					{
						for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								cout << itr->second << " ";
							}
						}
					}
					else if(m[1] == "double")
					{
						for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
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