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
const string version = "Teuing Version 0.0.6-a";
#endif

class Parse
{
	private:
		string text;

		regex newKey{"^new\\s(text|integer|bool|double|float)\\s([a-z]{3})\\s"};
		regex textVal{"\"(.*?)\";$"};
		regex integerVal{"([-]?[0-9]+);$"};
		regex floatVal{"([-]?[0-9]+[\\.][0-9]*);$"};
		regex doubleVal{"([-]?[0-9]+[\\.]?[0-9]*);$"};
		regex boolVal{"(true|false);$"};
		map<string, string> stringStorage;
		map<string, int> integerStorage;
		map<string, float> floatStorage;
		map<string, double> doubleStorage;
		map<string, bool> boolStorage;

		regex printKey{"^print\\s(text|integer|bool|double|float)\\s([a-z]{3});$"};
		regex printSpaceKey{"^printspace\\s(text|integer|bool|double|float)\\s([a-z]{3});$"};

		regex addKey{"^\\+\\s(text|integer|double|float)\\s([a-z]{3})\\s"};
		regex minKey{"^\\-\\s(integer|double|float)\\s([a-z]{3})\\s"};
		regex mulKey{"^\\*\\s(integer|double|float)\\s([a-z]{3})\\s"};
		regex divKey{"^/\\s(integer|double|float)\\s([a-z]{3})\\s"};
		regex changeKey{"^change\\s(text|integer|bool|double|float)\\s([a-z]{3})\\s"};
		regex eraseKey{"^erase\\s(text|integer|bool|double|float)\\s([a-z]{3});$"};

		regex pointerKey{"^\\point\\s(text|integer|bool|double|float)\\s([a-z]{3})\\s([a-z]{3});$"};

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

		void newKeyword(string type, string id, smatch val);
		void addKeyword(string type, string id, smatch val);
		void minKeyword(string type, string id, smatch val);
		void mulKeyword(string type, string id, smatch val);
		void divKeyword(string type, string id, smatch val);
		void chnageKeyword(string type, string id, smatch val);
		void eraseKeyword(string type, string id);

		void regularSyntaxInBlock(int beginNum);
		void regularSyntaxGoto(string textGoto);

		void insideLoop(int begin, int end) {
			for(; begin <= end; begin++)
			{
				regularSyntaxInBlock(begin);
			}
			inLoop = 0;
		}

		void start();
};
