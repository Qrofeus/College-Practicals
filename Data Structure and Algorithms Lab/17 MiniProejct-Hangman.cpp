/*
ASSIGNMENT 17

NINAD DESHPANDE
Roll No.: 10
SE COMP II
Batch: S1

Mini-Project:
Game Hangman
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

const int MAX_TRIES=5;

int letterFill (char, string, string&);

int main ()
{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"INDIA",
		"PAKISTAN",
		"NEPAL",
		"MALAYSIA",
		"PHILLIPINES",
		"AUSTRALIA",
		"IRAN",
		"ETHIOPIA",
		"OMAN",
		"INDONESIA",
		"YEMEN"
	};
	srand(time(NULL));
	int n=rand()% 11;
	word=words[n]; 	//choose and copy a word from array of words randomly

	string unknown(word.length(),'*'); // Initialize the secret word with the * character.
	cout<<"Guess a country Name";
	cout<<"\nEach letter is represented by a star";
	cout<<"\nAll letter are in CAPITAL";
	cout<<"\nYou can type only one letter per try";
	cout<<"\n\nYou have "<<MAX_TRIES<<" tries to try and guess the word.";
	while (num_of_wrong_guesses < MAX_TRIES) //Loop until tries are available
	{
        cout<<"\n__________________________________________";
		cout<<"\n"<<unknown<<"\nGuess a letter: ";
		cin>>letter;

		if (letterFill(letter, word, unknown)==0)
		{
			cout<<"\nWrong Letter!"<<endl;
			num_of_wrong_guesses++;
			cout<<"You have "<<MAX_TRIES-num_of_wrong_guesses<<" tries left"<<endl; //Number of tries left
		}
		else
			cout<<"\nLetter Found!"<<endl;
		if (word==unknown) //Check if word has been guessed
		{
			cout<<"\n******************************************\nCongratulations!!\nYou Guessed the Word Correctly\n";
            cout<<word<<endl;
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout<<"\nYou've been Hanged."<<endl;
		cout<<"The word was: "<<word<<endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}

/*
Take one character guess and the secret word, and fill in the unfinished guess-word.
Returns number of characters matched.
Also, returns zero if the character is already guessed.
*/

int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		if (guess == guessword[i]) //If Character already matched
			return 0;
		if (guess == secretword[i]) //If Character is a match
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
