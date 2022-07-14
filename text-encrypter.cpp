#include<bits/stdc++.h>

class encrypto
{

  private:
  char ch, filename[20], enfilename[20], defilename[20];
  int opt;
  
  void decrypt()
  {
    cout<<endl<<"\nEnter the file name that has to decryted."
    <<"Note that the file should be in same folder containing the APP\n"
    <<"\n EXAMPLE<><><> If the file name is test.en, enter as test\n"
    <<" ENTER<><><> ";
     
    cin>>filename;
    strcpy(defilename, filename);
    strcat(filename,".en");
    strcat(defilename,".txt");

    ifstream fin (filename);

    if(fin.fail()){ cout<<"\n FILE DOES'NT EXIST"; getch(); start();}
    ofstream fout(defilename);

    while(!fin.eof())
    {
      fin.get(ch);
      fout<<(char)(ch-9);
     }

      cout<<"\n DECRYPTED SUCCESSFULLY";
      getch();
      remove(filename);
      fin.close();
      fout.close();
      start();
    }

    void encrypt()
    {
      cout<<endl<<"\nEnter the text file name."
      <<"Note that the file should be in same folder containing the APP\n"
      <<"\n EXAMPLE<><><> If the file name is test.txt, enter as test\n"
      <<" ENTER<><><> ";
      cin>>filename;

      strcpy(enfilename, filename);
      strcat(filename,".txt");
      strcat(enfilename,".en");
      ifstream fin (filename);
      
      if(fin.fail()){ cout<<"\n\n FILE DOES'NT EXIST"; getch(); start();}
      ofstream fout(enfilename);

      while(!fin.eof())        
      {
          fin.get(ch);
          fout<<(char)(ch+9);
      }

      cout<<"\n ENCRYPTED SUCCESSFULLY";
      getch();
      remove(filename);
      fin.close();
      fout.close();
      start();
    }

  public:
  encrypto()
  {
    opt=3;
    strcpy(filename,NULL);
    strcpy(enfilename,NULL);
    strcpy(defilename,NULL);
  }

  void start()
  {
    clrscr();
    textcolor(YELLOW);
    
    cout<<"\t\t\t\t";
    cprintf("WELCOME TO ENCRYPTO");
    
    cout<<"\n\t\t";
    cprintf("ALL RIGHTS RESERVED ");
    cprintf("DEVELOPED BY NITHIN");
    
    cout<<"\n\n";
    textcolor(GREEN);
    cprintf(" NOTE <><><>");
    
    cout<<" This is a text file encrypter\n"
    <<" \t\t\t The Encrypted file is stored as <filename>.en"<< endl;
    cprintf(" SUPPORTED FORMATS <><><>");
    cout<<" *.txt TYPE FILES"<<endl;
    
    choice();
   }

    void choice()
    {
        cout<<endl<<endl;
        cprintf("PRESS:");

      cout<<"\n <><><> 1 for Encrypting\n <><><> 2 for Decrypting\n <><><> 3 for exit \n";
      textcolor(LIGHTRED);
      cprintf("<><><> Enter::");

      textcolor(WHITE);
      cin>>opt;


      if(opt==1) encrypt();
      else if(opt==2) decrypt();
      else if(opt==3) { cout<<"\nEXITING ENCRYTO PRESS ANY KEY TO CONTINUE";getch();exit(0);}
      else 
        { 
          cout<<"\nINVALID CHOICE ENTER AGAIN"; 
          getch(); 
          start();
        }
     }

};

void main()
{
  encrypto en;
  en.start();
  getch();
}
