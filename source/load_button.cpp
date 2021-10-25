#include "include/window.hpp"

load_button::load_button(gchar* label, GtkWidget* parent_widget)
{
    _button = gtk_button_new_with_label(label);
    gtk_container_add(GTK_CONTAINER(parent_widget), _button);
    g_signal_connect(_button, "clicked", G_CALLBACK(&load_image), NULL);
    gtk_widget_show_all(_button);
}

load_button::~load_button()
{
}

void load_button::load_image(GtkWidget* widget, gpointer data)
{
    g_print("load_button");
}