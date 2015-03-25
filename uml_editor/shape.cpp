#include "shape.h"

/**
 * @brief Shape
 *
 * Shape的預設建構子
 */
Shape :: Shape( )
{
    setSelected( false ) ;
}

/**
 * @brief Shape
 *
 * Shape的建構子
 *
 * @param pos Shape的(x,y)座標
 */
Shape :: Shape( int w , int h ) : width( w ) , height( h )
{
    pen.setWidth( 2 ) ;
    setSelected( false ) ;
    setFlags( ItemIsSelectable ) ;
}

Shape :: ~Shape( )
{

}

int Shape :: getWidth( )
{
    return width ;
}

int Shape :: getHeight( )
{
    return height ;
}

/**
 * @brief depthLessThen
 *
 * 判斷與其它Shape的相對深度
 *
 * @return 要回傳1.是否深度較淺 或2.回傳深度值
 */
bool Shape :: depthLessThen( Shape * )
{
    return false ;
}
