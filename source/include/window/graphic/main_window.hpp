#include <gtk/gtk.h>

class main_window
{
private:
    GtkWidget* _window;
    GtkWidget* _window_childs_pack;
public:
    main_window(gchar* title);
    ~main_window();
    GtkWidget* get_widget_pointer_reference();
    void print_children(GtkWidget* parent, int indent_size, int depth);
    GtkWidget* find_child_by_name(GtkWidget* parent, const gchar* name);
    GtkWidget* find_child_by_index(GtkWidget* parent, int depth, ...);
};