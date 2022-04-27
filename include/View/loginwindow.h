#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <FL/Fl_Window.H>
namespace view
{
class loginWindow : public Fl_Window
{
    public:
        loginWindow(int width, int height, const char* title);
        virtual ~loginWindow();

    protected:

    private:
};
}
#endif // LOGINWINDOW_H
