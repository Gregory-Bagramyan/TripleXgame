#include <iostream>
#include <ctime>

void PrintIntroduction() /*void represent the return type of the function and void means that there is no return for 
his function. This function will return no data*/
{
    // printing the into game sentences
    std::cout << std::endl;
    std::cout << "Yo wake up ! We need these numbers dude !\n";
    std::cout << "I know oreos are tasty out there but stop being selfish";
    std::cout << " just one sec please and give us the numbers, c'mon\n\n";
}

void PrintDifficultyLevel(int Difficulty) 
{
    //printing the level of difficulty
    std::cout << "By the way the alarm literaly SCREAMING level " << Difficulty << " of difficulty on repeat, if that helps \n";
}

bool PlayGame(int Difficulty) //the function returns a boolean. True if the players guessed right and false otherwise 
{
    PrintDifficultyLevel(Difficulty); //Calling the PrintIntroduction function for the introductory sentences
    //Declaring the 3 that the player has to guess to win 
    int FirstNumber = rand() % Difficulty +1; /*the value of a can be modified later AND rand()% Difficulty means the FirstNumer is a 
    random number between 0 and (Difficulty - 1) since the reminder of a number when devided by 4 for example range from 0 to 3 
    also we do not use just rand() because rond goes up to 32k so it would be an impossible game
    and we rather not have 0 as a possible answer so we add 1 to avoid it*/
    int SecondNumber = rand() % Difficulty + 1; // si on écrit const int b = 2 b ne sera plus modifiable par la suite
    int ThridNumber = rand() % Difficulty +1 ; 

    //Declaring the sum and the product of the 3 numbers so the player can guess the numbers based on the sum and product
    const int CodeSum = FirstNumber + SecondNumber + ThridNumber;
    const int CodeProduct = FirstNumber * SecondNumber * ThridNumber;

    //printing the sum and the product on separate lines so the player can try to find the 3 numbers based on these statments
    std::cout << "Give us the 3 numbers of the code dude FocuS !\n";
    std::cout << "+It says the 3 numbers should add-up to " << CodeSum;
    std::cout << "\n+And the pro.. prud.. when you multiply the 3 numbers the result is ";
    std::cout << CodeProduct << std::endl;;

    //Collection the guesses of the player for the 3 numbers (the player has to find the numbers in no particular order)
    int GuessFirstNumber, GuessSecondNumber, GuessThridNumber; 
    std::cout << "What are you waiting for ?! THE THREE NUM BERZZZZZ \n";
    std::cin >> GuessFirstNumber >> GuessSecondNumber >> GuessThridNumber;
    
    //computating the sum and product of the numbers guessed by the player 
    const int GuessSum = GuessFirstNumber + GuessSecondNumber + GuessThridNumber; 
    const int GuessProduct = GuessFirstNumber * GuessSecondNumber * GuessThridNumber; 

    //Printing the sum and the product of the numbers guessed by the player 
    std::cout << "\nDude the sum of the numbers you gave is " << GuessSum;
    std::cout << "\nand the pro.. pr.. you know what i mean, is " << GuessProduct;

    

    /*Checking if the sum and product of the numbers guessed by the player match the sum and product of the numbers the 
    players has to find. And ending the game with a WIN if the player guessed right. 
    Or printing a LOSE sentence otherwise */
    if (GuessSum == CodeSum and GuessProduct == CodeProduct) //and can be replaced with &&
    {
        std::cout << "\nThank you dude ! I knew you would remeber";
        return true;
    }
    else 
    {
        std::cout << "\nYou being serious right now ?! \n" ;
        std::cout << "We're not playing, we have real problems out here dude \n" ;
        std::cout << "Please FOCUS and give us the 3 right numbers, you are the only one to know them ! \n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //create a random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    PrintIntroduction();

    while (LevelDifficulty <= MaxDifficulty) //Loop the game until the max level of difficulty
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); 
        std::cin.clear();// Clears any errors 
        std::cin.ignore();// Discards the buffer  

        if (bLevelComplete) 
        {
            //increase the level of difficultie 
            std::cout << "\n\nYo bro wait it asks for another code !\n";
            ++LevelDifficulty;//Similar to LevelDifficulty = LevelDifficulty + 1
        }
    }

    std::cout << "You can now go back to eating cheese and ";
    std::cout << "think that nothing makes sense in this nonsense computational simulation you in \n";

    return 0; //return 0 means these was no errors durung the code processing  
    
}

/*
To compile (for mac) type in the terminal: g++ triplex.cpp -o triplex 
(for windows type: cl triplex.cpp)
when its compiled (for mac)type : ./triplex
(for wondows type: triplex)
*/

/*
pour compiler écrire dans le terminal (dans le bon directory ou en clicant sur
le fichier ici en haut à gauche (dans Vs code) (clic 2doigts puis ouvrir dans le terminal intégré)
 Bref écrire dans le terminal : g++ triplex.cpp -o triplex 
puis une fois que ça a compilé écrire : ./triplex
*/