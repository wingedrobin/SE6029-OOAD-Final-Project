#ifndef LINE_OBJECT_H
#define LINE_OBJECT_H

//自定義標頭檔
#include "shape.h"

class Port ;

/**
 * @brief The LineObject class
 *
 * Association Line, Generalization Line跟Composition Line皆為LineObject的一種
 */
class LineObject : public Shape
{
    public :
        /**
         * @brief LineObject
         *
         * LineObject的預設建構子
         */
        LineObject( ) ;

        /**
         * @brief LineObject
         *
         * LineObject的建構子
         */
        LineObject( Port * , Port * ) ;

        /**
         * @brief ~LineObject
         *
         * LineObject解構子
         */
        virtual ~LineObject( ) ;

        virtual QPainterPath shape( ) const = 0 ;

        /**
         * @brief paint
         *
         * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作出繪圖的功能
         */
        virtual void paint( QPainter * , const QStyleOptionGraphicsItem * , QWidget * ) ;

        /**
         * @brief isInside
         *
         * 確認Canvas上被點選的位置是否存在Shape
         */
        virtual bool isInside( QPointF ) ;

        /**
         * @brief isInside
         *
         * 確認Canvas上被點選的位置是否存在Shape
         */
        virtual bool isInside( QPointF , QPointF ) ;

        /**
         * @brief boundingRect
         *
         * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作Shape的四邊型範圍
         */
        virtual QRectF boundingRect( ) const ;

        /**
         * @brief drawArrow
         *
         * 在LineObject的某一端畫上箭頭
         */
        virtual QPainterPath setArrow( QPointF ) const = 0 ;

    protected :
        Port *startPort ;       //建立LineObject連線的起始Port
        Port *endPort ;         //建立LineObject連線的終點Port
} ;

#endif  // LINE_OBJECT_H
