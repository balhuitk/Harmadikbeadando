#include "dinamik.hpp"
#include "graphics.hpp"
using namespace genv;

Dinamik::Dinamik(int x, int y, int xmeret, int ymeret, std::string text)
    : Widget(x,y,xmeret,ymeret)
{
    _t=text;
    _checked=false;
}
void Dinamik::draw()
{
    gout << move_to(_x, _y) << color(0,0,0) << box(_size_x, _size_y);
    gout << move_to(_x+keretvastagsag, _y+keretvastagsag) << color(220,220,220) << box(_size_x-2*keretvastagsag, _size_y-2*keretvastagsag);
    if(is_checked())
    {
        gout << move_to(_x+keretvastagsag, _y+keretvastagsag) << color(220,220,220) << box(_size_x-2*keretvastagsag, _size_y-2*keretvastagsag)<<
        move_to(_x+vizszintes_eltolas, _y+_size_y/2) << color(0,0,0) << text(_t);
    }
    gout << move_to(_x+vizszintes_eltolas, _y+_size_y/2) << color(0,0,0) << text(_t);
}

void Dinamik::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && !_checked) {
        _checked = !_checked;
        if(_checked)
            _t+='|';
        else
            _t=_t.substr(0,_t.length()-1);
    }
    if (ev.type == ev_key && ev.keycode == key_tab && isnt_statik())
    {
        if(!_checked)
            _t+='|';
        _checked = true;
    }
    if (ev.type == ev_key && ev.keycode == key_backspace && _checked && _t.length()!=0) {
        if(_t[_t.length()-1]=='|' && _t.length()>2)
        {
            _t=_t.substr(0,_t.length()-2 );
            _t+='|';
        }
        else
        {
            _t=_t.substr(0,_t.length()-1 );
        }
    }
    if (ev.type == ev_key && 32<=ev.keycode && ev.keycode<127 && _checked && gout.twidth(_t)<_size_x-gout.twidth("|")) {
        {
            if(_t[_t.length()-1]=='|')
            {
                _t=_t.substr(0,_t.length()-1);
            }
            _t+=ev.keycode;
            _t+='|';
        }
    }
}
bool Dinamik::is_checked()
{
    return _checked;
}
bool Dinamik::isnt_statik()
{
    return 1;
}
void Dinamik::loseFocus()
{

}
std::string Dinamik::getValue()
{
    return _t.substr(0,_t.length()-1);
}
void Dinamik::setPlayer(int p)
{

}

//hf: probald meg megoldani, hogy az enteres dolgok ne keletkezzenek a libreszben,

