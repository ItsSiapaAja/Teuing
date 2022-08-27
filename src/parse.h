#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <map>

using namespace std;

class Parse
{
	private:
		string text;

		regex newKey{"^new\\s(text|integer)\\s([a-z]{3})\\s"};
		regex textVal{"\"(.*?)\";$"};
		regex integerVal{"([-]?[0-9]+);$"};
		regex boolVal{"(1|0);$"};
		regex floatVal{"([+|-]?[0-9]+\\.[0-9]?);$"};
		map<string, string> stringStorage;
		map<string, int> integerStorage;

		regex printKey{"^print\\s(text|integer)\\s([a-z]{3});$"};

		regex addKey{"^add\\s(text|integer)\\s([a-z]{3})\\s"};
		regex minKey{"^min\\s([a-z]{3})\\s"};
		regex mulKey{"^mul\\s([a-z]{3})\\s"};
		regex divKey{"^div\\s([a-z]{3})\\s"};
		regex changeKey{"^change\\s(text|integer)\\s([a-z]{3})\\s"};

		regex loopKey{"^loop\\srange\\(([0-9]+)\\suntil\\s([0-9]+)\\)\\sin\\sN\\s"};
		regex outLineKey{"outLine;$"};
		regex outSpaceKey{"outSpace;$"};
		regex outKey{"out;$"};
		map<string, int> nStorage;

		regex showStorageKey{"^show;$"};

	public:
		Parse(string text = "") {
			this->text = text;
		}

		~Parse() {
			stringStorage.clear();
			integerStorage.clear();
			nStorage.clear();
		}

		void setText(string text) {
			this->text = text;
		}

		void start() {
			smatch m, value;
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
			}
			else if(regex_search(this->text, m, showStorageKey))
			{
				cout << "Text : " << endl;
				for(auto itr = stringStorage.begin(); itr != stringStorage.end(); ++itr)
				{
					cout << itr->first << " : " << itr->second << endl;
				}

				cout << "Integer : " << endl;
				for(auto itr = integerStorage.begin(); itr != integerStorage.end(); ++itr)
				{
					cout << itr->first << " : " << itr->second << endl;
				}
			}
		}
};
