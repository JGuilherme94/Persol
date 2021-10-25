#include <gtk/gtk.h>

class load_button
{
private:
    GtkWidget* _button;
    void load_image(GtkWidget* widget, gpointer data);
public:
    load_button(gchar* label, GtkWidget* parent_widget);
    ~load_button();
};
