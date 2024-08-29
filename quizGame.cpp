#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <limits>
#include<windows.h>

using namespace std;

void welcome(); 
int displayMenu();
int displaySubjectOptions(); 
int displayRules(); 
void handleMainMenu();  
void handleSubjectMenu(); 
void handleRuleMenu(string subjectName);
int difficultyMenu();
string handleQuizDifficulty();
void quizHeader();
void startQuiz(string quizSubject);
void scoreHeader();
void playerInformationHeader();	
void playerInformation();
int resultMenu();
void resultCardHeader();
void resultCard();
void playerResultFile();  
void highScoreFile();
bool compareScores(const vector<string>& a, const vector<string>& b);  				  
void displayHighScore();
void setColor(int color);                       		  
void clearScreen();
                   
// Global Variables

const int PASSING_MARKS=5;
int currentRollNo;
int totalQuestions;
int correctAnswers;
int incorrectAnswers;
int remainingQuestions;
int currentPlayerScore;
string currentPlayerName;
string currentSubject;
string quizDifficulty;
double percentage;
char grade;

int main()
{
	
	welcome();
	handleMainMenu();
    
	return 0;
    
}


//-------------------------------------------Function for Welcome------------------------------------------------------//
void welcome(){
	
	clearScreen();
	system("COLOR 1F");
	setColor(607);
    cout << "\n\n\n\n\n" << endl;
    cout << "     __          __  _                            _           ____        _        _____                      \n";
    cout << "     \\ \\        / / | |                          | |         / __ \\      (_)      / ____|                     \n";
    cout << "      \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |  | |_   _ _ ____ | |  __  __ _ _ __ ___   ___ \n";
    cout << "       \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | |  | | | | | |_  / | | |_ |/ _` | '_ ` _ \\ / _ \\\n";
    cout << "        \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |__| | |_| | |/ /  | |__| | (_| | | | | | |  __/\n";
    cout << "         \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/   \\___\\_\\\\__,_|_/___|  \\_____|\\__,_|_| |_| |_|\\___|\n";
    cout << "                                                                                                              \n" << endl;
    setColor(287);
	cout << "\n\n\t\t\t\tTest your knowledge and have fun answering the quiz questions\n" << endl;
	cout << "\t\t\t\tLet's get started!\n" << endl;
	cout << "\t\t\t\tPress Enter to go Main Menu..." << endl;
	setColor(607);
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tDeveloped By: Abubakar Saeed" << endl;
	setColor(287);
    cin.get();
    
}
//----------------------------------Function to Display Menu---------------------------------------------//
int displayMenu()
{
	
	system("COLOR 1F");
    int choice;
    
    setColor(607);
    cout << "\t\t\t==========================================================================" << endl;
    cout << "\t\t\t                            Quiz Game Menu                                " << endl;
    cout << "\t\t\t==========================================================================" << endl;
    setColor(287);
	cout << "\n\n\n\n\n\t\t\t\t\t\t1. Start Quiz Game" << endl;
    cout << "\n\t\t\t\t\t\t2. View Hall of Fame" << endl;
    cout << "\n\t\t\t\t\t\t3. Exit\n" << endl;
    setColor(607);
    cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
    
    cin >> choice;
    setColor(287);
    return choice;  //returning choice to handleMenuSelection()
    
}
//----------------------------------Function to Display Subject Options---------------------------------//
int displaySubjectOptions()
{
	
	system("COLOR 1F");
    int subjectOption;
    
    setColor(607);
    cout << "\t\t\t==========================================================================" << endl;
    cout << "\t\t\t                           Select a Quiz Subject                          " << endl;
    cout << "\t\t\t==========================================================================" << endl;
    setColor(15);
    cout << "\n\t\t\t\tPlease choose the subject for the quiz:"<< endl;
    setColor(287);
    cout << "\n\t\t\t\t\t1. English" << endl;
    cout << "\n\t\t\t\t\t2. Digital Logic and Design" << endl;
    cout << "\n\t\t\t\t\t3. Calculus" << endl;
    cout << "\n\t\t\t\t\t4. Discrete Mathematics" << endl;
    cout << "\n\t\t\t\t\t5. Programming Fundamentals" << endl;
    cout << "\n\t\t\t\t\t6. Pak Study" << endl;
    cout << "\n\t\t\t\t\t7. Return to Main Menu\n" << endl;
    setColor(607);
    cout << "\t\t\t\t\tEnter your choice: ";
    
	cin >> subjectOption;
	setColor(287);
    return subjectOption; 					//returning choice to handleSubjectMenu()
    
}
//----------------------------------Function to Display Game Rules------------------------------------//
int displayRules()
{
	clearScreen();
	system("COLOR 1F");
	int choice;
	
	setColor(607);
	cout << "\t\t\t========================================================================== "<< endl;
    cout << "\t\t\t                                Quiz Rules                                 "<< endl;
	cout << "\t\t\t========================================================================== "<< endl;
	setColor(287);
	cout << "\n\t\t\t\ta.There are 10 questions in total." << endl;
	cout << "\n\t\t\t\tb.Every Question have four options Enter the correct one." << endl;
	cout << "\n\t\t\t\tc.Each question carries 1 point." << endl;
	cout << "\n\t\t\t\td.Skip questions consider as wrong answer." << endl;
	cout << "\n\t\t\t\te.Student Who got 50% are considered as PASS otherwise FAIL." << endl;
	cout << "\n\n\t\t\t1. Continue" << endl;
	cout << "\n\t\t\t2. Return to Subject Selection" << endl;
	setColor(607);
	cout << "\n\t\t\tEnter your choice: ";
	
	cin >> choice;
	setColor(287);
    return choice; // returning choice to handleRuleMenu()
    
}
//----------------------------------Function to Display Difficulty Menu------------------------------------//
int difficultyMenu(){
	
	system("COLOR 1F");
	setColor(607);
	cout << "\t\t\t==========================================================================" << endl;
    cout << "\t\t\t                                Quiz Diffculty                            " << endl;
	cout << "\t\t\t==========================================================================" << endl;
	setColor(287);
	int difficulty;
	
	setColor(15);
	cout << "\n\n\n\t\t\t\t\t\tSelect Your Difficulty "<< endl;
	setColor(287);
	cout << "\n\t\t\t\t\t\t\t1.Easy " << endl;
	cout << "\n\t\t\t\t\t\t\t2.Medium " << endl;
	cout << "\n\t\t\t\t\t\t\t3.Hard " << endl;
	cout << "\n\t\t\t\t\t\t\t4.Return to Subject Selection" << endl;
	setColor(607);
	cout << "\n\t\t\t\t\t\tEnter Your Choice: ";
	cin >> difficulty;
	setColor(287);
	
	return difficulty; //returning choice to handleQuizDifficulty()
	
}
//----------------------------------Function to Display Result Menu------------------------------------//
int resultMenu(){
	
	int choice;
	setColor(607);
	cout << "\n\n\t\t\t 1.Retake the quiz" << endl;
	cout << "\t\t\t 2.View Hall of Fame" << endl;
	cout << "\t\t\t 3.Return Main Menu or any other key to Exit" << endl;
	cout << "\n\t\t\tEnter your Choice: ";
	cin >> choice;
	setColor(287);
	return choice; //returning choice to ResultCard()
	
}
//-------------------------------------------Function to Handle Menu Selection--------------------------------------------//
void handleMainMenu()
{
	
    int choice;
    clearScreen();

    do {
    	
            choice = displayMenu();

            if (cin.fail()) {													// will be false if user input other then integer(true)
                
                cin.clear(); 										 			//Clearing  the error of cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 			// Ignore any remaining characters in the input buffer
                clearScreen();
				cerr << "\n\t\t\t\aInvalid choice. Please try again." << endl;  // Display an error message for invalid input
                continue;
           }
		    
            clearScreen();
            
			switch (choice) {
                
				case 1:
					
                    handleSubjectMenu();
                    break;

                case 2:
                	
                    displayHighScore();
                    break;

                case 3:
                	
                    cout << "\nExiting the quiz game. Goodbye!" << endl;
                    cout << "\nThanks for playing our Quiz Game. Good luck have a great day! " << endl;
                    exit(0);
                    break;

                default:
                	
                    cerr << "\n\t\t\t\aInvalid choice. Please try again." << endl;
                    break;
            }
    } while (choice != 3);
}
//----------------------------------Function to Handle Subject Selection--------------------------------------------------//
void handleSubjectMenu()
{
	clearScreen();
    int subjectOption;
    
    do {     
    
            subjectOption = displaySubjectOptions();
            
            if (cin.fail()) {
                
            	cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                clearScreen();
				cerr << "\n\t\t\t\aInvalid choice. Please try again." << endl; 
                continue;
                
            }
            
			clearScreen();
            
			switch (subjectOption) {

			    case 1:
                	
                    handleRuleMenu("English"); // Passing subject 
                    break;

                case 2:
                	
                    handleRuleMenu("DLD");
                    break;

                case 3:
                	
                    handleRuleMenu("Calculus");
                    break;

                case 4:
                	
                    handleRuleMenu("Disecrete Math");
                    break;

                case 5:
                	
                    handleRuleMenu("PF");
                    break;

                case 6:
                	
                    handleRuleMenu("Pak Study");
                    break;

                case 7:
                	
                    handleMainMenu();
                    break;

                default:
                	
                    cerr << "\n\t\t\t\aInvalid choice. Please try again." << endl;
                    break;
            }
    } while (subjectOption!=7);
}
//-------------------------------Function to handle Quiz Difficulty------------------------------------//
string handleQuizDifficulty(){

	int difficultyChoice;
	string fileName;
	
	clearScreen();
	
	do{
		
		difficultyChoice=difficultyMenu();
		
		if (cin.fail()){ 										 	 
                
        	cin.clear(); 										 	 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			clearScreen();	 
			cerr << "\n\t\t\t\aInvalid choice. Please try again." << endl; 
            continue;
            
        }
        
		switch(difficultyChoice){
		
		case 1:
			
			fileName =  "Subjects/Easy/" + currentSubject + ".txt";
			quizDifficulty="Easy";
			break;
			
		case 2:
		
			fileName =  "Subjects/Medium/" + currentSubject + ".txt";
			quizDifficulty="Medium";
			break;
			
		case 3:
		
			fileName =  "Subjects/Hard/" + currentSubject + ".txt";
			quizDifficulty="Hard";
			break;
			
		case 4:
			
			handleSubjectMenu();
			break;
			
		default:
			
			clearScreen();
			cerr << "\n\t\t\t\aInvalid Choice.please try again."  << endl;
			break;
			
	}
}while(difficultyChoice != 4 && difficultyChoice != 3 && difficultyChoice != 2 && difficultyChoice != 1);

	return fileName;
	
}
//----------------------------------Function to handle Rule Menu----------------------------------------------------//
void handleRuleMenu( string subjectName)
{
	int choice;
	currentSubject=subjectName;   // Assigining subject value to globl varaiable 
	
    do {
    	
        choice = displayRules();
           
		if (cin.fail()){ 										 	 		
                
        	cin.clear(); 										 	 		
            cin.ignore(numeric_limits<streamsize>::max(), '\n');	 		
			clearScreen();
			cerr << "\n\t\t\t\aInvalid choice. Please try again." << endl; 
            continue;
            
        }
        
		clearScreen();
		
        switch (choice) {
           
		    case 1:
            	
            	playerInformation();
                startQuiz(currentSubject);				// passing current subject  
                break;

            case 2:
            	
                handleSubjectMenu();
                break;

            default:
            	
                cerr << "\n\t\t\t\aInvalid choice. Please try again." << endl;
                break;
                
        }
    } while (choice!=2);
}
//----------------------------------Function for playerInformation---------------------------------------------//
void playerInformation(){
	
	bool isAlphabetic, isRollInteger=false;
    int rollNumber;
    string playerName;
	
	do{
	
		playerInformationHeader();
		cout << "\n\n\n\n\t\t\t\t\tEnter Name: ";
		setColor(607);
		cin.ignore();
	    getline(cin,playerName);
		setColor(287);
	
	    for (int i = 0; i < playerName.length(); ++i) {
	            
	        if (i==0)
				isAlphabetic = true;

			if(isdigit(playerName[i])||ispunct(playerName[i])){
					
				isAlphabetic = false;
						
			}		
	    }
		
	    if (!isAlphabetic) {
	        
			clearScreen();
			cerr << "\t\t\t\aInvalid input.Name should contain alphabetes only." << endl;
			continue;
		 	
	    }
		    
	playerName = playerName.substr(0, 15);
	       
	    for (int i = 0; i < playerName.length(); ++i) {
	    	
			if (i == 0 || isspace(playerName[i-1])) { // 1st and if there is space before the character then charater will be capitalized //
			 	
				playerName[i] = toupper(playerName[i]);
	        	
	    	}
			 
			else {
	
				playerName[i] = tolower(playerName[i]);
				
	    	}
	    }
	}while(!isAlphabetic);
	
    do {
    	
        cout << "\n\n\t\t\t\t\tEnter Roll number: ";
        setColor(607);
        cin>>rollNumber;
        setColor(287);
           	
        if (cin.fail()) {
		   	
	        clearScreen();
	    	playerInformationHeader();
	        cerr << "\n\t\t\t\aInvalid input. Roll number must be an integers." << endl;
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			isRollInteger=false;
		
		}
        
		else {
        	
        	isRollInteger = true; 
			clearScreen();
			   
        }
       
	} while (!isRollInteger);
	
	currentPlayerName= playerName;		// Assigining playerName value to globl varaiable 
	currentRollNo= rollNumber;			// Assigining rollNumber value to globl varaiable 
}
//----------------------------------Function to Start Quiz---------------------------------------------//
void startQuiz(string quizSubject)
{
	
	string fileName=handleQuizDifficulty();
	
    ifstream quizFile(fileName.c_str());

    if (!quizFile) {
    	
        cerr << "\n\aFailed to open the file." << endl;
        return ;
        
    }

    string line;
    int questionNumber = 0, score = 0, randomIndex,choice;
    vector<string> questions, options;
    vector<char> correctOptions;
    bool validAnswer = false;
    string userOption;
    
	while (getline(quizFile, line)) {
       
	    questions.push_back(line);				//pushing question in to question vector // line 0 txt file

        for (int i = 0; i < 4; i++) { 			// pushing 4 options into the options vector line 1-4 txt file
            
			getline(quizFile, line);
            options.push_back(line);
            
        }

        getline(quizFile, line);
        correctOptions.push_back(line[0]);  	//pushing correct option into the correctOptions vector // line 5 txt file

        questionNumber++;
    }
    
    quizFile.close();
	
	totalQuestions= questionNumber;
	remainingQuestions=totalQuestions;

    vector<int> questionIndices(questionNumber); // for random shuffling vector index will be proportional to questionNumber

    for (int i = 0; i < questionNumber; i++) {
        
		questionIndices[i] = i; 				// giving values to question indices for index 0-9
        
    }

	srand(static_cast<int>(time(NULL)));  		// for randomizing questions every time the quiz starts
    random_shuffle(questionIndices.begin(), questionIndices.end()); // random shuffling
	quizHeader();
	scoreHeader();		
	
    for (int i = 0; i < questionNumber; i++) { // printing questions
    	
		remainingQuestions--;
	    randomIndex = questionIndices[i]; // Assigning question indices vector elements to random index for using in question, option, correctOption index
	    setColor(831);
        cout << "\n\nQuestion #" << (i + 1) << ": " << questions[randomIndex] << "\n" << endl;  // Displaying Question
		setColor(287);
        
		for (int j = 0; j < 4; j++) { 	// printing options
		
			cout << static_cast<char>('A' + j) << ". " << options[randomIndex * 4 + j] << endl; // printing 4 options respective to random index
			
        }
        do {
        
        	setColor(607);
            cout << "\nEnter your answer (A, B, C, D or S to skip and E to End quiz): ";
           
            cin >> userOption;
            setColor(287);
            
            userOption[0]=toupper(userOption[0]); // given index 0 because of we want single character answer
		
            if (userOption.length() == 1 && (userOption[0] == 'A' || userOption[0] == 'B' || userOption[0] == 'C' || userOption[0] == 'D'||userOption[0] == 'E'||userOption[0] == 'S')) {
            	
				currentPlayerScore= score;   // Assigining score value to globl varaiable 
				validAnswer = true;
				
			if (userOption[0]=='S'){ // Question Skipped by user 
				
				incorrectAnswers++;
				clearScreen();
				quizHeader();
				scoreHeader();
				setColor(15);
				cout<<"\nSkipped "<<endl;
				break;
				
			}
			else if (userOption[0] == 'E') { // Quiz End by user 
        		
        		quizHeader();
        		scoreHeader();
    			setColor(287);
        		return resultCard(); 						// After ending the quiz return to resultCard() function to show result 
        		
    		}
            else if (userOption[0] == correctOptions[randomIndex]) { // authentication
                    
                correctAnswers++;
                quizHeader();
				scoreHeader();
                setColor(15);
				cout << "\nCorrect answer\n";
				setColor(287);
                score++; 									 // increment score    
            } else {
                	
                incorrectAnswers++;
                quizHeader();
				scoreHeader();
                setColor(335);
                cout << "\nIncorrect answer";
                setColor(287);
                cout << "\nThe correct answer is " << correctOptions[randomIndex] << endl;
                }

            } else {
            	
                cerr << "\aInvalid input. Please enter a valid character (A, B, C, or D).\n";
                validAnswer=false;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                
            }
        }while(!validAnswer);
    }
    resultCard(); // Showing result Card after end of all questions 
}
//----------------------------------Function to Show Result Card---------------------------------------------//
void resultCard(){
	
	clearScreen();
	resultCardHeader();
    
	if (currentPlayerScore<5){
	
		setColor(111);
		cout << "\n\t\t\tDon't feel bad, you can retake this Quiz." << endl;
		setColor(287);
		
	}
	
	percentage = (static_cast<double>(currentPlayerScore) / totalQuestions) * 100;
	
	if(percentage>=80.0)
		grade='A';					// Assigining grade value to globl varaiable 
	else if (percentage>=70.0)
		grade='B';
	else if (percentage>=60.0)
		grade='C';
	else 
		grade='D';

	cout << setw(22) << left << "\n\n\t\t\t\t\tPlayer Name:" << currentPlayerName << endl;
    cout << setw(21) << left << "\n\t\t\t\t\tRoll Number:" << currentRollNo << endl;
    cout << setw(21) << left << "\n\t\t\t\t\tQuiz Subject:" << currentSubject << endl;
    cout << setw(21) << left << "\n\t\t\t\t\tDifficulty:"<< quizDifficulty << endl;
    cout << setw(21) << left << "\n\t\t\t\t\tQuestions:" << totalQuestions << endl;
    cout << setw(21) << left << "\n\t\t\t\t\tYour Score:" << currentPlayerScore<< endl;
    cout << setw(21) << left << "\n\t\t\t\t\tPercentage:" <<percentage<<" %" << endl;
    cout << setw(21) << left << "\n\t\t\t\t\tGrade:" << grade << endl;
    cout << setw(21) << left << "\n\t\t\t\t\tStatus:" << ((currentPlayerScore >= PASSING_MARKS) ? "PASS" : "FAIL") << endl;
	
	int choice=resultMenu();
	
	switch(choice){
		
		case 1:
			
			startQuiz(currentSubject);
			break;
			
		case 2:
			
			highScoreFile();     // Writing result in three files with different pattern
			playerResultFile();
			displayHighScore();
			break;
			
		case 3:
			
			highScoreFile();
			playerResultFile();
			handleMainMenu();
			break;
			
		default:
			
			clearScreen();
			highScoreFile();
			playerResultFile();
			cout << "\nThanks for playing our Quiz Game. Good luck have a great day! " << endl;
			exit(0);
			break;
			
	}
}
//-------------------------------Function to Write Student Result on File with Student name ------------------------------------//
void playerResultFile(){
	
	string studentResult="Student Results/" + currentPlayerName +".txt";
	
	ofstream resultFile(studentResult.c_str());
	if(!resultFile){
		
		cerr << "\aError Writng on file " << endl;
		return;
	}
	                   
	resultFile << "\t\t\t===============================================================================" << endl;
	resultFile << "\t\t                                        Result Card                                                        " << endl;
	resultFile << "\t\t\t===============================================================================" << endl;
	resultFile << setw(22) << left << "\n\n\t\t\t\t\t\tPlayer Name:" << currentPlayerName << endl;
    resultFile << setw(21) << left << "\n\t\t\t\t\t\tRoll Number:" << currentRollNo << endl;
    resultFile << setw(21) << left << "\n\t\t\t\t\t\tQuiz Subject:" << currentSubject << endl;
    resultFile << setw(21) << left << "\n\t\t\t\t\t\tDifficulty:"<< quizDifficulty << endl;
    resultFile << setw(21) << left << "\n\t\t\t\t\t\tQuestions:" << totalQuestions << endl;
    resultFile << setw(21) << left << "\n\t\t\t\t\t\tYour Score:" << currentPlayerScore << endl;
    resultFile << setw(21) << left << "\n\t\t\t\t\t\tPercentage:" << percentage <<" %" << endl;
	resultFile << setw(21) << left << "\n\t\t\t\t\t\tGrade:" << grade << endl;  
    resultFile << setw(21) << left << "\n\t\t\t\t\t\tStatus:" << ((currentPlayerScore >= PASSING_MARKS) ? "PASS" : "FAIL") << endl;
    resultFile << "\n\n\n\t\t\t\t\t\t\t\t\tErrors and osmissions are excepted " << endl;
    
    resultFile.close();
		
}
//---------------------------------Function to Write high score on File------------------------------------//
void highScoreFile(){
	
	ofstream highScoreFile("High Score/High Score.txt",ios::app);

	if (!highScoreFile){
		
		cerr << "Error writing the file" << endl;
		return;
	}
	
	highScoreFile << currentPlayerName << endl; // writing line by line in file 
    highScoreFile << currentRollNo << endl;
    highScoreFile << quizDifficulty << endl;
    highScoreFile << currentSubject << endl;
    highScoreFile << currentPlayerScore << endl;
    highScoreFile << totalQuestions << endl;
    
    highScoreFile.close();
	
}
//----------------------------------Function to Display High Scores------------------------------------//
void displayHighScore() {
	
	clearScreen();
    ifstream highScoreFile("High Score/High Score.txt");
    
	if (!highScoreFile) {
		
		ofstream highScoreFile("High Score/High Score.txt");
    
	}
    else if (highScoreFile.peek() == ifstream::traits_type::eof()){ // when the file is empty
    	
		cout << "Nothing Here yet Be the first one to add your name in Hall Of Fame" << endl;
	
	}
	
    vector<vector<string> > playerScores;
    vector<string> playerRecord(6);
    string line;
    int choice;
	
    while (getline(highScoreFile, line)) {		  // condition become false when looping through all lines
    	
        playerRecord[0] = line; 				  // Player Name
        getline(highScoreFile, playerRecord[1]);  // Roll Number
        getline(highScoreFile, playerRecord[2]);  // Difficulty
        getline(highScoreFile, playerRecord[3]);  // Subject 
        getline(highScoreFile, playerRecord[4]);  // Score
        getline(highScoreFile, playerRecord[5]);  // Total Questions
        playerScores.push_back(playerRecord);     // Pushing in 2d vector 
        
    }

    highScoreFile.close();

    sort(playerScores.begin(), playerScores.end(), compareScores); // function compare scores act as comparator argument for sorting
	
	setColor(607);
	cout << "===============================================================================================================" << endl;
	cout << "                                                   High Scores                                                 " << endl;
	cout << "===============================================================================================================" << endl;
	setColor(287);
	setColor(15);
	cout << setw(5) << left << "No"                    		// formatting the output
    << setw(20) << left << "Player Name"
    << setw(20) << left << "Roll Number"
    << setw(20) << left << "Difficulty"
    << setw(20) << left << "Subject"
    << setw(11) << left << "Score"
    << setw(15) << left << "Total Questions" << endl;	
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	setColor(287);
	
	for (int i = 0; i < playerScores.size(); ++i) { 		// for displaying high scores // condition depends upon rows // outer loop
        
		if (i>0){											// to display line after the first loop

		cout << "---------------------------------------------------------------------------------------------------------------" << endl;
		
		}
		cout << setw(5) << left << (i + 1); 				// for numbering 

		for (int j = 0; j < playerScores[i].size(); ++j) {  // condition depends upon colum in 2d vector  // inner loop
			
            cout << setw(20) << left << playerScores[i][j]; // To display 2d playerScores vector elements
    
        }

        cout << endl;
    }
    
    setColor(607);
	cout << "\nEnter 1 to Return to Main Menu or any other key to exit: ";
	cin >> choice;
	setColor(287);
	
	switch(choice){
		
		case 1:
			
			handleMainMenu();
			break;
			
		default:
			
			clearScreen();
			cout << "\nThanks for playing our Quiz Game. Good luck have a great day! " << endl;
			exit(0);
			break;
	}
}
//--------------------------------Function to compare scores ------------------------------------------------------------//	
bool compareScores(const vector<string>& a, const vector<string>& b) {
        
	return atoi(a[4].c_str()) > atoi(b[4].c_str());   //   the formula that will compare scores on index 4 of playerScores vector

}
// ------------------------------------Function for coloring-----------------------------------------------------------//
void setColor(int color) {
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the handle to the console window
   
	WORD colorAttribute = color;
	
    // Set the console text attribute to the  color attribute
    SetConsoleTextAttribute(hConsole, colorAttribute);
    // Set console font type, size 
    CONSOLE_FONT_INFOEX fo;					// Declares a CONSOLE_FONT_INFOEX
	fo.cbSize = sizeof(fo);					// Intializing with current font size 
	fo.dwFontSize.X = 0;                    // Width of each character in the font
	fo.dwFontSize.Y = 20;                   // Height
	fo.FontFamily = FF_DONTCARE;			// font family can be chosen freely
	fo.FontWeight = FW_NORMAL;				// regular font size
	wcscpy(fo.FaceName, L"Consolas"); 		// Choose your font family
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fo); 

}
//----------------------------------Function to Clear Screen----------------------------------------------------------//
void clearScreen() {
    	
    system("cls"); 
    
}
//----------------------------------Player Information Header------------------------------------//
void playerInformationHeader(){
	
	setColor(607);
	cout << "\t\t\t==========================================================================" << endl;
    cout << "\t\t\t                            Player Information                            " << endl;
    cout << "\t\t\t==========================================================================" << endl;
    setColor(287);
    
}
//-----------------------------------------------Function for Result Card Header--------------------------------------------//
void resultCardHeader(){  

	/* to adjust background border color so that color don't go beyond the border 
	Spacing according to currentSubject character length*/ 
	
	setColor(607);
    if (currentSubject=="PF"){
    	
    cout << "\t\t\t=========================================================" << endl;
	cout << "\t\t\t                  " <<currentSubject<< " Quiz Result                         " << endl;
    cout << "\t\t\t=========================================================" << endl;
    	
	}
	else if (currentSubject=="English"){
	
	cout << "\t\t\t=========================================================" << endl;
	cout << "\t\t\t                  " <<currentSubject<< " Quiz Result                    " << endl;
    cout << "\t\t\t=========================================================" << endl;
	
	}
	else if (currentSubject=="Disecrete Math"){

	cout << "\t\t\t=========================================================" << endl;
	cout << "\t\t\t                  " <<currentSubject<< " Quiz Result             " << endl;
    cout << "\t\t\t=========================================================" << endl;
		
	}
	else if(currentSubject=="Calculus"){
	
	cout << "\t\t\t=========================================================" << endl;
	cout << "\t\t\t                  " <<currentSubject<< " Quiz Result                   " << endl;
    cout << "\t\t\t=========================================================" << endl;
    
	}
	else if(currentSubject=="DLD"){
	
	cout << "\t\t\t=========================================================" << endl;
	cout << "\t\t\t                  " <<currentSubject<< " Quiz Result                        " << endl;
    cout << "\t\t\t=========================================================" << endl;
    
	}
	else if (currentSubject=="Pak Study"){
	
	cout << "\t\t\t=========================================================" << endl;
	cout << "\t\t\t                  " <<currentSubject<< " Quiz Result                  " << endl;
    cout << "\t\t\t=========================================================" << endl;
    
	}
    setColor(287);
    
}
//-----------------------------------------------Function for Quiz Header--------------------------------------------//
void quizHeader(){

	/* to adjust background border color so that color don't go beyond the border 
	Spacing according to currentSubject character length*/ 
	
	clearScreen();
	setColor(607);
	if(currentSubject=="English"){
			
		cout << "===============================================================================================" << endl;
		cout << "                                        " << currentSubject << " Quiz                                           " << endl;
		cout << "===============================================================================================" << endl;
	}		
	else if(currentSubject=="DLD"){
			
		cout << "===============================================================================================" << endl;
		cout << "                                        " << currentSubject << " Quiz                                               " << endl;
		cout << "===============================================================================================" << endl;
	}	
	else if(currentSubject=="PF"){
				
		cout << "===============================================================================================" << endl;
		cout << "                                        " << currentSubject << " Quiz                                                " << endl;
		cout << "===============================================================================================" << endl;
		
		}
	else if(currentSubject=="Calculus"){
			
		cout << "===============================================================================================" << endl;
		cout << "                                        " << currentSubject << " Quiz                                          " << endl;
		cout << "===============================================================================================" << endl;
	}
	else if(currentSubject=="Disecrete Math"){
			
		cout << "===============================================================================================" << endl;
		cout << "                                        " << currentSubject << " Quiz                                    " << endl;
		cout << "===============================================================================================" << endl;
	}	
	else if(currentSubject=="Pak Study"){
			
		cout << "===============================================================================================" << endl;
		cout << "                                        " << currentSubject << " Quiz                                         " << endl;
		cout << "===============================================================================================" << endl;
	}
	setColor(287);
		
}
//-----------------------------------------------Function for Score Header in startQuiz()--------------------------------------------//
void scoreHeader(){
	
	/* to adjust background border color so that color don't go beyond the border spacing according  
	to integer length mean when single integer 1 and when in 10's form */ 
	
	if (remainingQuestions==10){
		
		setColor(15);
		cout <<"Total Questions: "<<totalQuestions
		<< setw(24) <<"Questions Left: "<<remainingQuestions
		<< setw(24) <<"Correct Answers: "<<correctAnswers 
		<< setw(24) <<"Incorrect Answers : "<<incorrectAnswers << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		setColor(351);
		cout << "Player Name: "<<currentPlayerName<<"                 Roll Number: "<<currentRollNo<<"                Difficulty: "<<quizDifficulty<<endl;
	
	}
	else{
	
	setColor(15);
	cout <<"Total Questions: "<<totalQuestions
	<< setw(24) <<"Questions Left: "<<remainingQuestions
	<< setw(25) <<"Correct Answers: "<<correctAnswers 
	<< setw(24) <<"Incorrect Answers : "<<incorrectAnswers << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	setColor(351);
	cout << "Player Name: "<<currentPlayerName<<"                 Roll Number: "<<currentRollNo<<"                Difficulty: "<<quizDifficulty<<endl;
	
	}
}
