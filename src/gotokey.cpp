#include "parse.h"

using namespace std;

void Parse::regularSyntaxGoto(string textGoto) {
	smatch m, value;
	if(inLoop == 0)
			{
				if(regex_search(this->text, m, newKey))
				{
					if(m[1] == "text" && regex_search(this->text, value, textVal))
					{
						stringStorage.insert(pair<string, string>(m[2], value[1]));
					}
					else if(m[1] == "integer" && regex_search(this->text, value, integerVal))
					{
						integerStorage.insert(pair<string, int>(m[2], stoi(value[1])));
					}
					else if(m[1] == "float" && regex_search(this->text, value, floatVal))
					{
						floatStorage.insert(pair<string, float>(m[2], stof(value[1])));
					}
					else if(m[1] == "double" && regex_search(this->text, value, doubleVal))
					{
						doubleStorage.insert(pair<string, double>(m[2], stod(value[1])));
					}
					else if(m[1] == "bool" && regex_search(this->text, value, boolVal))
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
				else if(regex_search(this->text, m, addKey))
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
					else if(m[1] == "float" && regex_search(this->text, value, floatVal))
					{
						for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second += stof(value[1]);
							}
						}
					}
					else if(m[1] == "double" && regex_search(this->text, value, doubleVal))
					{
						for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second += stod(value[1]);
							}
						}
					}
				}
				else if(regex_search(this->text, m, minKey))
				{
					if(m[1] == "integer" && regex_search(this->text, value, integerVal))
					{
						for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second -= stoi(value[1]);
							}
						}
					}
					else if(m[1] == "float" && regex_search(this->text, value, floatVal))
					{
						for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second -= stof(value[1]);
							}
						}
					}
					else if(m[1] == "double" && regex_search(this->text, value, doubleVal))
					{
						for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second -= stod(value[1]);
							}
						}
					}
				}
				else if(regex_search(this->text, m, mulKey))
				{
					if(m[1] == "integer" && regex_search(this->text, value, integerVal))
					{
						for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second *= stoi(value[1]);
							}
						}
					}
					else if(m[1] == "float" && regex_search(this->text, value, floatVal))
					{
						for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second *= stof(value[1]);
							}
						}
					}
					else if(m[1] == "double" && regex_search(this->text, value, doubleVal))
					{
						for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second *= stod(value[1]);
							}
						}
					}
				}
				else if(regex_search(this->text, m, divKey))
				{
					if(m[1] == "integer" && regex_search(this->text, value, integerVal))
					{
						for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second /= stoi(value[1]);
							}
						}
					}
					else if(m[1] == "float" && regex_search(this->text, value, floatVal))
					{
						for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second /= stof(value[1]);
							}
						}
					}
					else if(m[1] == "double" && regex_search(this->text, value, doubleVal))
					{
						for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second /= stod(value[1]);
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
					else if(m[1] == "float" && regex_search(this->text, value, floatVal))
					{
						for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second = stof(value[1]);
							}
						}
					}
					else if(m[1] == "double" && regex_search(this->text, value, doubleVal))
					{
						for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second = stod(value[1]);
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
					else if(m[1] == "float")
					{
						floatStorage.erase(m[2]);
					}
					else if(m[1] == "double")
					{
						doubleStorage.erase(m[2]);
					}
					else if(m[1] == "bool")
					{
						boolStorage.erase(m[2]);
					}
				}
				else if(regex_search(this->text, m, loopKey))
				{
					int n = stoi(m[1]);
					int end = stoi(m[2]);
					if(n < end)
					{
						if(regex_search(this->text, m, outKey))
						{
							nStorage["N"] = n;
							for(; nStorage["N"] <= end; nStorage["N"]++)
							{
								cout << nStorage["N"];
							}
						}
						else if(regex_search(this->text, m, outSpaceKey))
						{
							nStorage["N"] = n;
							for(; nStorage["N"] <= end; nStorage["N"]++)
							{
								cout << nStorage["N"] << " ";
							}
						}
						else if(regex_search(this->text, m, outLineKey))
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
				else if(regex_search(this->text, m, loopScope))
				{
					beginLoop = stoi(m[1]);
					endLoop = stoi(m[2]);
					if(beginLoop < endLoop)
					{
						inLoop = 1;
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
				else if(regex_search(this->text, m, showStorageKey))
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