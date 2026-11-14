#include <iostream>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include <iomanip>   // for setw()

using namespace std;

int main() {

    // Seed the random generator ONCE so the order is different every run
    srand(time(0));

    char playAgain;

    do {
        int score = 0;
        int totalQuestions = 8;

        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⡄\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣇\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⡏⣿⣿⡄\n⠤⣤⣤⣤⣤⣤⣤⣤⣤⣿⣿⠇⠀⢿⣿⣷⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⡶⠶⠶⠶⠶⠶⠶⠶⠶⠖⠒⠒⠒⠒⠒⠒⠒⠂\n⠀⠀⠘⢿⣿⣿⣟⠛⠛⠛⠛⠀⠀⠀⠛⠛⠛⠛⠋⠉⠉⠉⠉\n⠀⠀⠀⠀⠈⠛⣿⣿⣦⡀\n⠀⠀⠀⠀⠀⠀⠀⢹⣿⡿⠀⠀⠀⠀⠀MINI QUIZ GAME\n⠀⠀⠀⠀⠀⠀⠀⣾⣿⠁⢀⣤⣾⣦⡀\n⠀⠀⠀⠀⠀⠀⣸⣿⢇⣶⣿⠟⠙⠻⣿⣄\n⠀⠀⠀⠀⠀⢠⣿⣿⠿⠋⠁⠀⠀⠀⠀⠉⠳⣄\n⠀⠀⠀⠀⠀⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙" << endl;
      cout << "\n ⬩➤ Answer using a, b, c, or d." << endl;
      cout << "════════════════════════════════════════════════════════════════════════\n"<< endl;

        // Choose how many players (1 to 3)
        char playerChoice;
        int numPlayers;
        string names[3];
        int scores[3] = {0, 0, 0};

        cout << "┃⬩➤ HOW MANY PLAYERS?" << endl;
        cout << "┃    1) Solo  ( 1 player )" << endl;
        cout << "┃    2) Duo   ( 2 players )" << endl;
        cout << "┃    3) Trio  ( 3 players )" << endl;
        do {
            cout << "Your choice: ";
            cin >> playerChoice;
            cin.ignore(1000, '\n');   // throw away the rest of the line

            if (playerChoice != '1' && playerChoice != '2' && playerChoice != '3') {
                cout << "Invalid! Please type 1, 2, or 3." << endl;
            }
        } while (playerChoice != '1' && playerChoice != '2' && playerChoice != '3');
        numPlayers = playerChoice - '0'; // change the character into a number (1, 2, or 3)
        cout << endl;

        // Ask for each player's name
        cout << "════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⬩➤ ENTER YOUR NAME" << endl;
        cout << "════════════════════════════════════════════════════════════════════════" << endl;
        for (int p = 0; p < numPlayers; p++) {
            do {
                cout << "⬩➤ Player " << p + 1 << " name: ";
                getline(cin, names[p]);

                if (names[p].find_first_not_of(" \t") == string::npos) {
                    cout << "Invalid! Please type a name." << endl;
                }
            } while (names[p].find_first_not_of(" \t") == string::npos);

            if (names[p].length() > 15) {
                names[p] = names[p].substr(0, 15);   // keep names short so the leaderboard stays neat
            }
        }
        cout << endl;

        cout << "┃⬩➤ PLAYERS READY:" << endl;
        for (int p = 0; p < numPlayers; p++) {
            cout << "┃    ★ Player " << p + 1 << ": " << names[p] << endl;
        }
        cout << endl;

        // Choose the difficulty
        char choice;
        int difficulty;
        cout << "=================================" << endl;
        cout << "      CHOOSE DIFFICULTY" << endl;
        cout << "=================================" << endl;
        cout << "1) Easy" << endl;
        cout << "2) Medium" << endl;
        cout << "3) Hard" << endl;
        do {
            cout << "Your choice: ";
            cin >> choice;
            cin.ignore(1000, '\n');   // throw away the rest of the line

            if (choice != '1' && choice != '2' && choice != '3') {
                cout << "Invalid! Please type 1, 2, or 3." << endl;
            }
        } while (choice != '1' && choice != '2' && choice != '3');
        difficulty = choice - '0'; // change the character into a number (1, 2, or 3)
        cout << endl;

        // Shuffle the question order 
        int order[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        for (int i = totalQuestions - 1; i > 0; i--) {
            int j = rand() % (i + 1);      // random position from 0 to i
            int temp = order[i];           // swap order[i] and order[j]
            order[i] = order[j];        // 1 2 8 4 5 6 7 3
            order[j] = temp;
        }

        char correctAnswer;
        char answer;

        // Each player takes a turn answering the same shuffled questions
        for (int p = 0; p < numPlayers; p++) {
            score = 0;   // every player starts with 0 points

            cout << "════════════════════════════════════════════════════════════════════════" << endl;
            cout << "┃⬩➤ " << names[p] << ", it's your turn to answer!" << endl;
            if (numPlayers > 1) {
                cout << "┃⬩➤ Player " << p + 1 << " of " << numPlayers << endl;
            }
            cout << "════════════════════════════════════════════════════════════════════════" << endl;
            cout << "Press Enter to start...";
            cin.get();
            cout << endl;

            for (int q = 1; q <= totalQuestions; q++) {
                string question, optA, optB, optC, optD;
                bool isCorrect;

                // Pick the question using the shuffled order
                switch (order[q - 1] + (difficulty - 1) * 8) {
                    //EASY
                    case 1:
                        question = "Which data type is used to store whole numbers in C++?";
                        optA = "float";
                        optB = "int";
                        optC = "char";
                        optD = "string";
                        correctAnswer = 'b';
                        break;
                    case 2:
                        question = "What is debugging?";
                        optA = "Writing comments";
                        optB = "Designing a website";
                        optC = "Finding and fixing errors in a program";
                        optD = "Installing programming software";
                        correctAnswer = 'c';
                        break;
                    case 3:
                        question = "What does CCIT stand for?";
                        optA = "College of Communication and Information Technology";
                        optB = "College of Computing and Information Technology";
                        optC = "Center for Computer and Internet Technology";
                        optD = "College of Computer Innovation and Telecommunications";
                        correctAnswer = 'b';
                        break;
                    case 4:
                        question = "Which symbol ends a statement in C++?";
                        optA = ":";
                        optB = ".";
                        optC = ",";
                        optD = ";";
                        correctAnswer = 'd';
                        break;
                    case 5:
                        question = "Which data type stores true or false?";
                        optA = "int";
                        optB = "char";
                        optC = "bool";
                        optD = "string";
                        correctAnswer = 'c';
                        break;
                    case 6:
                        question = "Which data type is used for text?";
                        optA = "int";
                        optB = "float";
                        optC = "char";
                        optD = "string";
                        correctAnswer = 'd';
                        break;
                    case 7:
                        question = "What is the purpose of char in C++?";
                        optA = "To store whole number";
                        optB = "To store a single character";
                        optC = "To store decimal numbers ";
                        optD = "To display output";
                        correctAnswer = 'b';
                        break;
                    case 8: 
                        question = "Which operator is used to assign a value to a variable?";
                        optA = "==";
                        optB = "=";
                        optC = "!=";
                        optD = "+";
                        correctAnswer = 'b';
                        break;
                        //MEDIUM
                    case 9:
                        question = "Which operator is used to determine whether two values are NOT equal in C++?";
                        optA = "=";
                        optB = "==";
                        optC = "!=";
                        optD = "<=";
                        correctAnswer = 'c';
                        break;

                    case 10:
                        question = "What happens when the condition of a while loop is false before its first execution?";
                        optA = "The loop executes once";
                        optB = "The loop executes twice";
                        optC = "The loop body is skipped";
                        optD = "The program automatically terminates";
                        correctAnswer = 'c';
                        break;
                    case 11:
                        question = "Which of the following best explains the purpose of the void keyword in a function declaration?";
                        optA = "It indicates that the function returns no value.";
                        optB = "It indicates that the function returns an integer.";
                        optC = "It makes a function execute repeatedly.";
                        optD = "It prevents a function from receiving parameters.";
                        correctAnswer = 'a';
                        break;
                    case 12:
                        question = "What kind of operator is used to determine whether two values are less than or equal in C++?";
                        optA = "=";
                        optB = "==";
                        optC = "!=";
                        optD = "<=";
                        correctAnswer = 'd';
                        break;
                    case 13:
                        question = "What is the main purpose of the break statement in a loop?";
                        optA = "To restart the loop";
                        optB = "To skip one iteration";
                        optC = "To terminate the loop";
                        optD = "To declare a variable";
                        correctAnswer = 'c';
                        break;
                    case 14:
                        question = "Which of the following is NOT a fundamental data type in C++?";
                        optA = "int";
                        optB = "char";
                        optC = "float";
                        optD = "string";
                        correctAnswer = 'd';
                        break;
                    case 15:
                        question = "What is the purpose of comments in a C++ program?";
                        optA = "To execute additional instructions";
                        optB = "To explain or document the program without affecting its execution";
                        optC = "To declare variables automatically";
                        optD = "To convert code into machine language";
                        correctAnswer = 'b';
                        break;
                    case 16:
                        question = "What does syntax refer to in C++?";
                        optA = "The meaning or purpose of a program";
                        optB = "The rules governing how statements and expressions must be written";
                        optC = "The speed of program execution";
                        optD = "The amount of memory a program uses";
                        correctAnswer = 'b';
                        break;
                        //HARD
                    case 17:
                        question = "How do logical AND (&&) and logical OR (||) operators evaluate conditions in a statement?";
                        optA = "They check both sides of the statement no matter what.";
                        optB = "They stop checking as soon as the result is defined. && stops if the first part is false, and || stops if the first part is true.";
                        optC = "They check conditions from right to left.";
                        optD = "They run both sides at the exact same time.";
                        correctAnswer = 'b';
                        break;
                    case 18:
                        question = "If you put a break statement inside a for loop, what does it actually do to program execution?";
                        optA = "It pauses the loop for a few seconds and then resumes from where it stopped.";
                        optB = "It skips only the current turn of the loop and immediately starts the next turn.";
                        optC = "It completely stops the loop right away and jumps straight to the code below the loop.";
                        optD = "It restarts the loop back to turn number one.";
                        correctAnswer = 'c';
                        break;
                    case 19:
                        question = "Why can't a switch statement completely replace an if-else statement in every situation?";
                        optA = "A switch statement can only test if a variable equals exact fixed numbers or characters, while if-else can check value ranges and complex true/false conditions.";
                        optB = "A switch statement can only hold up to three options, whilst if-else has no limit.";
                        optC = "A switch statement runs every option at the exact same time, while if-else runs them one by one.";
                        optD = "A switch statement automatically deletes your variables when it finishes running.";
                        correctAnswer = 'a';
                        break;
                    case 20:
                        question = "What happens when a \"return\" statement runs inside a function?";
                        optA = "It ends the function and can send a value back to the code that called it.";
                        optB = "It repeats the function from the beginning.";
                        optC = "It skips only the current line and continues with the next one.";
                        optD = "It ends every loop in the program.";
                        correctAnswer = 'a';
                        break;
                    case 21:
                        question = "What is the purpose of an \"else\" block in an \"if-else\" statement?";
                        optA = "It runs only when the \"if\" condition is true.";
                        optB = "It runs when the \"if\" condition is false.";
                        optC = "It checks the same condition a second time.";
                        optD = "It stops the program if the condition is false.";
                        correctAnswer = 'b';
                        break;
                    case 22:
                        question = "What is the output of this code? void f(int a, int &b) { a++; b++; } int main() { int x = 1, y = 1; f(x, y); cout << x << y; }";
                        optA = "11";
                        optB = "21";
                        optC = "12";
                        optD = "22";
                        correctAnswer = 'c';
                        break;
                    case 23:
                        question = "What is the output of this code? int a = 7, b = 2; cout << a / b << \" \" << a % b << \" \" << (double)a / b;";
                        optA = "3 1 3.5";
                        optB = "3.5 1 3.5";
                        optC = "3 1 3";
                        optD = "4 1 3.5";
                        correctAnswer = 'a';
                        break;
                    case 24:
                        question = "What is the output of this code? int n = 2; switch (n) { case 1: cout << \"A\"; case 2: cout << \"B\"; case 3: cout << \"C\"; break; default: cout << \"D\"; }";
                        optA = "C";
                        optB = "BCD";
                        optC = "B";
                        optD = "BC";
                        correctAnswer = 'd';
                        break;
                    case 25:
                        question = "Which statement correctly describes the difference between \"const int* p\" and \"int* const p\"?";
                        optA = "Both make the pointed-to value and the pointer itself unchangeable.";
                        optB = "const int* p lets you change the pointed-to value but not the pointer, while int* const p is the opposite.";
                        optC = "const int* p prevents changing the value through p but lets p point elsewhere, while int* const p lets you change the value but p cannot point elsewhere.";
                        optD = "They are exactly the same.";
                        correctAnswer = 'c';
                        break;
                    case 26:
                        question = "What is the output if this function is called three times in a row? void count() { static int c = 0; c++; cout << c; }";
                        optA = "111";
                        optB = "123";
                        optC = "012";
                        optD = "321";
                        correctAnswer = 'b';
                        break;
                    default:
                        break;
                }

                // Show the question
                cout << "┃⬩➤ Question 𝄄𝄀 " << q << " 𝄀𝄄 of " << totalQuestions << "  ┃ " << names[p] << "'s turn" << endl;
                cout << question << endl;
                cout << "a) " << optA << endl;
                cout << "b) " << optB << endl;
                cout << "c) " << optC << endl;
                cout << "d) " << optD << endl;

                // Keep asking until the answer is a, b, c, or d
                do {
                    cout << "Your answer: ";
                    cin >> answer;
                    cin.ignore(1000, '\n');   // throw away the rest of the line

                    if (answer >= 'A' && answer <= 'D') {
                        answer = answer + 32; // change capital letter to small letter
                    }

                    if (answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd') {
                        cout << "Invalid! Please type a, b, c, or d." << endl;
                    }
                } while (answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd');

                // Check the answer
                if (answer == correctAnswer) {
                    isCorrect = true;
                } else {
                    isCorrect = false;
                }

                if (isCorrect) {
                    cout << "\n✔️🟢 Correct! +1 point" << endl;
                    score++;
                } else {
                    cout << "\n❌🚫 Wrong! The correct answer is 《 " << correctAnswer << " 》" << endl;
                }

                cout << "⬩➤ Score: " << score << endl;
                cout << "\n════════════════════════════════════════════════════════════════════════\n" << endl;
            }

            // Final result
            cout << "════════════════════════════════════════════════════════════════════════" << endl;
            cout << "⬩➤ " << names[p] << "'s Final Score: 《 " << score << " 》 out of " << totalQuestions << endl;

            if (score == totalQuestions) {
                cout << "(๑•̀ㅁ•́๑)✧ Perfect! You are a Quiz Master!" << endl;
            } else if (score >= 3) {
                cout << "( ദ്ദി ˙ᗜ˙ ) Good job!" << endl;
            } else {
                cout << "(ᵕ— ᴗ —) Keep practicing!" << endl;
            }
            cout << "════════════════════════════════════════════════════════════════════════" << endl;

            scores[p] = score;   // save this player's score for the leaderboard
            cout << endl;
        }

        // Sort the players from the highest score to the lowest (same swap idea as the shuffle)
        int standing[3] = {0, 1, 2};
        for (int a = 0; a < numPlayers - 1; a++) {
            for (int b = 0; b < numPlayers - 1 - a; b++) {
                if (scores[standing[b]] < scores[standing[b + 1]]) {
                    int temp = standing[b];
                    standing[b] = standing[b + 1];
                    standing[b + 1] = temp;
                }
            }
        }
        int highest = scores[standing[0]];

        cout << "════════════════════════════════════════════════════════════════════════" << endl;
        cout << "              🏆  L E A D E R B O A R D  🏆" << endl;
        cout << "════════════════════════════════════════════════════════════════════════" << endl;

        int place = 1;
        for (int r = 0; r < numPlayers; r++) {
            int p = standing[r];
            if (r > 0 && scores[p] < scores[standing[r - 1]]) {
                place = r + 1;   // same score = same place
            }
            cout << "┃⬩➤ #" << place << "  " << left << setw(16) << names[p]
                 << "《 " << scores[p] << " / " << totalQuestions << " 》" << endl;
        }
        cout << "════════════════════════════════════════════════════════════════════════" << endl;

        // Winner and losers (only when there is more than one player)
        if (numPlayers > 1) {
            int winners = 0;
            for (int p = 0; p < numPlayers; p++) {
                if (scores[p] == highest) {
                    winners++;
                }
            }
            if (winners > 1) {
                cout << "⬩➤ It's a tie for first place!" << endl;
            }
            for (int r = 0; r < numPlayers; r++) {
                int p = standing[r];
                if (scores[p] == highest) {
                    cout << "👑 " << names[p] << ", you are the winner!" << endl;
                } else {
                    cout << "💀 " << names[p] << ", you are a loser." << endl;
                }
            }
            cout << "════════════════════════════════════════════════════════════════════════" << endl;
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! ˖ ࣪‧₊˚⋆✩٩(ˊᗜˋ*)و ✩\n 『 GROUP 10 』" << endl;
    return 0;
}


