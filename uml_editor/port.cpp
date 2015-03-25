#include "port.h"
#include "basic_object.h"

#include <QDebug>
#include <iostream>

/**
 * @brief Port
 *
 * Port的預設建構子
 */
Port :: Port( )
{

}

Port :: Port( BasicObject *parent , QPointF pos )
{
    this->setParentItem( parent ) ;
    setX( pos.x( ) ) ;
    setY( pos.y( ) ) ;
    qDebug() << "in constructor of Port\n" ;
}

/**
 * @brief ~Port
 *
 * Port的解構子
 */
Port :: ~Port( )
{

}

/**
 * @brief shape
 * @return
 */
QPainterPath Port :: shape( )
{
//    qDebug( ) << "in Port, shape(), " ;
//    qDebug( ) << "port pos=" << pos() << ",scenePos=" << this ->scenePos() << "p=" << x() << "\n";

    QPainterPath path ;
    this -> brush.setColor( QColor :: fromRgb( 0 , 0 , 0 ) ) ;
    this -> brush.setStyle( Qt :: SolidPattern ) ;
    path.addEllipse( -5 , -5 , 10 , 10 ) ;
//    return mapFromParent( path ) ;
    return path ;
}

/**
 * @brief paint
 *
 * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作出繪圖的功能
 */
void Port :: paint( QPainter *painter , const QStyleOptionGraphicsItem *option , QWidget *widget )
{
    this -> painterPath = this -> shape( ) ;
    painter -> fillPath( painterPath , brush ) ;
}

/**
 * @brief boundingRect
 *
 * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作Shape的四邊型範圍
 */
QRectF Port :: boundingRect( ) const
{
    return painterPath.boundingRect( ) ;
}

void Port :: addLine( LineObject *line )
{
    connectedLine.push_back( line ) ;
}


//bool Port :: isLinked( )
//{
//    return true ;
//}
