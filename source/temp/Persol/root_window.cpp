#include "include/GTK_window.hpp"

using namespace std;

#pragma region | "class root window" 

#pragma region | "contructors"

root_window::root_window(window_root window_struct_data)
{

}

root_window::root_window(bool topmost, string title)
{
    window_struct_data.topmost = topmost;
    //window_struct_data.title;
    if (window_struct_data.topmost)
    {
        window_struct_data.window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    }
    else
    {
        window_struct_data.window = gtk_window_new (GTK_WINDOW_POPUP);
    }
    //gtk_window_set_title(GTK_WINDOW (window_struct_data.window), *window_struct_data.title);
    window_struct_data.button_load = gtk_button_new_with_label("load");
    gtk_container_add(GTK_CONTAINER (window_struct_data.window), window_struct_data.button_load);
    gtk_widget_show_all(window_struct_data.window);
    g_signal_connect(window_struct_data.button_load, "clicked", GCallback(&open_load_window), NULL);
}

root_window::~root_window()
{

}

#pragma endregion "contructors"

#pragma region | "functions"

void root_window::open_load_window(GtkWidget* window, gpointer data)
{
    //g_print ("button is pressed\n");
    file_browser = new file_browser_window(false, "file browser", nullptr);
    //file_path = get_loaded_file_path();
}

#pragma endregion "functions"

#pragma endregion class root window