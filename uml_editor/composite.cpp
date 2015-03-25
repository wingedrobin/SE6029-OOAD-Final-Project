#include "composite.h"

/**
 * @brief Composite
 *
 * Composite的預設建構子
 */
Composite :: Composite( ) : Shape( )
{

}

/**
 * @brief ~Composite
 *
 * Composite的解構子
 */
Composite :: ~Composite( )
{

}

/**
 * @brief addObject
 *
 * 將被選取到的Shape加入Composite中
 *
 * @param shape 被選取到的Shape
 */
void Composite :: addObject( Shape *shape )
{
    shape -> setParentItem( this ) ;
    this -> members.push_back( shape ) ;
    shape -> setFlag( QGraphicsItem::ItemStacksBehindParent , true ) ;
}

/**
 * @brief paint
 *
 * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作出繪圖的功能
 */
void Composite :: paint( QPainter * , const QStyleOptionGraphicsItem * , QWidget * )
{


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
bool Composite :: isInside( QPointF pos )
{
    QRectF bound = boundingRect( ) ;
    pos = mapFromScene( pos ) ;

    if( bound.contains( pos.x( ) , pos.y( ) ) )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

/**
 * @brief isInside
 *
 * 確認Canvas上被點選的位置是否存在Shape
 *
 * @return Canvas被點選時的位置上如果有存在ClassObject時為真,反之則為否
 */
bool Composite :: isInside( QPointF pos1 , QPointF pos2 )
{
    QRectF bound = boundingRect( ) ;
    pos1 = mapFromScene( pos1 ) ;           //將Canvas的座標系統轉成Item的座標系統
    pos2 = mapFromScene( pos2 ) ;           //將Canvas的座標系統轉成Item的座標系統
    QRectF area( pos1 , pos2 ) ;

    if( area.contains( bound ) )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

/**
 * @brief boundingRect
 *
 * 繼承自QGraphicsItem的虛擬函數,讓subclass自行改寫實作Shape的四邊型範圍
 */
QRectF Composite :: boundingRect( ) const
{
    qreal minX = 35536 , minY = 35536 , maxX = 0 , maxY = 0 ;
    foreach( Shape* shape , members )
    {
        qreal posX = shape -> scenePos( ).x( ) ;
        qreal posY = shape -> scenePos( ).y( ) ;
        if( posX < minX )
        {
            minX = posX ;
        }
        if( posY < minY )
        {
            minY = posY ;
        }
        if( posX + shape -> getWidth( ) > maxX )
        {
            maxX = posX + shape -> getWidth( ) ;
        }
        if( posY + shape -> getHeight( ) > maxY )
        {
            maxY = posY + shape -> getHeight( ) ;
        }
    }
    return QRectF( minX , minY , maxX , maxY ) ;
}

QVariant Composite :: itemChange( GraphicsItemChange change , const QVariant &value )
{
    switch( change )
    {
        case ItemSelectedHasChanged :
            if( isSelected( ) )
            {
                setFlag( ItemIsMovable , true ) ;
                foreach( Shape *shape , members )
                {
                    shape -> setFlag( ItemIsMovable , false ) ;
                }
            }
            else
            {
                setFlag( ItemIsMovable , false ) ;
            }
            break ;
        case ItemPositionHasChanged :
            break ;
    }
    return QGraphicsItem :: itemChange( change , value ) ;
}
