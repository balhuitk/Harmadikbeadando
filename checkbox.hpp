#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class CheckBox : public Widget {
protected:
    bool _checked;
    int player;
public:
    CheckBox(int x, int y, int xmeret, int ymeret, int p);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
    virtual bool isnt_statik();
    virtual void loseFocus();
    virtual void setPlayer(int p);
};


#endif // CHECKBOX_HPP_INCLUDED

