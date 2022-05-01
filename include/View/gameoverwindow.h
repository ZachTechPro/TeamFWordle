#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H
#include "okcancelwindow.h"
#include <Fl/Fl_Chart.H>
#include "player.h"
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
    Player* player;
    Fl_Chart* statsChart;
};
}
#endif // GAMEOVERWINDOW_H
