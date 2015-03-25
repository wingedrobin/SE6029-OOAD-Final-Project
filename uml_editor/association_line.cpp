#include "association_line.h"
#include "port.h"

/**
 * @brief AssociationLine
 *
 * AssocaitionLine的預設建構子
 */
AssociationLine :: AssociationLine( )
{

}

/**
 * @brief AssociationLine
 *
 * AssociationLine的建構子
 */
AssociationLine :: AssociationLine( Port *start , Port *end ) : LineObject( start , end )
{

}

/**
  * @brief ~AssociationLine
  *
  * AssociationLine的解構子
  */
AssociationLine :: ~AssociationLine( )
{

}

/**
 * @brief shape
 *
 * 要被繪製Line Object的路徑
 *
 * @return line path 路徑
 */
QPainterPath AssociationLine :: shape( ) const
{
    QPointF sp = startPort-> scenePos( ) ;
    QPointF ep = endPort-> scenePos( ) ;
    QPainterPath linePath( sp ) ;
    linePath.lineTo( ep ) ;
    return linePath ;
}

/**
 * @brief drawArrow
 *
 * 在LineObject的某一端畫上箭頭
 */
QPainterPath AssociationLine :: setArrow( QPointF ) const
{
    QPainterPath path ;
    return  path ;
}
