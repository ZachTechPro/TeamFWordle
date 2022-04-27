#ifndef LOGINVIEW_H
#define LOGINVIEW_H
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "logincontroller.h"
using namespace Controller;
namespace view
{

class LoginView : public Fl_Window
{
    public:
        LoginView(int width, int height, const char* title);
        virtual ~LoginView();

    protected:

    private:
        LoginController* controller;
        Fl_Button* loginButton;
        static void cbLogin(Fl_Widget* widget, void* data);
        void login();


};
}
#endif // LOGINVIEW_H
