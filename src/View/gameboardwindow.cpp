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
    string userGuess1 = this-> guessWordInput1-> value();
    string userGuess2 = this-> guessWordInput2-> value();
    string userGuess3 = this-> guessWordInput3-> value();
    string userGuess4 = this-> guessWordInput4-> value();
    string userGuess5 = this-> guessWordInput5-> value();
    string userGuess = userGuess1 + userGuess2 + userGuess3 + userGuess4 + userGuess5;


    if (userGuess.length() == 5)
    {
       int* solution = this-> gbController-> checkGuessAsCorrect(userGuess);
       if(solution[0] == 2){
        this->guessWordInput1->color(FL_YELLOW);
        this->guessWordInput1->deactivate();
        this->guessWordInput1->activate();
       }else if(solution[0] == 3){
        this->guessWordInput1->color(FL_GREEN);
        this->guessWordInput1->deactivate();
        this->guessWordInput1->activate();
       }else{
           this->guessWordInput1->color(FL_WHITE);
        this->guessWordInput1->deactivate();
        this->guessWordInput1->activate();
       }
    }
}

/**< private */
void GameBoardWindow::performFirstTimeSetup()
{
    this-> gbController = new GameBoardController();
    this-> guessWordInput1 = new Fl_Input(150, 120, 25, 25, "Enter your guess:");
    this-> guessWordInput2 = new Fl_Input(180, 120, 25, 25);
    this-> guessWordInput3 = new Fl_Input(210, 120, 25, 25);
    this-> guessWordInput4 = new Fl_Input(240, 120, 25, 25);
    this-> guessWordInput5 = new Fl_Input(270, 120, 25, 25);
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
    delete this-> guessWordInput1;
    delete this-> guessWordInput2;
    delete this-> guessWordInput3;
    delete this-> guessWordInput4;
    delete this-> guessWordInput5;
}

}
