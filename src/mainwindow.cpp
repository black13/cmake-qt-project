
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "call_back.h"
#include <QDebug>
#include "s7.h"

static s7_pointer dax_to_string(s7_scheme *sc, s7_pointer args)
{
  char *data_str, *str;
  s7_pointer result;
  int data_str_len;
  MainWindow *o = (MainWindow *)s7_c_object_value(s7_car(args));
  
  result = s7_make_string(sc, "mainwindow");
  
  return(result);
}

static void free_dax(void *val)
{
  if (val) free(val);
}

static bool equal_dax(void *val1, void *val2)
{
  return(val1 == val2);
}

static void mark_dax(void *val)
{
  MainWindow *o = (MainWindow *)val;
}

static int dax_type_tag = 0;

static s7_pointer make_dax(s7_scheme *sc, s7_pointer args)
{
  MainWindow *o;
 
  return(s7_make_c_object(sc, dax_type_tag, (void *)o));
}

static s7_pointer is_dax(s7_scheme *sc, s7_pointer args)
{
  return(s7_make_boolean(sc, 
			 s7_is_c_object(s7_car(args)) &&
			 s7_c_object_type(s7_car(args)) == dax_type_tag));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    env = s7_init();
    //s7_define_variable(env, "my-pi", s7_make_real(env, 3.14159265));
    //store a pointer to the mainwindow
    auto dax_type_tag = s7_make_c_type(env, "MainWindow");
    s7_make_c_object(env, dax_type_tag, (void *)this);
    

    s7_define_variable(env, "an-integer", s7_make_integer(env, 1));
    s7_eval_c_string(env, "(define (add1 a) (+ a 1))");
    qDebug() << s7_integer(s7_name_to_value(env, "an-integer")) ;
    
    s7_symbol_set_value(env, s7_make_symbol(env, "an-integer"), s7_make_integer(env, 32));

    qDebug() << s7_integer(s7_name_to_value(env, "an-integer"));

    qDebug() << s7_integer(s7_call(env, 
			     s7_name_to_value(env, "add1"), 
			     s7_cons(env, s7_make_integer(env, 2), s7_nil(env))));
    

    dax_type_tag = s7_make_c_type(env, "dax");
    s7_c_type_set_equal(env, dax_type_tag, equal_dax);
    s7_c_type_set_mark(env, dax_type_tag, mark_dax);
    s7_c_type_set_to_string(env, dax_type_tag, dax_to_string);
  
    s7_define_function(env, "make-dax", make_dax, 0, 0, false, "(make-dax x data) makes a new dax");
    s7_define_function(env, "dax?", is_dax, 1, 0, false, "(dax? anything) returns #t if its argument is a dax object");

 

    auto qwidget=ui->centralWidget->findChild<QObject*>("m_pushbutton");
    
    //s7_define_variable(env, "dax-data", s7_dilambda(env, "dax-data", dax_data, 1, 0, set_dax_data, 2, 0, "dax data field"));

    connect(qwidget , SIGNAL (released()),this, SLOT (on_pushbutton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_pushbutton()
{
    s7_eval_c_string(env,"(define obj (make-dax))");
    s7_eval_c_string(env,"(dax? obj)");
     //o = (dax *)s7_c_object_value(s7_car(args));
    //retrieve the pointer;
    //f(this,1); 
}
extern "C" int call_M_foo(MainWindow* m, int i) { return m->foo(i); }