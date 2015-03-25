#include "port.h"
#include "line_object.h"

LineObject :: LineObject( )
{

}

/**
 * @brief LineObject
 *
 * LineObject的建構子
 *
 * @param start 連線的起始Port
 * @param end 連線的終點Port
 */
LineObject :: LineObject( Port *start , Port *end )
{
    this -> startPort = start ;
    this -> endPort = end ;
}

/**
 * @brief ~LineObject
 *
 * LineObject解構子
 */
LineObject :: ~LineObject( )
{

}

void LineObject :: paint( QPainter *painter, const QStyleOptionGraphicsItem *option , QWidget *widget )
{
    QPainterPath path = shape( ) ;
    painter -> setPen( pen ) ;
    painter -> drawPath( path ) ;
}

/**
 * @brief isInside
 *
 * 確認Canvas上被點選的位置是否存在Shape
 *
 * @param
 * @param
 * @return Canvas被點選時的位置上如果有存在ClassObject時為真,反之則為否
 */
bool LineObject :: isInside( QPointF pos )
{
    Q_UNUSED( pos ) ;
    return false ;
}

/**
 * @brief isInside
 *
 * 確認Canvas上被點選的位置是否存在Shape
 *
 * @return Canvas被點選時的位置上如果有存在ClassObject時為真,反之則為否
 */
bool LineObject :: isInside( QPointF pos1 , QPointF pos2 )
{
    Q_UNUSED( pos1 ) ;
    Q_UNUSED( pos2 ) ;
    return false ;
}

/**
 * @brief boundingRect
 *
 * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作Shape的四邊型範圍
 */
QRectF LineObject :: boundingRect( ) const
{
    return QRectF( 10 , 10 , 10 , 10 ) ;
}
