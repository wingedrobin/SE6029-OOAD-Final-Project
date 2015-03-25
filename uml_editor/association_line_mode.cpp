#include "association_line_mode.h"

/**
 * @brief AssociationLineMode
 *
 * AssociationLineMode的預設建構子
 */
AssociationLineMode :: AssociationLineMode( )
{

}

/**
 * @brief ~AssociationLineMode
 *
 * AssociationLineMode的解構子
 */
AssociationLineMode :: ~AssociationLineMode( )
{

}


void AssociationLineMode :: actionPerformed( )
{

}

void AssociationLineMode :: actionPerformed( bool )
{

}

void AssociationLineMode :: actionPerformed( QString )
{

}

/**
 * @brief mousePressEvent
 *
 * 處理Canvas上的mouse press event
 *
 * @param event 由Canvas上接收到滑鼠所產生的事件
 */
void AssociationLineMode :: mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    QPointF pos = event -> scenePos( ) ;

    //透過Canvas的getInstance函數存取其Canvas的getShape,取得Canvas上所有shape
    std :: vector< Shape* > *shapes = ( Canvas :: getInstance( ) ) -> getShapes( ) ;

    //對Canvas上的所有shape
    foreach( Shape *shape , *shapes )
    {
        //如果shape為basic ojbect
        if( BasicObject *basicObject = dynamic_cast< BasicObject* >( shape ) )
        {
            //判斷其是否為被點選
            if( basicObject -> isInside( pos ) == true )
            {
                startPort = basicObject -> getPort( pos ) ;
            }
        }
    }
}

/**
 * @brief mousePressEvent
 *
 * 處理Canvas上的mouse release event
 *
 * @param event 由Canvas上接收到滑鼠所產生的事件
 */
void AssociationLineMode :: mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
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
                AssociationLine *associationLine = new AssociationLine( startPort , endPort ) ;
                Canvas :: getInstance( ) -> addShape( associationLine ) ;
                startPort -> addLine( associationLine ) ;
                endPort -> addLine( associationLine ) ;
            }
        }
    }
}

void AssociationLineMode :: mouseDragEvent(QGraphicsSceneMouseEvent* event )
{
    Q_UNUSED( event ) ;
}
