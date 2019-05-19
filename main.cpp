#include "graphics.hpp"
#include "widgets.hpp"
#include "num_change.hpp"
#include "menu.hpp"
#include "checkbox.hpp"
#include "statik.hpp"
#include "dinamik.hpp"
#include "push_button.hpp"
#include "application.hpp"
#include "amoba_logic.hpp"
#include <cstdlib>
#include <vector>
#include <math.h>
#include <fstream>
#include <functional>
#include <iostream>
using namespace genv;
using namespace std;

int main()
{
    Application * application = new Application(680,850);
    application->event_loop();

    return 0;
}
