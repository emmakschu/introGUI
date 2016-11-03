#ifndef __FIRSTAPPWIN_H
#define __FIRSTAPPWIN_H

#include <gtk/gtk.h>
#include "firstapp.h"

#define FIRST_APP_WINDOW_TYPE (first_app_window_get_type ())
G_DECLARE_FINAL_TYPE (FirstAppWindow, first_app_window, FIRST, APP_WINDOW,
        GtkApplicationWindow)

FirstAppWindow *first_app_window_new (FirstApp *app);
void first_app_window_open (FirstAppWindow *win, GFile *file);

#endif /* __FIRSTAPPWIN_H */
