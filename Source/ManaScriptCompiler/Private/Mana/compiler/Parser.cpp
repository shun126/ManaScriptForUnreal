// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 43 "Parser.yy"

	#include "../runner/common/Setup.h"
	#include "ErrorHandler.h"
	#include "Lexer.h"
	#include "ParsingDriver.h"
	#include "Symbol.h"
	#include "SyntaxNode.h"
	#include "TypeDescriptor.h"

#include "CodeGenerator.h"
#include "GlobalAddressResolver.h"
#include "GlobalSemanticAnalyzer.h"
#include "DataBuffer.h"
#include "SyntaxNode.h"
#include "TypeDescriptorFactory.h"

	#include "ParserDeclaration.inl"
	#include <memory>
	#include <string_view>

#line 60 "Parser.cpp"


// First part of user prologue.
#line 1 "Parser.yy"

/*!
mana (compiler)

@author	Shun Moriya
@date	2003-
*/

#if MANA_BUILD_TARGET < MANA_BUILD_RELEASE
#define YYERROR_VERBOSE
#endif


#line 78 "Parser.cpp"


#include "Parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 19 "Parser.yy"
namespace mana {
#line 157 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (mana::ParsingDriver* mParsingDriver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      mParsingDriver (mParsingDriver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_action_ref: // action_ref
        value.copy< mana::ActionReference > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tREAL: // tREAL
        value.copy< mana::float_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        value.copy< mana::int_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_line: // line
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_allocate_declarations: // allocate_declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_actor: // actor
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_members: // struct_members
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_function: // function
      case symbol_kind::S_variable_type: // variable_type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_constant: // constant
      case symbol_kind::S_left_hand: // left_hand
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case: // case
      case symbol_kind::S_arg_calls: // arg_calls
      case symbol_kind::S_arg_decls: // arg_decls
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_variable_sizes: // variable_sizes
      case symbol_kind::S_variable_size: // variable_size
        value.copy< std::shared_ptr<mana::SyntaxNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        value.copy< std::shared_ptr<mana::TypeDescriptor> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        value.copy< std::string_view > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_action_ref: // action_ref
        value.move< mana::ActionReference > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tREAL: // tREAL
        value.move< mana::float_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        value.move< mana::int_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_line: // line
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_allocate_declarations: // allocate_declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_actor: // actor
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_members: // struct_members
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_function: // function
      case symbol_kind::S_variable_type: // variable_type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_constant: // constant
      case symbol_kind::S_left_hand: // left_hand
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case: // case
      case symbol_kind::S_arg_calls: // arg_calls
      case symbol_kind::S_arg_decls: // arg_decls
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_variable_sizes: // variable_sizes
      case symbol_kind::S_variable_size: // variable_size
        value.move< std::shared_ptr<mana::SyntaxNode> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        value.move< std::shared_ptr<mana::TypeDescriptor> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< std::string_view > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_action_ref: // action_ref
        value.YY_MOVE_OR_COPY< mana::ActionReference > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tREAL: // tREAL
        value.YY_MOVE_OR_COPY< mana::float_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        value.YY_MOVE_OR_COPY< mana::int_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_line: // line
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_allocate_declarations: // allocate_declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_actor: // actor
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_members: // struct_members
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_function: // function
      case symbol_kind::S_variable_type: // variable_type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_constant: // constant
      case symbol_kind::S_left_hand: // left_hand
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case: // case
      case symbol_kind::S_arg_calls: // arg_calls
      case symbol_kind::S_arg_decls: // arg_decls
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_variable_sizes: // variable_sizes
      case symbol_kind::S_variable_size: // variable_size
        value.YY_MOVE_OR_COPY< std::shared_ptr<mana::SyntaxNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        value.YY_MOVE_OR_COPY< std::shared_ptr<mana::TypeDescriptor> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        value.YY_MOVE_OR_COPY< std::string_view > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_action_ref: // action_ref
        value.move< mana::ActionReference > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tREAL: // tREAL
        value.move< mana::float_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        value.move< mana::int_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_line: // line
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_allocate_declarations: // allocate_declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_actor: // actor
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_members: // struct_members
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_function: // function
      case symbol_kind::S_variable_type: // variable_type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_constant: // constant
      case symbol_kind::S_left_hand: // left_hand
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case: // case
      case symbol_kind::S_arg_calls: // arg_calls
      case symbol_kind::S_arg_decls: // arg_decls
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_variable_sizes: // variable_sizes
      case symbol_kind::S_variable_size: // variable_size
        value.move< std::shared_ptr<mana::SyntaxNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        value.move< std::shared_ptr<mana::TypeDescriptor> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< std::string_view > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_action_ref: // action_ref
        value.copy< mana::ActionReference > (that.value);
        break;

      case symbol_kind::S_tREAL: // tREAL
        value.copy< mana::float_t > (that.value);
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        value.copy< mana::int_t > (that.value);
        break;

      case symbol_kind::S_line: // line
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_allocate_declarations: // allocate_declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_actor: // actor
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_members: // struct_members
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_function: // function
      case symbol_kind::S_variable_type: // variable_type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_constant: // constant
      case symbol_kind::S_left_hand: // left_hand
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case: // case
      case symbol_kind::S_arg_calls: // arg_calls
      case symbol_kind::S_arg_decls: // arg_decls
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_variable_sizes: // variable_sizes
      case symbol_kind::S_variable_size: // variable_size
        value.copy< std::shared_ptr<mana::SyntaxNode> > (that.value);
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        value.copy< std::shared_ptr<mana::TypeDescriptor> > (that.value);
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        value.copy< std::string_view > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_action_ref: // action_ref
        value.move< mana::ActionReference > (that.value);
        break;

      case symbol_kind::S_tREAL: // tREAL
        value.move< mana::float_t > (that.value);
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        value.move< mana::int_t > (that.value);
        break;

      case symbol_kind::S_line: // line
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_allocate_declarations: // allocate_declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_actor: // actor
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_members: // struct_members
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_function: // function
      case symbol_kind::S_variable_type: // variable_type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_constant: // constant
      case symbol_kind::S_left_hand: // left_hand
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case: // case
      case symbol_kind::S_arg_calls: // arg_calls
      case symbol_kind::S_arg_decls: // arg_decls
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_variable_sizes: // variable_sizes
      case symbol_kind::S_variable_size: // variable_size
        value.move< std::shared_ptr<mana::SyntaxNode> > (that.value);
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        value.move< std::shared_ptr<mana::TypeDescriptor> > (that.value);
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< std::string_view > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_action_ref: // action_ref
        yylhs.value.emplace< mana::ActionReference > ();
        break;

      case symbol_kind::S_tREAL: // tREAL
        yylhs.value.emplace< mana::float_t > ();
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        yylhs.value.emplace< mana::int_t > ();
        break;

