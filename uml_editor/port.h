#ifndef PORT_H
#define PORT_H

#include <vector>
#include <QtGlobal>
#include <QGraphicsItem>

//自定義標頭檔
#include "line_object.h"

class BasicObject ;

class Port : public QGraphicsItem
{
    public :
        /**
         * @brief Port
         *
         * Port的預設建構子
         */
        Port( ) ;

        /**
         * @brief Port
         *
         * Port的建構子
         */
        Port( BasicObject * , QPointF ) ;

        /**
         * @brief ~Port
         *
         * Port的解構子
         */
        ~Port( ) ;

        /**
         * @brief shape
         * @return
         */
        virtual QPainterPath shape( ) ;

        /**
         * @brief paint
         *
         * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作出繪圖的功能
         */
        virtual void paint( QPainter * , const QStyleOptionGraphicsItem * , QWidget * ) ;

        /**
         * @brief boundingRect
         *
         * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作Shape的四邊型範圍
         */
        virtual QRectF boundingRect( ) const ;

        void addLine( LineObject * ) ;

    private :
        QBrush brush ;
        QPainterPath painterPath ;
        BasicObject *parent ;
        std :: vector< LineObject* > connectedLine ;
} ;

#endif // PORT_H
