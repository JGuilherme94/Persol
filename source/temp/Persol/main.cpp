/**
 * @file main.cpp
 * @author Jose Guilherme Delacroix (Dminer)
 * @brief This is the program main entry point execute avery time the program is called
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "include/GTK_window.hpp"
#include "include/CV_analysis.hpp"

using namespace std;

static bool main_loop_run = true;
root_window* root;
cnh_analysis* cnh;
gchar* file_selected_path;

int main (int argc, char **argv)
{
  gtk_init (&argc, &argv);
  root = new root_window(true, argv[0]);
  if (root == nullptr) return 0;
  main_loop_run = true;
  do
  { 
    cnh = new cnh_analysis("resources\\Pernalonga.jfif");
    if (cnh->is_valid()) g_print ("is cnh: %s\n", "resources\\cnh_for_analysis.JPG");
    else g_print ("is not cnh: %s\n", "resources\\cnh_for_analysis.JPG");
    g_print ("pre main!!!\n");
    gtk_main();
    g_print ("pos main!!!\n");

    //file_selected_path = ;
    //g_print ("pos main!!! file_selected_path: %s\n", file_selected_path);
    
    //
    
    //cnh = new cnh_analysis(file_selected_path.c_str());
    //main_loop_run = false;
  } while (main_loop_run);
  return 0;
}