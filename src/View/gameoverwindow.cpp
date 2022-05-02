#include "gameoverwindow.h"
#include "okcancelwindow.h"
#include <iostream>
#include <Fl/Fl_Chart.H>
using namespace std;
namespace view
{
GameOverWindow::GameOverWindow() : OKCancelWindow(430, 315, "Login")
{
    this-> setCancelLocation(200, 230);
    this-> setOKLocation(100, 230);

    begin();
    this-> statsChart = new Fl_Chart(30,30,150,150,"Player stats");
    this-> statsChart-> type(FL_HORBAR_CHART);
    this-> statsChart-> autosize(1);
    end();
}

void GameOverWindow::drawStats()
{
    this-> statsChart-> insert(1, this-> player-> getOneTryWins(), "1 guesses", 1);
    this-> statsChart-> insert(2, this-> player-> getTwoTryWins(), "2 guesses", 2);
    this-> statsChart-> insert(3, this-> player-> getThreeTryWins(), "3 guesses", 3);
    this-> statsChart-> insert(4, this-> player-> getFourTryWins(), "4 guesses", 4);
    this-> statsChart-> insert(5, this-> player-> getFiveTryWins(), "5 guesses", 5);
    this-> statsChart-> insert(6, this-> player-> getSixTryWins(), "6 guesses", 6);
}

void GameOverWindow::setPlayer(Player* player)
{
    this-> player = player;
    this-> drawStats();
}

void GameOverWindow::okHandler()
{

}

void GameOverWindow::cancelHandler()
{
    cout << "click cancel to close the app" << endl;
}

GameOverWindow::~GameOverWindow()
{
    delete this-> statsChart;
}
}
