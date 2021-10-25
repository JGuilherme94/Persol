#include <gtk/gtk.h>

#include <string>
#include <string.h>

#pragma region | "delegates"



#pragma endregion "delegates"

#pragma region | "classes"

class root_window;
class file_browser_window;

#pragma endregion "classes"

#pragma region | "class root window"

struct window_root
{
    bool topmost = false;
    GString title;
    GtkWidget* parent = NULL;
    GtkWidget* children = nullptr;
    GtkWidget* window = nullptr;
    GtkWidget* button_load = nullptr;
};

class root_window
{
private:
    void open_load_window(GtkWidget* window, gpointer data);
protected:
    window_root window_struct_data;
    file_browser_window* file_browser;
public:
    root_window(window_root window_struct_data);
    root_window(bool topmost, std::string title);
    ~root_window();
    gchar* file_path;
};

#pragma endregion "class root window"

#pragma region | "class file browser window"

struct window_file_browser
{
    bool topmost = false;
    bool attached = false;
    GString title;
    GtkWidget* parent = nullptr;
    GtkWidget* browser = nullptr;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint response = 0;
}; 

class file_browser_window
{
private:
    //void on_response (GtkNativeDialog *native, int response);
protected:
    window_file_browser browser_struct_data;
public:
    file_browser_window (window_file_browser browser_struct_data);
    file_browser_window (bool topmost, std::string title, GtkWidget* parent);
    ~file_browser_window ();
    GFile* chosen_file;
    gchar* get_file_path ();
};

#pragma endregion "class file browser window"

#pragma region | "class image window"

struct window_image
{
    bool topmost = false;
    bool attached = false;
    GString title;
    GtkWidget* parent = nullptr;
    GtkWidget* image = nullptr;
};

#pragma endregion "class image window"