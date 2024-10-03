#include <iostream>
std::string hangmanLogo[] =
{ "+---+\n"
  "|   |\n"
   "    |\n"
   "    |\n"
   "    |\n"
   "    |\n"
"=========\n",
  "+---+\n"
  "|   |\n"
  "O   |\n"
   "    |\n"
   "    |\n"
   "    |\n"
"=========\n",
  "+---+\n"
  "|   |\n"
  "O   |\n"
  "|   |\n"
   "    |\n"
   "    |\n"
"=========\n",
  " +---+\n"
  " |   |\n"
  " O   |\n"
 "/|   |\n"
  "     |\n"
  "     |\n"
"=========\n",
  " +---+\n"
  " |   |\n"
  " O   |\n"
 "/|\   |\n"
  "     |\n"
  "     |\n"
"=========\n",
  " +---+\n"
  " |   |\n"
  " O   |\n"
 "/|\\  |\n"
 "/    |\n"
  "     |\n"
"=========\n",
  " +---+\n"
  " |   |\n"
  " O   |\n"
 "/|\\  |\n"
 "/ \\  |\n"
  "     |\n"
"========="};
std::string Questions[]={"1) What is the correct way to declare a variable in C++?",
                         "2) Which of the following is a valid comment in C++? ",
                         "3) Which of the following data types can store decimal numbers in C++?",
                         "4) How do you define a function in C++?",
                         "5)What is the default access specifier for class members in C++? ",
                         "6)Which of the following operators is used for logical AND in C++?"
                         "7) What is the output of 'cout << 5 + 2 * 3;'?",
                         "8) Which keyword is used to inherit a class in C++?",
                         "9) Which of the following is a valid way to create a pointer in C++?",
                         "10) What is the correct syntax to include a header file?",
                         "11) Which operator is used to access a class member using a pointer?",
                         "12) What is the purpose of the 'new' keyword in C++?",
                         "13) Which of the following is used to define a constant in C++?",
                         "14) Which function is used to read input from the user?",
                         "15) What is the default return type of a function that does not return a value?",
                         "16) What is the correct way to create a single-line comment?"};
std::string options[][4]={
    {"A) int num",
     "B) num int",
     "C) declare int num",
     "D) var num: int"
     },
     {"A) <!-- This is a comment -->",
      "B) // This is a comment",
      "C) /* This is a comment */",
      "D) Both B and C",
     },
     {"A) int",
      "B) char",
      "C) float",
      "D) bool"
     },
     {"A) function void myFunc() {}",
      "B) void myFunc() {}",
      "C) def myFunc() {}",
      "D) myFunc() : void {}",
     },
     { "A) object",
       "B) class",
       "C) struct",
       "D) instance"
     },
     { "A) &",
       "B) &&",
       "C) ||",
       "D) !"
     },
     {"A) 11",
     "B) 16",
     "C) 21",
     "D) 23"},
     
    {"A) inherit",
     "B) base",
     "C) extends",
     "D) public"},
     
    {"A) int* p",
     "B) p int*",
     "C) *p int",
     "D) int p*"},
     
    {"A) #include <filename>",
     "B) include <filename>",
     "C) #include filename",
     "D) #include 'filename'"},
     
    {"A) .",
     "B) ->",
     "C) *",
     "D) &"},
     
    {"A) To allocate memory",
     "B) To free memory",
     "C) To declare variables",
     "D) To create functions"},
     
    {"A) const",
     "B) static",
     "C) final",
     "D) define"},
     
    {"A) input()",
     "B) cin",
     "C) read()",
     "D) get()"},
     
    {"A) void",
     "B) int",
     "C) return",
     "D) None"},
     
    {"A) // This is a comment",
     "B) /* This is a comment */",
     "C) # This is a comment",
     "D) < This is a comment"}
     };
char Key[]={'A','D','C','B','B','B','A', 'A', 'A', 'A', 'B', 'A', 'A', 'B', 'A', 'A'};


int lives=0;
int points=0;
bool game=true;
int main ()
{
std::cout<<"\n*************WELCOME TO HANGMAN GAME!!***********\n\n";
for (int i =0;i < sizeof(Questions)/sizeof(Questions[0]);i++){
            std::cout<<"*****************************************************\n";
            std::cout<<Questions[i]<<std::endl;
            std::cout<<"*****************************************************\n";
    for(int j=0; j < sizeof(options[0])/sizeof(options[0][0]) ; j++){
        std::cout<<options[i][j]<<std::endl;
    }
    char answer;
    std::cout<<"Enter your answer here by writing option :";
    std::cin>>answer;
    answer=toupper(answer);
    if(answer==Key[i]){
        std::cout<<"\nYour Answer is Correct!!\n";
        points++;
    }
    else{
            std::cout<<"\nYour Answer is Wrong!!\n";
            lives++;
            std::cout<<hangmanLogo[lives];
            if(lives==6){
                std::cout<<"\nGame Over!\n"<<"Your points are "<<points;
                break;
            }
    }

}
    return 0;
}
