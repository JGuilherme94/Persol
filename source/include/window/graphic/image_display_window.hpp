#include <gtk/gtk.h>

class image_display
{
private:
    GtkWidget* _display;
public:
    image_display(const gchar* filepath, GtkWidget* parent_widget);
    ~image_display();
};