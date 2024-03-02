#include <iostream>
#include <random>

using namespace std;

const int MIN_INDEX_OF_UPPERCASE_LETTERS = 65;
const int MAX_INDEX_OF_UPPERCASE_LETTERS = 90;
const int MIN_INDEX_OF_LOWERCASE_LETTERS = 97;
const int MAX_INDEX_OF_LOWERCASE_LETTERS = 122;
const int MIN_INDEX_OF_NUMBERS = 48;
const int MAX_INDEX_OF_NUMBERS = 57;

char generate_random_symbol(int min, int max)
{
    random_device random_device;
    mt19937 gen(random_device());

    uniform_int_distribution<> dis(min, max);

    int random_number = dis(gen);
    char random_character = (char) random_number;
    return random_character;
}

int generate_random_sequence()
{
    random_device random_device;
    mt19937 gen(random_device());

    uniform_int_distribution<> dis(1, 3);
    int random_sequence = dis(gen);
    return random_sequence;
}

void add_symbol_to_password(string &password, int random_sequence)
{
    if (random_sequence == 1)
    {
        char random_uppercase_symbol = generate_random_symbol(MIN_INDEX_OF_UPPERCASE_LETTERS,
                                                              MAX_INDEX_OF_UPPERCASE_LETTERS);
        password.push_back(random_uppercase_symbol);
    }
    if (random_sequence == 2)
    {
        char random_lowercase_symbol = generate_random_symbol(MIN_INDEX_OF_LOWERCASE_LETTERS,
                                                              MAX_INDEX_OF_LOWERCASE_LETTERS);
        password.push_back(random_lowercase_symbol);
    }
    if (random_sequence == 3)
    {
        char random_number_symbol = generate_random_symbol(MIN_INDEX_OF_NUMBERS,
                                                           MAX_INDEX_OF_NUMBERS);
        password.push_back(random_number_symbol);
    }
}

string generate_password(int length)
{
    string password;

    for (int i = 0; i < length; i++)
    {
        int random_sequence = generate_random_sequence();
        add_symbol_to_password(password, random_sequence);
    }

    return password;
}

int main()
{
    cout << "Hello, this is an application for generating passwords! You are welcome!" << endl;
    cout << "If you want to generate password, enter - 1, otherwise - enter 2." << endl;

    int operation;

    cin >> operation;

    if (operation == 2)
    {
        cout << "Thank you! Goodbye!" << endl;
        return 0;
    }


    if (operation != 1)
    {
        throw runtime_error("Invalid operation");
    }

    cout << "Okay, the next step is to determine the length of the password!" << endl;
    cout << "Please, enter a desired length of password! (from 6 to 20)" << endl;

    int length_password;

    cin >> length_password;

    if (length_password < 6 || length_password > 20)
    {
        throw runtime_error("The max length of password is 20. The min length of password is 6.");
    }

    cout << "Okay, the process of generating password is happening..." << endl;

    string password = generate_password(length_password);

    cout << "Your generated password: " << password << endl;
    cout << "Thank you for trusting us! Have a nice day!" << endl;
}