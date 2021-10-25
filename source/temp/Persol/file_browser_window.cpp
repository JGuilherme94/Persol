#include "include/GTK_window.hpp"

using namespace std;

#pragma region | "class file browser window"

#pragma region | "contructors"

file_browser_window::file_browser_window(window_file_browser browser_struct_data)
{

}
    
file_browser_window::file_browser_window(bool topmost, std::string title, GtkWidget* parent)
{
    browser_struct_data.topmost = topmost;
    //browser_struct_data.title = title;
    browser_struct_data.parent = parent;
    browser_struct_data.browser = gtk_file_chooser_dialog_new ("File Browser", nullptr, browser_struct_data.action, ("_Cancel"), GTK_RESPONSE_CANCEL, ("_Open"), GTK_RESPONSE_ACCEPT, NULL);
    browser_struct_data.response = gtk_dialog_run (GTK_DIALOG (browser_struct_data.browser));
}

file_browser_window::~file_browser_window()
{
    gtk_widget_destroy (browser_struct_data.browser);
    g_free(chosen_file);
    gtk_main_quit();
}

#pragma endregion "contructors"

#pragma region | "functions"

/*void file_browser_window::on_response (GtkNativeDialog *native, int response)
{
    if (response == GTK_RESPONSE_ACCEPT)
    {
      GtkFileChooser *chooser = GTK_FILE_CHOOSER (native);
      file = gtk_file_chooser_get_file (chooser);

      if ( g_file_get_path(file) == NULL) g_free (file); return;

      g_print ("file found: %s\n", g_file_get_path(file));
      g_object_unref (file);
    }
    else
    {
      g_print ("response failed !!!");
    }

  g_object_unref (native);
}*/

#pragma endregion "functions"

#pragma endregion "class file browser window"