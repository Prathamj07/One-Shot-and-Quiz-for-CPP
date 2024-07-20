#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


int score = 0;

class Quiz {
public:
    void header() {
        cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "\t\t\t QUIZ GAME " << endl;
        cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
    }

    void footer() {
        cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "\t\t\tRESULTS " << endl;
        cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
    }

    void user() {
        string name;
        cout << "\nGuest Enter Your Name : ";
        cin >> name;
        cout << "\nWelcome " << name << endl;
    }

    void results(int totalQuestions, int correctQuestions) {
        int score = ((correctQuestions * 10) / totalQuestions);

        if (score == 100)
            cout << " \n Excellent! You got a perfect score of 100%." << endl;
        else if (score >= 90)
            cout << " \n Great job! Your Score is " << score << "%." << endl;
        else if (score >= 80)
            cout << " \n Well done! Your Score is " << score << "%." << endl;
        else if (score >= 40)
            cout << " \n You can do better. Your Score is " << score << "%. Better luck next time." << endl;
        else
            cout << " \n You need to work harder. Your Score is " << score << "%. Keep learning." << endl;
    }
};

void QUIZ() {
    char answer;
    Quiz quiz;
    quiz.user();
    quiz.header();

    srand(static_cast<unsigned int>(time(nullptr))); // Initialize the random number generator

    // Define a set of questions and answers
    vector<pair<string, char>> questions = {
        {"Q. What is the primary purpose of the 'int main()' function in a C++ program?\n\ta. To declare integer variables\n\tb. To print output to the console\n\tc. To specify the program's entry point", 'c'},
        {"Q. Which C++ data type is used to store single characters?\n\ta. int\n\tb. char\n\tc. string", 'b'},
        {"Q. What does 'cout' represent in C++?\n\ta. Input stream\n\tb. Output stream\n\tc. File handling", 'b'},
        {"Q. In C++, which of the following is used to allocate dynamic memory?\n\ta. new\n\tb. malloc\n\tc. allocate", 'a'},
        {"Q. What is the purpose of the 'if' statement in C++?\n\ta. To perform conditional execution\n\tb. To declare a variable\n\tc. To define a loop", 'a'},
        {"Q. Which operator is used for logical AND in C++?\n\ta. &&\n\tb. ||\n\tc. !", 'a'},
        {"Q. What is the scope resolution operator in C++ denoted as?\n\ta. ::\n\tb. .\n\tc. ->", 'a'},
        {"Q. Which C++ keyword is used to define a class?\n\ta. class\n\tb. struct\n\tc. object", 'a'},
        {"Q. What is a pointer in C++?\n\ta. A variable that stores the memory address of another variable\n\tb. A reference to a class object\n\tc. A type of data structure", 'a'},
        {"Q. What is the purpose of the 'break' statement in C++?\n\ta. To end a loop prematurely\n\tb. To declare a variable\n\tc. To skip the current iteration of a loop", 'a'},
        {"Q. What is the symbol for the modulos operator in C++?\n\ta. %\n\tb. /\n\tc. *", 'a'},
        {"Q. What is the 'this' pointer in C++ used for?\n\ta. It points to the previous function\n\tb. It points to the current class object\n\tc. It is used for memory allocation", 'b'},
        {"Q. In C++, how can you include the contents of a header file in your program?\n\ta. #include <file.h>\n\tb. #import <file.h>\n\tc. #require <file.h>", 'a'},
        {"Q. What is the C++ operator used to access the member functions and variables of an object?\n\ta. . (dot)\n\tb. -> (arrow)\n\tc. :: (scope resolution)", 'b'},
        {"Q. What is the purpose of the 'else' statement in C++?\n\ta. To begin a loop\n\tb. To define a class\n\tc. To specify an alternative code block to execute when an 'if' condition is false", 'c'},
        {"Q. What is the data type of the elements in a C++ array?\n\ta. int\n\tb. char\n\tc. Depends on the type of elements stored in the array", 'c'},
        {"Q. How is a C++ reference different from a pointer?\n\ta. References cannot be changed after initialization\n\tb. Pointers cannot be used in function parameters\n\tc. Pointers are used to access arrays", 'a'},
        {"Q. What is the C++ operator for the multiplication of two numbers?\n\ta. +\n\tb. -\n\tc. *", 'c'},
        {"Q. Which C++ keyword is used to create a new instance of a class?\n\ta. create\n\tb. new\n\tc. instance", 'b'},
        {"Q. What is the primary purpose of a C++ constructor?\n\ta. To initialize the object's member variables\n\tb. To perform mathematical calculations\n\tc. To free memory", 'a'},
        {"Q. Which C++ keyword is used to define a function that does not return a value?\n\ta. void\n\tb. return\n\tc. null", 'a'},
        {"Q. What is the C++ 'const' keyword used for?\n\ta. To define a constant value\n\tb. To create an infinite loop\n\tc. To declare a variable", 'a'},
        {"Q. In C++, what is the purpose of the 'for' loop?\n\ta. To perform a specific task once\n\tb. To execute a block of code repeatedly while a condition is true\n\tc. To define a class", 'b'},
        {"Q. What is the difference between 'while' and 'do-while' loops in C++?\n\ta. 'while' loops are used for input, and 'do-while' loops are used for output\n\tb. 'do-while' loops always execute at least once, while 'while' loops may not execute at all\n\tc. There is no difference; they are used interchangeably", 'b'},
        {"Q. Which C++ keyword is used to exit a loop prematurely?\n\ta. continue\n\tb. stop\n\tc. break", 'c'},
        {"Q. What is the syntax for a single-line comment in C++?\n\ta. // This is a comment\n\tb. /* This is a comment */\n\tc. # This is a comment", 'a'},
        {"Q. How can you compare two strings for equality in C++?\n\ta. Using the '==' operator\n\tb. Using the 'compare' function\n\tc. Strings cannot be compared in C++", 'a'},
        {"Q. What is the C++ keyword used to define a conditional switch-case statement?\n\ta. switch\n\tb. case\n\tc. if", 'a'},
        {"Q. What is the C++ operator used to access the memory location of a variable?\n\ta. & (address-of)\n\tb. * (pointer)\n\tc. :: (scope resolution)", 'a'},
        {"Q. What is the 'sizeof' operator in C++ used for?\n\ta. To determine the size of an array\n\tb. To calculate the square root of a number\n\tc. To find the size, in bytes, of a data type or object", 'c'},
        {"Q. Which C++ standard library header is used for input and output operations?\n\ta. <iostream>\n\tb. <math.h>\n\tc. <string>", 'a'},
        {"Q. What is the purpose of the 'const' qualifier in a C++ function declaration?\n\ta. To indicate that the function is constant and cannot be modified\n\tb. To specify a constant return type for the function\n\tc. To restrict the use of the function to specific conditions", 'a'},
        {"Q. What does 'cin' represent in C++?\n\ta. Output stream\n\tb. Input stream\n\tc. File handling", 'b'},
        {"Q. What is the C++ keyword used to define a function that returns a value?\n\ta. void\n\tb. return\n\tc. null", 'b'},
        {"Q. In C++, what is the purpose of the 'do-while' loop?\n\ta. To execute a block of code repeatedly while a condition is true\n\tb. To execute a block of code once and then check a condition\n\tc. To define a class", 'b'},
        {"Q. What is the C++ 'break' statement used for?\n\ta. To execute a block of code\n\tb. To end a loop prematurely\n\tc. To define a class", 'b'},
        {"Q. How can you create a constant in C++ that cannot be changed?\n\ta. Using the 'const' keyword\n\tb. Using the 'final' keyword\n\tc. By declaring it inside a class", 'a'},
        {"Q. What is the purpose of the 'continue' statement in C++?\n\ta. To end the program\n\tb. To skip the current iteration of a loop and continue with the next\n\tc. To declare a variable", 'b'},
        {"Q. Which C++ keyword is used to define a variable that can be accessed globally throughout the program?\n\ta. local\n\tb. static\n\tc. global", 'c'},
        {"Q. In C++, what is the purpose of the 'switch' statement?\n\ta. To declare a variable\n\tb. To execute a block of code repeatedly\n\tc. To perform different actions based on the value of an expression", 'c'},
        {"Q. What is the C++ operator for division?\n\ta. +\n\tb. -\n\tc. /", 'c'},
        {"Q. What is the primary purpose of the 'include' directive in C++?\n\ta. To include external libraries\n\tb. To execute a block of code\n\tc. To define a class", 'a'},
        {"Q. What is the C++ 'delete' operator used for?\n\ta. To remove a character from a string\n\tb. To deallocate memory previously allocated with 'new'\n\tc. To execute a block of code", 'b'},
        {"Q. What is the C++ 'typedef' keyword used for?\n\ta. To declare a function\n\tb. To define a new data type\n\tc. To specify a class", 'b'},
        {"Q. How can you declare a constant pointer in C++?\n\ta. by using 'static' keyword\n\tb. by using 'const' keyword\n\tc. by using 'void' keyword", 'b'},
        {"Q. What is the purpose of the 'endl' manipulator in C++?\n\ta. To end the program\n\tb. To insert a new line and flush the output buffer\n\tc. To define a class", 'b'},
        {"Q. What is the C++ 'sizeof' operator used for?\n\ta. To calculate the square root of a number\n\tb. To determine the size, in bytes, of a data type or object\n\tc. To execute a block of code", 'b'},
        {"Q. In C++, what is the purpose of the 'static' keyword?\n\ta. To declare a constant variable\n\tb. To define a new data type\n\tc. To declare a variable with static storage duration", 'c'},
        {"Q. Which C++ standard library header is used for mathematical operations?\n\ta. <iostream>\n\tb. <math.h>\n\tc. <string>", 'b'},
        {"Q. What is the C++ 'namespace' used for?\n\ta. To enclose a class definition\n\tb. To group related functions and classes together\n\tc. To declare global variables", 'b'}


    };


    int numQuestions = questions.size();
    int noq;
    cout << "Enter number of questions you want to take quiz of = ";
    cin >> noq;
    cin.ignore(); // Ignore the newline character left by cin

    if (noq > numQuestions) {
        cout << "You can't select more questions than available. Setting number of questions to " << numQuestions << "." << endl;
        noq = numQuestions;
    }

    int correctAnswers = 0;
    for (int i = 0; i < noq; i++) {
        int randomIndex = rand() % questions.size();
        cout << questions[randomIndex].first << endl;
        cout << "Enter your answer as a, b, or c = ";
        cin >> answer;
        cin.ignore(); // Ignore the newline character left by cin

        if (answer == questions[randomIndex].second) {
            score += 10;
            correctAnswers++;
            cout << " \t Great! Your Game score is: " << score << endl;
        } else {
            cout << " \t Sorry, wrong answer. The correct answer was " << questions[randomIndex].second << "." << endl;
        }
        cout << " \t Press Enter! ";
        getch();
        cout << "\n";
        quiz.header();
        questions.erase(questions.begin() + randomIndex); // Remove the used question
    }

    quiz.footer();
    quiz.results(noq, correctAnswers);
    getch();
}
void displayTopic(const string& topic, const string& theory, const string& example) {
    cout << "\n------------------- " << topic << " -------------------\n" << endl;
    cout << theory << endl;
    cout << "Example: " << example << endl;
}

