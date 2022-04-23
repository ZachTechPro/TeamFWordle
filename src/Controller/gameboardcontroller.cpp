#include "gameboardcontroller.h"
namespace Controller
{

/** \brief Constructor
 *
 */
GameBoardController::GameBoardController()
{
    this-> fileIo = new FileIo();
}

/** \brief Will loads from the words list that are of length 5
 *
 */
void GameBoardController::loadWordsForPlay()
{
    this-> fileIo-> loadWords();
}

/** \brief Destructor
*
*/
GameBoardController::~GameBoardController()
{
    delete this-> fileIo;
}
}
