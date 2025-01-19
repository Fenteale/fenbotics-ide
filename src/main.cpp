#include "gui/fen_gui_init.h"
#include "docker/fen_docker.h"

// Main code
int main(int, char**)
{
    fen_docker fd;
    fd.list_docker_container();

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
