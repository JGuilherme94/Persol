#include <string>

enum error_type 
{
    no_error = 0,
    arguments_number = -1,
    invalid_argument = -2,
};
static const char* error_type_char_pointer[] = 
{
    "no error. SUCCESS!!!",
    "insuficient number of arguments",
    "invalid argument",
};
static void error_message(error_type type)
{
    switch(type)
    {
        case no_error: printf("Build = %i: %s\n", type, error_type_char_pointer[-type]); break;
        default: printf("Fatal Error = %i: %s\n", type, error_type_char_pointer[-type]); break;
    }
    system("pause");
    exit(type);
}
