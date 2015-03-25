#include "class_object.h"

/**
 * @brief ClassObject
 *
 * ClassObject的預設建構子
 */
ClassObject :: ClassObject( ) : BasicObject( 150 , 150 )
{

}

/**
 * @brief ~ClassObject
 *
 * ClassObject的解構子
 */
ClassObject :: ~ClassObject( )
{

}

/**
 * @brief shape
 * @return
 */
QPainterPath ClassObject :: shape( ) const
{
    QPainterPath path ;

    //設定Item自身的座標系統下的shape path
    path.addRect( 0 , 0 , width , height ) ;
    path.moveTo( 0 , height / 3 ) ;
    path.lineTo( width , height / 3 ) ;
    path.moveTo( 0 , height / 1.5 ) ;
    path.lineTo( width , height / 1.5 ) ;
    return path ;
}
