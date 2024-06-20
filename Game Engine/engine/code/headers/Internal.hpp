
// This is free code released into the public domain.
// Drafted by �ngel in January 2019.
// angel.rodriguez@esne.edu

#pragma once

// Se crean declaraciones adelantadas de algunos identificadores de librer�as externas
// que se usan en las cabeceras del engine para que en los proyectos en los que se
// incluyan �stas no sea necesario a�adir las cabeceras de las librer�as externas.

///////////////////////////////////////// SDL /////////////////////////////////////////

typedef struct SDL_Window   SDL_Window;
typedef void* SDL_GLContext;

/////////////////////////////////// OPENGL TOOLKIT ////////////////////////////////////

namespace glt
{

    class Render_Node;

}
