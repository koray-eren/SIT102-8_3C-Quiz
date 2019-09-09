#include "splashkit.h"
#include <string>
#include <vector>
using std::vector;
using namespace std;

// function that reads in a line of texts and returns this as a string
string read_string(string prompt)
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}

// function that reads in a number string and returns this as an integer
int read_integer(string prompt)
{
    string line;
    int result;

    line = read_string(prompt);

    while (! is_integer(line))
    {
        write_line("Please enter a whole number:");
        line = read_string(prompt);
    }

    result = convert_to_integer(line);

    return result;
}

struct computer
{
    string name;
    int id;
    int count;
};

computer read_computer()
{
    computer result;
    result.name = read_string("Enter a computer name: ");
    result.id = read_integer("Enter a computer ID: ");
    result.count = read_integer("Enter a computer count: ");
    return result;
}

// prints computer name, id, and stock level based on count (low being less than 5)
void print_computer(const computer &computer_input)
{
    write_line(computer_input.name + " (" + to_string(computer_input.id) + ")");
    if (computer_input.count == 0)
    {
        write_line("Count: Out of stock");
    }
    else if (computer_input.count < 5)
    {
        write_line("Count: Low stock");
    }
    else
    {
        write_line("Count: In stock");
    }
    write_line();
}

int total_count(const vector<computer> &computers)
{
    int sum = 0;
    for (int i = 0; i < computers.size(); i++)
    {
        sum = sum + computers[i].count;
    }
    
    return sum;
}

int index_of_computer_with_id(const vector<computer> &computers, int search_id)
{
    for (int i = 0; i < computers.size(); i++)
    {
        if (computers[i].id == search_id)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<computer> computer_array_1;
    vector<computer> computer_array_2;
    int i, computer_id;
    write_line("-- Enter Array 1 Computer Data --");
    for (i = 0; i < 7; i++)
    {
        computer_array_1.push_back( read_computer() );
    }

    write_line("-- Enter Array 2 Computer Data --");
    for (i = 0; i < 4; i++)
    {
        computer_array_2.push_back( read_computer() );
    }

    write_line("-- Computer Array 1 --");
    for (i = 0; i < computer_array_1.size(); i++)
    {
        print_computer(computer_array_1[i]);
    }
    write("Total count of computers in computer_array_1: ");
    write_line( total_count(computer_array_1) );
    write_line();
    
    write_line("-- Computer Array 2 --");
    for (i = 0; i < computer_array_2.size(); i++)
    {
        print_computer(computer_array_2[i]);
    }
    write("Total count of computers in computer_array_2: ");
    write_line( total_count(computer_array_2) );
    write_line();

    computer_id = read_integer("Enter a computer ID to of a computer to print, or enter '0' to quit: ");
    while (computer_id != 0)
    {
        int search_result;

        search_result = index_of_computer_with_id(computer_array_1, computer_id);
        if (search_result >= 0)
        {
            write_line("computer_array_1 results: ");
            print_computer( computer_array_1[search_result] );
        }
        else
        {
            write_line("The selected computer ID was not found in computer_array_1.");
        }
        

        search_result = index_of_computer_with_id(computer_array_2, computer_id);
        if (search_result >= 0)
        {
            write_line("computer_array_2 results: ");
            print_computer( computer_array_2[search_result] );
        }
        else
        {
            write_line("The selected computer ID was not found in computer_array_2.");
        }
        computer_id = read_integer("Enter a computer ID to of a computer to print, or enter '0' to quit: ");
    }
    return 0;
}
