/*            
			 GROUP 06
		PROJECT HANGMAN GAME
		BY	SHEROZ AHMED
			SAAD SHAKEEL
			WALEED UR REHMAN (LEADER)
			SAIFULLAH SAQID KHAN
			RAJA ABBAS AFFANDI
*/			
#include <iostream>
#include <conio.h> 
#include <string> 
#include <stdlib.h> 
#include <ctime>

#define WRONGTRIES 3

using namespace std;

void DrawMan(int tries)
{
	cout<<endl<<endl;
		cout<<"       		  ||===="<<endl;
		cout<<"         	  ||    |"<<endl;
		cout<<"      		  ||    |"<<endl; 
		cout<<"                  ||";if(3>=tries) cout<<"    O  "; cout<<endl; 
		cout<<"                  ||";if(2>=tries) cout<<"   /|\\   "; cout<<endl;
		cout<<"                  ||";if(1>=tries) cout<<"   / \\    "; cout<<endl;
		cout<<"                 _||_";if(0>=tries) cout<<" HANGED"; cout<<endl;
		cout<<"                |____|"<<endl;  
		cout<<"\n\n\n";
}

int main()
{
	char ch;
	while(true)
	{

	
	string wordList[] =
{
		"january",
		"february",
		"march",
		"april",
		"may",
		"june",
		"july",
		"august",
		"september",
		"october",
		"november",
		"december"
	};
	string word;
	srand (time(NULL));
	word = wordList[rand()%12];
 	string guessed;

	int wordLength = word.length();
	string dispWord (wordLength, '_');
	
	int found = 0;
	char guess = ' ';
	int tries = 3; //No of wrong tries
	int flagFound = 0; 

	while(tries>=0)
	{
		system("cls"); 
		cout<<"Guess Month Name: "<<endl<<endl;
		 
		for(int i=0; i<wordLength; i++)
			cout<<" "<<dispWord[i]<<" "; 
		cout<<endl<<endl<<endl;
		 		
		cout<<"Wrong Attempts: "<<tries<<" / "<<WRONGTRIES<<endl;
		cout<<"Guessed Letters: "<<guessed<<endl; 
		
		DrawMan(tries);
		
		if( found == wordLength )
		{
			cout<<endl;
			cout<<"*****************"<<endl;
			cout<<"*    You Win    *"<<endl;
			cout<<"*****************"<<endl;
   			cout <<"\nThe month is : " << word << endl;
   			char ch;
  		cout<<"\nDo you want to play again y/n"<<endl;
  		cin>>ch;
  		if(ch == 'n' || ch == 'N'){
  			cout<<"\nThanks for Playing Hangman Game :)"<<endl;
  			return 0;
		  }
		  
            break;
		}
		
		if( tries == 0) break; 
		
		cout<<"Pick a Letter:";
		guess = getche();
		
		guessed = guessed + " " + guess;
		
		if( dispWord.find(guess)!=string::npos ) tries++;
		
		flagFound = 0;
		for(int i=0; i<wordLength; i++)
		{
			if( word[i]==guess && dispWord[i]=='_' )
			{
				dispWord[i] = guess;
				found++;
				flagFound = 1; 
			}
		}
		 
		if( !flagFound )
			tries--;
	}
	if( found != wordLength )
	{
		cout<<endl;
		cout<<"******************"<<endl;
		cout<<"*    You Lose    *"<<endl;
		cout<<"******************"<<endl;
  		cout<<"\nThe month is : " << word << endl;
  		char ch;
  		cout<<"\nDo you want to play again y/n"<<endl;
  		cin>>ch;
  		if(ch == 'n' || ch == 'N'){
  			cout<<"\nThanks for Playing Hangman Game :)"<<endl;
  			return 0;
		  }
	}
//	getch();
	cout<<"\n";
	system("PAUSE");
	
}
}
