/*
 Conor Rybacki
 csc1720-01
 4.29.2019
 Program4: Card guessing game
*/

#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<string> deck;
    bool flag = 0;
    int n;
    string userGuess;
    string Draw;
	//string of the suits used to load the vector 
    string x[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
	//loading a vector with 52 cards 
    for(int i=0;i<4;i++){
        for(int j=1; j< 14; j++){
            if(j == 1)
                deck.push_back("Ace of " + x[i]);
            else if(j == 11)
               deck.push_back("Jack of " + x[i]);
            else if(j == 12)
                deck.push_back("Queen of " + x[i]);
            else if(j == 13)
                deck.push_back("King of " + x[i]);
            else
                deck.push_back(to_string(j) + " of " + x[i]);
        }
    }
 	//user interface 
    cout << "\n---WELCOME TO CONORS CARD GUESSING GAME---\n" << endl;

	//while loop that will run the interface until the user exits 
	while(!flag){
		n = 0;
		srand(time(0));
		//shuffling the deck
	    random_shuffle(deck.begin(), deck.end());
		Draw = deck[rand() % 52];
		//uncomment next line to reveal card and test for correct answers 
		//cout << Draw << endl; 
		cout << "(1) Play Game " << endl;
		cout << "(2) Exit " << endl << endl;
		cout << "Please make a selection by inputing a number: ";
		cin >> n;

		if(n < 1 || n > 2){
			cout << "\nInvalid input; Exiting...\n";
			return 1;
		}
		//necessacary to avoid infinite loop
		cin.ignore();
		cout << endl;
		//switch statement that dictates what is done 
		//based on the user input
		switch(n)
		{
			case 1:
				//asking the user to guess and storing their guess
				cout << "Please guess a card, capitalizing the suit" 
				<< " and face if necessary (ex. 3 of Spades): " << endl;
				getline(cin,userGuess);
				cout << endl;
				//testing to see if the user is correct or not
				if(userGuess == Draw)
					cout << "Congratulations! You win!" << endl << endl;
				else
					cout << "Better luck next time! " << 
					"The card was:\n" << Draw << endl << endl;
				break;
			case 2:
				//case that will exit the program
				cout << "Exiting...\n" << endl;
				//flag flipped so the loop will be exited
				flag = 1;
				break;
		}
		
		
	}

	return 0;

}


