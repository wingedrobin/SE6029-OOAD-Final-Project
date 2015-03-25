#ifndef ASSOCIATION_LINE_H
#define ASSOCIATION_LINE_H

#include "line_object.h"

//class Port ;

class AssociationLine : public LineObject
{
    public :
        /**
         * @brief AssociationLine
         *
         * AssocaitionLine的預設建構子
         */
        AssociationLine( ) ;

        /**
         * @brief AssociationLine
         *
         * AssociationLine的建構子
         */
        AssociationLine( Port * , Port * ) ;

        /**
          * @brief ~AssociationLine
          *
          * AssociationLine的解構子
          */
        ~AssociationLine( ) ;


        virtual QPainterPath shape( ) const ;

        /**
         * @brief drawArrow
         *
         * 在LineObject的某一端畫上箭頭
         */
        virtual QPainterPath setArrow( QPointF ) const ;
} ;

#endif // ASSOCIATION_LINE_H
