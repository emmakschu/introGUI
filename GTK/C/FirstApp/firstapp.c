#include <gtk/gtk.h>

#include "firstapp.h"
#include "firstappwin.h"

struct _FirstApp
{
    GtkApplication parent;
};

G_DEFINE_TYPE (FirstApp, first_app, GTK_TYPE_APPLICATION);

static void first_app_init (FirstApp *app)
{
}

static void first_app_activate (GApplication *app)
{
    FirstAppWindow *win;

    win = first_app_window_new (FIRST_APP (app));
    gtk_window_present (GTK_WINDOW (win));
}
