#include <iostream>
#include <filesystem>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Display.H>

namespace fs = std::filesystem;

 void convert_cb(Fl_Widget*, void*);
 void list_cb(Fl_Widget*, void*);
 void preview_cb(Fl_Widget*, void*);

int main()
{
Fl_Window* win = new Fl_Window (780, 380, "title");

//Fl_Group* group = new Fl_Group(780, 380, 400, 200, "group");
win->color((Fl_Color)53);
win->labelcolor(FL_BLACK);
win->begin();

Fl_Button* convert_button = new Fl_Button(605, 250, 100, 60, "convert");
  convert_button->color((Fl_Color)44);
  convert_button->labeltype(FL_ENGRAVED_LABEL);
  convert_button->callback (convert_cb);

Fl_Button* list_button = new Fl_Button(35, 105, 70, 55, "list");
  list_button->callback((Fl_Callback*)list_cb);

Fl_Input* to = new Fl_Input(495, 40, 80, 25, "to");
  to->textcolor(FL_GRAY0);

Fl_Input* extension = new Fl_Input(210, 40, 90, 25, "extension");
  extension->textcolor(FL_GRAY0);

Fl_Text_Display* dis = new Fl_Text_Display(140, 100, 400, 210, "datafiles");

Fl_Input* from = new Fl_Input(365, 40, 95, 25, "from");
  from->color((Fl_Color)55);
  from->selection_color((Fl_Color)134);
  from->textcolor(FL_BLACK);

Fl_Button* preview = new Fl_Button(610, 100, 80, 60, "preview");
//  preview->callback((Fl_Callback*)preview_cb);

win->end();

win->show();
return Fl::run();

}


 void convert_cb(Fl_Widget*, void*){
 std::cout << "show";
 }
 
 void list_cb (Fl_Widget* w, void* out)
{
    Fl_Text_Display* list_out = (Fl_Text_Display*) out;
    std::string str;
   for (const auto & entry : fs::directory_iterator(fs::current_path()))
   {str += entry.path().filename();
    str += "\n";}
    std::cout << str;
q
    char* ch = new char[str.length() +1];
    strcpy (ch, str.c_str());

     list_out->value (ch);
     delete[] ch;

}

