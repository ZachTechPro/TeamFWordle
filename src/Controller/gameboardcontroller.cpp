#include "gameboardcontroller.h"
#include <iostream>
namespace Controller
{

/** \brief Constructor
 *
 */
GameBoardController::GameBoardController()
{
    this-> fileIo = new FileIo();
    this-> guessChecker = new GuessChecker();
}

/** \brief Will loads from the words list that are of length 5
 *
 */
void GameBoardController::loadWordsForPlay()
{
    if(this->repeatLetters)
    {
        this->chosenWord = this->fileIo->loadWords();
    }
    else
    {
        this->chosenWord = this-> fileIo->loadWordsNoDuplicateLetters();
    }

    cout <<chosenWord << endl;
}

int* GameBoardController::checkGuessAsCorrect(const string& userGuess)
{
    return this-> guessChecker-> checkGuessAsCorrect(userGuess, chosenWord);
}

bool GameBoardController::checkForCompletedSolution(int* solutionFlags, int numCells)
{
    int correctLetterCorrectSpotFlag = 3;
    int hasGuessedAll = true;
    for (int flagIndex = 0; flagIndex < numCells; flagIndex++)
    {
        if (solutionFlags[flagIndex] != correctLetterCorrectSpotFlag)
        {
            hasGuessedAll = false;
        }
    }
    return hasGuessedAll;
}

bool GameBoardController::getRepeatLetters()
{
    return this->repeatLetters;
}
void GameBoardController::setRepeatLetters(bool repeat)
{
    this->repeatLetters = repeat;
}

void GameBoardController::updateGameLostStats(Player* player)
{

}

void GameBoardController::updateGameWonStats(Player* player, int numGuesses)
{
    const int singleGuess = 1;
    const int twoGuesses = 2;
    const int threeGuesses = 3;
    const int fourGuesses = 4;
    const int fiveGuesses = 5;
    const int sixGuesses = 6;
    switch(numGuesses)
    {
    case singleGuess:
        player-> setOneTryWins(player-> getOneTryWins() + 1);
        break;

    case twoGuesses:
        player -> setTwoTryWins(player-> getTwoTryWins() + 1);
        break;

    case threeGuesses:
        player -> setThreeTryWins(player-> getThreeTryWins() + 1);
        break;

    case fourGuesses:
        player -> setFourTryWins(player-> getFourTryWins() + 1);
        break;

    case fiveGuesses:
        player -> setFiveTryWins(player-> getFiveTryWins() + 1);
        break;

    case sixGuesses:
        player -> setSixTryWins(player-> getSixTryWins() + 1);
        break;
    }

    // handles new win streak and updating current win streak
    if (player-> getIsOnWinStreak())
    {
        player-> setcurrentWinStreak(player-> getCurrentWinStreak() + 1);
        if (player-> getCurrentWinStreak() > player-> getMaxWinStreak())
        {
            player-> setMaxWinStreak(player-> getCurrentWinStreak());
        }
    }

}



/** \brief Destructor
*
*/
GameBoardController::~GameBoardController()
{
    delete this-> fileIo;
    delete this-> guessChecker;
}
}
