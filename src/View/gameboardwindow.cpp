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
//    string userGuess1 = this-> guessWordInput1-> value();
 //   string userGuess2 = this-> guessWordInput2-> value();
 //   string userGuess3 = this-> guessWordInput3-> value();
 //   string userGuess4 = this-> guessWordInput4-> value();
  //  string userGuess5 = this-> guessWordInput5-> value();
  //  string userGuess = userGuess1 + userGuess2 + userGuess3 + userGuess4 + userGuess5;

    string userGuess = "";
    for (int i = 0; i <= 4; i++)
    {
        userGuess += this-> wordGrid[i]-> value();
    }

    if (userGuess.length() == 5)
    {
       int* solution = this-> gbController-> checkGuessAsCorrect(userGuess);

        for (int i = 0; i <= 4; i++)
        {
            this-> highLightLetterCell(this-> wordGrid[i], solution[i]);
        }
    }
}

/**< private */
void GameBoardWindow::highLightLetterCell(Fl_Input* inputCell, int positionFlag)
{
     if(positionFlag == 2){
        inputCell-> color(FL_YELLOW);
        inputCell-> deactivate();
        inputCell-> activate();
       }else if(positionFlag == 3){
        inputCell-> color(FL_GREEN);
        inputCell-> deactivate();
        inputCell-> activate();
       }else{
           inputCell-> color(FL_WHITE);
        inputCell-> deactivate();
        inputCell-> activate();
       }
}


/**< private */
void GameBoardWindow::performFirstTimeSetup()
{
    this-> gbController = new GameBoardController();

    int thing = 120;
    for (int i = 0; i < 5; i++)
    {
        thing += 30;
        this->wordGrid[i] = new Fl_Input(thing, 120, 25, 25);
    }


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
    delete[] this-> wordGrid;
}

}
