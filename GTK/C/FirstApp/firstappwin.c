#include <gtk/gtk.h>

#include "firstapp.h"
#include "firstappwin.h"

struct _FirstAppWindow
{
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE (FirstAppWindow, first_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void first_app_window_init (FirstAppWindow *app)
{
}

static void first_app_window_class_init (FirstAppWindowClass *class)
{
}

FirstAppWindow * first_app_window_new (FirstApp *app)
{
    return g_object_new (FIRST_APP_WINDOW_TYPE, "application", app, NULL);
}

void first_app_window_open (FirstAppWindow *win, GFile *file)
{
}
