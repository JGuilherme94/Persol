#include "include/window.hpp"

image_display::image_display(const gchar* filepath, GtkWidget* parent_widget)
{
    _display = gtk_image_new_from_file(filepath);
    gtk_container_add(GTK_CONTAINER(parent_widget), _display);
    //g_signal_connect(_display, "clicked", G_CALLBACK(&load_image), NULL);
    gtk_widget_show_all(_display);
}

image_display::~image_display()
{
}