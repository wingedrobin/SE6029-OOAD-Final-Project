#include "use_case_mode.h"
#include <QDebug>
UseCaseMode :: UseCaseMode( )
{

}

UseCaseMode :: ~UseCaseMode( )
{

}

void UseCaseMode :: actionPerformed( )
{

}

void UseCaseMode :: actionPerformed( bool )
{

}

void UseCaseMode :: actionPerformed( QString )
{

}

void UseCaseMode :: mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    Q_UNUSED( event ) ;
}

void UseCaseMode :: mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    QPointF pos = event -> buttonDownScenePos( Qt :: LeftButton ) ;
    Shape *useCaseObject = new UseCaseObject ;
    useCaseObject -> setPos( pos.x( ) , pos.y( ) );
    Canvas :: getInstance( ) -> addShape( useCaseObject ) ;
}

void UseCaseMode :: mouseDragEvent( QGraphicsSceneMouseEvent* event )
{
    Q_UNUSED( event ) ;
}
