#include "uml_editor.h"
#include <QDebug>

/**
 * @brief UMLEditor::UMLEditor
 *
 * UML Editor的建構子
 *
 * @param parent UML Editor的parent widget
 * @param f Qt::WindowType
 */
UMLEditor :: UMLEditor( QWidget *parent , Qt::WindowFlags f ) : QWidget( parent , f )
{
    //建立Actions,選單,設定排版及view區域
//    setNamingDialog( ) ;
    createActions( ) ;
    createMenus( ) ;
    createButtons( ) ;
    groupingButtons( ) ;
    createViewArea( ) ;
    setLayouts( ) ;
    groupingActions( ) ;
}

/**
 * @brief UMLEditor::~UMLEditor
 *
 * UML Editor的解構子
 */
UMLEditor :: ~UMLEditor( )
{

}

/**
 * @brief UMLEditor::createMenus
 *
 * 建立選單
 */
void UMLEditor :: createMenus( )
{
    //建立選單欄
    menuBar = new QMenuBar( this ) ;

    //建立File選單
    fileMenu = new QMenu( tr( "File" ) , this ) ;

    //在選單欄中加入File選單
    menuBar -> addMenu( fileMenu ) ;
    //fileMenu -> addAcion( ) ;

    //在選單欄中加入Edit選單
    editMenu = new QMenu( tr( "Edit" ) , this ) ;

    //在選單欄中加入Edit選單
    menuBar -> addMenu( editMenu ) ;
    editMenu -> addAction( groupAction ) ;                  //Edit選項下加入group action
    editMenu -> addAction( ungroupAction ) ;                //Edit選項下加入ungroup action
    editMenu -> addAction( changeObjectNameAction ) ;       //Edit選項下加入change object name action
}

/**
 * @brief UMLEditor::createActions
 *
 * 建立Edit選單內的功能action
 */
void UMLEditor :: createActions( )
{
    groupAction = new QAction( tr( "Group" ) , this ) ;
//    connect( groupAction , SIGNAL( triggered( ) ) , this , SLOT( objectGroup( ) ) ) ;

    ungroupAction = new QAction( tr( "Ungroup" ) , this ) ;
//    connect( groupAction , SIGNAL( triggered( ) ) , this , SLOT( objectUngroup( ) ) ) ;

    changeObjectNameAction = new QAction( tr( "Change Object Name" ) , this ) ;
//    connect( changeObjectNameAction , SIGNAL( triggered( ) ) , this , SLOT( createNamingDialog( ) ) ) ;
}

/**
 * @brief UMLEditor::createButtons
 *
 * 建立按鈕
 */
void UMLEditor :: createButtons( )
{
    selectButton = new QPushButton( QIcon( "select.png" ) , tr( "Select" ) , this ) ;
    associationLineButton = new QPushButton( QIcon( "association.png" ) , tr( "Association Line" ) , this ) ;
    generalizationLineButton = new QPushButton( QIcon( "generalization.png" ) ,tr( "Generalization Line" ) , this ) ;
    compositionLineButton = new QPushButton( QIcon( "composition.png" ) , tr( "Composition Line" ) , this ) ;
    classButton = new QPushButton( QIcon( "class.png" ) , tr( "Class" ) , this ) ;
    useCaseButton = new QPushButton( QIcon( "use case.png" ) , tr( "Use Case" ) , this ) ;
}

/**
 * @brief UMLEditor::groupingButtons
 *
 * Group所有按鈕
 */
void UMLEditor :: groupingButtons( )
{
    buttonGroup = new QButtonGroup ;
    buttonGroup -> addButton( selectButton , 0 ) ;
    buttonGroup -> addButton( associationLineButton , 1 ) ;
    buttonGroup -> addButton( generalizationLineButton , 2 ) ;
    buttonGroup -> addButton( compositionLineButton , 3 ) ;
    buttonGroup -> addButton( classButton , 4 ) ;
    buttonGroup -> addButton( useCaseButton , 5 ) ;
    buttonGroup -> setExclusive( true ) ;
    connect( buttonGroup , SIGNAL( buttonClicked( int ) ) , this , SLOT( buttonClickedAction( int ) ) ) ;
}

