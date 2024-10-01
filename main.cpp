#include <iostream>
void decode(std::string message, int decodeValue,char MyList[],int siza);
void encriptedMessage(int siza,char myList[]);
int findIndex( char lst[], int size, char value) {
    for (int index = 0; index < size; ++index) {
        if (lst[index] == value) {
            return index; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
        char myList[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    };

    int siza=sizeof(myList)/sizeof(myList[0]);
    char choice;
     std::cout<<"\n\n________________________Welcome to CipherGame!!________________________\n\n";
     std::cout<<"Do you want to incript or decript code?\nFor encript Enter '0'\nFor decript Enter '1'\n Enter your choice here : " ;
     std::cin>>choice;
     std::cin.ignore();
   if(choice=='0'){
    encriptedMessage(siza,myList);
   }
   else if (choice=='1'){
    std::string message,encriptedMessage;
    int decription;
    std::cout<<"\nWrite the message you want to decode :";
    std::getline(std::cin,message);
    std::cout<<"\nEnter decription code (1-5) : ";
    std::cin>>decription;
    decode(message,decription,myList,siza);
   }






    }



void encriptedMessage(int siza,char myList[]){
    std::string message,encriptedMessage;
    int increption;
    std::cout<<"\nWrite the message you want to encode : ";
    std::getline(std::cin,message);
    std::cout<<"\nEnter Encription code (1-5) : ";
    std::cin>>increption;
    int num=0;
    for (int word =0 ; word < message.size() ;word++){
        if (message[word]==' '){
            encriptedMessage+=" ";
           num+=1;
       }
        else{
            int index=findIndex(myList,siza,message[word]);
            index+=increption;
            encriptedMessage+=myList[index];
            num+=1;
        }
    }
    std::cout<<"\nEncripted code is "<<encriptedMessage<<" no of letters are:"<<num;

}


















void decode(std::string message, int decodeValue,char myList[],int siza){
    std::string decriptedMessage;
    for (int word =0 ; word < message.size() ;word++){
        if (message[word]==' '){
            decriptedMessage+=" ";
       }
        else{
            int index=findIndex(myList,siza,message[word]);
            index-=decodeValue;
            decriptedMessage+=myList[index];
        }

    }
    std::cout<<"\nDecripted code is "<<decriptedMessage;
}
