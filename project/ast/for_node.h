// $Id: while_node.h,v 1.1 2016/02/19 19:29:48 david Exp $ -*- c++ -*-
#ifndef __ZU_FORNODE_H__
#define __ZU_FORNODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  class for_node: public cdk::basic_node {
	cdk::expression_node *_init;  
    cdk::expression_node *_condition;
    cdk::expression_node *_incr;
    cdk::basic_node *_block;

  public:
    inline for_node(int lineno, cdk::expression_node *init, cdk::expression_node *condition, 
		cdk::expression_node *incr, cdk::basic_node *block) :
        basic_node(lineno), _init(init), _condition(condition), _incr(incr), _block(block) {
    }

  public:
    inline cdk::expression_node *init() {
      return _init;
    }
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline cdk::expression_node *incr() {
      return _incr;
    }
    inline cdk::basic_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_for_node(this, level);
    }

  };

} // zu

#endif
