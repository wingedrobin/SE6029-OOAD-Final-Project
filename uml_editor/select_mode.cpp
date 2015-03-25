#include "select_mode.h"
#include <QApplication>
#include <QGraphicsItem>

SelectMode :: SelectMode( )
{

}

SelectMode :: ~SelectMode( )
{

}

void SelectMode :: actionPerformed( )
{

}

void SelectMode :: actionPerformed( bool doGrouping )
{
    //Grouping
    if( doGrouping )
    {
        Composite *composite = new Composite ;
        int depth = 0 ,count=0;
        std :: vector< Shape* > *shapes = ( Canvas :: getInstance( ) ) -> getShapes( ) ;
        foreach( Shape* shape , *shapes )
        {
            if( shape -> isSelected( ) )
            {
                if( shape->zValue() >= depth )
                {
                    depth ++ ;
                }
                composite -> addObject( shape ) ;
            }
        }

        Canvas :: getInstance( ) -> addShape( composite ) ;
        composite -> setFlag( QGraphicsItem :: ItemIsMovable , true ) ;
        composite -> setZValue( depth ) ;
    }

    //Ungrouping
    else
    {
        int c = 0 , s = 0 ;
        std :: vector< Shape* > *shapes = ( Canvas :: getInstance( ) ) -> getShapes( ) ;
        for( std :: vector< Shape* > :: iterator it = shapes -> begin( ) ; it != shapes -> end( ) ; it ++ )
        {
            s ++ ;
            Shape *shape = *it ;
            if( Composite *composite = dynamic_cast< Composite* >( shape ) )
            {
                c ++ ;
                if( composite -> isSelected( ) )
                {
                    shapes -> erase( it ) ;
                }
            }
        }
    }
}

void SelectMode :: actionPerformed( QString name )
{
    std :: vector< Shape* > *shapes = ( Canvas :: getInstance( ) ) -> getShapes( ) ;
    foreach( Shape* shape , *shapes )
    {
        if( BasicObject *basicObject = dynamic_cast< BasicObject* >( shape ) )
        {
            if( basicObject -> isSelected( ) )
            {
                basicObject -> setName( name ) ;
            }
        }
    }
}

void SelectMode :: mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    this -> pressedPos = event -> scenePos( ) ;
}

/**
 * @brief SelectMode::mouseReleaseEvent
 * @param event
 */
void SelectMode :: mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    this -> releasedPos = event -> scenePos( ) ;
    std :: vector< Shape* > *shapes = ( Canvas :: getInstance( ) ) -> getShapes( ) ;

    int cnt = 0 ;
    foreach( Shape *shape , *shapes )
    {
        //如果滑鼠在Canvas上按下的位置跟釋放的位置相同,表示為點選
        if( pressedPos == releasedPos )
        {
            //如果在Canvas上滑鼠點選的位置落於Shape中,則將該Shape設定為select
            if( shape -> isInside( pressedPos ) == true )
            {
                shape -> setSelected( true ) ;
                cnt ++ ;
            }
            //反之則取消原本被選取的Shape
            else
            {
                shape -> setSelected( false ) ;
            }
        }
        //反之則為圈選
        else
        {
            if( shape -> isInside( pressedPos , releasedPos ) == true )
            {
                shape -> setSelected( true ) ;
                cnt ++ ;
            }
            else
            {
                shape -> setSelected( false ) ;
            }
        }
    }
}

void SelectMode :: mouseClickEvent( QGraphicsSceneMouseEvent* event )
{
    Q_UNUSED( event ) ;
}


void SelectMode :: mouseDragEvent(QGraphicsSceneMouseEvent* event )
{

}
