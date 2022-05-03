#include "gameoverwindow.h"
#include "okcancelwindow.h"
#include <iostream>
#include <Fl/Fl_Chart.H>
#include <Fl/Fl_Box.H>
#include <cstring>
using namespace std;
namespace view
{
/// \brief Constructor that derives OKCancelWindow widget
///
GameOverWindow::GameOverWindow() : OKCancelWindow(430, 415, "Login")
{
    this-> setCancelLocation(80, 330);
    this-> setOKLocation(5, 330);

    begin();
    this-> statsChart = new Fl_Chart(30,30,200,200,"Player stats");
    this-> statsChart-> type(FL_HORBAR_CHART);
    this-> statsChart-> autosize(1);
    this-> outputLabel = new Fl_Box(145, 80, 200, 200);
    end();
}

/// \brief Will draw the user's game statistics in the window
///
/// \return void
///
///
void GameOverWindow::drawStats()
{
    this-> statsChart-> insert(1, this-> player-> getOneTryWins(), "1 guesses", 1);
    this-> statsChart-> insert(2, this-> player-> getTwoTryWins(), "2 guesses", 2);
    this-> statsChart-> insert(3, this-> player-> getThreeTryWins(), "3 guesses", 3);
    this-> statsChart-> insert(4, this-> player-> getFourTryWins(), "4 guesses", 4);
    this-> statsChart-> insert(5, this-> player-> getFiveTryWins(), "5 guesses", 5);
    this-> statsChart-> insert(6, this-> player-> getSixTryWins(), "6 guesses", 6);

    char* output = strcpy(new char[player-> printPlayer().length() + 1], player-> printPlayer().c_str());
    outputLabel-> label(output);
}

/// \brief Will set the player
///
/// \param player Player* -- the currently logged in player
/// \return void
///
///
void GameOverWindow::setPlayer(Player* player)
{
    this-> player = player;
    this-> drawStats();
}

/// \brief Event handler for ok button press
///
/// \return void
///
///
void GameOverWindow::okHandler()
{
    this-> hide();
}

/// \brief Event handler for cacncel button press
///
/// \return void
///
///
void GameOverWindow::cancelHandler()
{
    exit(0);
}

/// \brief Destructor
///
GameOverWindow::~GameOverWindow()
{
    delete this-> statsChart;
    delete this-> outputLabel;
}
}
