//*****************************************************************************
// File Name:  FcgiWorker.cpp
// Copyright:  Tianz, Inc. 2018. All rights reserved.
//*****************************************************************************

#include "FcgiWorker.h"


CFcgiWorker::CFcgiWorker()
{
   std::string uploadPath = "/home/tianz/fazzer/webservices/tmp";
   std::string parsingFile = "/home/tianz/fazzer/webservices/tmp/FcgiParsing.txt";

   // Create the qentry object.
   m_Request = qcgireq_setoption( NULL, true, uploadPath.c_str(), 1 );

   // Parsing the request string.
   m_Request = qcgireq_parse( m_Request, (Q_CGI_T)( Q_CGI_POST | Q_CGI_GET ) );

   // Save the parsing info into the file which on the filesystem in order to
   // help people to monitor the request content.
   m_Request->save( m_Request, parsingFile.c_str() );
}

CFcgiWorker::~CFcgiWorker()
{
   m_Request->free( m_Request );
}

std::string CFcgiWorker::GetReqStr( const std::string& pName )
{
   char* retStr = NULL;

   retStr = m_Request->getstr( m_Request, pName.c_str(), false );

   return ( retStr == NULL ) ? "NULL string" : retStr;
}

