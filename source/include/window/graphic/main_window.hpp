#include <gtk/gtk.h>

class main_window
{
private:
    GtkWidget* _window;
    GtkWidget* _window_vertical_box;
    GtkWidget* _window_horizontal_box;
    GtkWidget* _window_image_display_box;
    GtkWidget* _window_vertical_tools_box;
public:
    main_window(gchar* title);
    ~main_window();
    GtkWidget* get_windows_vertical_box();
    GtkWidget* get_windows_horizontal_box();
    GtkWidget* get_window_image_display_box();
    GtkWidget* get_windows_tools_box();
    /*void print_children(GtkWidget* parent, int indent_size, int depth);
    GtkWidget* find_child_by_name(GtkWidget* parent, const gchar* name);
    GtkWidget* find_child_by_index(GtkWidget* parent, int depth, ...);*/
};