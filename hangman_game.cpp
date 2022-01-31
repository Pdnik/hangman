#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
#include<cctype>
#include<bits/stdc++.h>
using namespace std;

const int max_TRIES=5;
int Fill_letter (char, string, string&);

int main ()
{
 string name;
 char letter,Letter;
 int num_of_wrong_guesses=0;
 string word;
 string words[] =
 {
 "india",
 "pakistan",
 "nepal",
 "malaysia",
 "philippines",
 "australia",
 "iran",
 "ethiopia",
 "oman",
 "indonesia",
 "slovakia",
 "kyrgyzstan",
 "kiribati",
 "morocco",
 "venezuela"
 };

 //choose and copy a word from array of words randomly
 srand(time(NULL));
 int n=rand()% 10;
 word=words[n];

 // Initialize the secret word with the * character.
 string unknown(word.length(),'*');

 // welcome..... the user
 cout << "\n\nWelcome to hangman...Guess a Country Name";
 cout << "\n\nEach letter is represented by a star.";

 

 cout << "\n\n type only one letter in one try";

 

 cout << "\n\nYou have " << max_TRIES << " tries to try and guess the word.";
 cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

 // Loop until the guesses are used up
 while (num_of_wrong_guesses < max_TRIES)
 {
 cout << "\n\n" << unknown;
 cout << "\n\nGuess a letter: ";
 cin >> letter;
 Letter=(char)tolower(letter);
 // Fill secret word with letter if the guess is correct,
 // otherwise increment the number of wrong guesses.
 if (Fill_letter(Letter, word, unknown)==0)
 {
 cout << endl << "Whoops! That letter isn't in there!" << endl;
 num_of_wrong_guesses++;
 }
 else
 {
 cout << endl << "You found a letter!  that's exciting!" << endl;
 }
 // Tell user how many guesses has left.
 cout << "You have " << max_TRIES - num_of_wrong_guesses;
 cout << " guesses left." << endl;
 // Check if user guessed the word.
 if (word==unknown)
 {
 cout << word << endl;
 cout << "Yeah! You got it!";
 break;
 }
 }
 if(num_of_wrong_guesses == max_TRIES)
 {
 cout << "\nSorry, you lose...you've been hanged." << endl;
 cout << "The word was : " << word << endl;
 }
 cin.ignore();
 cin.get();
 return 0;
}

/*  guesses a character and ultimately the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.

 

 Also, returns zero if the character is already guessed. */

int Fill_letter (char guess, string secretword, string &guessword)
{
 int k;
 int match=0;
 int len=secretword.length();
 for (k = 0; k< len; k++)
 {
 // Did we already match this letter in a previous guess?
 if (guess == guessword[k])
 return 0;
 // Is the guess in the secret word?
 if (guess == secretword[k])
 {
 guessword[k] = guess;
 match++;
 }
 }
 return match;
}
