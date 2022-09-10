#include "parse.h"

void Parse::sectionRead(string textSection) {
			smatch m, value;

			if(!regex_search(textSection, m, gotoKey) && label == 1)
			{
				labelStorage[labelName] += textSection + '\n';
			}
			else if(regex_search(textSection, m, gotoKey))
			{
				stringstream strstream(labelStorage[m[1]]);
				string textBuffer;
				while(getline(strstream, textBuffer))
				{
					regularSyntaxGoto(textBuffer);
				}

				label = 0;
			}

			if(inLoop == 0)
			{
				if(regex_search(textSection, m, newKey))
				{
					newKeyword(textSection, m[1], m[2], value);
				}
				else if(regex_search(textSection, m, addKey))
				{
					addKeyword(textSection, m[1], m[2], value);
				}
				else if(regex_search(textSection, m, minKey))
				{
					minKeyword(textSection, m[1], m[2], value);
				}
				else if(regex_search(textSection, m, mulKey))
				{
					mulKeyword(textSection, m[1], m[2], value);
				}
				else if(regex_search(textSection, m, divKey))
				{
					divKeyword(textSection, m[1], m[2], value);
				}
				else if(regex_search(textSection, m, changeKey))
				{
					if(m[1] == "text" && regex_search(textSection, value, textVal))
					{
						for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second = value[1];
							}
						}
					}
					else if(m[1] == "integer" && regex_search(textSection, value, integerVal))
					{
						for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second = stoi(value[1]);
							}
						}
					}
					else if(m[1] == "float" && regex_search(textSection, value, floatVal))
					{
						for(auto itr = floatStorage.begin(); itr != floatStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second = stof(value[1]);
							}
						}
					}
					else if(m[1] == "double" && regex_search(textSection, value, doubleVal))
					{
						for(auto itr = doubleStorage.begin(); itr != doubleStorage.end(); ++itr)
						{
							if(m[2] == itr->first)
							{
								itr->second = stod(value[1]);
							}
						}
					}
					else if(m[1] == "bool" && regex_search(textSection, value, boolVal))
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
				else if(regex_search(textSection, m, eraseKey))
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
				else if(regex_search(textSection, m, loopKey))
				{
					int n = stoi(m[1]);
					int end = stoi(m[2]);
					if(n < end)
					{
						if(regex_search(textSection, m, outKey))
						{
							nStorage["N"] = n;
							for(; nStorage["N"] <= end; nStorage["N"]++)
							{
								cout << nStorage["N"];
							}
						}
						else if(regex_search(textSection, m, outSpaceKey))
						{
							nStorage["N"] = n;
							for(; nStorage["N"] <= end; nStorage["N"]++)
							{
								cout << nStorage["N"] << " ";
							}
						}
						else if(regex_search(textSection, m, outLineKey))
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
				else if(regex_search(textSection, m, loopScope))
				{
					beginLoop = stoi(m[1]);
					endLoop = stoi(m[2]);
					if(beginLoop < endLoop)
					{
						inLoop = 1;
					}
				}
				else if(regex_search(textSection, m, printKey))
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
				else if(regex_search(textSection, m, printSpaceKey))
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
				else if(regex_search(textSection, m, showStorageKey))
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
				else if(regex_search(textSection, m, labelKey) && label == 0)
				{
					label = 1;
					labelName = m[1];
				}
				else if(regex_search(textSection, m, useSectionKey))
				{
					sectionRead(sectionStorage[m[1]]);
				}
			}
			else if(inLoop == 1)
			{
				insideLoop(beginLoop, endLoop);
			}
}