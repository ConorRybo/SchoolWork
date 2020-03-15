/*
Conor Rybacki
2/9/2018
csc1720-01
Chapter 9; Exercise 7; Page 650
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
//setting up my struct
struct footballData{
  char name[30];
  string position;
  int touchdowns, catches, passing, recieving, rushing;
};
//function prototyes
void menu(footballData*);
void inputData(footballData*);
void outputData(footballData*);
void dataSort(footballData*);
void playerSearch(footballData*);
void dataEdit(footballData*, int);
void lastCall(footballData*);
void newFile(footballData*);
//our main program
int main(){
  cout << "-----FOOTBALL DATA LOG-----" << endl << endl;
  int a;
  footballData players[10];
  inputData(players);
  menu(players);
  lastCall(players);
	
  return 0;
}
//function that will read in the input data
void inputData(footballData person[]){
  ifstream infile;
  char discard;
  infile.open("inputfile.txt");
  for(int i=0; i < 10; i++){
    infile >> person[i].name;
    infile >> person[i].position >> person[i].touchdowns >> person[i].catches
    >> person[i].passing >> person[i].recieving >> person[i].rushing;
  }
  infile.close();
}
//function for the menu, the menu is a crucial part of the program
void menu(footballData person[]){
  int i;
  bool exit = 0;
  while(!exit){
	cout << "Please make a selection by entering the corresponding number and pressing enter: " << endl;
	cout << "1) View All Player Data" << endl;
	cout << "2) Search Player" << endl;
	cout << "3) Exit" << endl;
	cin >> i;
	cout << endl << endl;
	switch(i){
	    case 1:
	      outputData(person);
	      break;
	    case 2:
	      playerSearch(person);
	      break;
	    case 3:
	      exit = true;
	      return;
	    default :
	      cout << "Invalid Entry" << endl;
	}	
  }
}
//function that will output sorted data

void outputData(footballData person[]){
    int x;
    dataSort(person);

    cout << left << setw(11) << "Name ";
	cout << left << setw(13) << "Position ";
	cout << left << setw(12) << "Touchdowns ";
	cout << left << setw(11) << "Catches ";
	cout << left << setw(12) << "Pass Yards ";
	cout << left << setw(10) << "Rec Yards ";
	cout << left << setw(10) << "Rush Yards " << endl;	
      for(int i=0; i < 10; i++){
        cout << left << setw(10) << person[i].name << " ";
        cout << left << setw(15) << person[i].position << " ";
        cout << right << setw(3) << person[i].touchdowns << " ";
        cout << right << setw(9) << person[i].catches << " ";
        cout << right << setw(12) << person[i].passing << " ";
        cout << right << setw(10) << person[i].recieving << " ";
        cout << right << setw(10) << person[i].rushing << endl;
      }
	cout << endl;
    
}
//function that will sort the data base on touchdowns
void dataSort(footballData person[]){
	footballData temp;
	int i, j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 10 - i - 1; j++){
			if(person[j].touchdowns < person[j+1].touchdowns){
				temp = person[j];
				person[j] = person[j+1];
				person[j+1] = temp;
			}
		}
	}		
	
}
//function that will search and display the information of a specific player
void playerSearch(footballData person[]){
	int i,x;
	cout << "ALL PLAYERS" << endl;
	for(int i=0; i < 10; i++){
		cout << i << ") ";
    		cout << person[i].name << endl;	
	}

	cout << endl << "Please input a number that corresponds with the player that youd like to view: ";
	cin >> i;
	cout << endl;

    cout << left << setw(11) << "Name ";
	cout << left << setw(13) << "Position ";
	cout << left << setw(12) << "Touchdowns ";
	cout << left << setw(11) << "Catches ";
	cout << left << setw(12) << "Pass Yards ";
	cout << left << setw(10) << "Rec Yards ";
	cout << left << setw(10) << "Rush Yards " << endl;

    cout << left << setw(10) << person[i].name << " ";
    cout << left << setw(15) << person[i].position << " ";
    cout << right << setw(3) << person[i].touchdowns << " ";
    cout << right << setw(9) << person[i].catches << " ";
    cout << right << setw(12) << person[i].passing << " ";
    cout << right << setw(10) << person[i].recieving << " ";
    cout << right << setw(10) << person[i].rushing << endl << endl;

	cout << "Would you like to edit this data?" << endl << "1) Yes" << endl << "2) No" << endl;
	cin >> x;
	
	if(x != 1)
		return; 
	else
		dataEdit(person, i);
	

}
//function that allows us to edit the data of a player 
void dataEdit(footballData person[], int a){
	bool exit = 0;
	int x, p;
	while(!exit){
		cout << "What data would you like to edit: " << endl;
		cout << "1) Touchdowns" << endl << "2) Catches" << endl 
		<< "3) Passing Yards" << endl << "4) Receiving Yards" 
		<< endl << "5) Rushing Yards" << endl << "6) Exit to menu" <<  endl; 
		cin >> x;
	
		switch(x){
			case 1:{
				cout << "Please enter a new value: ";
				cin >> p;
				person[a].touchdowns = p;
				cout << "...Saved..." << endl;
				break;
			}
			case 2:{
				cout << "Please enter a new value: ";
				cin >> p;
				person[a].catches = p;
				cout << "...Saved..." << endl;
				break;
			}	
			case 3:{
				cout << "Please enter a new value: ";
				cin >> p;
				person[a].passing = p;
				cout << "...Saved..." << endl;
				break;
			}
			case 4:{
				cout << "Please enter a new value: ";
				cin >> p;
				person[a].recieving = p;
				cout << "...Saved..." << endl;
				break;
			}
			case 5:{
				cout << "Please enter a new value: ";
				cin >> p;
				person[a].rushing = p;
				cout << "...Saved..." << endl;
				break;
			}
			default:
				exit = 1;
				break;
		}
	}	 
	
}
//fucntion that asks the user if they want to save their data to a datafile
void lastCall(footballData person[]){
	int x;
	cout << "Before you exit, would you like to save the data to a new file?" << endl << "1) Yes" << endl << "2) No" << endl;
	cin >> x;

	if(x == 1){
		newFile(person);
	}
	else{
		cout << endl << "...Exiting..." << endl;
		return;
	}
}
//function that 
void newFile(footballData person[]){
	ofstream outfile;
	char filename[25];
	cout << "Please enter desired file name, ending in .txt: ";

	cin >> filename;
	outfile.open(filename);

    dataSort(person);

    outfile << left << setw(11) << "Name ";
	outfile << left << setw(13) << "Position ";
	outfile << left << setw(12) << "Touchdowns ";
	outfile << left << setw(11) << "Catches ";
	outfile << left << setw(12) << "Pass Yards ";
	outfile << left << setw(10) << "Rec Yards ";
	outfile << left << setw(10) << "Rush Yards " << endl;	
      for(int i=0; i < 10; i++){
        outfile << left << setw(10) << person[i].name << " ";
        outfile << left << setw(15) << person[i].position << " ";
        outfile << right << setw(3) << person[i].touchdowns << " ";
        outfile << right << setw(9) << person[i].catches << " ";
        outfile << right << setw(12) << person[i].passing << " ";
        outfile << right << setw(10) << person[i].recieving << " ";
        outfile << right << setw(10) << person[i].rushing << endl;
      }

	outfile.close();
	cout << "...Saved... Exiting..." << endl;
    
}












