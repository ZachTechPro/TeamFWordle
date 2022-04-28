#include "gameboardwindow.h"
#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <FL/Fl.H>
#include <iostream>
#include <vector>
#include "loginview.h"

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
    string userGuess = "";

    for (int i = 0; i <= 4; i++)
    {
        userGuess += this-> wordGrid[this-> rowNumber + i]-> value();
    }

    if (userGuess.length() == 5)
    {
        int* solution = this-> gbController-> checkGuessAsCorrect(userGuess);

        for (int i = 0; i <= 4; i++)
        {
            this-> highLightLetterCell(this-> wordGrid[this-> rowNumber + i], solution[i]);
        }
        this-> rowNumber += 5;
    }
}

/**< private */
void GameBoardWindow::highLightLetterCell(Fl_Input* inputCell, int positionFlag)
{
    if(positionFlag == 2)
    {
        inputCell-> color(FL_YELLOW);
    }
    else if(positionFlag == 3)
    {
        inputCell-> color(FL_GREEN);
    }

    this-> updateColorAndDisable(inputCell);
}

/**< private */
void GameBoardWindow::updateColorAndDisable(Fl_Input* inputCell)
{
    inputCell-> deactivate();
    inputCell-> activate();
    inputCell-> deactivate();
}


/**< private */
void GameBoardWindow::performFirstTimeSetup()
{
    this-> gbController = new GameBoardController();

    int rowX = 150;
    int rowY = rowX;
    int gridIndex = 0;
    for (int rows = 0; rows < 6; rows++)
    {
        for (int column = 0; column < 5; column++)
        {
            rowX += 30;
            Fl_Input* input = new Fl_Input(rowX, rowY, 25, 25);
            input->maximum_size(1);
            this-> wordGrid[gridIndex++] = input;


        }
        rowY += 30;
        rowX = 150;
    }

    this-> submitGuessButton = new Fl_Button(320, 330, 70, 30, "Submit");
    this-> submitGuessButton-> callback(cbSubmitGuess, this);
    this-> login();
    this-> gbController-> loadWordsForPlay();
    this-> rowNumber = 0;


}

void GameBoardWindow::login()
{
    LoginView login(220, 220, "login");
    login.set_modal();
    login.show();

    while(login.shown())
    {
        Fl::wait();
    }

}

/** \brief Destructor
 *
 */
GameBoardWindow::~GameBoardWindow()
{
    delete this-> gbController;
    delete this-> submitGuessButton;
}

}
