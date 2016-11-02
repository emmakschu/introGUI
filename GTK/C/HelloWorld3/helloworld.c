/*
 * mkschu:introGUI/GTK/C/HelloWorld3/helloworld.c
 *
 * This program will add yet more complexity to the Hello World application
 * by printing the "Hello World" message in a button which, when clicked,
 * will close the window and terminate the application.
 *
 * Author:   Michael K Schumacher (Github, Bitbucket: mkschu)
 * Created:  02-Nov-2016
 * Modified: 02-Nov-2016
 */

// Include the GTK headers
#include <gtk/gtk.h>

// Define function to print message into button object
static void print_hello (GtkWidget *widget, gpointer data)
{
    g_print ("Hello World\n");
}

// Define the app's activate function
static void activate (GtkApplication *app, gpointer user_data)
{
    // Declare widget pointers for window, button, and button box
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button_box;

    // Assign window values
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Hello World");
    gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);

    // Assign button_box values and add to window container
    button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add (GTK_CONTAINER (window), button_box);

    // Assign button values, connect click to close, and add to window
    button = gtk_button_new_with_label ("Hello World");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    g_signal_connect_swapped (button, "clicked",
            G_CALLBACK (gtk_widget_destroy), window);
    gtk_container_add (GTK_CONTAINER (button_box), button);

    // Show widgets
    gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
    // Declare GtkApplication and status variable
    GtkApplication *app;
    int status;

    // Assign GtkApplication pointer to new app
    app = gtk_application_new ("com.github.mkschu.HelloWorld3",
            G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    // Return status to terminate program when window is closed
    return status;
}
