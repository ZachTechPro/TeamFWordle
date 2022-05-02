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

/** \brief Destructor
*
*/
GameBoardController::~GameBoardController()
{
    delete this-> fileIo;
    delete this-> guessChecker;
}
}
