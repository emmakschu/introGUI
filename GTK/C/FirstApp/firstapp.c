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

static void first_app_open (GApplication *app,
                            GFile **files,
                            gint n_files,
                            const gchar *hint)
{
    GList *windows;
    FirstAppWindow *win;
    int i;

    windows = gtk_application_get_windows (GTK_APPLICATION (app));
    if (windows)
        win = FIRST_APP_WINDOW (windows->data);
    else
        win = first_app_window_new (FIRST_APP (app));

    for (i = 0; i < n_files; i++)
        first_app_window_open (win, files[i]);

    gtk_window_present (GTK_WINDOW (win));
}
