
//Obsolete

#if defined(_WIN32) || defined(_WIN64)

    #include <windows.h>

    extern int main (int , char ** ); //ignorar a visual esto compila

    int WINAPI WinMain (HINSTANCE , HINSTANCE , LPSTR , INT )
    {
        return main (__argc, __argv);
    }

#endif
