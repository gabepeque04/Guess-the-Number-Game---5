#include<iostream> //Necessary for input/output.
#include<cstdlib> //Random number generator. For rand() and srand().
#include<ctime> //For time functions. time().

using namespace std; //Allows the use of standard c++ functions without prefixing them with std::

int generateRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min; //0-99 + 1 -> 100. Generates a random number within the specified range.
}

//Class definition for NumberGuesser.
class NumberGuesser {

private:
	int secretNumber; //Stores the secret number to be guessed.

	int previousGuess; //Stores the user's previous guess.

	int attempts; //Stores the number of attempts made by the user.
	
	bool hintsEnabled;  // Added a flag to enable/disable hints.


public:
	NumberGuesser() {
		srand(time(0)); //Seed the random number generator with the current time to produce different random numbers each time the program runs.
		secretNumber = generateRandomNumber(1, 100); //Generate a random number between 1 and 100.

		previousGuess = 0;
		attempts = 0;
		hintsEnabled = true;  // Hints are enabled by default.


		cout << "Welcome to Advanced Number Guesser!" << endl;
		cout << "Try to guess the secret number between 1 and 100." << endl;
		cout << "You can enter '0' to get a hint." << endl;
		cout << "You can also disable hints by entering '-1'." << endl;  // Added instructions for disabling hints.
	}
	//Function to provide hints based on the difference between the guess and the secret number.
	void provideHint() {
		if (!hintsEnabled) {
			cout << "Hints are currently disabled." << endl;
			return;
		}
		int difference = abs(previousGuess - secretNumber); //Absolute difference between the previous guess and secret number is calculated to ensure positive values.
		//If the user's guess is 20 or more away from the secret number, provide a hint.
		if (difference >= 20) {
			cout << "Hint: You are far from the secret number." << endl;
		}
		//If the user's guess is 10 or more away form the secret number, provide a hint.
		else if (difference >= 10) {
			cout << "Hint: You are getting closer to the secret number." << endl;
		}
		else {
			cout << "Hint: You are very close to the secret number." << endl;
		}

	}
	//Fuction to play the number guessing game.
	void playGame() {
		do {
			cout << "Enter your guess: ";
			int guess;
			cin >> guess; // Read the user's input and assign it to the variable guess.
			attempts++; //Increment the attempts counter for each guess.
			//Check if the user's guess is equal to the secret number. Output Congratulations and how many attempts it took.
			if (guess == secretNumber) {
				cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
			}
			//If the user enters 0, provide a hint.
			else if (guess == 0) {
				provideHint();
			}
			else if (guess == -1) {  // Added the ability to disable hints.
				hintsEnabled = false;
				cout << "Hints are now disabled. Continue guessing." << endl;
			}
			//Check if the guess is out of the limit.
			else if (guess < 1 || guess > 100) {
				cout << "Invalid guess. Please enter a number between 1 and 100." << endl;
			}
			//Check if the guess is lower than the secret number.
			else if (guess < secretNumber) {
				cout << "Too low. Try again!" << endl;
			}
			//Catch if the guess is higher than the secret number.
			else {
				cout << "Too high. Try again!" << endl;
			}
			previousGuess = guess; //Update previousGuess for the next iteration.

		} while (previousGuess != secretNumber); //Continue the loop until the user guesses the correct number.
	}
};

int main() {
	NumberGuesser game; // Create an object (game) of the NumberGuesser class.

	game.playGame(); //Call the playGame function to start the game.

	return 0; //Indicates succesful program execution.

}