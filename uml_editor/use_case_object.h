#ifndef USE_CASE_OBJECT_H
#define USE_CASE_OBJECT_H

#include "basic_object.h"
#include "port.h"

class UseCaseObject : public BasicObject
{
    public :
        /**
         * @brief UseCaseObject
         *
         * UseCaseObject的預設建構子
         */
        UseCaseObject( ) ;

        /**
         * @brief ~UseCaseObject
         *
         * UseCaseObject的解構子
         */
        virtual ~UseCaseObject( ) ;

        /**
         * @brief shape
         * @return
         */
        virtual QPainterPath shape( ) const ;
} ;

#endif // USE_CASE_OBJECT_H
