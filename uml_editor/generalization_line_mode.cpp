#include "generalization_line_mode.h"

GeneralizationLineMode :: GeneralizationLineMode( )
{

}

GeneralizationLineMode :: ~GeneralizationLineMode( )
{

}

void GeneralizationLineMode :: actionPerformed( )
{

}

void GeneralizationLineMode :: actionPerformed( bool )
{

}

void GeneralizationLineMode :: actionPerformed( QString )
{

}

void GeneralizationLineMode :: mousePressEvent( QGraphicsSceneMouseEvent* event )
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

void GeneralizationLineMode :: mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
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
                GeneralizationLine *generalizationLine = new GeneralizationLine( startPort , endPort ) ;
                Canvas :: getInstance( ) -> addShape( generalizationLine ) ;
                startPort -> addLine( generalizationLine ) ;
                endPort -> addLine( generalizationLine ) ;
            }
        }
    }
}

void GeneralizationLineMode :: mouseDragEvent(QGraphicsSceneMouseEvent* event )
{
    Q_UNUSED( event ) ;
}
