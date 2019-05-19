#include "num_change.hpp"
#include "graphics.hpp"
using namespace genv;

Num_Change::Num_Change(int x, int y, int xmeret, int ymeret, int a, int b)
    : Widget(x,y,xmeret,ymeret)
{
    _a=a;
    _b=b;
    _value=(a+b)/2;
    _checked=false;
}
/*bool Num_Change::is_selected(int mouse _x, int mouse _y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}*/
void Num_Change::draw()
{
    gout << move_to(_x, _y) << color(105,105,105) << box(_size_x-eltolas, _size_y);
    gout << move_to(_x+keretvastagsag, _y+keretvastagsag) << color(220,220,220) << box(_size_x-eltolas-2*keretvastagsag, _size_y-2*keretvastagsag);
    gout << move_to(_x+_size_x-eltolas+inbetween, _y) << color(105,105,105) << box(eltolas, _size_y);
    gout << move_to(_x+_size_x-eltolas+inbetween+keretvastagsag, _y+keretvastagsag) << color(220,220,220) << box(eltolas-2*keretvastagsag, _size_y-2*keretvastagsag);
    gout << move_to(_x+5, _y+2*_size_y/3) << color(0,0,0) << text(std::to_string(_value));
    for(int i=1;i<=_size_y/3;i++)
    {
        gout<<move_to(_x+_size_x-(eltolas)/2+keretvastagsag-i,_y+_size_y-keretvastagsag-i)<<color(105,105,105)<<line(2*i,0);
    }
    for(int i=_size_y/3;i>0;i--)
    {
        gout<<move_to(_x+_size_x-(eltolas)/2+keretvastagsag-i,_y+keretvastagsag+i)<<color(105,105,105)<<line(2*i,0);
    }
    if(is_checked())
    {
       gout << move_to(_x+stringstarter, _y+2*_size_y/3) << color(0,0,0) << text(std::to_string(_value));
    }
}
bool Num_Change::bennevan1(int x, int y)
{
    if(_x+_size_x-20<x && _x+_size_x+1> x && _y<y && _y+(_size_y/2)>y)
        return 1;
    return 0;
}
bool Num_Change::bennevan2(int x, int y)
{
    if(_x+_size_x-20<x && _x+_size_x+1> x && _y+(_size_y/2)<y && _y+_size_y>y)
        return 1;
    return 0;
}
void Num_Change::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
    if (ev.type == ev_mouse && bennevan1(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        if(_value<_b)
        {
           _value++;
        }

    }
    if (ev.type == ev_mouse && bennevan2(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        if(_value>_a)
        {
           _value--;
        }
    }
    if(ev.type == ev_key && ev.keycode == key_up)
    {
        if(_value<_b)
        {
           _value++;
        }
    }
    if(ev.type == ev_key && ev.keycode == key_down)
    {
        if(_value>_a)
        {
           _value--;
        }
    }
    if(ev.type == ev_key && ev.keycode == key_pgup && _value<_b-bigger_jump)
    {
       _value+=10;
    }
     if(ev.type == ev_key && ev.keycode == key_pgdn && _value>_a+bigger_jump)
    {
       _value-=10;
    }
}
bool Num_Change::is_checked()
{
    return _checked;
}

int Num_Change::getValue()
{
    return _value;
}

void Num_Change::loseFocus()
{

}
bool Num_Change::isnt_statik()
{
    return 1;
}
void Num_Change::setPlayer(int p)
{

}
