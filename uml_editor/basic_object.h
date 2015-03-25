#ifndef BASIC_OBJECT_H
#define BASIC_OBJECT_H

#include <QString>

//自定義標頭檔
#include "shape.h"
#include "port.h"

/**
 * @brief The BasicObject class
 *
 *  class diagram或use case diagram為basic object的一種
 */
class BasicObject : public Shape
{
    public :
        /**
         * @brief BasicObject
         *
         * BasicObject的預設建構子
         */
        BasicObject( ) ;

        /**
         * @brief BasicObject
         *
         * BasicObject的建構子
         */
        BasicObject(  int , int ) ;

        /**
         * @brief ~BasicObject
         *
         * BasicObject的解構子
         */
        virtual ~BasicObject( ) ;

        /**
         * @brief shape
         *
         * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作出各圖形的形狀
         */
        virtual QPainterPath shape( ) const = 0 ;

        /**
         * @brief paint
         *
         * 繼承自QGraphicsItem的虛擬函數,繪製各種subclass的圖形形狀
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
         * 確認Canvas上被圈選的範圍中是否存在Shape
         */
        virtual bool isInside( QPointF , QPointF ) ;

        /**
         * @brief boundingRect
         *
         * 繼承自QGraphicsItem的虛擬函數,由各subclass定義出的shape(形狀)計算出邊界範圍
         */
        virtual QRectF boundingRect( ) const ;

        /**
         * @brief setName
         *
         * 設定basic object的名稱
         */
        void setName( QString ) ;

        /**
         * @brief setPorts
         *
         * 設定4個Port在basic object上個別的位置
         */
        void setPorts( ) ;

        /**
         * @brief getPort
         *
         * 找出basic object被點選時,距離最近的Port
         */
        Port *getPort( QPointF ) ;

    protected :
        QFont font ;
        QPointF center ;        //Basic object的中心位置
        QString name ;          //Basic object的名稱
        Port ports[ 4 ] ;       //Basic object的四個port

        virtual QVariant itemChange( GraphicsItemChange , const QVariant & ) ;
} ;

#endif // BASIC_OBJECT_H
