#include "gameboardwindow.h"
#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <FL/Fl.H>
#include <iostream>
#include <vector>

using namespace std;
namespace view
{

/** \brief Constructor
 *
 * \param width -- the width of the game board view
 * \param height -- the height of the game board view
 * \param title -- the application title window
 * \return
 *
 */
GameBoardWindow::GameBoardWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this-> performFirstTimeSetup();
}

/** \brief call back for handling submit button click
 *
 * \param widget -- the FLTK widget
 * \param data -- the gameboard window
 * \return
 *
 */
void GameBoardWindow::cbSubmitGuess(Fl_Widget* widget, void* data)
{
    GameBoardWindow* window = (GameBoardWindow*) data;
    window-> submitGuess();
}

/** \brief Will handle the submission of a user guess.
 *
 */
void GameBoardWindow::submitGuess()
{

}


/**< private */
void GameBoardWindow::performFirstTimeSetup()
{
    this-> gbController = new GameBoardController();
    this-> guessWordInput = new Fl_Input(200, 330, 100, 25, "Enter your guess:");
    this-> submitGuessButton = new Fl_Button(320, 330, 70, 30, "Submit");

    this-> submitGuessButton-> callback(cbSubmitGuess, this);
    this-> gbController-> loadWordsForPlay();
}

/** \brief Destructor
 *
 */
GameBoardWindow::~GameBoardWindow()
{
    delete this-> gbController;
    delete this-> submitGuessButton;
    delete this-> guessWordInput;
}

}
