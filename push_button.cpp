#include "push_button.hpp"
#include "graphics.hpp"
using namespace genv;

Push_Button::Push_Button(int x, int y, int xmeret, int ymeret, std::function<void()>f, std::string text)
    : Widget(x,y,xmeret,ymeret)
{
    _f=f;
    _t=text;
}
void Push_Button::draw()
{
    gout << move_to(_x, _y) << color(0,0,0) << box(_size_x,_size_y) << move_to(_x+keretvastagsag, _y+keretvastagsag) << color(220,220,220) <<
    box(_size_x-2*keretvastagsag,_size_y-2*keretvastagsag);
    gout << move_to(_x+keretvastagsag+_size_x/3,_y+_size_y/2)<<color(0,0,0)<<text(_t);
}

void Push_Button::handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left && bennevan(ev.pos_x,ev.pos_y))
        _f();

}

bool Push_Button::isnt_statik()
{
    return 1;
}

bool Push_Button::bennevan(int x, int y)
{
    return x>_x && x<_x+_size_x && y>_y && y<_y+_size_y;
}
void Push_Button::loseFocus()
{

}
void Push_Button::setPlayer(int p)
{

}
