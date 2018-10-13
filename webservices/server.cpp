//*****************************************************************************
// File Name:  server.cpp
// Copyright:  Tianz, Inc. 2018. All rights reserved.
//*****************************************************************************

#include <stdio.h>

// The Fastcgi standart header.
#include "fcgi_stdio.h"


int main( int argc, char* argv[] )
{
	unsigned int times = 0;

	while( FCGI_Accept() >= 0 )
	{
		// Set the content type of respond header.
		printf( "content-type: /text/plain\n\n" );
		printf( "This is the %u times you asked me!!!\n", times++ );
	}
	
	return 0;
}