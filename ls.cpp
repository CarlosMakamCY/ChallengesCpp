#include <iostream>
#include <dirent.h>

using namespace std;

DIR *dir;
struct dirent *ent;

int main()
{
  int Ndirectories=0, Nfiles=0;
  if ((dir = opendir ("c:\\Users\\")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    printf ("%s\n", ent->d_name);
    if(ent->d_type == DT_DIR){
      Ndirectories++;
    }else if(ent->d_type == DT_REG){
      Nfiles++;
    }
  }
  closedir (dir);
} else {
  /* could not open directory */
  perror ("");
  return EXIT_FAILURE;
}
cout<<"There are "<<Ndirectories<<" directories and "<<Nfiles<<" files"<<endl;
return 0;
}