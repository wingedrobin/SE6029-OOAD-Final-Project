#ifndef MODE_H
#define MODE_H

#include <QObject>
#include <QAction>
#include <QGraphicsScene>

//<<interface>>
class Mode : public QObject
{
    Q_OBJECT

    public :
        virtual void mousePressEvent( QGraphicsSceneMouseEvent*  ) = 0 ;
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent*  ) = 0 ;
        virtual void mouseDragEvent(QGraphicsSceneMouseEvent* ) = 0 ;

        virtual void actionPerformed( ) = 0 ;
        virtual void actionPerformed( bool ) = 0 ;
        virtual void actionPerformed( QString ) = 0 ;
} ;

#endif // MODE_H
