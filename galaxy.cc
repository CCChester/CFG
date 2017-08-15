#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <deque>
using std::stack;
using std::string;
using std::istream;
using std::ostream;

void skipLine(istream &in) {
  string s;
  getline(in, s);
}
 
void skipGrammar(istream &in) {
  int i, numTerm, numNonTerm, numRules;
  in >> numTerm;
  skipLine(in);
  for (i = 0; i < numTerm; i++) {
    skipLine(in);
  }
  in >> numNonTerm;
  skipLine(in);
  for (i = 0; i < numNonTerm; i++) {
    skipLine(in);
  }
  skipLine(in);
  in >> numRules;
  skipLine(in);
  for (i = 0; i < numRules; i++) {
    skipLine(in);
  }
}

string trim(const string &str) {
  size_t begin = str.find_first_not_of(" \t\n");
  if (begin == string::npos) return "";

  size_t end = str.find_last_not_of(" \t\n");

  return str.substr(begin, end - begin + 1);
}


int getRule(istream &in) {
	string line;
	while(getline(in, line)){
		if(trim(line).compare("term id") == 0){
			return 42;
		}
		if(trim(line).compare("S BOF expr EOF") == 0) {
			continue;
		}
		if(trim(line).compare("expr term") == 0){
			continue;
		}
		if(trim(line).compare("expr expr - term") == 0){
			return getRule(in) - getRule(in);
		}
		if(trim(line).compare("term ( expr )") == 0) {
			continue;
		}
	}
}

void printDerivation(istream &in, ostream &out) {
  string line; 
  int num = 0;
  int result = getRule(in);
  out << result << '\n';
}

int main() {
    skipGrammar(std::cin);
    printDerivation(std::cin, std::cout);
}
