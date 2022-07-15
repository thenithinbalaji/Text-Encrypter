#include<iostream>
#include<fstream>
#include<stdio.h> 
using namespace std;

void starttext(){
  cout<<R"(
     /$$$$$$$$                                                     /$$                        
    | $$_____/                                                    | $$                        
    | $$       /$$$$$$$   /$$$$$$$  /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ 
    | $$$$$   | $$__  $$ /$$_____/ /$$__  $$| $$  | $$ /$$__  $$|_  $$_/   /$$__  $$ /$$__  $$
    | $$__/   | $$  \ $$| $$      | $$  \__/| $$  | $$| $$  \ $$  | $$    | $$  \ $$| $$  \__/
    | $$      | $$  | $$| $$      | $$      | $$  | $$| $$  | $$  | $$ /$$| $$  | $$| $$      
    | $$$$$$$$| $$  | $$|  $$$$$$$| $$      |  $$$$$$$| $$$$$$$/  |  $$$$/|  $$$$$$/| $$      
    |________/|__/  |__/ \_______/|__/       \____  $$| $$____/    \___/   \______/ |__/      
                                             /$$  | $$| $$                                    
                                            |  $$$$$$/| $$                                    
                                             \______/ |__/)";                             


  cout<<endl<<endl<<endl;

  cout<<"\nQuick note";
  cout<<"\n----------";
  cout<<"\n+ You will be asked for file name and file extension";
  cout<<"\n+ Enter txt in file extension to encrypt the .txt file";
  cout<<"\n+ Enter en  in file extension to decrypt the .en  file";
  cout<<"\n+ <filename>.txt file will be encrypted, <filename>.en file will be decrypted";
  cout<<"\n+ The files must be present in the root of the code or exe";

  cout<<endl<<endl;
  
}

void encrypt(string filename){

  ifstream fin;
  fin.open(filename + ".txt");
  
  if(fin.fail()){ 
    cout<<"\nFATAL ERROR 02 := Unknown file `"<<filename<<".txt`\nFile doesn't exist. Read Quick Note!!";
  }

  else{
    ofstream fout;
    fout.open(filename + ".en");

    char ch;
    while(!fin.eof()){
      fin.get(ch);
      fout<<(char)(ch+69);
    }

    cout<<"\nFile ENCRYPTED successfully";

    filename += ".txt";
    const char *charfilename = &filename[0];
    
    fin.close();
    fout.close();
    
    if( remove(charfilename) != 0 )
    perror("\nError deleting the .txt file");
    else
    puts("\n.txt file successfully deleted\n.en file created" );

  }

}

 void decrypt(string filename){

  ifstream fin;
  fin.open(filename + ".en");

  if(fin.fail()){ 
    cout<<"\nFATAL ERROR 02 := Unknown file `"<<filename<<".en`\nFile doesn't exist. Read Quick Note!!";
  }

  else{
    ofstream fout(filename + ".txt");

    char ch;
    while(!fin.eof()){
      fin.get(ch);
      fout<<(char)(ch-69);
    }

    cout<<"\nFile DECRYPTED successfully";
    
    filename += ".en";
    const char *charfilename = &filename[0];

    fin.close();
    fout.close();
    
    if( remove(charfilename) != 0 )
    perror("\nError deleting the .en file");
    else
    puts("\n.en file successfully deleted\n.txt file created" );

  }

}

int main(){

  begin:
    cout << "\033[2J\033[1;1H";
    starttext();

    string filename;
    cout<<"\nEnter file name:: ";
    cin>>filename;

    string fileext;
    cout<<"Enter file extension:: ";
    cin>>fileext;

    if(fileext == "txt") encrypt(filename);
    else if(fileext == "en") decrypt(filename);
    else cout<<"\nFATAL ERROR 01 := Unsupported file extension `."<<fileext<<"`\nOnly txt and en are supported. Read Quick Note!!";

    char ch;
    cout<<"\n\n\nEnter q to exit, any other character to restart:: ";
    cin>>ch;

    if(ch == 'q');
    else goto begin;

  return 0;
}
