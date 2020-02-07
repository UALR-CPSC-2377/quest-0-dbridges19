/*
        HANGMAN
*/
#include <iostream>
#include <string>
#include <random>
#include <ctype.h>

using namespace std;

void fillLetters (char, string);
int chooseRandomCountry ();
void pauseConsole ();
void printGameBoard (string);
char processUserInput ();
void clearConsole ();
bool isGameDone (string);
void printGameOver (string guess);
bool isGameSuccessful (string currentGuess);
void printNumberOfTries ();

const int numCountries = 30;
int padding = 3; // number of spaces on each side of the word

// These variables are important to keep in mind
const int maxNumberGuesses = 4;
int currentGuessNumber = 0;
string currentGuessString = "";
string correctCountry = "";

string countries [] = {
    "senegal",
    "serbia",
    "seychelles",
    "singapore",
    "slovakia",
    "slovenia",
    "somalia",
    "spain",
    "sudan",
    "suriname",
    "swaziland",
    "sweden",
    "switzerland",
    "syria",
    "taiwan",
    "tajikistan",
    "tanzania",
    "thailand",
    "togo",
    "tonga",
    "tunisia",
    "turkey",
    "turkmenistan",
    "tuvalu",
    "uganda",
    "ukraine",
    "uruguay",
    "uzbekistan",
    "vanuatu",
    "venezuela",
};

int main () {
    clearConsole();

    correctCountry = countries[chooseRandomCountry()];

    // this will initialize the currentGuess String to
    // be the same length as the chosen county but contain only asterisks
	currentGuessString = std::string(correctCountry.length(), '*');

    while (isGameDone(currentGuessString) == false) {
        printGameBoard(currentGuessString);
        printNumberOfTries();
        char userGuess = processUserInput();
        fillLetters(userGuess, correctCountry);

        clearConsole();
    }

    printGameOver(currentGuessString);
}

bool isGameDone (string currentGuess) {

	int asterickCount = currentGuessString.length(); //Number of Astericks 
	for (int i = 0; i < currentGuessString.length(); i++) { //Cycle through string to see if any astericks are left.
		if (currentGuessString[i] != '*') {
			asterickCount -= 1;
		}
	}

	if ((currentGuessNumber == 4) || (asterickCount == 0)) { //If they have 4 guesses, it returns true and prints game over.
		return true;
		isGameSuccessful(currentGuess);
	}
	else {
		return false;
	}

	
	

    /*  This function determines if the game is over */

    return false; // placeholder
}

bool isGameSuccessful (string currentGuess) {
	if (currentGuess == correctCountry) {
		return true;
	}
	if(currentGuessNumber == 4){
		return false;
	}


    /*  This function determines if a player succesfully
        guessed all of the characters
    */

    return false; // placeholder
}

void printGameOver (string currentGuess) {
	printGameBoard(currentGuessString);
	if (isGameSuccessful(currentGuessString) == true) {
		cout << "CONGRATS";
	}
	if (isGameSuccessful(currentGuessString) == false) {
		cout << "YOU FAILED";
	}

	/*
        This function will print out the game board with a message at the bottom
        "CONGRATS" if the the player was successful and "YOU FAILED" if they werent.
    */
}

void printGameBoard (string guess) {

	//Line 1
	cout << "+";
	for (int i = 0; i < correctCountry.size() + ((padding *2)); i++) { //Takes length of the correctCountry, adds padding to it, doubled for both sides.
		cout << "-";
	}
	cout << "+" << endl;

	//Line 2
	cout << "|";
	for (int i = 0; i < padding; i++) {
		cout << " ";
	}
	cout << currentGuessString; //Remember to change this back to currentGuessString
	for (int i = 0; i < padding; i++) {
		cout << " ";
	}
	cout << "|" << endl;

	//Line 3
	cout << "|";
	for (int i = 0; i < padding; i++) {
		cout << " ";
	}
	for (int i = 0; i < correctCountry.size(); i++) {
		cout << "_";
	}
	for (int i = 0; i < padding; i++) {
		cout << " ";
	}
	cout << "|" << endl;

	//Line 4
	cout << "+";
	for (int i = 0; i < correctCountry.size() + ((padding * 2)); i++) { 
		cout << "-";
	}
	cout << "+" << endl;
    /*
        This function will print out a rectangle to contain the
        current guess and the line

        The width of the box is the length of the guess string + 2*padding.
        The padding defines the number of spaces on either side of the underline
    */
}

void printNumberOfTries () {
	cout << "NUMBER OF TRIES: " << currentGuessNumber<< endl;
    /* this function will print out the number of tries that the user has attempted
        as well as a message
    */
}

char processUserInput () { //Asks for userGuess, returns it. 
	cout << "Enter a Guess!: ";
	char userGuess;
	cin >> userGuess;
    /*
        This function will print out a message for the user to enter a character
        The character will then be returned,
    */

    return userGuess; // placeholder
}

void fillLetters (char guessChar, string secretWord) {
	int matches = 0; //To record if the user had a character match.
	for (int i = 0; i < secretWord.length(); i++) {
		if (guessChar == secretWord[i]) {
			currentGuessString[i] = guessChar;
			matches += 1;
		}
	}

	if (matches == 0) { //If the user had no matches after the loop has gone through the entire string, add 1 to currentGuessNumber
		currentGuessNumber += 1;
	}

	

    /*
        This function will modify the global variable currentGuessString.
        If any characters in the secretWord match with the guessChar, those
        characters in currentGuessString need to be changed.
    */
}

void pauseConsole () {
    std::string temp;
    std::cout << "Enter to continue... ";
    std::getline(std::cin, temp);
}

void clearConsole () {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    	system("cls");
    #else
        system("clear");
    #endif
}

int chooseRandomCountry () {
    random_device seed;
    default_random_engine engine(seed());
    uniform_int_distribution<int> dist(0, numCountries-1);

    return dist(engine);
}
