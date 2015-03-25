#include "basic_object.h"

#include <QStyle>
#include <QStyleOption>

/**
 * @brief BasicObject
 *
 * BasicObject的預設建構子
 */
BasicObject :: BasicObject( )
{


}

/**
 * @brief BasicObject
 *
 * BasicObject的建構子
 */
BasicObject :: BasicObject( int w , int h ) : Shape( w , h )
{
    name = '\0' ;
    center = ( this -> boundingRect( ) ).center( ) ;
    setPorts( ) ;
}

/**
 * @brief ~BasicObject
 *
 * BasicObject的解構子
 */
BasicObject :: ~BasicObject( )
{

}

/**
 * @brief paint
 *
 * 繼承自QGraphicsItem的虛擬函數,繪製各種subclass的圖形形狀
 */
void BasicObject :: paint( QPainter *painter , const QStyleOptionGraphicsItem *option , QWidget *widget )
{
    painterPath = shape( ) ;
    painter -> setPen( pen ) ;

    //使用者輸入object name後,在其中心畫出name
    if( name != '\0' )
    {
        center = ( boundingRect( ) ).center( ) ;
        painter -> drawText( center , name ) ;
    }
    painter -> drawPath( painterPath ) ;
}

/**
 * @brief isInside
 *
 * 確認Canvas上被點選的位置是否存在Shape
 */
bool BasicObject :: isInside( QPointF pos )
{
    QRectF bound = boundingRect( ) ;
    pos = mapFromScene( pos ) ;         //將Canvas的座標系統轉成Item的座標系統
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
 * 確認Canvas上被圈選的範圍中是否存在Shape
 */
bool BasicObject :: isInside( QPointF pos1 , QPointF pos2 )
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
 * 繼承自QGraphicsItem的虛擬函數,由各subclass定義出的shape(形狀)計算出邊界範圍
 */
QRectF BasicObject :: boundingRect( ) const
{
    return this -> painterPath.boundingRect( ) ;
}

/**
 * @brief setName
 *
 * 設定basic object的名稱
 *
 * @param name 使用者所輸入指定的Object名稱
 */
void BasicObject :: setName( QString name )
{
    this -> name = name ;
}

/**
 * @brief setPorts
 *
 * 設定4個Port在basic object上個別的位置
 */
void BasicObject :: setPorts( )
{
    for( int i = 0 ; i < 4 ; i ++ )
    {
        ports[ i ].setParentItem( this ) ;
        ports[ i ].setVisible( false ) ;
    }

    ports[ 0 ].setPos( width / 2 , 0 ) ;
    ports[ 1 ].setPos( width , height / 2 ) ;
    ports[ 2 ].setPos( width / 2 , height ) ;
    ports[ 3 ].setPos( 0 , height / 2 ) ;
}

/**
 * @brief getPort
 *
 * 找出basic object被點選時,距離最近的Port
 *
 * @param pressed 在Basic Object範圍中被點選到位置
 * @return 距離最近的Port
 */
Port *BasicObject :: getPort( QPointF pressed )
{
    qreal pX = pressed.x( ) ;
    qreal pY = pressed.y( ) ;

    qreal LRBound = ( pX - x( ) ) * height - ( pY - y( ) ) * width ;
    qreal RLBound = ( pX - x( ) ) * height + ( pY - y( ) - height ) * width ;

    if( LRBound > 0 && RLBound < 0 )
    {
        return &( ports[ 0 ] ) ;
    }
    else if( LRBound > 0 && RLBound > 0 )
    {
        return &( ports[ 1 ] ) ;
    }
    else if( LRBound < 0 && RLBound > 0 )
    {
        return &( ports[ 2 ] ) ;
    }
    else    //right < 0 && leftDiag < 0
    {
        return &( ports[ 3 ] ) ;
    }
}

/**
 * @brief BasicObject::itemChange
 *
 * 繼承自QGraphicsItem的虛擬函數
 *
 * @param change
 * @param value
 * @return
 */
QVariant BasicObject :: itemChange( GraphicsItemChange change , const QVariant &value )
{
    switch( change )
    {
        case ItemSelectedHasChanged :
            if ( isSelected( ) )
            {
                setFlag( ItemIsMovable , true ) ;
                for( int i = 0 ; i < 4 ; i ++ )
                {
                    ports[ i ].setVisible( true ) ;
                }
            }
            else
            {
                setFlag( ItemIsMovable , false ) ;
                for( int i = 0 ; i < 4 ; i ++ )
                {
                    ports[ i ].setVisible( false ) ;
                }
            }
            break ;
        case ItemPositionHasChanged :
            break ;
    }
    return QGraphicsItem :: itemChange( change , value ) ;
}
