#ifndef GENERALIZATION_LINE_H
#define GENERALIZATION_LINE_H

#include "line_object.h"

class GeneralizationLine : public LineObject
{
    public :
        /**
         * @brief GeneralizationLine
         *
         * GeneralizationLine的預設建構子
         */
        GeneralizationLine( ) ;

        /**
         * @brief GeneralizationLine
         *
         * GeneralizationLine的建構子
         */
        GeneralizationLine( Port * , Port * ) ;

        /**
         * @brief ~GeneralizationLine
         *
         * GeneralizationLine的解構子
         */
        virtual ~GeneralizationLine( ) ;

        virtual QPainterPath shape( ) const ;

        /**
         * @brief drawArrow
         *
         * 在LineObject的某一端畫上箭頭
         */
        virtual QPainterPath setArrow( QPointF ) const ;
} ;

#endif // GENERALIZATION_LINE_H
