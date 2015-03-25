#include "generalization_line.h"
#include "port.h"

/**
 * @brief GeneralizationLine
 *
 * GeneralizationLine的預設建構子
 */
GeneralizationLine :: GeneralizationLine( )
{

}

GeneralizationLine :: GeneralizationLine( Port *start , Port *end ) : LineObject( start , end )
{

}

/**
 * @brief ~GeneralizationLine
 *
 * GeneralizationLine的解構子
 */
GeneralizationLine :: ~GeneralizationLine( )
{

}

QPainterPath GeneralizationLine :: shape( ) const
{
    QPointF sp = startPort -> scenePos( ) ;
    QPointF ep = endPort -> scenePos( ) ;
    QPainterPath linePath ;
    linePath.addPath( setArrow( ep ) ) ;
    linePath.lineTo( sp ) ;
    return linePath ;
}

/**
 * @brief drawArrow
 *
 * 在LineObject的某一端畫上箭頭
 */
QPainterPath GeneralizationLine :: setArrow( QPointF endPos ) const
{
    QPainterPath path( endPos ) ;
    path.lineTo( endPos.x( ) - 20 , endPos.y( ) - 10 ) ;
    path.lineTo( endPos.x( ) - 20 , endPos.y( ) + 10 ) ;
    path.lineTo( endPos ) ;
    return path ;
}
