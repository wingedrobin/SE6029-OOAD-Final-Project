#include "canvas.h"

Canvas *Canvas :: uniqueInstance = NULL ;

Canvas :: Canvas( )
{

}

Canvas :: Canvas( qreal x , qreal y , qreal width , qreal height , QObject *parent ) : QGraphicsScene( x , y , width , height , parent )
{
    currentMode = new SelectMode( ) ;       //將select設定為預設的mode
}

Canvas :: ~Canvas( )
{

}

Canvas *Canvas :: getInstance( )
{
    if( uniqueInstance == NULL )
    {
        uniqueInstance = new Canvas ;
    }
    return uniqueInstance ;
}

Canvas *Canvas :: getInstance( qreal x , qreal y , qreal width , qreal height , QObject *parent )
{
    if( uniqueInstance == NULL )
    {
        uniqueInstance = new Canvas( x , y , width , height , parent ) ;
    }
    return uniqueInstance ;
}

Mode *Canvas :: getCurrentMode( )
{
    return currentMode ;
}

void Canvas :: addShape( Shape *shape )
{
    this -> shapes.push_back( shape ) ;
    this -> addItem( shape ) ;
}

void Canvas :: setSModeFlag( bool flag )
{
    sModeFlag = flag ;
}

std :: vector<Shape *> *Canvas :: getShapes( )
{
    return &( this -> shapes ) ;
}

void Canvas :: setCurrentMode( Mode *mode )
{
    currentMode = mode ;
}

void Canvas :: mousePressEvent( QGraphicsSceneMouseEvent *event )
{
    currentMode -> mousePressEvent( event ) ;
    update( ) ;
    QGraphicsScene :: mousePressEvent( event ) ;
}

void Canvas :: mouseReleaseEvent( QGraphicsSceneMouseEvent *event )
{
    currentMode -> mouseReleaseEvent( event ) ;
    update( ) ;
    QGraphicsScene :: mouseReleaseEvent( event ) ;
}

void Canvas :: mouseMoveEvent( QGraphicsSceneMouseEvent *event )
{
    currentMode -> mouseDragEvent( event ) ;
    update( ) ;
    if( sModeFlag )
    {
        QGraphicsScene :: mouseMoveEvent( event ) ;
    }
}
