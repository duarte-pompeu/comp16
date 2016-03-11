#ifndef __ZU_AST_EXPRESSION_AND_H__
#define __ZU_AST_EXPRESSION_AND_H__

#include <cdk/ast/binary_expression_node.h>

namespace zu {

  class and_node: public cdk::binary_expression_node {
  public:
    inline and_node(int lineno, expression_node *left, expression_node *right) :
        binary_expression_node(lineno, left, right) {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_and_node(this, level);
    }
  };
}

#endif
