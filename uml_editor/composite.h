#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>

//自定義標頭檔
#include "shape.h"

/**
 * @brief The Composite class
 *
 * composite物件由多個基本物件經過group的功能組合而成。composite物件是一種樹狀的container，
 * 也就是說composite物件本身又可以包含composite物件。
 * composite物件的範圍可以定義為最小的正方形區域完全包含它的所有組成物件。
 */
class Composite : public Shape
{
    public :
        /**
         * @brief Composite
         *
         * Composite的預設建構子
         */
        Composite( ) ;

        /**
         * @brief ~Composite
         *
         * Composite的解構子
         */
        virtual ~Composite( ) ;

        /**
         * @brief addObject
         *
         * 將被選取到的Shape加入Composite中
         */
        void addObject( Shape * ) ;

        //void addObject( std :: vector< Shape * > ) ;

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

        virtual bool isInside( QPointF );

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

        virtual QVariant itemChange( GraphicsItemChange , const QVariant & ) ;

    private :
        std :: vector< Shape* > members ;
} ;

#endif // COMPOSITE_H
