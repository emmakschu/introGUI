// Include the GTK headers
#include <gtk/gtk.h>

// Include my app headers
#include "firstapp.h"

int main (int argc, char *argv[])
{
    return g_application_run (G_APPLICATION (first_app_new ()), argc, argv);
}
