#include "class_mode.h"

ClassMode :: ClassMode( )
{

}

ClassMode :: ~ClassMode( )
{

}

void ClassMode :: actionPerformed( )
{

}

void ClassMode :: actionPerformed( bool )
{

}

void ClassMode :: actionPerformed( QString )
{

}

void ClassMode :: mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    Q_UNUSED( event ) ;
}

void ClassMode :: mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    QPointF pos = event -> scenePos( ) ;
    Shape *classObject = new ClassObject ;
    classObject -> setPos( pos.x( ) , pos.y( ) ) ;
    Canvas :: getInstance( ) -> addShape( classObject ) ;
}

void ClassMode :: mouseDragEvent(QGraphicsSceneMouseEvent* event )
{
    Q_UNUSED( event ) ;
}
