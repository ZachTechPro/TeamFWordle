#include "gameboardcontroller.h"
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
    this-> fileIo-> loadWords();
}

void GameBoardController::checkGuessAsCorrect(const string& userGuess)
{
   this-> guessChecker-> checkGuessAsCorrect(userGuess);
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
