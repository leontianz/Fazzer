//*****************************************************************************
// File Name:  FcgiWorker.h
// Copyright:  Tianz, Inc. 2018. All rights reserved.
//*****************************************************************************

#ifndef FCGIWORKER_H
#define FCGIWORKER_H

#include <iostream>

extern "C"
{
   #include <qdecoder.h>
}

class CFcgiWorker
{
   public:
      CFcgiWorker();
      ~CFcgiWorker();

      std::string GetReqStr( const std::string& pName );

   private:
      qentry_t* m_Request;
};

#endif
