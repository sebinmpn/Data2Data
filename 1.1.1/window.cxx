#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>

int main()
{

    Fl_Window *window = new Fl_Window (600, 300, "data2data");
    Fl_Button *button = new Fl_Button (100, 100, 400, 50, "button");
    Fl_Input *input = new Fl_Input (100, 200, 400, 50, "input");
    input->value("haii Sir");


    window->show();

    return Fl::run();
}