      case symbol_kind::S_line: // line
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_allocate_declarations: // allocate_declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_actor: // actor
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_members: // struct_members
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_function: // function
      case symbol_kind::S_variable_type: // variable_type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_constant: // constant
      case symbol_kind::S_left_hand: // left_hand
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case: // case
      case symbol_kind::S_arg_calls: // arg_calls
      case symbol_kind::S_arg_decls: // arg_decls
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_variable_sizes: // variable_sizes
      case symbol_kind::S_variable_size: // variable_size
        yylhs.value.emplace< std::shared_ptr<mana::SyntaxNode> > ();
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        yylhs.value.emplace< std::shared_ptr<mana::TypeDescriptor> > ();
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        yylhs.value.emplace< std::string_view > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: line
#line 121 "Parser.yy"
                                        {
						auto root = mParsingDriver->InjectGlobalInitializers(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ());
						mParsingDriver->SetRootSyntaxNode(root);

						auto globalSemanticAnalyzer = mParsingDriver->GetGlobalSemanticAnalyzer();
						globalSemanticAnalyzer->Resolve(root);

						auto codeGenerator = mParsingDriver->GetCodeGenerator();
						codeGenerator->GenerateCode(root, true);

						auto globalAddressResolver = mParsingDriver->GetCodeGenerator()->GetGlobalAddressResolver();
						globalAddressResolver->ResolveAddress();
					}
#line 1015 "Parser.cpp"
    break;

  case 3: // line: %empty
#line 137 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1021 "Parser.cpp"
    break;

  case 4: // line: declarations line
#line 139 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1027 "Parser.cpp"
    break;

  case 5: // declarations: actor
#line 142 "Parser.yy"
                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1033 "Parser.cpp"
    break;

  case 6: // declarations: struct
#line 143 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1039 "Parser.cpp"
    break;

  case 7: // declarations: function
#line 144 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1045 "Parser.cpp"
    break;

  case 8: // declarations: declaration ';'
#line 145 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1051 "Parser.cpp"
    break;

  case 9: // declarations: tNAMESPACE qualified_name '{' line '}'
#line 147 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNamespace(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1057 "Parser.cpp"
    break;

  case 10: // declarations: tUSING qualified_name ';'
#line 149 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateUsing(yystack_[1].value.as < std::string_view > ()); }
#line 1063 "Parser.cpp"
    break;

  case 11: // declarations: tNATIVE variable_type tIDENTIFIER '(' arg_decls ')' ';'
#line 152 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNativeFunction(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::string_view > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1069 "Parser.cpp"
    break;

  case 12: // declarations: tALLOCATE tDIGIT '{' allocate_declarations '}'
#line 155 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareMemory(yystack_[3].value.as < mana::int_t > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1075 "Parser.cpp"
    break;

  case 13: // declarations: tSTATIC '{' allocate_declarations '}'
#line 157 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareStaticMemory(0, yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1081 "Parser.cpp"
    break;

  case 14: // declarations: tSTATIC tALLOCATE tDIGIT '{' allocate_declarations '}'
#line 159 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareStaticMemory(yystack_[3].value.as < mana::int_t > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1087 "Parser.cpp"
    break;

  case 15: // declarations: tINCLUDE tSTRING ';'
#line 162 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; if(! lexer::Open(yystack_[1].value.as < std::string_view > (), false)){ YYABORT; } }
#line 1093 "Parser.cpp"
    break;

  case 16: // declarations: tIMPORT tSTRING ';'
#line 164 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; if(! lexer::Open(yystack_[1].value.as < std::string_view > (), true)){ YYABORT; } }
#line 1099 "Parser.cpp"
    break;

  case 17: // allocate_declarations: %empty
#line 169 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1105 "Parser.cpp"
    break;

  case 18: // allocate_declarations: variable_decl ';' allocate_declarations
#line 171 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1111 "Parser.cpp"
    break;

