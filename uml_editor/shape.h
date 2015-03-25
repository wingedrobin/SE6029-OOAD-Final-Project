#ifndef SHAPE_H
#define SHAPE_H

#include <QPen>
#include <vector>
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>

/**
 * @brief The Shape class
 *
 * Shape為一個abstract class,任何能夠畫於畫布上的圖形物件皆繼承自Shape object
 */
class Shape : public QGraphicsItem
{
    public :
        /**
         * @brief Shape
         *
         * Shape的預設建構子
         */
        Shape( ) ;

        /**
         * @brief Shape
         *
         * Shape的建構子
         */
        Shape( int , int ) ;

        /**
         * @brief ~Shape
         *
         * Shape的解構子
         */
        virtual ~Shape( ) ;

        int getWidth( ) ;

        int getHeight( ) ;

        /**
         * @brief paint
         *
         * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作出繪圖的功能
         */
        virtual void paint( QPainter * , const QStyleOptionGraphicsItem * , QWidget * ) = 0 ;

        /**
         * @brief isInside
         *
         * 確認Canvas上被點選的位置是否存在Shape
         */
        virtual bool isInside( QPointF ) = 0 ;

        /**
         * @brief isInside
         *
         * 確認Canvas上被點選的位置是否存在Shape
         */
        virtual bool isInside( QPointF , QPointF ) = 0 ;

        /**
         * @brief boundingRect
         *
         * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作Shape的四邊型範圍
         */
        virtual QRectF boundingRect( ) const = 0 ;

        /**
         * @brief depthLessThen
         *
         * 判斷與其它Shape的相對深度
         */
        bool depthLessThen( Shape * ) ;

    protected :
        QPen pen ;
        int height ;            //Shape的高度
        int width ;             //Shape的寬度
        QPainterPath painterPath ;
        bool selected ;         //Shape的狀態是否為被點選中
} ;

#endif // SHAPE_H
