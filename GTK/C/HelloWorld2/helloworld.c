/*
 * mkschu:introGUI/GTK/C/HelloWorld2/helloworld.c
 *
 * This program builds on the complexity of the basic Hello World window,
 * minimizing the main function by moving most of the window details into
 * a separate function (which will eventually use separate source and header)
 * files). This will create an 800x600 window titled "Hello World" with the
 * application ID "com.github.mkschu.HelloWorld2".
 *
 * Author:   Michael K Schumacher (Github, Bitbucket: mkschu)
 * Created:  02-Nov-2016
 * Modified: 02-Nov-2016
 */

// Include the GTK+ header file
#include <gtk/gtk.h>

// Create function describing the window details
static void activate (GtkApplication* app, gpointer user_data)
{
    // Declare GtkWidget object variable
    GtkWidget *window;

    // Set object to new application window
    window = gtk_application_window_new (app);

    // Set title and default window size
    gtk_window_set_title (GTK_WINDOW (window), "Hello World");
    gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);

    // Show the window object
    gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
    // Declare GtkApplication object and status variable
    GtkApplication *app;
    int status;

    // Assign GtkApplication object to new gtk_application
    app = gtk_application_new ("com.github.mkschu.HelloWorld2",
            G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

    // Check the status of the app
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    // Return status to terminate program when window is closed.
    return status;
}
