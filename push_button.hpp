#ifndef PUSH_BUTTON_HPP_INCLUDED
#define PUSH_BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string.h>
#include <functional>

class Push_Button : public Widget {
protected:
    int keretvastagsag=2;
    std::function <void()>_f;
    std::string _t;
public:
    Push_Button(int x, int y, int xmeret, int ymeret, std::function<void()>f, std::string text);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool isnt_statik();
    virtual void loseFocus();
    virtual void setPlayer(int p);
private:
    virtual bool bennevan(int x, int y);
};
#endif // PUSH_BUTTON_HPP_INCLUDED

