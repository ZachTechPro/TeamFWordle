#include "gameboardwindow.h"
#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <FL/Fl.H>
#include <iostream>
#include <vector>
#define DIAGNOSTIC_OUTPUT
#include "loginview.h"
#include "player.h"
#include "gameoverwindow.h"
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

/// \brief callback for handling letter input
///
/// \param widget Fl_Widget* -- the FLTK Widget
/// \param data void* -- the gameboard window
/// \return void
///
///
void GameBoardWindow::cbHandleLetter(Fl_Widget* widget, void* data)
{
    GameBoardWindow* window = (GameBoardWindow*) data;
    window-> handleLetter(widget->label());
}

/// \brief Functionality to handle letter input per cell in the GameBoard
///
/// \param letter const string& -- a letter in their guess word
/// \return void
///
///
void GameBoardWindow::handleLetter(const string& letter)
{
    if(letter == "del")
    {

        Fl_Input* last;
        for(int i = 0; i < 30; i++)
        {
            if(strlen(this->wordGrid[i]->value()) > 0)
            {
                last = this->wordGrid[i];
                continue;
            }
            if (i == 0)
            {
                return;
            }
            if(i == (this->roundCount-1) * 5)
            {
                return;
            }
            last->value("");
            return;


        }
    }
    const char* letterChar = strcpy(new char[letter.length() + 1], letter.c_str());
    for(int i = 0; i < 30; i++)
    {
        if(strlen(this->wordGrid[i]->value()) > 0)
        {
            continue;
        }
        if(i == this->roundCount * 5)
        {
            return;
        }
        this->wordGrid[i]->value(letterChar);
        return;

    }
}

/** \brief Will handle the submission of a user guess.
 *
 */
void GameBoardWindow::submitGuess()
{
    string userGuess = "";
    int numCells = 4;
    int maxRowNumber = 25;
    bool hasRunOutOfGuesses = this-> rowNumber >= maxRowNumber;
    if (hasRunOutOfGuesses)
    {
        this-> showStatsPage();
    }

    for (int i = 0; i <= numCells; i++)
    {
        userGuess += this-> wordGrid[this-> rowNumber + i]-> value();
    }

    if (userGuess.length() == numCells + 1 && this-> gbController-> isValidGuess(userGuess))
    {
        int* solution = this-> gbController-> checkGuessAsCorrect(userGuess);
        this-> checkForCompletedSolution(solution, numCells);

        for (int i = 0; i <= numCells; i++)
        {
            this-> highLightLetterCell(this-> wordGrid[this-> rowNumber + i], solution[i]);
        }

        if (this-> hasGuessedCompletedWord)
        {
            this-> gbController-> updateGameWonStats(this-> player, this-> roundCount);
            this-> showStatsPage();
        }
        else
        {
            int rowIncrement = 5;
            this-> roundCount++;
            this-> rowNumber += rowIncrement;
        }
    }
}

///< private
void GameBoardWindow::checkForCompletedSolution(int* solutionFlags, int numCells)
{
    this-> hasGuessedCompletedWord = this-> gbController-> checkForCompletedSolution(solutionFlags, numCells);
}

///< private
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

///< private
void GameBoardWindow::showStatsPage()
{
    int numWordleCells = 30;
    for (int currWordleCellNumber = 0; currWordleCellNumber < numWordleCells; currWordleCellNumber++)
    {
        this-> wordGrid[currWordleCellNumber]-> deactivate();
    }

    GameOverWindow gameOverWindow;
    gameOverWindow.setPlayer(this-> player);
    gameOverWindow.set_modal();
    gameOverWindow.show();

    while(gameOverWindow.shown())
    {
        Fl::wait();
    }
    if (gameOverWindow.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        this-> resetBoard();
        this-> performFirstTimeSetup();
    }
}

///< private
void GameBoardWindow::resetBoard()
{
    for (int i = 0; i < 30; i++)
    {
        this-> wordGrid[i]-> value("");
        this-> wordGrid[i]-> color(FL_WHITE);
        this-> wordGrid[i]-> activate();
    }
}

/**< private */
void GameBoardWindow::performFirstTimeSetup()
{
    if(!this->replay)
    {
        this-> gbController = new GameBoardController();
        this-> buildWordleGrid();
        this-> buildKeyboard();
        this-> usernameLabel = new Fl_Box(50, 50, 100, 50, "welcome");
        this-> usernameLabel-> box(Fl_Boxtype::FL_NO_BOX);
        this->wordGuessLabel = new Fl_Box(50, 75, 100, 50, "");
        this->wordGuessLabel->box(Fl_Boxtype::FL_NO_BOX);
        this-> submitGuessButton = new Fl_Button(320, 330, 70, 30, "Submit");
        this-> submitGuessButton-> callback(cbSubmitGuess, this);
        this-> login();
    }
    if (this-> replay)
    {
        this-> submitGuessButton-> redraw();
        this-> submitGuessButton-> callback(cbSubmitGuess, this);
    }

    this-> gbController-> loadWordsForPlay();
    this-> roundCount = 1;
    this-> hasGuessedCompletedWord = false;
    this-> rowNumber = 0;
    string word = this->gbController->getChosenWord();
    char* wordLabel = strcpy(new char[word.length() + 1], word.c_str());
    string name = "Welcome, " + this-> player-> getUserName() + "!";
    char* nameLabel = strcpy(new char[name.length() + 1], name.c_str());
    this-> usernameLabel-> label(nameLabel);
    this->replay = true;

#ifdef DIAGNOSTIC_OUTPUT
    this->wordGuessLabel->label(wordLabel);
#endif

}

void GameBoardWindow::buildKeyboard()
{
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
            const char* converted = new char(letter);
            Fl_Button* button;
            if(AsciiValue == finalAscii)
            {
                button = new Fl_Button(rowXKeys, rowYKeys, 35, 35, "del");
            }
            else
            {
                button = new Fl_Button(rowXKeys, rowYKeys, 35, 35, converted);
            }
            button->callback(cbHandleLetter, this);

            this-> keyboardGrid[gridIndexKeyboard++] = button;
            AsciiValue++;
            letter = AsciiValue;
        }
        limitForRowLength--;
        rowYKeys += 40;
        rowXKeys = 30;
    }
}

void GameBoardWindow::buildWordleGrid()
{
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
        this->gbController->setRepeatLetters(login.getCheckedRepeatLetters());
    }
}


/** \brief Destructor
 *
 */
GameBoardWindow::~GameBoardWindow()
{
    delete this-> gbController;
    delete this-> submitGuessButton;
    delete this-> player;
    delete this-> usernameLabel;
}

}
