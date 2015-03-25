#include "composition_line.h"
#include "port.h"

/**
 * @brief CompositionLine
 *
 * CompositionLine的預設建構子
 */
CompositionLine :: CompositionLine( ) : LineObject( )
{

}

CompositionLine :: CompositionLine( Port *start , Port *end ) : LineObject( start , end )
{

}

/**
 * @brief ~CompositionLine
 *
 * CompositionLine的解構子
 */
CompositionLine :: ~CompositionLine( )
{

}

QPainterPath CompositionLine :: shape( ) const
{
    QPointF sp = startPort-> scenePos( ) ;
    QPointF ep = endPort-> scenePos( ) ;
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
QPainterPath CompositionLine :: setArrow( QPointF endPos ) const
{
    QPainterPath path( endPos ) ;
    path.lineTo( endPos.x( ) - 10 , endPos.y( ) + 12 ) ;
    path.lineTo( endPos.x( ) , endPos.y( ) + 24 ) ;
    path.lineTo( endPos.x( ) + 10 , endPos.y( ) + 12 ) ;
    path.lineTo( endPos ) ;
    path.moveTo( endPos.x( ), endPos.y( ) + 24 ) ;
    return path ;
}
