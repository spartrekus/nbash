

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   //chdir
#include <dirent.h>


int main( int argc, char *argv[])
{ 
    if ( argc >= 2)
      if ( strcmp( argv[1] , "" ) !=  0 )
	 chdir( argv[ 1 ] );

   DIR *dirp;
   struct dirent *dp;
   dirp = opendir( "." );
   while  ((dp = readdir( dirp )) != NULL ) 
   {
         if (  strcmp( dp->d_name, "." ) != 0 )
         if (  strcmp( dp->d_name, ".." ) != 0 )
             printf( "%s\n", dp->d_name );
   }
   closedir( dirp );
   return 0;
}


