#include "menu.hpp"
#include "graphics.hpp"
using namespace genv;

std::string t="Choice: ";
int size_text=gout.twidth(t);

Menu::Menu(int x, int y, int xmeret, int ymeret1, int ymeret2, std::vector<std::string> _options)
    : Widget(x,y,xmeret,ymeret1)
{
    _checked=false;
    drop=false;
    drop_size=ymeret2;
    for(size_t i=0;i<_options.size();i++)
    {
        options.push_back(_options[i]);
    }
    currentoption=options[0];
}
void Menu::draw()
{
    if(drop)
    {
        gout << move_to(_x, _y) << color(105,105,105) << box(_size_x-nyileltolas, _size_y+drop_size);
        gout << move_to(_x+keretvastagsag, _y+keretvastagsag) << color(220,220,220) << box(_size_x-2*keretvastagsag-nyileltolas, _size_y-2*keretvastagsag+drop_size);
        gout << move_to(_x+_size_x-nyileltolas, _y) << color(105,105,105) << box(nyileltolas, _size_y);
        gout << move_to(_x+_size_x+keretvastagsag-nyileltolas, _y+keretvastagsag) << color(220,220,220) << box(nyileltolas-2*keretvastagsag, _size_y-2*keretvastagsag);
        for(int i=1;i<=_size_y/3;i++)
        {
            gout<<move_to(_x+_size_x-(nyileltolas)/2-i,_y+5*_size_y/6-keretvastagsag-i)<<color(105,105,105)<<line(2*i,0);//Az y szerinti eltolas imaxbol es a fuggoleges meret felebol kepezett osszeg
        }
        gout << move_to(_x+keretvastagsag, _y+keretvastagsag+(marked1)*(verticalsize)+_size_y) << color(0,0,255) << box(_size_x-2*keretvastagsag-nyileltolas, verticalsize);
        gout << move_to(_x+stringstarter,_y+2*_size_y/3)<< color(0,0,0)<<text(currentoption);
        for(size_t i=1;i<=(drop_size)/(verticalsize);i++)//
        {
            if(i+indexeltol<=options.size())//
            {
                gout << move_to(_x+stringstarter,_y+(i)*(verticalsize)+_size_y)<< color(0,0,0)<<text(options[i+indexeltol-1]);//
            }
        }
    }
    else
    {
        gout << move_to(_x, _y) << color(105,105,105) << box(_size_x-nyileltolas, _size_y);
        gout << move_to(_x+keretvastagsag, _y+keretvastagsag) << color(220,220,220) << box(_size_x-2*keretvastagsag-nyileltolas, _size_y-2*keretvastagsag);
        gout << move_to(_x+_size_x-nyileltolas, _y) << color(105,105,105) << box(nyileltolas, _size_y);
        gout << move_to(_x+_size_x+keretvastagsag-nyileltolas, _y+keretvastagsag) << color(220,220,220) << box(nyileltolas-2*keretvastagsag, _size_y-2*keretvastagsag);
        for(int i=1;i<=_size_y/3;i++)
        {
            gout<<move_to(_x+_size_x-(nyileltolas)/2-i,_y+5*_size_y/6-keretvastagsag-i)<<color(105,105,105)<<line(2*i,0);//Az y szerinti eltolas imaxbol es a fuggoleges meret felebol kepezett osszeg
        }
        gout << move_to(_x+stringstarter, _y+2*_size_y/3) << color(0,0,0) << text(currentoption);
    }
}
bool Menu::bennevandrop(int x, int y)
{
    if(_x<x && _x+_size_x> x && _y<y && _y+_size_y>y)
        return 1;
    return 0;
}
bool Menu::bennevanoption(int x, int y, int iteration)
{
    if(_x<x && _x+_size_x> x && (iteration)*verticalsize+_y+_size_y<y && y<_y+(iteration+1)*verticalsize+_size_y)//
        return 1;
    return 0;
}
bool Menu::is_selected2(int x, int y)
{
    return x>_x && x<_x+_size_x-nyileltolas && y>_y && y<_y+_size_y+drop_size;
}
bool Menu::is_selected(int x, int y)
{
    if(!drop)
    {
        return Widget::is_selected(x,y);
    }
    else
        return is_selected2(x,y);
}
void Menu::handle(event ev)
{
    mouse_x=ev.pos_x;
    mouse_y=ev.pos_y;
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
    if (ev.type == ev_mouse && bennevandrop(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        drop = !drop;
    }
    if (ev.type == ev_mouse && ev.button == btn_wheeldown && indexeltol<options.size()-(drop_size)/(verticalsize))
    {
        indexeltol++;
        draw();
    }
    if (ev.type == ev_key && ev.keycode == key_space)
    {
        drop=!drop;
    }
    if (ev.type == ev_mouse && ev.button == btn_wheelup && indexeltol>0)
    {
        indexeltol--;
        draw();
    }
    for(size_t i=0;i<options.size();i++)
    {
        if(bennevanoption(mouse_x, mouse_y,i)&& i<(drop_size)/(verticalsize))
            marked1=i;
    }
     if (ev.type == ev_mouse && ev.button == btn_left && bennevanoption(mouse_x,mouse_y,marked1)&& is_selected2(mouse_x,mouse_y))
    {
        currentoption=options[marked1+indexeltol];
        draw();
        drop=false;
    }
}

std::string Menu::getValue()
{
    return currentoption;
}
std::vector<std::string> Menu::getElements()
{
    return options;
}

void Menu::setElements(std::vector<std::string> lista)
{
    options=lista;
    if(options.size()>0)
        currentoption=options[0];
    else
        currentoption="";
}

void Menu::loseFocus()
{
    drop = false;
}
bool Menu::isnt_statik()
{
    return 1;
}
void Menu::setPlayer(int p)
{

}
