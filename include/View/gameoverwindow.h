#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H
#include "okcancelwindow.h"
#include <Fl/Fl_Chart.H>
#include "player.h"
#include <Fl/Fl_Box.H>
using namespace model;
namespace view
{
class GameOverWindow : public OKCancelWindow
{
public:
    void setPlayer(Player* player);
    void okHandler();
    void cancelHandler();
    GameOverWindow();
    virtual ~GameOverWindow();

protected:

private:
    void drawStats();
    Player* player;
    Fl_Chart* statsChart;
    Fl_Box* outputLabel;
};
}
#endif // GAMEOVERWINDOW_H
