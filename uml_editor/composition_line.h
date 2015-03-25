#ifndef COMPOSITION_LINE_H
#define COMPOSITION_LINE_H

#include "line_object.h"

class CompositionLine : public LineObject
{
    public :
        /**
         * @brief CompositionLine
         *
         * CompositionLine的預設建構子
         */
        CompositionLine( ) ;

        /**
         * @brief CompositionLine
         *
         * CompositionLine的建構子
         */
        CompositionLine( Port * , Port * ) ;

        /**
         * @brief ~CompositionLine
         *
         * CompositionLine的解構子
         */
        virtual ~CompositionLine( ) ;

        /**
         * @brief shape
         *
         * 要被繪製Line Object的路徑
         */
        virtual QPainterPath shape( ) const ;

        /**
         * @brief drawArrow
         *
         * 在LineObject的某一端畫上箭頭
         */
        virtual QPainterPath setArrow( QPointF endPos ) const ;
} ;

#endif // COMPOSITION_LINE_H
