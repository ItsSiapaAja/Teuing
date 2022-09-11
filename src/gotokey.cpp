#include "parse.h"

using namespace std;

void Parse::regularSyntaxGoto(string textGoto) {
	smatch m, value;
	if(inLoop == 0)
			{
				if(regex_search(textGoto, m, newKey))
				{
					newKeyword(textGoto, m[1], m[2], value);
				}
				else if(regex_search(textGoto, m, addKey))
				{
					addKeyword(textGoto, m[1], m[2], value);
				}
				else if(regex_search(textGoto, m, minKey))
				{
					minKeyword(textGoto, m[1], m[2], value);
				}
				else if(regex_search(textGoto, m, mulKey))
				{
					mulKeyword(textGoto, m[1], m[2], value);
				}
				else if(regex_search(textGoto, m, divKey))
				{
					divKeyword(textGoto, m[1], m[2], value);
				}
				else if(regex_search(textGoto, m, changeKey))
				{
					changeKeyword(textGoto, m[1], m[2], value);
				}
				else if(regex_search(textGoto, m, eraseKey))
				{
					eraseKeyword(textGoto, m[1], m[2]);
				}
				else if(regex_search(textGoto, m, deleteKey))
				{
					deleteKeyword(textGoto, m[1]);
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
					cout << "Float : " << endl;
					for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
					{
						cout << itr->first << " : " << itr->second << endl;
					}

					cout << endl;
					cout << "Double : " << endl;
					for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
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