#include "checkbox.hpp"
#include "graphics.hpp"
using namespace genv;

CheckBox::CheckBox(int x, int y, int xmeret, int ymeret, int p)
    : Widget(x,y,xmeret,ymeret)
{
    _checked=false;
    player=p;
    focusable=1;
}

void CheckBox::draw()
{
    gout << move_to(_x, _y) << color(0,0,0) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
    if (_checked && player==1) {
        gout << color(0,0,0);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
    if (_checked && player==-1) {


        gout << color(0,0,0);
        gout << move_to(_x+_size_x/3, _y+2*_size_y/3) << text("O");
    }
}

void CheckBox::handle(event ev)
{
    /*if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = true;
    }*/
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = true;
        focusable=0;
    }
}
bool CheckBox::is_checked()
{
    return _checked;
}
void CheckBox::setPlayer(int p)
{
    if(!_checked)
        player=p;
}
bool CheckBox::isnt_statik()
{
    return focusable;
}
void CheckBox::loseFocus()
{

}
void CheckBox::setStatic()
{
    focusable=0;
}
