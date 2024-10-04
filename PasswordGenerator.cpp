#include <iostream>
#include <ctime>
using namespace std;
int numbers[]={1,2,3,4,5,6,7,8,9};
char symbols[]={'!','~','`','@','#','%','$','^','&','*','(',')','_','-','+','='};
char alphabets[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
std::string password ;
int main(){
    srand(time(NULL));

    int ch1,ch2,ch3;
    std::cout<<"\n\n###################  Welome to PasswordGenerator tool #####################\n\n";
    std::cout<<"Enter no of alphabets you want in your password \n";
    std::cin>>ch1;
    std::cout<<"Enter no of numbers you want in your password \n";
    std::cin>>ch2;
    std::cout<<"Enter no of symbols you want in your password \n";
    std::cin>>ch3;
    for(int i=0;i<ch1;i++){
     int randm=rand() % 26;
     password+=alphabets[randm];
    }
    for(int i=0;i<ch2;i++){
     int  randm=rand() % 9;
    password+=to_string(numbers[randm]);

    }
    for(int i=0;i<ch3;i++){
     int randm=rand() % sizeof(symbols)/sizeof(symbols[0]);
     password+=symbols[randm];
    }
     std::cout<<"\nYour Generated Password is |||  "<<password<<"  ||| with no of characters "<<ch1+ch2+ch3<<"\n";
    return 0;

    }
