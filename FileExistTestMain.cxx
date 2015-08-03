#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include "helloworld.h"

extern int ModuleEntryPoint(int argc, char *argv[]);

int main (int argc, char *argv[])
{

  if( argc < 2 )
  {
    std::cout<<"Not enough arguments - requires at least one parameter [filename]"<<std::endl;
    return EXIT_FAILURE;
  }
  
 
  int res;
  res=ModuleEntryPoint(argc-1,argv+1);
  
  if( res )
  {
  std::cerr << "Error while running command"<<std::endl;
  return EXIT_FAILURE;
  }
  

  FILE * pFile;
  char *file;
  file=argv[1];
  
  pFile = fopen(file,"r");
  
  if(pFile != NULL)
  {
   std::cout<<"File exists"<<std::endl;
   return EXIT_SUCCESS;
  }
  else
  {
   std::cout<<"File doesn't exist"<<std::endl;
   return EXIT_FAILURE;
  }

}
