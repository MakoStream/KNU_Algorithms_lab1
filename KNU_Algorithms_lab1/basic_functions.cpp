#include "basic_functions.h"

vector<string> split(const string& input) {
	vector<string> tokens;
	istringstream iss(input);
	string word;
	while (iss >> word) {
		tokens.push_back(word);
	};
	return tokens;
};


vector<double> split_d(const string& input) {
	vector<double> tokens;
	istringstream iss(input);
	string word;
	while (iss >> word) {
		tokens.push_back(stod(word));
	};
	return tokens;
};