  case 19: // declaration: variable_decl
#line 174 "Parser.yy"
                          { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1117 "Parser.cpp"
    break;

  case 20: // declaration: const_decl
#line 175 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1123 "Parser.cpp"
    break;

  case 21: // actor: tACTOR tIDENTIFIER '{' actions '}'
#line 179 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateActor(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1129 "Parser.cpp"
    break;

  case 22: // actor: tPHANTOM tIDENTIFIER '{' actions '}'
#line 181 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreatePhantom(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1135 "Parser.cpp"
    break;

  case 23: // actor: tMODULE tIDENTIFIER '{' actions '}'
#line 183 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateModule(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1141 "Parser.cpp"
    break;

  case 24: // actions: %empty
#line 187 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1147 "Parser.cpp"
    break;

  case 25: // actions: action actions
#line 189 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1153 "Parser.cpp"
    break;

  case 26: // action: tACTION tIDENTIFIER block
#line 193 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAction(yystack_[1].value.as < std::string_view > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1159 "Parser.cpp"
    break;

  case 27: // action: tEXTEND qualified_name ';'
#line 195 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateExtend(yystack_[1].value.as < std::string_view > ()); }
#line 1165 "Parser.cpp"
    break;

  case 28: // action: declaration ';'
#line 196 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1171 "Parser.cpp"
    break;

  case 29: // struct: tSTRUCT tIDENTIFIER '{' struct_members '}'
#line 200 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateStruct(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1177 "Parser.cpp"
    break;

  case 30: // struct_members: %empty
#line 204 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1183 "Parser.cpp"
    break;

  case 31: // struct_members: struct_member struct_members
#line 206 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1189 "Parser.cpp"
    break;

  case 32: // struct_member: variable_decl ';'
#line 209 "Parser.yy"
                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1195 "Parser.cpp"
    break;

  case 33: // struct_member: function
#line 210 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1201 "Parser.cpp"
    break;

  case 34: // struct_member: tNATIVE variable_type tIDENTIFIER '(' arg_decls ')' ';'
#line 212 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNativeFunction(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::string_view > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1207 "Parser.cpp"
    break;

  case 35: // function: variable_type tIDENTIFIER '(' arg_decls ')' block
#line 216 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateInternalFunction(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::string_view > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1213 "Parser.cpp"
    break;

  case 36: // variable_type: tACTOR
#line 220 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateActorTypeDescription(); }
#line 1219 "Parser.cpp"
    break;

  case 37: // variable_type: qualified_name
#line 222 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateTypeDescription(yystack_[0].value.as < std::string_view > ()); }
#line 1225 "Parser.cpp"
    break;

  case 38: // variable_type: tTYPE
#line 224 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateTypeDescription(yystack_[0].value.as < std::shared_ptr<mana::TypeDescriptor> > ()); }
#line 1231 "Parser.cpp"
    break;

  case 39: // block: '{' statements '}'
#line 228 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateBlock(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1237 "Parser.cpp"
    break;

  case 40: // statements: %empty
#line 232 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1243 "Parser.cpp"
    break;

  case 41: // statements: statement statements
#line 234 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1249 "Parser.cpp"
    break;

  case 42: // statement: tIF '(' expression ')' statement
#line 237 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIf(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (), nullptr); }
#line 1255 "Parser.cpp"
    break;

  case 43: // statement: tIF '(' expression ')' statement tELSE statement
#line 239 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIf(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1261 "Parser.cpp"
    break;

  case 44: // statement: tSWITCH '(' expression ')' '{' cases '}'
#line 241 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSwitch(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1267 "Parser.cpp"
    break;

  case 45: // statement: tWHILE '(' expression ')' statement
#line 243 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateWhile(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1273 "Parser.cpp"
    break;

  case 46: // statement: tDO statement tWHILE '(' expression ')' ';'
#line 245 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDoWhile(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1279 "Parser.cpp"
    break;

  case 47: // statement: tFOR '(' expression ';' expression ';' expression ')' statement
#line 247 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateFor(yystack_[6].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1285 "Parser.cpp"
    break;

  case 48: // statement: tFOR '(' variable_decl ';' expression ';' expression ')' statement
#line 249 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateFor(yystack_[6].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1291 "Parser.cpp"
    break;

  case 49: // statement: tLOOP statement
#line 251 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLoop(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1297 "Parser.cpp"
    break;

  case 50: // statement: tLOCK statement
#line 253 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLock(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1303 "Parser.cpp"
    break;

  case 51: // statement: GOTO tIDENTIFIER ';'
#line 255 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateGoto(yystack_[1].value.as < std::string_view > ()); }
#line 1309 "Parser.cpp"
    break;

  case 52: // statement: tIDENTIFIER ':'
#line 257 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLabel(yystack_[1].value.as < std::string_view > ()); }
#line 1315 "Parser.cpp"
    break;

  case 53: // statement: tRETURN ';'
#line 259 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateReturn(nullptr); }
#line 1321 "Parser.cpp"
    break;

  case 54: // statement: tRETURN expression ';'
#line 261 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateReturn(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1327 "Parser.cpp"
    break;

  case 55: // statement: tROLLBACK expression ';'
#line 263 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRollback(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1333 "Parser.cpp"
    break;

  case 56: // statement: tBREAK ';'
#line 265 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateBreak(); }
#line 1339 "Parser.cpp"
    break;

  case 57: // statement: tCONTINUE ';'
#line 267 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateContinue(); }
#line 1345 "Parser.cpp"
    break;

  case 58: // statement: tHALT '(' ')' ';'
#line 269 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateHalt(); }
#line 1351 "Parser.cpp"
    break;

  case 59: // statement: tYIELD '(' ')' ';'
#line 271 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateYield(); }
#line 1357 "Parser.cpp"
    break;

  case 60: // statement: tCOMPLY '(' ')' ';'
#line 273 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateComply(); }
#line 1363 "Parser.cpp"
    break;

  case 61: // statement: tREFUSE '(' ')' ';'
#line 275 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRefuse(); }
#line 1369 "Parser.cpp"
    break;

  case 62: // statement: tPRINT '(' arg_calls ')' ';'
#line 277 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreatePrint(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1375 "Parser.cpp"
    break;

  case 63: // statement: tREQUEST '(' expression ',' action_ref ')' ';'
#line 279 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRequest(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < mana::ActionReference > ().actor, yystack_[2].value.as < mana::ActionReference > ().action); }
#line 1381 "Parser.cpp"
    break;

  case 64: // statement: tAwaitStart '(' expression ',' action_ref ')' ';'
#line 281 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAwaitStart(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < mana::ActionReference > ().actor, yystack_[2].value.as < mana::ActionReference > ().action); }
#line 1387 "Parser.cpp"
    break;

  case 65: // statement: tAwaitCompletion '(' expression ',' action_ref ')' ';'
#line 283 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAwaitCompletion(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < mana::ActionReference > ().actor, yystack_[2].value.as < mana::ActionReference > ().action); }
#line 1393 "Parser.cpp"
    break;

  case 66: // statement: tJOIN '(' expression ',' expression ')' ';'
#line 285 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateJoin(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1399 "Parser.cpp"
    break;

  case 67: // statement: block
#line 286 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1405 "Parser.cpp"
    break;

  case 68: // statement: declaration ';'
#line 287 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1411 "Parser.cpp"
    break;

  case 69: // statement: expression ';'
#line 288 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1417 "Parser.cpp"
    break;

  case 70: // statement: ';'
#line 290 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1423 "Parser.cpp"
    break;

  case 71: // statement: error ';'
#line 292 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; yyerrok; yyclearin; }
#line 1429 "Parser.cpp"
    break;

  case 72: // statement: error '}'
#line 294 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; yyerrok; yyclearin; }
#line 1435 "Parser.cpp"
    break;

  case 73: // expression: left_hand '=' expression
#line 298 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1441 "Parser.cpp"
    break;

  case 74: // expression: expression tAND expression
#line 300 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLogicalAnd(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1447 "Parser.cpp"
    break;

  case 75: // expression: expression tOR expression
#line 302 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLogicalOr(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1453 "Parser.cpp"
    break;

  case 76: // expression: expression tAADD expression
#line 304 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAddAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1459 "Parser.cpp"
    break;

  case 77: // expression: expression tASUB expression
#line 306 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSubAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1465 "Parser.cpp"
    break;

  case 78: // expression: expression tAMUL expression
#line 308 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMulAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1471 "Parser.cpp"
    break;

  case 79: // expression: expression tADIV expression
#line 310 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDivAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1477 "Parser.cpp"
    break;

  case 80: // expression: expression tAMOD expression
#line 312 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateModAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1483 "Parser.cpp"
    break;

  case 81: // expression: expression tAAND expression
#line 314 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAndAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1489 "Parser.cpp"
    break;

  case 82: // expression: expression tAOR expression
#line 316 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateOrAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1495 "Parser.cpp"
    break;

  case 83: // expression: expression tAXOR expression
#line 318 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateXorAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1501 "Parser.cpp"
    break;

  case 84: // expression: expression tALSHFT expression
#line 320 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLeftShiftAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1507 "Parser.cpp"
    break;

  case 85: // expression: expression tARSHFT expression
#line 322 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRightShiftAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1513 "Parser.cpp"
    break;

  case 86: // expression: expression '+' expression
#line 324 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAdd(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1519 "Parser.cpp"
    break;

  case 87: // expression: expression '-' expression
#line 326 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSub(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1525 "Parser.cpp"
    break;

  case 88: // expression: expression '*' expression
#line 328 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMul(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1531 "Parser.cpp"
    break;

  case 89: // expression: expression '/' expression
#line 330 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDiv(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1537 "Parser.cpp"
    break;

  case 90: // expression: expression '%' expression
#line 332 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMod(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1543 "Parser.cpp"
    break;

  case 91: // expression: expression tPOW expression
#line 334 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreatePow(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1549 "Parser.cpp"
    break;

  case 92: // expression: expression '&' expression
#line 336 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAnd(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1555 "Parser.cpp"
    break;

  case 93: // expression: expression '|' expression
#line 338 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateOr(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1561 "Parser.cpp"
    break;

  case 94: // expression: expression '^' expression
#line 340 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateXor(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1567 "Parser.cpp"
    break;

  case 95: // expression: expression tLSHFT expression
#line 342 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLeftShift(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1573 "Parser.cpp"
    break;

  case 96: // expression: expression tRSHFT expression
#line 344 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRightShift(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1579 "Parser.cpp"
    break;

  case 97: // expression: expression '>' expression
#line 346 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateGreater(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1585 "Parser.cpp"
    break;

  case 98: // expression: expression tGE expression
#line 348 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateGreaterEqual(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1591 "Parser.cpp"
    break;

  case 99: // expression: expression '<' expression
#line 350 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLess(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1597 "Parser.cpp"
    break;

  case 100: // expression: expression tLE expression
#line 352 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLessEqual(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1603 "Parser.cpp"
    break;

  case 101: // expression: expression tEQ expression
#line 354 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateEqual(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1609 "Parser.cpp"
    break;

  case 102: // expression: expression tNE expression
#line 356 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNotEqual(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1615 "Parser.cpp"
    break;

  case 103: // expression: tINC expression
#line 358 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIncrement(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1621 "Parser.cpp"
    break;

  case 104: // expression: tDEC expression
#line 360 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDecrement(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1627 "Parser.cpp"
    break;

  case 105: // expression: expression tINC
#line 362 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIncrement(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1633 "Parser.cpp"
    break;

  case 106: // expression: expression tDEC
#line 364 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDecrement(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1639 "Parser.cpp"
    break;

  case 107: // expression: expression '?' expression ':' expression
#line 366 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateExpressionIf(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1645 "Parser.cpp"
    break;

  case 108: // expression: primary
#line 367 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1651 "Parser.cpp"
    break;

  case 109: // primary: '-' expression
#line 371 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNegative(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1657 "Parser.cpp"
    break;

  case 110: // primary: '+' expression
#line 373 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1663 "Parser.cpp"
    break;

  case 111: // primary: '!' expression
#line 375 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNot(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1669 "Parser.cpp"
    break;

  case 112: // primary: '~' expression
#line 377 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateComplement1(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1675 "Parser.cpp"
    break;

  case 113: // primary: tSIZEOF '(' variable_type ')'
#line 379 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSizeOf(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1681 "Parser.cpp"
    break;

  case 114: // primary: tIDENTIFIER '(' arg_calls ')'
#line 381 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateCall(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1687 "Parser.cpp"
    break;

  case 115: // primary: constant
#line 382 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1693 "Parser.cpp"
    break;

  case 116: // primary: left_hand
#line 383 "Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1699 "Parser.cpp"
    break;

  case 117: // constant: tFALSE
#line 387 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateBool(false); }
#line 1705 "Parser.cpp"
    break;

  case 118: // constant: tTRUE
#line 389 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateBool(true); }
#line 1711 "Parser.cpp"
    break;

  case 119: // constant: tPRIORITY
#line 391 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreatePriority(); }
#line 1717 "Parser.cpp"
    break;

  case 120: // constant: tSELF
#line 393 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSelf(); }
#line 1723 "Parser.cpp"
    break;

  case 121: // constant: tSENDER
#line 395 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSender(); }
#line 1729 "Parser.cpp"
    break;

  case 122: // constant: tNIL
#line 397 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNil(); }
#line 1735 "Parser.cpp"
    break;

  case 123: // constant: tDIGIT
#line 399 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateInteger(yystack_[0].value.as < mana::int_t > ()); }
#line 1741 "Parser.cpp"
    break;

  case 124: // constant: tREAL
#line 401 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateFloat(yystack_[0].value.as < mana::float_t > ()); }
#line 1747 "Parser.cpp"
    break;

  case 125: // constant: tSTRING
#line 403 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateString(yystack_[0].value.as < std::string_view > ()); }
#line 1753 "Parser.cpp"
    break;

  case 126: // left_hand: left_hand '.' tIDENTIFIER
#line 407 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMemberVariable(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::string_view > ()); }
#line 1759 "Parser.cpp"
    break;

  case 127: // left_hand: left_hand '.' tIDENTIFIER '(' arg_calls ')'
#line 409 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMemberFunction(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1765 "Parser.cpp"
    break;

  case 128: // left_hand: left_hand '[' expression ']'
#line 411 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateArray(yystack_[3].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1771 "Parser.cpp"
    break;

  case 129: // left_hand: tIDENTIFIER
#line 413 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIdentifier(yystack_[0].value.as < std::string_view > ()); }
#line 1777 "Parser.cpp"
    break;

  case 130: // left_hand: tTHIS
#line 415 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateThis(); }
#line 1783 "Parser.cpp"
    break;

  case 131: // left_hand: '(' expression ')'
#line 417 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1789 "Parser.cpp"
    break;

  case 132: // qualified_name: tIDENTIFIER
#line 421 "Parser.yy"
                                        { yylhs.value.as < std::string_view > () = yystack_[0].value.as < std::string_view > (); }
#line 1795 "Parser.cpp"
    break;

  case 133: // qualified_name: qualified_name tDC tIDENTIFIER
#line 423 "Parser.yy"
                                        { yylhs.value.as < std::string_view > () = mParsingDriver->CreateQualifiedName(yystack_[2].value.as < std::string_view > (), yystack_[0].value.as < std::string_view > ()); }
#line 1801 "Parser.cpp"
    break;

  case 134: // action_ref: expression tARROW tIDENTIFIER
#line 427 "Parser.yy"
                                        {
						yylhs.value.as < mana::ActionReference > ().actor = yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ();
						yylhs.value.as < mana::ActionReference > ().action = yystack_[0].value.as < std::string_view > ();
					}
#line 1810 "Parser.cpp"
    break;

  case 135: // action_ref: qualified_name tARROW tIDENTIFIER
#line 432 "Parser.yy"
                                        {
						yylhs.value.as < mana::ActionReference > ().actor = mParsingDriver->CreateIdentifier(yystack_[2].value.as < std::string_view > ());
						yylhs.value.as < mana::ActionReference > ().action = yystack_[0].value.as < std::string_view > ();
					}
#line 1819 "Parser.cpp"
    break;

  case 136: // action_ref: qualified_name tDC tIDENTIFIER
#line 437 "Parser.yy"
                                        {
						if (yystack_[2].value.as < std::string_view > ().find("::") != std::string_view::npos)
						{
							mana::CompileError({ "legacy action reference cannot use namespace '", yystack_[2].value.as < std::string_view > (), "'" });
						}
						else
						{
							mana::CompileWarning({ "legacy action reference '", yystack_[2].value.as < std::string_view > (), "::", yystack_[0].value.as < std::string_view > (), "' is deprecated. Use '->' instead." });
						}
						yylhs.value.as < mana::ActionReference > ().actor = mParsingDriver->CreateIdentifier(yystack_[2].value.as < std::string_view > ());
						yylhs.value.as < mana::ActionReference > ().action = yystack_[0].value.as < std::string_view > ();
						yylhs.value.as < mana::ActionReference > ().legacy = true;
					}
#line 1837 "Parser.cpp"
    break;

  case 137: // cases: case
#line 452 "Parser.yy"
                          { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1843 "Parser.cpp"
    break;

  case 138: // cases: cases case
#line 454 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->BindCaseNode(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1849 "Parser.cpp"
    break;

  case 139: // case: tCASE expression ':' statements
#line 457 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSwitchCaseNode(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1855 "Parser.cpp"
    break;

  case 140: // case: tDEFAULT ':' statements
#line 459 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSwitchDefaultNode(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1861 "Parser.cpp"
    break;

  case 141: // arg_calls: %empty
#line 463 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1867 "Parser.cpp"
    break;

  case 142: // arg_calls: expression
#line 465 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateArgumentNode(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1873 "Parser.cpp"
    break;

  case 143: // arg_calls: expression ',' arg_calls
#line 467 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateArgumentNode(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1879 "Parser.cpp"
    break;

  case 144: // arg_decls: %empty
#line 471 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1885 "Parser.cpp"
    break;

  case 145: // arg_decls: variable_decl
#line 473 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareArgumentNode(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1891 "Parser.cpp"
    break;

  case 146: // arg_decls: arg_decls ',' variable_decl
#line 475 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareArgumentNode(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1897 "Parser.cpp"
    break;

  case 147: // variable_decl: variable_type declarator
#line 480 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareVariableNode(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (), nullptr); }
#line 1903 "Parser.cpp"
    break;

  case 148: // variable_decl: variable_type declarator '=' expression
#line 482 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareVariableNode(yystack_[3].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1909 "Parser.cpp"
    break;

  case 149: // const_decl: tCONST variable_type tIDENTIFIER '=' expression
#line 487 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateConstDeclarationNode(yystack_[3].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::string_view > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1915 "Parser.cpp"
    break;

  case 150: // declarator: tIDENTIFIER
#line 491 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclaratorNode(yystack_[0].value.as < std::string_view > ()); }
#line 1921 "Parser.cpp"
    break;

  case 151: // declarator: tIDENTIFIER variable_sizes
#line 493 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclaratorNode(yystack_[1].value.as < std::string_view > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1927 "Parser.cpp"
    break;

  case 152: // variable_sizes: variable_size
#line 496 "Parser.yy"
                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1933 "Parser.cpp"
    break;

  case 153: // variable_sizes: variable_size variable_sizes
#line 498 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = 	mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1939 "Parser.cpp"
    break;

  case 154: // variable_size: '[' tDIGIT ']'
#line 501 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = 	mParsingDriver->CreateVariableSizeNode(yystack_[1].value.as < mana::int_t > ()); }
#line 1945 "Parser.cpp"
    break;

  case 155: // variable_size: '[' tIDENTIFIER ']'
#line 503 "Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = 	mParsingDriver->CreateVariableSizeNode(yystack_[1].value.as < std::string_view > ()); }
#line 1951 "Parser.cpp"
    break;


#line 1955 "Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short Parser::yypact_ninf_ = -250;

  const short Parser::yytable_ninf_ = -137;

  const short
  Parser::yypact_[] =
  {
     260,  -250,  -250,    20,    34,   204,   204,    15,    43,    48,
      52,    62,    62,   -40,   116,   122,  -250,   260,    29,  -250,
    -250,  -250,   126,    94,  -250,  -250,    46,    49,  -250,   153,
     158,    75,    80,   109,   113,   -34,   -32,   212,   204,   118,
    -250,  -250,  -250,   -85,   149,   217,  -250,  -250,   157,   125,
     194,   114,   114,   114,   260,  -250,   128,   130,   219,   133,
     204,   204,    32,  -250,   127,   581,  -250,   581,   204,   204,
     137,   194,  -250,   135,   232,    62,   143,   142,   114,   144,
     148,   150,   204,  -250,   127,   204,   151,   -69,  -250,   139,
     141,  -250,  -250,  -250,  -250,   152,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,   581,   581,   161,   581,   581,   581,   581,
     581,  1663,  -250,  -250,   -35,  1663,    37,   237,  -250,  -250,
    -250,   159,   -31,  -250,  -250,  -250,  -250,  -250,  -250,   163,
    -250,  -250,   159,   204,  -250,  -250,   581,   -23,   -23,   204,
     -23,   -23,  -250,  -250,   965,   581,   581,   581,   581,   581,
     581,   581,   581,   581,   581,   581,   581,   581,   581,   581,
     581,   581,   581,   581,   581,   581,   581,   581,   581,   581,
     581,   581,   581,   581,   581,  -250,  -250,   581,   243,   581,
     154,   164,   398,  -250,  -250,  -250,  -250,  -250,   730,   162,
     167,  -250,  1702,  1702,  1702,  1738,  1738,  1772,  1772,   290,
     290,   290,  1585,  1796,  1796,  1820,  1820,  1842,  1842,  1842,
    1842,   104,   104,   201,   477,   477,    68,    68,    42,    42,
      42,    42,   389,   176,   691,  -250,   204,   -19,    11,   178,
     191,   193,   196,   207,   213,   293,   209,   499,   499,   214,
     215,   499,   216,   553,   581,   236,   239,   249,   250,   256,
    -250,   220,  -250,   238,   297,  1333,   581,  -250,  -250,   581,
     581,  -250,    40,  -250,  -250,  -250,   581,   581,   581,   581,
    -250,  -250,   261,   277,  -250,   331,   145,   581,  -250,   281,
    -250,  1375,  1417,   581,   581,   581,   287,   288,  -250,  -250,
    -250,  -250,  -250,   389,   291,   296,   777,   824,   871,   918,
    -250,   302,   305,    16,  1459,   309,  1011,   310,  -250,  -250,
    1057,  1103,   307,   313,   314,  -250,  -250,   607,   607,   607,
     581,  -250,   581,   581,   581,   499,  -250,   315,   499,   317,
    -250,  -250,   652,   117,   316,   332,   336,  1149,  1195,  1501,
    1543,   373,   147,  -250,  -250,   411,   413,   427,   341,   343,
     353,   354,   357,   581,   581,   499,   581,   387,   -25,  -250,
    -250,   356,  -250,  -250,  -250,  -250,  -250,  -250,  1241,  1287,
    -250,  1624,   297,  -250,  -250,   499,   499,   297,  -250,  -250,
    -250,  -250
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       3,   132,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     5,
       6,     7,     0,    37,    19,    20,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       1,     4,     8,   150,   147,     0,    15,    16,     0,     0,
      30,    24,    24,    24,     3,    10,     0,     0,     0,     0,
      17,   144,     0,   151,   152,     0,   133,     0,   144,     0,
       0,    30,    33,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    17,    13,   150,    17,     0,     0,   145,     0,
       0,   153,   123,   124,   125,   129,   117,   118,   119,   120,
     121,   130,   122,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   108,   115,   116,   149,     0,     0,    29,    31,
      32,     0,     0,    28,    21,    25,    22,    23,     9,     0,
      18,    12,     0,     0,   154,   155,   141,   110,   109,     0,
     111,   112,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,     0,     0,
       0,     0,     0,    26,    27,    14,    35,   146,   142,     0,
       0,   131,    78,    79,    80,    76,    77,    84,    85,    81,
      82,    83,     0,    74,    75,   101,   102,    97,    98,   100,
      99,    93,    94,    92,    95,    96,    86,    87,    88,    89,
      90,    91,    73,   126,     0,    11,   144,     0,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,    67,     0,     0,     0,   141,   114,   113,     0,
     141,   128,     0,    71,    72,    52,     0,     0,     0,     0,
      56,    57,     0,     0,    50,     0,     0,     0,    49,     0,
      53,     0,     0,     0,     0,   141,     0,     0,    68,    39,
      41,    69,   143,   107,     0,     0,     0,     0,     0,     0,
      51,     0,     0,   129,     0,     0,     0,     0,    54,    55,
       0,     0,     0,     0,     0,   127,    34,     0,     0,     0,
       0,    58,     0,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    45,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     134,   133,   135,    63,    64,    65,    66,    46,     0,     0,
      43,     0,     0,    44,   138,     0,     0,     0,   140,    47,
      48,   139
  };

  const short
  Parser::yypgoto_[] =
  {
    -250,  -250,     1,  -250,    53,   124,  -250,   -16,  -250,  -250,
     407,  -250,   -21,     7,  -106,  -249,  -210,   -63,  -250,  -250,
    -250,   -11,  -124,  -250,   121,  -237,   -65,    -8,  -250,  -250,
     416,  -250
  };

  const short
  Parser::yydefgoto_[] =
  {
       0,    15,    16,    17,    57,   251,    19,    77,    78,    20,
      70,    71,    21,    58,   252,   253,   254,   255,   112,   113,
     114,    23,   334,   358,   359,   189,    87,    24,    25,    44,
      63,    64
  };

  const short
  Parser::yytable_[] =
  {
      35,    36,   111,   116,   115,   290,    45,    22,    45,    45,
     356,   357,    29,    30,    37,   183,    61,  -132,    41,   292,
      62,    31,  -132,   294,    22,    26,   186,   274,   275,    72,
      59,   278,   177,   132,   133,    89,    79,    80,    90,    27,
     137,   138,    73,   140,   141,   142,   143,   144,   312,    32,
      72,  -132,    59,    88,    33,    81,  -132,    22,    34,    38,
      88,    22,   125,    73,   122,    54,    55,   184,     1,   178,
     179,   175,   176,   188,    59,   373,   117,    59,    22,   263,
     265,   264,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   136,    86,   222,   341,   224,   136,   343,    39,
       1,     2,    40,   378,    18,   187,     5,    42,   381,    28,
     174,    74,    43,    75,    45,   129,   175,   176,   130,   180,
     133,    18,   295,   133,    46,   370,   190,    47,    92,    93,
      94,   303,     2,   171,   172,   173,   174,   346,   347,    48,
      28,   262,   175,   176,    49,   379,   380,    96,    97,    98,
      99,   100,   101,   102,    50,    76,    76,    76,    18,    51,
     281,   282,   356,   357,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   188,   335,   336,   293,   188,   175,   176,
       1,     2,    76,   296,   297,   298,   299,    69,    52,    28,
       1,     2,    53,   304,   306,    56,    65,    60,    88,    28,
     310,   311,   188,    66,    67,    84,    68,    82,   103,   104,
      83,    85,    62,   120,   105,   106,   107,   118,   121,   108,
     109,   123,   124,   181,   126,   134,   110,   135,   127,   223,
     128,   131,   225,   136,   332,   332,   332,   337,   182,   338,
     339,   340,   139,   185,   257,   226,     1,     2,   305,   258,
       3,     4,     5,     6,     7,     8,     9,   260,    10,   266,
      11,    12,   167,   168,   169,   170,   171,   172,   173,   174,
     368,   369,   267,   371,   268,   175,   176,   269,   227,   272,
      92,    93,    94,   228,     2,   270,   333,   333,   333,     5,
     273,   271,    28,    13,    14,   276,   277,   279,   288,    96,
      97,    98,    99,   100,   101,   102,   229,   230,   231,   232,
     233,   234,   -40,   -40,   235,   236,   237,   283,   289,   238,
     284,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     285,   286,   248,   249,  -137,  -137,  -137,   287,   155,   300,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   301,
     103,   104,   302,   307,   175,   176,   105,   106,   107,   313,
     314,   108,   109,   315,   316,   250,   182,   -40,   110,   227,
     321,    92,    93,    94,   228,     2,   322,   324,   326,   329,
       5,   330,   331,    28,   342,   344,   355,   360,   348,   361,
      96,    97,    98,    99,   100,   101,   102,   229,   230,   231,
     232,   233,   234,   362,   349,   235,   236,   237,   350,   363,
     238,   364,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   365,   366,   248,   249,   367,   372,   155,  -136,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   119,   374,
      91,   103,   104,   175,   176,     0,     0,   105,   106,   107,
       0,     0,   108,   109,     0,     0,   250,   182,   -40,   110,
     227,     0,    92,    93,    94,   228,     2,     0,     0,     0,
       0,     5,     0,     0,    28,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   229,   230,
     231,   232,   233,   234,     0,     0,   235,   236,   237,     0,
       0,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,     0,   248,   249,    92,    93,    94,    95,
     169,   170,   171,   172,   173,   174,     0,     0,     0,     0,
       0,   175,   176,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    92,    93,    94,    95,   105,   106,
     107,     0,     0,   108,   109,     0,     0,   250,   182,     0,
     110,     0,     0,    96,    97,    98,    99,   100,   101,   102,
      92,    93,    94,   303,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,     0,   105,   106,   107,     0,     0,   108,   109,     0,
       0,   280,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,     0,     0,     0,     0,
     105,   106,   107,     0,     0,   108,   109,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
     103,   104,     0,   345,     0,     0,   105,   106,   107,     0,
       0,   108,   109,     0,     0,     0,     0,     0,   110,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     0,     0,     0,     0,     0,   175,   176,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,     0,     0,     0,   175,   176,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   261,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,     0,
       0,     0,     0,     0,   175,   176,     0,     0,     0,     0,
       0,     0,     0,   256,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,     0,     0,     0,
       0,   175,   176,     0,     0,     0,     0,     0,     0,     0,
     317,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,     0,     0,     0,     0,     0,   175,   176,
       0,     0,     0,     0,     0,     0,     0,   318,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
       0,     0,     0,     0,   319,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,     0,     0,     0,
       0,     0,   175,   176,     0,     0,     0,     0,     0,     0,
       0,   320,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,     0,     0,     0,     0,   175,
     176,     0,     0,     0,     0,     0,     0,   191,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
       0,     0,     0,   325,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,     0,     0,     0,
       0,   175,   176,     0,     0,     0,     0,     0,     0,   327,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,     0,     0,     0,     0,   175,   176,     0,
       0,     0,     0,     0,     0,   328,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,     0,     0,
       0,     0,     0,   175,   176,     0,     0,     0,     0,     0,
       0,   351,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,     0,     0,     0,     0,   175,
     176,     0,     0,     0,     0,     0,     0,   352,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
       0,     0,     0,   375,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,     0,     0,     0,
       0,   175,   176,     0,     0,     0,     0,     0,     0,   376,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,     0,     0,     0,     0,   175,   176,     0,
       0,   291,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,     0,     0,     0,     0,   175,
     176,     0,     0,   308,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,     0,     0,     0,
       0,   175,   176,     0,     0,   309,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,     0,     0,
       0,     0,     0,   175,   176,     0,     0,   323,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,     0,     0,     0,   175,   176,     0,     0,   353,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,     0,     0,     0,     0,   175,   176,     0,
       0,   354,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   259,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,     0,     0,     0,     0,   175,
     176,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   377,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,     0,     0,     0,     0,     0,   175,   176,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,     0,     0,     0,     0,   175,   176,  -137,
    -137,  -137,   148,   149,   150,   151,   152,   153,   154,     0,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     0,     0,     0,     0,     0,   175,   176,  -137,  -137,
     150,   151,   152,   153,   154,     0,   155,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,     0,     0,     0,
       0,     0,   175,   176,  -137,  -137,   152,   153,   154,     0,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     0,     0,     0,     0,     0,   175,   176,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,     0,     0,     0,     0,     0,
     175,   176,  -137,  -137,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,     0,
       0,     0,     0,     0,   175,   176,  -137,  -137,  -137,  -137,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     0,     0,     0,     0,     0,   175,   176
  };

  const short
  Parser::yycheck_[] =
  {
      11,    12,    65,    68,    67,   254,    40,     0,    40,    40,
      35,    36,     5,     6,    54,   121,   101,     6,    17,   256,
     105,     6,     6,   260,    17,     5,   132,   237,   238,    50,
      38,   241,    67,   102,   103,     3,    52,    53,     6,     5,
     103,   104,    50,   106,   107,   108,   109,   110,   285,     6,
      71,    40,    60,    61,     6,    54,    40,    50,     6,    99,
      68,    54,    78,    71,    75,    99,    98,    98,     6,   104,
     105,    94,    95,   136,    82,   100,    69,    85,    71,    98,
      69,   100,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   101,    60,   177,   325,   179,   101,   328,     3,
       6,     7,     0,   372,     0,   133,    12,    98,   377,    15,
      88,    17,     6,    19,    40,    82,    94,    95,    85,   102,
     103,    17,   102,   103,    98,   355,   139,    98,     3,     4,
       5,     6,     7,    85,    86,    87,    88,    40,    41,     6,
      15,   226,    94,    95,     6,   375,   376,    22,    23,    24,
      25,    26,    27,    28,    99,    51,    52,    53,    54,    99,
     243,   244,    35,    36,    80,    81,    82,    83,    84,    85,
      86,    87,    88,   256,   318,   319,   259,   260,    94,    95,
       6,     7,    78,   266,   267,   268,   269,    13,    99,    15,
       6,     7,    99,   276,   277,     3,    67,    99,   226,    15,
     283,   284,   285,     6,    67,     6,   101,    99,    83,    84,
     100,    98,   105,    98,    89,    90,    91,   100,     6,    94,
      95,    98,   100,     6,   100,   106,   101,   106,   100,     6,
     100,   100,    98,   101,   317,   318,   319,   320,    99,   322,
     323,   324,   101,   100,   102,   101,     6,     7,   276,   102,
      10,    11,    12,    13,    14,    15,    16,   101,    18,   101,
      20,    21,    81,    82,    83,    84,    85,    86,    87,    88,
     353,   354,   101,   356,   101,    94,    95,   101,     1,     6,
       3,     4,     5,     6,     7,    98,   317,   318,   319,    12,
     101,    98,    15,    53,    54,   101,   101,   101,    98,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   101,   100,    42,
     101,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     101,   101,    55,    56,    64,    65,    66,   101,    68,    98,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   102,
      83,    84,    51,   102,    94,    95,    89,    90,    91,   102,
     102,    94,    95,   102,    98,    98,    99,   100,   101,     1,
      98,     3,     4,     5,     6,     7,   101,    98,    98,   102,
      12,    98,    98,    15,    99,    98,    43,     6,   102,     6,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     6,   102,    37,    38,    39,   102,    98,
      42,    98,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    98,    98,    55,    56,    98,    69,    68,   102,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    71,   358,
      64,    83,    84,    94,    95,    -1,    -1,    89,    90,    91,
      -1,    -1,    94,    95,    -1,    -1,    98,    99,   100,   101,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    37,    38,    39,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    55,    56,     3,     4,     5,     6,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    83,    84,     3,     4,     5,     6,    89,    90,
      91,    -1,    -1,    94,    95,    -1,    -1,    98,    99,    -1,
     101,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    83,    84,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      89,    90,    91,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    41,    -1,    -1,    89,    90,    91,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,   101,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    94,    95,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    94,    95,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,   106,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   102,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   102,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,
      95,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    94,    95,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    94,    95,    62,    63,    64,    65,    66,    -1,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    94,    95,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      94,    95,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    94,    95,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    94,    95
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     6,     7,    10,    11,    12,    13,    14,    15,    16,
      18,    20,    21,    53,    54,   108,   109,   110,   112,   113,
     116,   119,   120,   128,   134,   135,     5,     5,    15,   120,
     120,     6,     6,     6,     6,   128,   128,    54,    99,     3,
       0,   109,    98,     6,   136,    40,    98,    98,     6,     6,
      99,    99,    99,    99,    99,    98,     3,   111,   120,   134,
      99,   101,   105,   137,   138,    67,     6,    67,   101,    13,
     117,   118,   119,   134,    17,    19,   112,   114,   115,   114,
     114,   109,    99,   100,     6,    98,   111,   133,   134,     3,
       6,   137,     3,     4,     5,     6,    22,    23,    24,    25,
      26,    27,    28,    83,    84,    89,    90,    91,    94,    95,
     101,   124,   125,   126,   127,   124,   133,   120,   100,   117,
      98,     6,   128,    98,   100,   114,   100,   100,   100,   111,
     111,   100,   102,   103,   106,   106,   101,   124,   124,   101,
     124,   124,   124,   124,   124,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    68,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    94,    95,    67,   104,   105,
     102,     6,    99,   121,    98,   100,   121,   134,   124,   132,
     120,   102,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,     6,   124,    98,   101,     1,     6,    29,
      30,    31,    32,    33,    34,    37,    38,    39,    42,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    55,    56,
      98,   112,   121,   122,   123,   124,   103,   102,   102,    69,
     101,   106,   133,    98,   100,    69,   101,   101,   101,   101,
      98,    98,     6,   101,   123,   123,   101,   101,   123,   101,
      98,   124,   124,   101,   101,   101,   101,   101,    98,   100,
     122,    98,   132,   124,   132,   102,   124,   124,   124,   124,
      98,   102,    51,     6,   124,   134,   124,   102,    98,    98,
     124,   124,   132,   102,   102,   102,    98,   103,   103,   103,
     103,    98,   101,    98,    98,   102,    98,   102,   102,   102,
      98,    98,   124,   128,   129,   129,   129,   124,   124,   124,
     124,   123,    99,   123,    98,    41,    40,    41,   102,   102,
     102,   102,   102,    98,    98,    43,    35,    36,   130,   131,
       6,     6,     6,    98,    98,    98,    98,    98,   124,   124,
     123,   124,    69,   100,   131,   102,   102,    69,   122,   123,
     123,   122
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,   107,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     112,   113,   113,   113,   114,   114,   115,   115,   115,   116,
     117,   117,   118,   118,   118,   119,   120,   120,   120,   121,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   127,   127,   127,   127,
     127,   127,   128,   128,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   132,   133,   133,   133,   134,   134,   135,
     136,   136,   137,   137,   138,   138
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     2,     5,
       3,     7,     5,     4,     6,     3,     3,     0,     3,     1,
       1,     5,     5,     5,     0,     2,     3,     3,     2,     5,
       0,     2,     2,     1,     7,     6,     1,     1,     1,     3,
       0,     2,     5,     7,     7,     5,     7,     9,     9,     2,
       2,     3,     2,     2,     3,     3,     2,     2,     4,     4,
       4,     4,     5,     7,     7,     7,     7,     1,     2,     2,
       1,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     5,     1,     2,
       2,     2,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     4,     1,
       1,     3,     1,     3,     3,     3,     3,     1,     2,     4,
       3,     0,     1,     3,     0,     1,     3,     2,     4,     5,
       1,     2,     1,     2,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "tDIGIT", "tREAL",
  "tSTRING", "tIDENTIFIER", "tTYPE", "tDEFINE", "tUNDEF", "tINCLUDE",
  "tIMPORT", "tCONST", "tNATIVE", "tSTRUCT", "tACTOR", "tPHANTOM",
  "tACTION", "tMODULE", "tEXTEND", "tNAMESPACE", "tUSING", "tFALSE",
  "tTRUE", "tPRIORITY", "tSELF", "tSENDER", "tTHIS", "tNIL", "tREQUEST",
  "tAwaitStart", "tAwaitCompletion", "tJOIN", "tBREAK", "tCONTINUE",
  "tCASE", "tDEFAULT", "GOTO", "tHALT", "tLOCK", "tDC", "tARROW", "tDO",
  "tELSE", "tFOR", "tIF", "tLOOP", "tYIELD", "tRETURN", "tROLLBACK",
  "tSWITCH", "tWHILE", "tPRINT", "tSTATIC", "tALLOCATE", "tCOMPLY",
  "tREFUSE", "tAMUL", "tADIV", "tAMOD", "tAADD", "tASUB", "tALSHFT",
  "tARSHFT", "tAAND", "tAOR", "tAXOR", "'='", "'?'", "':'", "tAND", "tOR",
  "tEQ", "tNE", "'>'", "tGE", "tLE", "'<'", "'|'", "'^'", "'&'", "tLSHFT",
  "tRSHFT", "'+'", "'-'", "'*'", "'/'", "'%'", "tPOW", "tSIZEOF", "'!'",
  "'~'", "tUPLUS", "tUMINUS", "tINC", "tDEC", "tUINC", "tUDEC", "';'",
  "'{'", "'}'", "'('", "')'", "','", "'.'", "'['", "']'", "$accept",
  "program", "line", "declarations", "allocate_declarations",
  "declaration", "actor", "actions", "action", "struct", "struct_members",
  "struct_member", "function", "variable_type", "block", "statements",
  "statement", "expression", "primary", "constant", "left_hand",
  "qualified_name", "action_ref", "cases", "case", "arg_calls",
  "arg_decls", "variable_decl", "const_decl", "declarator",
  "variable_sizes", "variable_size", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   120,   120,   137,   138,   142,   143,   144,   145,   146,
     148,   151,   154,   156,   158,   161,   163,   169,   170,   174,
     175,   178,   180,   182,   187,   188,   192,   194,   196,   199,
     204,   205,   209,   210,   211,   215,   219,   221,   223,   227,
     232,   233,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   287,   288,
     289,   291,   293,   297,   299,   301,   303,   305,   307,   309,
     311,   313,   315,   317,   319,   321,   323,   325,   327,   329,
     331,   333,   335,   337,   339,   341,   343,   345,   347,   349,
     351,   353,   355,   357,   359,   361,   363,   365,   367,   370,
     372,   374,   376,   378,   380,   382,   383,   386,   388,   390,
     392,   394,   396,   398,   400,   402,   406,   408,   410,   412,
     414,   416,   420,   422,   426,   431,   436,   452,   453,   456,
     458,   463,   464,   466,   471,   472,   474,   479,   481,   486,
     490,   492,   496,   497,   500,   502
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,     2,     2,     2,    87,    80,     2,
     101,   102,    85,    83,   103,    84,   104,    86,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    98,
      77,    67,    74,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   105,     2,   106,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    99,    78,   100,    91,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    70,    71,    72,    73,    75,    76,    81,    82,
      88,    89,    92,    93,    94,    95,    96,    97
    };
    // Last valid token kind.
    const int code_max = 337;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 19 "Parser.yy"
} // mana
#line 2877 "Parser.cpp"

#line 505 "Parser.yy"


#include "ParserDefinition.inl"
