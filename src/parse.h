#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

#ifndef TEUING_STD
#define TEUING_STD
const string version = "Teuing Version 0.0.4";
#endif

class Parse
{
	private:
		string text;

		regex newKey{"^new\\s(text|integer|bool)\\s([a-z]{3})\\s"};
		regex textVal{"\"(.*?)\";$"};
		regex integerVal{"([-]?[0-9]+);$"};
		regex boolVal{"(true|false);$"};
		map<string, string> stringStorage;
		map<string, int> integerStorage;
		map<string, bool> boolStorage;

		regex printKey{"^print\\s(text|integer|bool)\\s([a-z]{3});$"};
		regex printSpaceKey{"^printspace\\s(text|integer|bool)\\s([a-z]{3});$"};

		regex addKey{"^\\+\\s(text|integer)\\s([a-z]{3})\\s"};
		regex minKey{"^\\-\\sinteger\\s([a-z]{3})\\s"};
		regex mulKey{"^\\*\\sinteger\\s([a-z]{3})\\s"};
		regex divKey{"^/\\sinteger\\s([a-z]{3})\\s"};
		regex changeKey{"^change\\s(text|integer|bool)\\s([a-z]{3})\\s"};
		regex eraseKey{"^erase\\s(text|integer|bool)\\s([a-z]{3});$"};

		regex loopKey{"^loop\\srange\\(([0-9]+)\\suntil\\s([0-9]+)\\)\\sin\\sN\\s"};
		regex outLineKey{"outLine;$"};
		regex outSpaceKey{"outSpace;$"};
		regex outKey{"out;$"};
		map<string, int> nStorage;

		regex loopScope{"^loop\\(range\\(([0-9]+)\\suntil\\s([0-9]+)\\)\\)\\sstart;$"};

		regex labelKey{"^label\\s([a-z][0-9]);$"};
		regex gotoKey{"^goto\\s([a-z][0-9]);$"};
		map<string, string> labelStorage;

		regex showStorageKey{"^show;$"};

		int label = 0;
		string labelName;

		int inLoop = 0;
		int beginLoop, endLoop;
	public:
		Parse(string text = "") {
			this->text = text;
			stringStorage["spc"] = " ";
			stringStorage["ver"] = version;
		}

		~Parse() {
			stringStorage.clear();
			integerStorage.clear();
			nStorage.clear();
		}

		void setText(string text) {
			this->text = text;
		}

		void regularSyntaxInBlock(int beginNum);
		void regularSyntaxGoto(string textGoto);

		void insideLoop(int begin, int end) {
			for(; begin <= end; begin++)
			{
				regularSyntaxInBlock(begin);
			}
			inLoop = 0;
		}

		void start() {
			smatch m, value;

			if(!regex_search(this->text, m, gotoKey) && label == 1)
			{
				labelStorage[labelName] += this->text + '\n';
			}
			else if(regex_search(this->text, m, gotoKey))
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
					cout << "Boolean : " << endl;
					for(auto itr = boolStorage.begin(); itr != boolStorage.end(); ++itr)
					{
						cout << itr->first << " : " << itr->second << endl;
					}
				}
				else if(regex_search(this->text, m, labelKey) && label == 0)
				{
					label = 1;
					labelName = m[1];
				}
			}
			else if(inLoop == 1)
			{
				insideLoop(beginLoop, endLoop);
			}
		}
};
