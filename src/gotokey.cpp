#include "parse.h"

using namespace std;

void Parse::regularSyntaxGoto(string textGoto) {
	smatch m, value;
	if(inLoop == 0)
			{
				if(regex_search(textGoto, m, newKey))
				{
					if(m[1] == "text" && regex_search(textGoto, value, textVal))
					{
						stringStorage.insert(pair<string, string>(m[2], value[1]));
					}
					else if(m[1] == "integer" && regex_search(textGoto, value, integerVal))
					{
						integerStorage.insert(pair<string, int>(m[2], stoi(value[1])));
					}
					else if(m[1] == "bool" && regex_search(textGoto, value, boolVal))
					{
						if(value[1] == "true")
						{
							boolStorage.insert(pair<string, bool>(m[2], true));
						}
						else if(value[1] == "false")
						{
							boolStorage.insert(pair<string, bool>(m[2], false));
						}
					}
				}
				else if(regex_search(textGoto, m, addKey))
				{
					if(m[1] == "text" && regex_search(textGoto, value, textVal))
					{
						for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second += value[1];
							}
						}
					}
					else if(m[1] == "integer" && regex_search(textGoto, value, integerVal))
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
				else if(regex_search(textGoto, m, minKey))
				{
					if(regex_search(textGoto, value, integerVal))
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
				else if(regex_search(textGoto, m, mulKey))
				{
					if(regex_search(textGoto, value, integerVal))
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
				else if(regex_search(textGoto, m, divKey))
				{
					if(regex_search(textGoto, value, integerVal))
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
				else if(regex_search(textGoto, m, changeKey))
				{
					if(m[1] == "text" && regex_search(textGoto, value, textVal))
					{
						for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second = value[1];
							}
						}
					}
					else if(m[1] == "integer" && regex_search(textGoto, value, integerVal))
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
				else if(regex_search(textGoto, m, loopKey))
				{
					int n = stoi(m[1]);
					int end = stoi(m[2]);
					if(n < end)
					{
						if(regex_search(textGoto, m, outKey))
						{
							nStorage["N"] = n;
							for(; nStorage["N"] <= end; nStorage["N"]++)
							{
								cout << nStorage["N"];
							}
						}
						else if(regex_search(textGoto, m, outSpaceKey))
						{
							nStorage["N"] = n;
							for(; nStorage["N"] <= end; nStorage["N"]++)
							{
								cout << nStorage["N"] << " ";
							}
						}
						else if(regex_search(textGoto, m, outLineKey))
						{
							nStorage["N"] = n;
							for(; nStorage["N"] <= end; nStorage["N"]++)
							{
								cout << nStorage["N"] << endl;
							}
						}
					}
					nStorage.clear();
				}
				else if(regex_search(textGoto, m, loopScope))
				{
					beginLoop = stoi(m[1]);
					endLoop = stoi(m[2]);
					if(beginLoop < endLoop)
					{
						inLoop = 1;
					}
				}
				else if(regex_search(textGoto, m, printKey))
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
				else if(regex_search(textGoto, m, printSpaceKey))
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
				else if(regex_search(textGoto, m, showStorageKey))
				{
					cout << "Text : " << endl;
					for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
					{
						cout << itr->first << " : " << itr->second << endl;
					}

					cout << endl;
					cout << "Integer : " << endl;
					for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
					{
						cout << itr->first << " : " << itr->second << endl;
					}

					cout << endl;
					cout << "Boolean : " << endl;
					for(auto itr = boolStorage.begin(); itr != boolStorage.end(); ++itr)
					{
						cout << itr->first << " : " << itr->second << endl;
					}
				}
			}
			else if(inLoop == 1)
			{
				insideLoop(beginLoop, endLoop);
			}
}