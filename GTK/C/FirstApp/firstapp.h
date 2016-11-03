#ifndef __FIRSTAPP_H
#define __FIRSTAPP_H

#include <gtk/gtk.h>

#define FIRST_APP_TYPE (first_app_get_type ())
G_DECLARE_FINAL_TYPE (FirstApp, first_app, FIRST, APP, GtkApplication)

FirstApp *first_app_new (void);

#endif /* __FIRSTAPP_H */
