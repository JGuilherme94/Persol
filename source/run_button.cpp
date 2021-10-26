#include "include/window.hpp"

run_button::run_button(gchar* label, GtkWidget* parent_widget)
{
    _button = gtk_button_new_with_label(label);
    gtk_widget_set_size_request(_button, 100, 50);
    gtk_container_add(GTK_CONTAINER(parent_widget), _button);
    g_signal_connect(_button, "clicked", G_CALLBACK(&run_image_analysis), NULL);
    gtk_widget_show_all(_button);
}

run_button::~run_button()
{
}

void run_button::run_image_analysis(GtkWidget* widget, gpointer data)
{
    g_print("\nRunning...analysis!!!");
}