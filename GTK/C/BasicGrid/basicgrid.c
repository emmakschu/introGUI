/*
 * mkschu:introGUI/GTK/C/BasicGrid/basicgrid.c
 *
 * This program creates a simple 3-button grid window. Two of the buttons
 * will print a message to the console (assuming the program is run from the
 * command line), while the third will close the window and terminate the
 * program. Note that points and sizes on the grid follow standard Cartesian
 * numbering style (horizontal, vertical).
 *
 * Author:   Michael K Schumacher (Github, Bitbucket: mkschu)
 * Created:  02-Nov-2016
 * Modified: 02-Nov-2016
 */

// Include GTK headers
#include <gtk/gtk.h>

// Define a function to print a message for button 1
static void print_b1 (GtkWidget *widget, gpointer data)
{
    // The g_print method prints a message to the console
    g_print ("Button 1 clicked\n");
}

// Define a function to print a message for button 2
static void print_b2 (GtkWidget *widget, gpointer data)
{
    g_print ("Button 2 clicked\n");
}

// Define the activate function for the window
static void activate (GtkApplication *app, gpointer user_data)
{
    // Declare GTK widget objects
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;

    // Assign window properties
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Grid Example");
    gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    // Create a new grid and assign it to the window container
    grid = gtk_grid_new ();
    gtk_container_add (GTK_CONTAINER (window), grid);

    // Create a button and assign the button 1 click function
    button = gtk_button_new_with_label ("Button 1");
    g_signal_connect (button, "clicked", G_CALLBACK (print_b1), NULL);

    // Attach Button 1 to the grid at point (0,0) with size (1,1)
    gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

    // Create another button and assign the button 2 click function
    button = gtk_button_new_with_label ("Button 2");
    g_signal_connect (button, "clicked", G_CALLBACK (print_b2), NULL);

    // Attach button 2 to the grid at point (1,0) with size (1,1)
    gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);

    // Create another button and assign it to close window on click
    button = gtk_button_new_with_label ("Quit");
    g_signal_connect_swapped (button, "clicked",
            G_CALLBACK (gtk_widget_destroy), window);

    // Attach the Quit button to the grid at point (0,1) with size (2,1)
    gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);

    // Show the window and all attached content
    gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
    // Declare GtkApplication and status variable
    GtkApplication *app;
    int status;

    // Create new application object and assign activate function
    app = gtk_application_new ("com.github.mkschu.BasicGrid",
            G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    // Return status = 0 once window is closed to terminate program
    return status;
}
