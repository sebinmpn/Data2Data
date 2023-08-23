// generated by Fast Light User Interface Designer (fluid) version 1.0308

#ifndef form_h
#define form_h
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Display.H>

extern void convert_cb(Fl_Button*, void*);
extern void list_cb(Fl_Button*, void*);
extern void preview_cb(Fl_Button*, void*);

class form : public Fl_Group {
public:
  form(int X, int Y, int W, int H, const char *L = 0);
};
#endif