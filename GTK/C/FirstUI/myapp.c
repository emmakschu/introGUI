/*
 * mkschu:introGUI/GTK/C/FirstUI/myapp.c
 *
 * This file contains the C logic code for the FirstGUI application. As the
 * complexity increases, control of the UI will move to separate XML markup
 * files. Here we link to the markup file "builder.ui" with the gtk_builder
 * method.
 *
 * Author:   Michael K Schumacher
 * Created:  02-Nov-2016
 * Modified: 03-Nov-2016
 */

// Include the GTK headers
#include <gtk/gtk.h>

// Define a function to print a message on button 1 click
static void print_b1 (GtkWidget *widget, gpointer data)
{
    g_print ("Button 1 clicked!\n");
}

// Define a function to print a message on button 2 click
static void print_b2 (GtkWidget *widget, gpointer data)
{
    g_print ("Button 2 clicked!\n");
}

/*
 * The activate function is not needed this time, since we are linking to
 * the markup file for details on the UI components.
 */

int main (int argc, char *argv[])
{
    // Declare GTK builder, window and button objects
    GtkBuilder *builder;
    GObject *window;
    GObject *button;

    // Initialize gtk instance
    gtk_init (&argc, &argv);

    // Create new gtk_builder object, and add from the builder.ui file
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "builder.ui", NULL);

    // Create a window object and connect it to the gtk_main_quit method
    window = gtk_builder_get_object (builder, "window");
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    // Create a button with id button1 and connect to print_b1 function
    button = gtk_builder_get_object (builder, "button1");
    g_signal_connect (button, "clicked", G_CALLBACK (print_b1), NULL);

    // Create a button with id button2 and connect to print_b2 function
    button = gtk_builder_get_object (builder, "button2");
    g_signal_connect (button, "clicked", G_CALLBACK (print_b2), NULL);

    // Create a button with id quit and connect to gtk_main_quit method
    button = gtk_builder_get_object (builder, "quit");
    g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

    gtk_main();

    return 0;
}
