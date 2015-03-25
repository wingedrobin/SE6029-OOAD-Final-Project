#include "use_case_object.h"
#include <QDebug>
#include <QCursor>

/**
 * @brief UseCaseObject
 *
 * UseCaseObject的預設建構子
 */
UseCaseObject :: UseCaseObject( ) : BasicObject( 150 , 100 )
{
    center = ( this -> boundingRect( ) ).center( ) ;
}

/**
 * @brief ~UseCaseObject
 *
 * UseCaseObject的解構子
 */
UseCaseObject :: ~UseCaseObject( )
{

}

/**
 * @brief shape
 * @return
 */
QPainterPath UseCaseObject :: shape( ) const
{
    QPainterPath path ;
    path.addEllipse( 0 , 0 , width , height );
    return path ;
}
