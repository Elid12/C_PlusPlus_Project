//Hangman//
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime> //enables to use time in game//

using namespace std;
const int ATTEMPTS=8;//player's max tries

//Introduction//
string intro(string answer)
{
	cout<<"Welcome my friend!!!"<<'\n'
	<<"Do you want to play?"<<'\n'
	<<"Press yes or no ---> ";
	return answer;
}

//Checking the answer//
string reply(string answer)	
{
	cout<<"Wrong answer. Please type yes or no: ";
	return answer;
}

//Game Instructions//
void ins()
{
	cout<<"You have to find the hidden word. There are 8 attempts in total."<<'\n'
	<<"If you lose all of them the game is over. To find the word you "<<'\n'
	<<"have to guess a letter each time. If the chosen letter is not "<<'\n'
	<<"in the hidden word you lose one attempt."<<endl<<endl<<endl;
}

int main() {
	//Title//
	cout<<setw(20)<<"*HANGMAN*"<<endl<<endl;
	
	string answer;
	
	//Showing the Introduction//
	cout<<intro(answer);
	getline(cin,answer);//enables entering a whole word//
	
	//Implementing the function that checks the player's answer.//
	while (!(answer =="yes" || answer =="no"))
	{
		answer.clear();/*Erases the content of the answer,becomes a string with 0 characters.
		Without it the previous wrong answer given by the player would be repeated in the next
		iteration.*/
		cout<<reply(answer);
		getline(cin,answer);
	}
	
	//In case,player refuses to play.//
	if(answer == "no")
	{
		system("PAUSE");
		return EXIT_SUCCESS;
	}

	cout<<endl;
	
	//Asking the player for instructions.//
	cout<<"Do you wish to read the game instructions?"<<'\n'
	<<"Press yes or no ---> ";
	getline(cin,answer);
	
	//Checking if the answer is invalid.//
	while (!(answer =="yes" || answer =="no"))
	{
		answer.clear();
		cout<<reply(answer);
		getline(cin,answer);
	}

	cout<<endl;
	
	//Showing game instructions//
	if(answer == "yes")
	{
		ins();
		answer.clear();
	}
	else
	{
		answer.clear();
		cout<<"Ok. Let's start the game!";
	}
		
	cout<<endl;
	
	//An array of the game words//
	string words[26]={"amazing","bold","complex","dynamic","exclaim","failure","generation",
	"hardware","illegal","jeopardize","kingdom","ladder","manufacture","negligent","obtain",
	"parade","quality","rational","satisfaction","talk","ugly","village","wardrobe","xenophobia",
	"yield","zoom"};
	
	//Arrays of hangman images//
	string hangman[10]={ "+--------+",
						 "|",
					  	 "|",
					  	 "|",
					 	 "|",
						 "|",
					     "|",
					  	 "|",
					  	 "|",
					 	"=+="};
					 	   
	string hangman1[10]={ "+--------+",
						  "|        |",
					  	  "|",
					  	  "|",
					 	  "|",
						  "|",
					  	  "|",
					  	  "|",
					  	  "|",
					 	 "=+="};
					 	    
	string hangman2[10]={ "+--------+",
						  "|        |",
					  	  "|        O",
					  	  "|",
					 	  "|",
						  "|",
					  	  "|",
					  	  "|",
					  	  "|",
					 	 "=+="};
					 	    
	string hangman3[10]={ "+--------+",
						  "|        |",
					  	  "|        O",
					  	  "|        |",
					 	  "|",
						  "|",
					  	  "|",
					  	  "|",
					  	  "|",
					 	 "=+="};
					 	 
	string hangman4[10]={ "+--------+",
						  "|        |",
					  	  "|        O",
					  	  "|        |",
					 	  "|        |",
						  "|",
					  	  "|",
					  	  "|",
					  	  "|",
					 	 "=+="};
					 	 
	string hangman5[10]={ "+--------+",
						  "|        |",
					  	  "|        O",
					  	  "|       /|",
					 	  "|        |",
						  "|",
					  	  "|",
					  	  "|",
					  	  "|",
					 	 "=+="};
					 	 
	string hangman6[10]={ "+--------+",
						  "|        |",
					  	  "|        O",
					  	  "|       /|\\",
					 	  "|        |",
						  "|",
					  	  "|",
					  	  "|",
					  	  "|",
					 	 "=+="};
					 	 
	string hangman7[10]={ "+--------+",
						  "|        |",
					  	  "|        O",
					  	  "|       /|\\",
					 	  "|        |",
						  "|       /",
					  	  "|",
					  	  "|",
					  	  "|",
					 	 "=+="};
					 	 
	string hangman8[10]={ "+--------+",
						  "|        |",
					  	  "|        O",
					  	  "|       /|\\",
					 	  "|        |",
						  "|       / \\",
					  	  "|",
					  	  "|",
					  	  "|",
					 	 "=+="};
					 
	//Picking and copying a random word from the words array//
	
	//srand is a void function that initializes random number generator
	srand(time(NULL));/*time(NULL) returns the value of the current time but doesn't store it
	anywhere. It's used by the random number generator.*/
	
	int randNum = rand()%26;/*rand generates random numbers in range 0 to 25(the length of the
	array words)*/
	string w=words[randNum];//storing the chosen word to a variable
	
	//initializing the hidden word with -
	string hiddenWord(w.length(),'-');/*the length function returns the length of the string in
	terms of bytes.*/
	
	int wrong_guess=0;
	char guess;
	
    //Telling the player to guess
	while(wrong_guess < ATTEMPTS)
	{
		if(wrong_guess==0)
		{
			for(int i=0;i<10;i++)
				cout<<hangman[i]<<endl;
			cout<<setw(20)<<hiddenWord<<endl;
		}

		cout<<"Guess a letter: ";
    	cin>>guess;
	
    	size_t find=w.find(guess);//checks if player's guess is in the word
    	if(find == string::npos)//if guess is not in the word
    	{
    		wrong_guess+=1;
    		cout<<"Wrong! "<<endl;
    		
    		//showing the hangman image depending the number of wrong guesses
    		if(wrong_guess==1)
			{
				for(int i=0;i<10;i++)
					cout<<hangman1[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==2)
			{
				for(int i=0;i<10;i++)
					cout<<hangman2[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==3)
			{
				for(int i=0;i<10;i++)
					cout<<hangman3[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==4)
			{
				for(int i=0;i<10;i++)
					cout<<hangman4[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==5)
			{
				for(int i=0;i<10;i++)
					cout<<hangman5[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==6)
			{
				for(int i=0;i<10;i++)
					cout<<hangman6[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			if(wrong_guess==7)
			{
				for(int i=0;i<10;i++)
					cout<<hangman7[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
		}
		else
		{
			cout<<"Correct! "<<endl;
			
			//replace guess in the right position of the hidden word
			for(int i=0;i<w.length();i++)
			{
				if(guess == w[i])
					hiddenWord[i] = guess;	
			}
			
			//showing the hangman image depending on wrong guess
			if(wrong_guess==1)
			{
				for(int i=0;i<10;i++)
					cout<<hangman1[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==2)
			{
				for(int i=0;i<10;i++)
					cout<<hangman2[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==3)
			{
				for(int i=0;i<10;i++)
					cout<<hangman3[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==4)
			{
				for(int i=0;i<10;i++)
					cout<<hangman4[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==5)
			{
				for(int i=0;i<10;i++)
					cout<<hangman5[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			
			if(wrong_guess==6)
			{
				for(int i=0;i<10;i++)
					cout<<hangman6[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}
			if(wrong_guess==7)
			{
				for(int i=0;i<10;i++)
					cout<<hangman7[i]<<endl;
				cout<<setw(20)<<hiddenWord<<endl;
			}			
		}
		
		//in case player finds the hidden word without loosing all the attempts
		if(w==hiddenWord)
		{
			cout<<"YOU WIN!"<<endl;
			break;
		}
	}
	
	//In case that player looses all his attempts
	if(wrong_guess == ATTEMPTS)
	{
		for(int i=0;i<10;i++)
			cout<<hangman8[i]<<endl;
		cout<<"GAME OVER!"<<endl;
		cout<<"The hidden word was: "<<w<<endl;
	}
	
	return 0;	
}	

