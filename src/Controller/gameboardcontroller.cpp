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
    this->chosenWord = this-> fileIo-> loadWords();
    cout<<chosenWord<<endl;
}

int* GameBoardController::checkGuessAsCorrect(const string& userGuess)
{
    return this-> guessChecker-> checkGuessAsCorrect(userGuess, chosenWord);
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