int main() {
    int choice;
    do {
        cout << "Choose a topic to learn about:" << endl;
        cout << "1. Basic Input/Output" << endl;
        cout << "2. Variables and Data Types" << endl;
        cout << "3. Operators" << endl;
        cout << "4. Control Structures" << endl;
        cout << "5. Functions" << endl;
        cout << "6. Arrays" << endl;
        cout << "7. Classes and Objects" << endl;
        cout << "8. Strings" << endl;
        cout << "9. Pointers" << endl;
        cout << "10. A QUIZ of C++ " << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left by cin

        switch (choice) {
        case 1:
            displayTopic("Basic Input/Output",
                "Basic Input/Output, often referred to as I/O, is a fundamental concept in C++. It involves interactions between the program and the user or external data sources.",
                "C++ provides the 'cin' object for input and 'cout' object for output. 'cin' is used to read data from the user, while 'cout' is used to display data on the console.\n\n"
                "Example:\n"
                "int number;\ncout << \"Enter an integer: \";\ncin >> number;\ncout << \"You entered: \" << number;");
            break;
        case 2:
            displayTopic("Variables and Data Types",
                "Variables are storage locations used to hold data. C++ supports various data types, such as int, float, char, and more, to represent different kinds of information.",
                "For example, you can declare an 'int' variable to store integer values, a 'float' variable for floating-point numbers, and a 'char' variable for single characters.\n\n"
                "int age = 30;\nfloat price = 12.99;\nchar grade = 'A';");
            break;
        case 3:
            displayTopic("Operators",
                "Operators in C++ are symbols that are used to perform operations on data. They can be categorized into various types, including arithmetic, comparison, and logical operators.",
                "For instance, the '+' operator is used for addition, '==' for equality comparison, and '&&' for logical 'AND'. Operators allow you to manipulate and analyze data in your programs.\n\n"
                "int x = 10, y = 20;\nint sum = x + y;\nbool isGreater = (x > y);");
            break;
        case 4:
            displayTopic("Control Structures",
                "Control structures are used to manage the flow of a program. In C++, you have 'if' statements and loops like 'for' and 'while' for controlling program execution based on conditions.",
                "For example, 'if' statements allow you to make decisions. You can use them to execute a block of code only if a certain condition is true. This is crucial for building dynamic and interactive programs.\n\n"
                "int age;\ncout << \"Enter your age: \";\ncin >> age;\nif (age >= 18) {\n    cout << \"You are eligible to vote.\";\n}");
            break;
        case 5:
            displayTopic("Functions",
                "Functions are reusable blocks of code that can be called with specific inputs (arguments) and may return results. They promote code modularity and reusability.",
                "In C++, you can create functions to perform tasks and calculations. Functions take parameters and can return values. This allows you to break your code into manageable pieces and reuse them efficiently.\n\n"
                "int add(int a, int b) {\n    return a + b;\n}\ncout << \"The sum of 5 and 7 is: \" << add(5, 7);");
            break;
        case 6:
            displayTopic("Arrays",
                "Arrays are data structures that store collections of elements of the same data type. Elements in an array are accessed using an index, which starts from 0.",
                "Arrays are useful for storing multiple values of the same type in a structured manner. You can access elements by specifying their position in the array using square brackets.\n\n"
                "int numbers[] = {1, 2, 3, 4, 5};\ncout << \"Third element: \" << numbers[2];");
            break;
        case 7:
            displayTopic("Classes and Objects",
                "Classes and objects are the foundation of object-oriented programming (OOP) in C++. A class defines a blueprint for creating objects, while objects are instances of a class.",
                "Using classes, you can encapsulate data (attributes) and methods (functions) into a single unit. This promotes code organization and reusability.\n\n"
                "class Student {\npublic:\n    string name;\n    int age;\n};\nStudent john(\"John\", 20);\ncout << \"Student: \" << john.name << \", Age: \" << john.age;");
            break;
        case 8:
            displayTopic("Strings",
                "Strings are sequences of characters. In C++, the 'string' class is used to work with strings. It provides various methods to manipulate and analyze text data.",
                "Strings are essential for working with textual information. You can create, modify, and manipulate strings in C++ programs using the 'string' class and its member functions.\n\n"
                "string greeting = \"Hello, World!\";\ncout << greeting;");
            break;
        case 9:
            displayTopic("Pointers",
                "Pointers are variables that store memory addresses. They allow direct manipulation of memory and are crucial for dynamic memory allocation and efficient array handling.",
                "Pointers can be used to refer to objects, dynamically allocated memory, and function addresses. Understanding pointers is key for advanced programming techniques in C++.\n\n"
                "int value = 10;\nint* ptr = &value;\ncout << \"Value: \" << *ptr;");
            break;
        case 10:
            QUIZ();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
