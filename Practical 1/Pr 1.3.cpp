#include<iostream>
#include<string>
using namespace std;
int main()
{
   string sentence="My name is Mahii";
   cout<<sentence<<endl;
   int length=0,longest=0,endindex=0;
   for(int i=0;i<sentence.length();i++)
   {
       if(sentence[i]==' ')
       {
          if(length>longest)
          {
              longest=length;
              endindex=i-1;
          }
          length=0;
       }
       else
       {
           length++;
       }
   }
   if(length>longest)
   {
       longest=length;
       endindex=sentence.length();
   }
   cout<<"Longest word: ";
   for(int i= endindex - longest; i < endindex; i++)
   {
       cout<<sentence[i];
   }
   cout<<endl;
   return 0;
}
