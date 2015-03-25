#include <QApplication>

//自定義標頭檔
#include "UML_Editor.h"

int main( int argc , char* argv[ ] )
{
    QApplication app( argc , argv ) ;

    UMLEditor umlEditor( 0 , Qt :: Window ) ;
    umlEditor.show( ) ;

    return app.exec( ) ;
}
