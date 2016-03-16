// $Id: return_node.h,v 1.1 2016/02/19 19:29:48 david Exp $ -*- c++ -*-
#ifndef __CDK_RETURNNODE_H__
#define __CDK_RETURNNODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing return nodes.
   */
  class return_node: public cdk::basic_node {
    cdk::expression_node *_expression;

  public:
    inline return_node(int lineno, cdk::expression_node *expression) :
        cdk::basic_node(lineno), _expression(expression) {
    }

  public:
    inline cdk::expression_node *expression() {
      return _expression;
    }
  

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // zu
//FIXME: _expression é expression_node ou basic ou outra??? 
#endif
 
