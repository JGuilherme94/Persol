/**
 * @file main.cpp
 * @author Jose Guilherme Delacroix (DMiner)
 * @brief This is the program main entry point called every time it is executed.
 * @version 0.1
 * @date 2021-10-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/types_c.h>

#include <gtk/gtk.h>

#include <iostream>
#include <string>
#include <string.h>

#include "include/tools.hpp"
#include "include/window.hpp"
#include "include/performance/error_manager.hpp"

#define MIN_NUMBER_OF_ARGUMENTS 1

using namespace std;

main_window* _main_window;
load_button* _main_window_load_button;
image_display* _main_window_image_display;
int phase = 0;

int main(int argc, char** argv)
{
  if (argc <= MIN_NUMBER_OF_ARGUMENTS) error_message(error_type::arguments_number);
  gtk_init(&argc, &argv);
  do
  {
    g_print("PHASE: %i\n", phase);
    _main_window = new main_window(argv[0]);
    _main_window_load_button = new load_button("Load", _main_window->get_widget_pointer_reference());
    _main_window_image_display = new image_display("resources\\cnh_for_analysis.JPG", _main_window->get_widget_pointer_reference());
    gtk_main();
    phase++;
  } while (argv[argc] != "exit");
  error_message(error_type::no_error);
};