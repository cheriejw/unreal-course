#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty)
{
    // Introductory Messages with insertion operator
    std::cout << "You are a secret agent breaking into a level " << LevelDifficulty << " secure server room...\n";
    std::cout << "Enter the correct code to continue...\n";
}

bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);

    // Variable Initializations
    int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print Sum and Product
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "Sum is: " << CodeSum << std::endl;
    std::cout << "Product is: " << CodeProduct << std::endl;

    // Player's Input with extration operator
    int GuessA, GuessB, GuessC;
    std::cout << "Your Guess: ";
    // Stops at Space
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "You win!\n";
        return true;
    } else
    {
        std::cout << "BOOM! You lose! Try again!\n";
        return false;
    }
}

int main()
{
    // Seed rand()
    srand(time(NULL));

    // bool bWillContinue = true;
    int LevelDifficulty = 1;
    int MaxLevelDifficulty = 5;

    while (LevelDifficulty <= MaxLevelDifficulty)
    {
        bool bWillContinue = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clear errors
        std::cin.ignore(); // Discards buffer

        if (bWillContinue)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "Congratulations! You've beat the game!";

    return 0;
}