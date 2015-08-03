#include <iostream> 
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

extern int ModuleEntryPoint(int argc, char *argv[]);

int main(int argc, char * argv[])
{
  if( argc < 3 )
 {
    std::cout<<"Not enough arguments - requires at least two parameters [filename to compare] [filename checked]"<<std::endl;
    return EXIT_FAILURE;
  }
 
  int res;
   res=ModuleEntryPoint(argc-2,argv+2);

   if( res )
   {
   std::cerr << "Error while running command"<<std::endl;
   return EXIT_FAILURE;
   }

  std::ifstream fileToCompare (argv[1]);
  std::ifstream fileChecked (argv[2]);

  if (fileToCompare)  //file can be open
  {
    if(fileChecked)
    {
      std::string lineTocompare;
      std::string lineChecked;
      while(!fileToCompare.eof())
      {
        while (!fileChecked.eof())
        {
          getline(fileToCompare, lineTocompare);
          getline(fileChecked, lineChecked);

          //std::cout<<lineTocompare<<std::endl;
          if(lineTocompare!=lineChecked)
          {
            std::cout<<"Files are different"<<std::endl;
            return EXIT_FAILURE;
          }
          else
          {

          }
        }
      }

      fileToCompare.close();
      fileChecked.close();
      std::cout<<"Files are equal"<<std::endl;
      return EXIT_SUCCESS;
    }
    else
    {
      std::cerr<<"File checked can't be open"<<std::cout;
      return EXIT_FAILURE;
    }

  }
  else
  {
    std::cerr<<"File to compare can't be open"<<std::cout;
    return EXIT_FAILURE;

  }
}

