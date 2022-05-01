#include "gameboardwindow.h"
#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <FL/Fl.H>
#include <iostream>
#include <vector>
#include "loginview.h"
#include "player.h"
using namespace model;
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
    int numCells = 4;
    for (int i = 0; i <= numCells; i++)
    {
        userGuess += this-> wordGrid[this-> rowNumber + i]-> value();
    }

    if (userGuess.length() == numCells + 1)
    {
        int* solution = this-> gbController-> checkGuessAsCorrect(userGuess);
        this-> checkForCompletedSolution(solution, numCells);
        if (this-> hasGuessedCompletedWord)
        {
            this-> showWin();
        }

        for (int i = 0; i <= numCells; i++)
        {
            this-> highLightLetterCell(this-> wordGrid[this-> rowNumber + i], solution[i]);
        }
        this-> rowNumber += 5;
    }
}


void GameBoardWindow::checkForCompletedSolution(int* solutionFlags, int numCells)
{
     this-> hasGuessedCompletedWord = this-> gbController-> checkForCompletedSolution(solutionFlags, numCells);
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

void GameBoardWindow::showWin()
{
    for (int i = 0; i < 30; i++)
    {
        this-> wordGrid[i]-> deactivate();
    }
}

/**< private */
void GameBoardWindow::performFirstTimeSetup()
{
    this-> gbController = new GameBoardController();
    this-> hasGuessedCompletedWord = false;
    int rowX = 150;
    int rowY = rowX - 120;
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
    int rowXKeys = 30;
    int rowYKeys = rowXKeys +180;
    int limitForRowLength = 10;
    int gridIndexKeyboard = 0;
    int AsciiValue = 97;
    char letter = AsciiValue;
    int finalAscii = 123;
    for (int rows = 0; rows < 3; rows++)
    {
        for (int column = 0; column < limitForRowLength; column++)
        {
            rowXKeys += 40;
            cout<<letter;
            const char* converted = new char(letter);
            Fl_Button* button;
            if(AsciiValue == finalAscii){
                button = new Fl_Button(rowXKeys, rowYKeys, 35, 35, "del");
            }else{
                button = new Fl_Button(rowXKeys, rowYKeys, 35, 35, converted);
            }



            this-> keyboardGrid[gridIndexKeyboard++] = button;
            AsciiValue++;
            letter = AsciiValue;


        }
        limitForRowLength--;
        rowYKeys += 40;
        rowXKeys = 30;
    }

    //string nameLabel = "Welcome, " + name + "!";
    this-> usernameLabel = new Fl_Box(50, 50, 100, 50, "Welcome!");
    this-> usernameLabel ->box(Fl_Boxtype::FL_NO_BOX);


    this-> submitGuessButton = new Fl_Button(320, 330, 70, 30, "Submit");
    this-> submitGuessButton-> callback(cbSubmitGuess, this);
    this-> login();
    this-> gbController-> loadWordsForPlay();
    this-> rowNumber = 0;
}

void GameBoardWindow::login()
{
    LoginView login;
    login.set_modal();
    login.show();

    while(login.shown())
    {
        Fl::wait();
    }
   if (login.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        this-> player = login.getPlayer();
        cout<<this->player->getCurrentWinStreak();

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
