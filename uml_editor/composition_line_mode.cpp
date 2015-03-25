#include "composition_line_mode.h"

CompositionLineMode :: CompositionLineMode( )
{

}

CompositionLineMode :: ~CompositionLineMode( )
{

}

void CompositionLineMode :: actionPerformed( )
{

}

void CompositionLineMode :: actionPerformed( bool )
{

}

void CompositionLineMode :: actionPerformed( QString )
{

}

void CompositionLineMode :: mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    QPointF pos = event -> scenePos( ) ;
    std :: vector< Shape* > *shapes = ( Canvas :: getInstance( ) ) -> getShapes( ) ;

    foreach( Shape *shape , *shapes )
    {
        if( BasicObject *basicObject = dynamic_cast< BasicObject* >( shape ) )
        {
            if( basicObject -> isInside( pos ) == true )
            {
                startPort = basicObject -> getPort( pos ) ;
            }
        }
    }
}

void CompositionLineMode :: mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    QPointF pos = event -> scenePos( ) ;
    std :: vector< Shape* > *shapes = ( Canvas :: getInstance( ) ) -> getShapes( ) ;

    foreach( Shape *shape , *shapes )
    {
        if( BasicObject *basicObject = dynamic_cast< BasicObject* >( shape ) )
        {
            if( basicObject -> isInside( pos ) == true )
            {
                endPort = basicObject -> getPort( pos ) ;
                CompositionLine *compositionLine = new CompositionLine( startPort , endPort ) ;
                Canvas :: getInstance( ) -> addShape( compositionLine ) ;
                startPort -> addLine( compositionLine ) ;
                endPort -> addLine( compositionLine ) ;
            }
        }
    }
}

void CompositionLineMode :: mouseDragEvent(QGraphicsSceneMouseEvent* event )
{
    Q_UNUSED( event ) ;
}
