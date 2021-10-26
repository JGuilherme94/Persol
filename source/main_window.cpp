#include "include/window.hpp"

main_window::main_window(gchar* title)
{
    _window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(_window), title);
    gtk_window_set_default_size(GTK_WINDOW(_window), 550, 550);
    _window_vertical_box = gtk_vbox_new(FALSE, 5);
    _window_horizontal_box = gtk_hbox_new(FALSE, 5);
    _window_vertical_tools_box = gtk_vbox_new(FALSE, 0);
    //gtk_container_add(GTK_CONTAINER(_window_vertical_box), _window_horizontal_box);
    //gtk_container_add(GTK_CONTAINER(_window_horizontal_box), _window_vertical_tools_box);
    gtk_container_add(GTK_CONTAINER(_window), _window_vertical_box);
    gtk_box_pack_start(GTK_BOX(_window_vertical_box), _window_horizontal_box, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(_window_horizontal_box), _window_image_display_box, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(_window_horizontal_box), _window_vertical_tools_box, TRUE, TRUE, 0);
    //gtk_container_add(GTK_WINDOW(_window), _window_childs_pack);
    gtk_widget_show_all(_window);
}

main_window::~main_window()
{
}

GtkWidget* main_window::get_windows_vertical_box()
{
    return _window_vertical_box;
}

GtkWidget* main_window::get_windows_horizontal_box()
{
    return _window_horizontal_box;
}

GtkWidget* main_window::get_window_image_display_box()
{
    return _window_image_display_box;
}

GtkWidget* main_window::get_windows_tools_box()
{
    return _window_vertical_tools_box;
}
/*
GtkWidget* main_window::find_child_by_name(GtkWidget* parent, const gchar* name)
{
    if (g_strcmp0(gtk_widget_get_name(parent), name) == 0)
        return parent;

    GList* children = NULL;
    if (GTK_IS_CONTAINER(parent))
        children = gtk_container_get_children(GTK_CONTAINER(parent));

    while (children != NULL)
    {
        GtkWidget* widget = find_child_by_name(children->data, name);

        if (widget != NULL)
            return widget;

        children = children->next;
    }

    return NULL;
}

void main_window::print_children(GtkWidget* parent, int indent_size, int depth)
{
    for (int i = 0; i < depth * indent_size; i++)
        printf(" ");
    printf("%s\n", gtk_widget_get_name(parent));

    GList* children = NULL;
    if (GTK_IS_CONTAINER(parent))
        children = gtk_container_get_children(GTK_CONTAINER(parent));

    while (children != NULL)
    {
        print_children(children->data, indent_size, depth + 1);
        children = children->next;
    }
}

GtkWidget* main_window::find_child_by_index(GtkWidget* parent, int depth, ...)
{
    va_list argp;
    va_start(argp, depth);

    for (int i = 0; i < depth; i++)
    {
        int index = va_arg(argp, int);

        GList* children = NULL;
        if (GTK_IS_CONTAINER(parent))
            children = gtk_container_get_children(GTK_CONTAINER(parent));

        for (int j = 0; j < index; j++)
            if (children != NULL)
                children = children->next;

        if (children != NULL)
            parent = children->data;
        else
            return NULL;
    }

    va_end(argp);
    return parent;
}*/