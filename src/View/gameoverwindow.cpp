#include "gameoverwindow.h"
#include "okcancelwindow.h"
#include <iostream>
#include <Fl/Fl_Chart.H>
using namespace std;
namespace view
{
GameOverWindow::GameOverWindow() : OKCancelWindow(330, 215, "Login")
{
//    this-> setCancelLocation()
    this-> statsChart = new Fl_Chart(50,50,100,100,"Player stats");
    this-> statsChart-> autosize(1);
    this-> statsChart-> type(FL_HORBAR_CHART);
}

void GameOverWindow::setPlayer(Player* player)
{
    this-> player = player;
    cout << this-> player-> getUserName() << endl;
}

void GameOverWindow::okHandler()
{
    cout << "click ok to start a new game" << endl;
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
