//*****************************************************************************
// File Name:  server.cpp
// Copyright:  Tianz, Inc. 2018. All rights reserved.
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Fastcgi standart header.
#include <fcgi_stdio.h>

#include "FcgiWorker.h"

int main( int argc, char* argv[] )
{
	unsigned int times = 0;

	while( FCGI_Accept() >= 0 )
	{
      // Set the content type of respond header.
      printf( "content-type: /text/plain\n\n" );

	   CFcgiWorker FcgiWorker;

	   std::string name = "count";
	   std::string value = "";

      value = FcgiWorker.GetReqStr( name );
	   
		printf( "This is the %u times. %s: %s\n", times++, name.c_str(), value.c_str() );
	}
	
	return 0;
}

// GET method
/*char *query_string = getenv("QUERY_STRING");

if( query_string == NULL )
{
   value = "0";
}
else
{
   value = getenv("REQUEST_URI");
}*/

// POST method    
/*char *request_method = getenv("REQUEST_METHOD");
char *content_length = getenv("CONTENT_LENGTH");
if( request_method == NULL )
{
   name = "NO method";
}
else
{
   name = request_method;

   size_t length = sizeof(request_method) - 1;

   if( strncmp( request_method, "POST", length ) == 0 )
   {
      int contentLength = atoi( content_length );
      char* content = new char[contentLength + 1];
      if( content != NULL )
      {
         int index = 0;
         for( ; index < contentLength; index++ )
         {
            content[index] = fgetc( stdin );
         }
         content[index] = '\0';

         printf( "[POST]: length: %d, str: %s\n", contentLength, content );

         delete [] content;
      }
   }
}

if( content_length == NULL )
{
   value = "NO lenth";
}
else
{
   value = content_length;
}*/


