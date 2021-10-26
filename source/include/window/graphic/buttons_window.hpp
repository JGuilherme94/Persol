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

class run_button
{
private:
    GtkWidget* _button;
    void run_image_analysis(GtkWidget* widget, gpointer data);
public:
    run_button(gchar* label, GtkWidget* parent_widget);
    ~run_button();
};