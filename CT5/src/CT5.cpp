//============================================================================
// Name        : CT5.cpp
// Author      : Nolan Hill
// Version     :
// Copyright   : Your copyright notice
// Description : User Input Program in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
 * Method to create new file that has all characters reversed from the input file
 */
int reverseFile(string originalFile, string reverseFile) {
	// Create input and output streams for file to read and file to write to
	ifstream fileToReverse(originalFile);
	ofstream reversedFile(reverseFile);

	// Ensure original file opened correctly
	if (!fileToReverse.is_open()) {
		cout << "Unable to open original file.";
		return 1;
	}

	// Ensure new reverse file opened correctly
	if (!reversedFile.is_open()) {
			cout << "Unable to open new file.";
			return 2;
	}

	// Declare temporary variable to hold each line of original file
	string line;

	// Copy each line from file and write it in reverse to new file
	while (getline(fileToReverse, line)) {
		// Check if line is blank and start newline
		if (line.empty()) {
		    reversedFile << '\n';
		    continue;
		}

		// Iterate through each line, starting at the end and writing to new file
		for (int i = (int)line.size() - 1; i >= 0; i--) {
			reversedFile << line[i];
		}

		// End each line with newline
		reversedFile << '\n';
	}

	// Close both file streams
	fileToReverse.close();
	reversedFile.close();

	return 0;
}

/*
 * Demonstrates appending user input to end of a file and
 * calls on reverseFile method to create new file with reversed
 * characters.
 */
int main() {
	string userInput;

    // Create output file stream
	ofstream fileToUpdate("CSC450_CT5_mod5.txt", ios::app);

	// Check if file opened correctly
	if (!fileToUpdate.is_open()) {
		cout << "Unable to open file for appending.";
		return 1;
	}

	// Prompt user for input and store to variable
	cout << "Enter text to add to file: ";
	getline(cin, userInput);

	// Append user input to end of file
	fileToUpdate << userInput << endl;

	// Close file stream
	fileToUpdate.close();

	// Call on method to create a copy of a file with reversed text
	reverseFile("CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");

	return 0;
}
