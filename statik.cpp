#include "statik.hpp"
#include "graphics.hpp"
using namespace genv;

Statik::Statik(int x, int y, int xmeret, int ymeret, std::string text)
    : Widget(x,y,xmeret,ymeret)
{
    _t=text;
    l= _size_x/gout.twidth(_t.substr(0,1));
    if(_t.length()>l)
    {
        _t=_t.substr(0,l-1);
    }
}
void Statik::draw()
{
    if(is_checked())
    gout <<  move_to(_x+vizszintes_eltolas,_y+_size_y/2) << text(_t);
}

void Statik::handle(event ev)
{

}
bool Statik::is_checked()
{
    return 1;
}
bool Statik::isnt_statik()
{
    return 0;
}
void Statik::SetValue()
{

}
void Statik::loseFocus()
{

}
void Statik::setPlayer(int p)
{

}
