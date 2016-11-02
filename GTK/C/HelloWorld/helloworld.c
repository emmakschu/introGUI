/*
 * mkschu:introGUI/GTK/C/HelloWorld/helloworld.c
 *
 * This is an example of the bare minimum C application to use GTK+ 3.0 to
 * launch a window with the title "Hello World". Further programs will build
 * on this to add to the complexity of the standard Hello World program.
 *
 * Author:   Michael K Schumacher (Github, Bitbucket: mkschu)
 * Created:  02-Nov-2016
 * Modified: 02-Nov-2016
 */

// Include the GTK+ headers
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    // Declare a GTK window variable
    GtkWidget *window;

    // Initialize the GTK object
    gtk_init (&argc, &argv);

    // Initialize the window object as GTK top-level window
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    // Set the window title, and show it
    gtk_window_set_title (GTK_WINDOW (window), "Hello World");
    gtk_widget_show (window);
    gtk_main();

    // Exit the C program's main function
    return 0;
}
