#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <string.h>

class Menu : public Widget {
protected:
    bool _checked;
    std::vector <std::string> options;
public:
    Menu(int x, int y, int xmeret, int ymeret1,int ymeret2, std::vector<std::string> _options);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_selected(int x, int y);
    virtual bool isnt_statik();

    virtual std::string getValue();
    virtual std::vector<std::string> getElements();
    virtual void setElements(std::vector<std::string> lista);

    virtual void loseFocus();
    virtual void setPlayer(int p);
private:
    virtual bool bennevandrop(int x, int y);
    virtual bool bennevanoption(int x, int y, int iteration);
    virtual bool is_selected2(int x, int y);

    const static int keretvastagsag=2;
    const static int nyileltolas=25;
    const static int text_height=20;
    const static int stringstarter=5;
    int verticalsize=genv::gout.cascent()+genv::gout.cdescent()+2;
    int drop_size;
    int indexeltol=0;
    int iteration=0;
    int mouse_x;
    int mouse_y;
    int marked1=0;
    bool drop;
    std::string currentoption="";
};


#endif // MENU_HPP_INCLUDED

