
#include "ft.h"  // Assuming your header file is named "ft.h" and contains necessary declarations

t_dict	*parse_dictionary(const char *filename);
char	*con_lett(int number, t_dict *dictionary);

int main(void)
{
    t_dict *dictionary;  // Assuming you have a struct t_dict defined

    dictionary = parse_dictionary("numbers.dict");
    if (dictionary == NULL)
    {
        printf("Error parsing the dictionary.\n");
        return 1;  // Return an error code
    }
    // Test cases
    int test_numbers[] = {91};  // Replace these with the numbers you want to convert

    for (size_t i = 0; i < sizeof(test_numbers) / sizeof(test_numbers[0]); i++)
    {
        int current_number = test_numbers[i];
        char *result = con_lett(current_number, dictionary);

        if (result != NULL)
        {
            printf("Number %d in words: %s\n", current_number, result);
            free(result);  // Don't forget to free the allocated memory
        }
        else
        {
            printf("Error converting number %d to words.\n", current_number);
        }
    }

    free_dictionary(dictionary); // Clean up resources, e.g., free_dictionary(&dictionary);

    return 0;
}

