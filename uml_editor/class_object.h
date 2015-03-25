#ifndef CLASS_OBJECT_H
#define CLASS_OBJECT_H

//自定義標頭檔
#include "basic_object.h"

class ClassObject : public BasicObject
{
    public :
        /**
         * @brief ClassObject
         *
         * ClassObject的預設建構子
         */
        ClassObject( ) ;

        /**
         * @brief ~ClassObject
         *
         * ClassObject的解構子
         */
        virtual ~ClassObject( ) ;

        /**
         * @brief shape
         * @return
         */
        virtual QPainterPath shape( ) const ;

    private :
} ;

#endif // CLASS_OBJECT_H
