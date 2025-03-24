#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int countLines(const string& filename) {
	ifstream file(filename);
	int lineCount = 0;
	string line;
	while (getline(file, line)) {
		lineCount++;
	}
	file.close();
	return lineCount;
}

int countVowels(const string& line) {
	int vowelCount = 0;
	string vowels = "aeiouAEIOUàå¸èîóûýþÿ";
	for (char c : line) {
		if (vowels.find(c) != string::npos) {
			vowelCount++;
		}
	}
	return vowelCount;
}

int main() {
	dynArr da;
	sort srt;

	string filename;
	print << "filename: ";
	scan >> filename;

	int lineCount = countLines(filename);
	print << "fileLines: " << lineCount << e;

	ifstream file(filename);
	string line;
	int lineNumber = 1;
	while (getline(file, line)) {
		int vowelCount = countVowels(line);
		print << "Line " << lineNumber << ": " << vowelCount << " glasnyh" << e;
		lineNumber++;
	}
	file.close();

	string file1Name, file2Name;
	print << "first file to random fill: ";
	scan >> file1Name;
	print << "second file to random fill: ";
	scan >> file2Name;

	ofstream file1(file1Name);
	int randomNumbers[10];
	for (int i = 0; i < 10; ++i) {
		file1 << randomNumbers[i] << " ";
	}
	file1.close();

	ifstream sourceFile(file1Name);
	ofstream destFile(file2Name);
	string content;

	while (getline(sourceFile, content)) {
		destFile << content << e;
	}

	sourceFile.close();
	destFile.close();

	print << "file1 " << file1Name << " was copyed to file2 " << file2Name << "." << e;
}