void UMLEditor :: groupingActions( )
{
    actionGroup = new QActionGroup( this ) ;
    actionGroup -> addAction( groupAction ) ;
    actionGroup -> addAction( ungroupAction ) ;
    actionGroup -> addAction( changeObjectNameAction ) ;
    actionGroup -> setExclusive( true ) ;
    connect( actionGroup , SIGNAL( triggered( QAction* ) ) , this , SLOT( actionPerformed( QAction * ) ) ) ;
}

/**
 * @brief UMLEditor::createViewArea
 *
 * 建立view區域
 */
void UMLEditor :: createViewArea( )
{
    //建立畫布
    canvas = Canvas :: getInstance( 0 , 0 , 800 , 600 , this ) ;

    //建立view區域
    graphicsViewArea = new QGraphicsView( this ) ;

    //設定view區域所對應的scene
    graphicsViewArea -> setScene( canvas ) ;
}

/**
 * @brief UMLEditor::setLayouts
 *
 * 設定UML Editor所有widgets的排版
 */
void UMLEditor :: setLayouts( )
{
    //建立視窗左方的排版
    leftLayout = new QVBoxLayout ;

    //將Buttons加入視窗的leftLayout
    leftLayout -> addWidget( selectButton ) ;
    leftLayout -> addWidget( associationLineButton ) ;
    leftLayout -> addWidget( generalizationLineButton ) ;
    leftLayout -> addWidget( compositionLineButton ) ;
    leftLayout -> addWidget( classButton ) ;
    leftLayout -> addWidget( useCaseButton ) ;
    leftLayout -> addStretch( ) ;

    //建立視窗中間排版
    middleLayout = new QHBoxLayout ;

    //將左方排版及view區域加入middleLayout
    middleLayout -> addLayout( leftLayout ) ;
    middleLayout -> addWidget( graphicsViewArea ) ;

    //建立整個視窗的排版
    mainLayout = new QVBoxLayout ;

    //將選單欄及middleLayout加入mainLayout
    mainLayout -> setMenuBar( menuBar ) ;
    mainLayout -> addLayout( middleLayout ) ;

    //設定視窗邊界空白間距
    mainLayout -> setContentsMargins( 0 , 0 , 0 , 0 );

    //將mainLayout設定為UML Editor的layout
    this -> setLayout( mainLayout ) ;
}

void UMLEditor :: buttonClickedAction( int id )
{
    QList< QAbstractButton* > buttons = buttonGroup -> buttons( ) ;
    foreach( QAbstractButton *button , buttons )
    {
        if( buttonGroup -> button( id ) != button )
        {
            button -> setChecked( false ) ;
            button -> setStyleSheet( "border-color: navy;" ) ;
        }
        else
        {
            button -> setChecked( true ) ;
            button -> setStyleSheet( "background-color: rgb(135 , 206, 255);" ) ;
        }
    }
    switch( id )
    {
        case 0 :
            mode = new SelectMode ;
            this -> canvas -> setCurrentMode( mode ) ;
            canvas -> setSModeFlag( true ) ;
            break ;
        case 1 :
            mode = new AssociationLineMode ;
            this -> canvas -> setCurrentMode( mode ) ;
            canvas -> setSModeFlag( false ) ;
            break ;
        case 2 :
            mode = new GeneralizationLineMode ;
            this -> canvas -> setCurrentMode( mode ) ;
            canvas -> setSModeFlag( false ) ;
            break ;
        case 3 :
            mode = new CompositionLineMode ;
            this -> canvas -> setCurrentMode( mode ) ;
            canvas -> setSModeFlag( false ) ;
            break ;
        case 4 :
            mode = new ClassMode ;
            this -> canvas -> setCurrentMode( mode ) ;
            canvas -> setSModeFlag( false ) ;
            break ;
        case 5 :
            mode = new UseCaseMode ;
            this -> canvas -> setCurrentMode( mode ) ;
            canvas -> setSModeFlag( false ) ;
            break ;
    }
}

void UMLEditor :: actionPerformed( QAction *action )
{
    QString text = action -> text( ) ;
    if( text == "Group" )
    {
        this -> mode -> actionPerformed( true ) ;
    }
    else if( text == "Ungroup" )
    {
        this -> mode -> actionPerformed( false ) ;
    }
    else if( text == "Change Object Name" )
    {
        bool isOK ;
        QString name = QInputDialog :: getText( this , "Change object name" , "Enter a name", QLineEdit :: Normal, "input" , &isOK ) ;
        if( isOK && !name.isEmpty( ) )
        {
            this -> mode -> actionPerformed( name ) ;
        }
    }
}
