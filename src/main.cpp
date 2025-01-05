#include "gui/fen_gui_init.h"

// Main code
int main(int, char**)
{
    fen_gui_init fg;

#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_BEGIN {
      fg.loop();
#else
    while (fg.loop()) {
#endif

    }

    return 0;
}
