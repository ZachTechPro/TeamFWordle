#ifndef LOGINVIEW_H
#define LOGINVIEW_H
#include <Fl/Fl_Input.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include "logincontroller.h"
#include "player.h"
#include "okcancelwindow.h"
using namespace model;
using namespace Controller;
namespace view
{
class LoginView : public OKCancelWindow
{
    public:
        void okHandler();
        void cancelHandler();
        Player* getPlayer();
        LoginView();
        virtual ~LoginView();


    protected:

    private:
        Player* player;
        Fl_Input* userNameInput;
        LoginController* controller;
        Fl_Button* loginButton;
        static void cbLogin(Fl_Widget* widget, void* data);
        void login();


};
}
#endif // LOGINVIEW_H
