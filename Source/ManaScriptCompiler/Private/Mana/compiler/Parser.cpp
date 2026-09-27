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
#line 43 "/home/runner/work/Mana/Mana/compiler/Parser.yy"

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

#line 60 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"


// First part of user prologue.
#line 1 "/home/runner/work/Mana/Mana/compiler/Parser.yy"

/*!
mana (compiler)

@author	Shun Moriya
@date	2003-
*/

#if MANA_BUILD_TARGET < MANA_BUILD_RELEASE
#define YYERROR_VERBOSE
#endif


#line 78 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"


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

#line 19 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
namespace mana {
#line 157 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"

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
#line 121 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
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
#line 1015 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 3: // line: %empty
#line 137 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1021 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 4: // line: declarations line
#line 139 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1027 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 5: // declarations: actor
#line 142 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1033 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 6: // declarations: struct
#line 143 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1039 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 7: // declarations: function
#line 144 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1045 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 8: // declarations: declaration ';'
#line 145 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1051 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 9: // declarations: tNAMESPACE qualified_name '{' line '}'
#line 147 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNamespace(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1057 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 10: // declarations: tUSING qualified_name ';'
#line 149 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateUsing(yystack_[1].value.as < std::string_view > ()); }
#line 1063 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 11: // declarations: tNATIVE variable_type tIDENTIFIER '(' arg_decls ')' ';'
#line 152 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNativeFunction(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::string_view > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1069 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 12: // declarations: tALLOCATE tDIGIT '{' allocate_declarations '}'
#line 155 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareMemory(yystack_[3].value.as < mana::int_t > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1075 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 13: // declarations: tSTATIC '{' allocate_declarations '}'
#line 157 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareStaticMemory(0, yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1081 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 14: // declarations: tSTATIC tALLOCATE tDIGIT '{' allocate_declarations '}'
#line 159 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareStaticMemory(yystack_[3].value.as < mana::int_t > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1087 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 15: // declarations: tINCLUDE tSTRING ';'
#line 162 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; if(! lexer::Open(yystack_[1].value.as < std::string_view > (), false)){ YYABORT; } }
#line 1093 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 16: // declarations: tIMPORT tSTRING ';'
#line 164 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; if(! lexer::Open(yystack_[1].value.as < std::string_view > (), true)){ YYABORT; } }
#line 1099 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 17: // allocate_declarations: %empty
#line 169 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1105 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 18: // allocate_declarations: variable_decl ';' allocate_declarations
#line 171 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1111 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 19: // declaration: variable_decl
#line 174 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                          { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1117 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 20: // declaration: const_decl
#line 175 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1123 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 21: // actor: tACTOR tIDENTIFIER '{' actions '}'
#line 179 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateActor(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1129 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 22: // actor: tPHANTOM tIDENTIFIER '{' actions '}'
#line 181 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreatePhantom(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1135 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 23: // actor: tMODULE tIDENTIFIER '{' actions '}'
#line 183 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateModule(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1141 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 24: // actions: %empty
#line 187 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1147 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 25: // actions: action actions
#line 189 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1153 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 26: // action: tACTION tIDENTIFIER optional_empty_parens block
#line 193 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAction(yystack_[2].value.as < std::string_view > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1159 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 27: // action: tEXTEND qualified_name ';'
#line 195 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateExtend(yystack_[1].value.as < std::string_view > ()); }
#line 1165 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 28: // action: declaration ';'
#line 196 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1171 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 29: // struct: tSTRUCT tIDENTIFIER '{' struct_members '}'
#line 200 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateStruct(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1177 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 30: // struct_members: %empty
#line 204 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1183 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 31: // struct_members: struct_member struct_members
#line 206 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1189 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 32: // struct_member: variable_decl ';'
#line 209 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1195 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 33: // struct_member: function
#line 210 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1201 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 34: // struct_member: tNATIVE variable_type tIDENTIFIER '(' arg_decls ')' ';'
#line 212 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNativeFunction(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::string_view > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1207 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 35: // function: variable_type tIDENTIFIER '(' arg_decls ')' block
#line 216 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateInternalFunction(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::string_view > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1213 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 36: // function: variable_type tIDENTIFIER block
#line 218 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateInternalFunction(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[1].value.as < std::string_view > (), nullptr, yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1219 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 37: // variable_type: qualified_name
#line 222 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateTypeDescription(yystack_[0].value.as < std::string_view > ()); }
#line 1225 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 38: // variable_type: tTYPE
#line 224 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateTypeDescription(yystack_[0].value.as < std::shared_ptr<mana::TypeDescriptor> > ()); }
#line 1231 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 39: // block: '{' statements '}'
#line 228 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateBlock(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1237 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 40: // statements: %empty
#line 232 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1243 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 41: // statements: statement statements
#line 234 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1249 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 42: // statement: tIF '(' expression ')' statement
#line 237 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIf(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (), nullptr); }
#line 1255 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 43: // statement: tIF '(' expression ')' statement tELSE statement
#line 239 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIf(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1261 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 44: // statement: tSWITCH '(' expression ')' '{' cases '}'
#line 241 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSwitch(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1267 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 45: // statement: tWHILE '(' expression ')' statement
#line 243 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateWhile(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1273 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 46: // statement: tDO statement tWHILE '(' expression ')' ';'
#line 245 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDoWhile(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1279 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 47: // statement: tFOR '(' expression ';' expression ';' expression ')' statement
#line 247 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateFor(yystack_[6].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1285 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 48: // statement: tFOR '(' variable_decl ';' expression ';' expression ')' statement
#line 249 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateFor(yystack_[6].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1291 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 49: // statement: tLOOP statement
#line 251 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLoop(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1297 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 50: // statement: tLOCK statement
#line 253 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLock(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1303 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 51: // statement: GOTO tIDENTIFIER ';'
#line 255 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateGoto(yystack_[1].value.as < std::string_view > ()); }
#line 1309 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 52: // statement: tIDENTIFIER ':'
#line 257 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLabel(yystack_[1].value.as < std::string_view > ()); }
#line 1315 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 53: // statement: tRETURN ';'
#line 259 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateReturn(nullptr); }
#line 1321 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 54: // statement: tRETURN expression ';'
#line 261 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateReturn(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1327 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 55: // statement: tROLLBACK expression ';'
#line 263 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRollback(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1333 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 56: // statement: tBREAK ';'
#line 265 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateBreak(); }
#line 1339 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 57: // statement: tCONTINUE ';'
#line 267 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateContinue(); }
#line 1345 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 58: // statement: tHALT '(' ')' ';'
#line 269 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateHalt(); }
#line 1351 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 59: // statement: tYIELD '(' ')' ';'
#line 271 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateYield(); }
#line 1357 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 60: // statement: tCOMPLY '(' ')' ';'
#line 273 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateComply(); }
#line 1363 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 61: // statement: tREFUSE '(' ')' ';'
#line 275 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRefuse(); }
#line 1369 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 62: // statement: tPRINT '(' arg_calls ')' ';'
#line 277 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreatePrint(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1375 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 63: // statement: tREQUEST '(' expression ',' action_ref ')' ';'
#line 279 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRequest(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < mana::ActionReference > ().actor, yystack_[2].value.as < mana::ActionReference > ().action); }
#line 1381 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 64: // statement: tAwaitStart '(' expression ',' action_ref ')' ';'
#line 281 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAwaitStart(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < mana::ActionReference > ().actor, yystack_[2].value.as < mana::ActionReference > ().action); }
#line 1387 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 65: // statement: tAwaitCompletion '(' expression ',' action_ref ')' ';'
#line 283 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAwaitCompletion(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < mana::ActionReference > ().actor, yystack_[2].value.as < mana::ActionReference > ().action); }
#line 1393 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 66: // statement: tJOIN '(' expression ',' expression ')' ';'
#line 285 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateJoin(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1399 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 67: // statement: block
#line 286 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1405 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 68: // statement: declaration ';'
#line 287 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1411 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 69: // statement: expression ';'
#line 288 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1417 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 70: // statement: ';'
#line 290 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1423 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 71: // statement: error ';'
#line 292 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; yyerrok; yyclearin; }
#line 1429 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 72: // statement: error '}'
#line 294 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; yyerrok; yyclearin; }
#line 1435 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 73: // expression: left_hand '=' expression
#line 298 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1441 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 74: // expression: expression tAND expression
#line 300 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLogicalAnd(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1447 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 75: // expression: expression tOR expression
#line 302 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLogicalOr(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1453 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 76: // expression: expression tAADD expression
#line 304 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAddAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1459 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 77: // expression: expression tASUB expression
#line 306 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSubAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1465 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 78: // expression: expression tAMUL expression
#line 308 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMulAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1471 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 79: // expression: expression tADIV expression
#line 310 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDivAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1477 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 80: // expression: expression tAMOD expression
#line 312 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateModAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1483 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 81: // expression: expression tAAND expression
#line 314 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAndAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1489 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 82: // expression: expression tAOR expression
#line 316 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateOrAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1495 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 83: // expression: expression tAXOR expression
#line 318 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateXorAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1501 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 84: // expression: expression tALSHFT expression
#line 320 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLeftShiftAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1507 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 85: // expression: expression tARSHFT expression
#line 322 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRightShiftAndAssign(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1513 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 86: // expression: expression '+' expression
#line 324 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAdd(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1519 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 87: // expression: expression '-' expression
#line 326 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSub(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1525 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 88: // expression: expression '*' expression
#line 328 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMul(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1531 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 89: // expression: expression '/' expression
#line 330 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDiv(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1537 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 90: // expression: expression '%' expression
#line 332 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMod(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1543 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 91: // expression: expression tPOW expression
#line 334 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreatePow(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1549 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 92: // expression: expression '&' expression
#line 336 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateAnd(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1555 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 93: // expression: expression '|' expression
#line 338 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateOr(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1561 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 94: // expression: expression '^' expression
#line 340 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateXor(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1567 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 95: // expression: expression tLSHFT expression
#line 342 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLeftShift(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1573 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 96: // expression: expression tRSHFT expression
#line 344 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateRightShift(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1579 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 97: // expression: expression '>' expression
#line 346 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateGreater(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1585 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 98: // expression: expression tGE expression
#line 348 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateGreaterEqual(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1591 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 99: // expression: expression '<' expression
#line 350 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLess(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1597 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 100: // expression: expression tLE expression
#line 352 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateLessEqual(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1603 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 101: // expression: expression tEQ expression
#line 354 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateEqual(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1609 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 102: // expression: expression tNE expression
#line 356 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNotEqual(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1615 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 103: // expression: tINC expression
#line 358 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIncrement(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1621 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 104: // expression: tDEC expression
#line 360 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDecrement(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1627 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 105: // expression: expression tINC
#line 362 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIncrement(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1633 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 106: // expression: expression tDEC
#line 364 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDecrement(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1639 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 107: // expression: expression '?' expression ':' expression
#line 366 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateExpressionIf(yystack_[4].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1645 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 108: // expression: primary
#line 367 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1651 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 109: // primary: '-' expression
#line 371 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNegative(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1657 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 110: // primary: '+' expression
#line 373 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1663 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 111: // primary: '!' expression
#line 375 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNot(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1669 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 112: // primary: '~' expression
#line 377 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateComplement1(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1675 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 113: // primary: tSIZEOF '(' variable_type ')'
#line 379 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSizeOf(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1681 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 114: // primary: tIDENTIFIER '(' arg_calls ')'
#line 381 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateCall(yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1687 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 115: // primary: constant
#line 382 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1693 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 116: // primary: left_hand
#line 383 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1699 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 117: // constant: tFALSE
#line 387 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateBool(false); }
#line 1705 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 118: // constant: tTRUE
#line 389 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateBool(true); }
#line 1711 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 119: // constant: tPRIORITY
#line 391 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreatePriority(); }
#line 1717 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 120: // constant: tSELF
#line 393 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSelf(); }
#line 1723 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 121: // constant: tSENDER
#line 395 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSender(); }
#line 1729 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 122: // constant: tNIL
#line 397 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateNil(); }
#line 1735 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 123: // constant: tDIGIT
#line 399 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateInteger(yystack_[0].value.as < mana::int_t > ()); }
#line 1741 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 124: // constant: tREAL
#line 401 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateFloat(yystack_[0].value.as < mana::float_t > ()); }
#line 1747 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 125: // constant: tSTRING
#line 403 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateString(yystack_[0].value.as < std::string_view > ()); }
#line 1753 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 126: // left_hand: left_hand '.' tIDENTIFIER
#line 407 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMemberVariable(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::string_view > ()); }
#line 1759 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 127: // left_hand: left_hand '.' tIDENTIFIER '(' arg_calls ')'
#line 409 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateMemberFunction(yystack_[5].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[3].value.as < std::string_view > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1765 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 128: // left_hand: left_hand '[' expression ']'
#line 411 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateArray(yystack_[3].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1771 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 129: // left_hand: tIDENTIFIER
#line 413 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateIdentifier(yystack_[0].value.as < std::string_view > ()); }
#line 1777 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 130: // left_hand: tTHIS
#line 415 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateThis(); }
#line 1783 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 131: // left_hand: '(' expression ')'
#line 417 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1789 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 132: // qualified_name: tIDENTIFIER
#line 421 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::string_view > () = yystack_[0].value.as < std::string_view > (); }
#line 1795 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 133: // qualified_name: qualified_name tDC tIDENTIFIER
#line 423 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::string_view > () = mParsingDriver->CreateQualifiedName(yystack_[2].value.as < std::string_view > (), yystack_[0].value.as < std::string_view > ()); }
#line 1801 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 134: // action_ref: expression tARROW tIDENTIFIER optional_empty_parens
#line 427 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        {
						yylhs.value.as < mana::ActionReference > ().actor = yystack_[3].value.as < std::shared_ptr<mana::SyntaxNode> > ();
						yylhs.value.as < mana::ActionReference > ().action = yystack_[1].value.as < std::string_view > ();
					}
#line 1810 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 135: // action_ref: qualified_name tARROW tIDENTIFIER optional_empty_parens
#line 432 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        {
						yylhs.value.as < mana::ActionReference > ().actor = mParsingDriver->CreateIdentifier(yystack_[3].value.as < std::string_view > ());
						yylhs.value.as < mana::ActionReference > ().action = yystack_[1].value.as < std::string_view > ();
					}
#line 1819 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 136: // action_ref: qualified_name tDC tIDENTIFIER optional_empty_parens
#line 437 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        {
						if (yystack_[3].value.as < std::string_view > ().find("::") != std::string_view::npos)
						{
							mana::CompileError({ "legacy action reference cannot use namespace '", yystack_[3].value.as < std::string_view > (), "'" });
						}
						else
						{
							mana::CompileWarning({ "legacy action reference '", yystack_[3].value.as < std::string_view > (), "::", yystack_[1].value.as < std::string_view > (), "' is deprecated. Use '->' instead." });
						}
						yylhs.value.as < mana::ActionReference > ().actor = mParsingDriver->CreateIdentifier(yystack_[3].value.as < std::string_view > ());
						yylhs.value.as < mana::ActionReference > ().action = yystack_[1].value.as < std::string_view > ();
						yylhs.value.as < mana::ActionReference > ().legacy = true;
					}
#line 1837 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 139: // cases: case
#line 457 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                          { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1843 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 140: // cases: cases case
#line 459 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->BindCaseNode(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1849 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 141: // case: tCASE expression ':' statements
#line 462 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSwitchCaseNode(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1855 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 142: // case: tDEFAULT ':' statements
#line 464 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateSwitchDefaultNode(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1861 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 143: // arg_calls: %empty
#line 468 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1867 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 144: // arg_calls: expression
#line 470 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateArgumentNode(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1873 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 145: // arg_calls: expression ',' arg_calls
#line 472 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateArgumentNode(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1879 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 146: // arg_decls: %empty
#line 476 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = nullptr; }
#line 1885 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 147: // arg_decls: variable_decl
#line 478 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareArgumentNode(yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1891 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 148: // arg_decls: arg_decls ',' variable_decl
#line 480 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareArgumentNode(yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1897 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 149: // variable_decl: variable_type declarator
#line 485 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareVariableNode(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (), nullptr); }
#line 1903 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 150: // variable_decl: variable_type declarator '=' expression
#line 487 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclareVariableNode(yystack_[3].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1909 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 151: // const_decl: tCONST variable_type tIDENTIFIER '=' expression
#line 492 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateConstDeclarationNode(yystack_[3].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[2].value.as < std::string_view > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1915 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 152: // declarator: tIDENTIFIER
#line 496 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclaratorNode(yystack_[0].value.as < std::string_view > ()); }
#line 1921 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 153: // declarator: tIDENTIFIER variable_sizes
#line 498 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = mParsingDriver->CreateDeclaratorNode(yystack_[1].value.as < std::string_view > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1927 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 154: // variable_sizes: variable_size
#line 501 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                  { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > (); }
#line 1933 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 155: // variable_sizes: variable_size variable_sizes
#line 503 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = 	mParsingDriver->Bind(yystack_[1].value.as < std::shared_ptr<mana::SyntaxNode> > (), yystack_[0].value.as < std::shared_ptr<mana::SyntaxNode> > ()); }
#line 1939 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 156: // variable_size: '[' tDIGIT ']'
#line 506 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = 	mParsingDriver->CreateVariableSizeNode(yystack_[1].value.as < mana::int_t > ()); }
#line 1945 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;

  case 157: // variable_size: '[' tIDENTIFIER ']'
#line 508 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
                                        { yylhs.value.as < std::shared_ptr<mana::SyntaxNode> > () = 	mParsingDriver->CreateVariableSizeNode(yystack_[1].value.as < std::string_view > ()); }
#line 1951 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"
    break;


#line 1955 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"

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









  const short Parser::yypact_ninf_ = -325;

  const short Parser::yytable_ninf_ = -138;

  const short
  Parser::yypact_[] =
  {
     166,  -325,  -325,    14,    55,    89,    89,    36,    64,    67,
      79,    85,    85,   -27,    34,    93,  -325,   166,    -1,  -325,
    -325,  -325,    94,    71,  -325,  -325,    21,    35,   164,   177,
     106,   107,   110,   111,   -31,   -29,   204,    89,   112,  -325,
    -325,  -325,    -7,   145,   207,  -325,  -325,   150,   113,    23,
      26,    26,    26,   166,  -325,   137,   138,   233,   142,    89,
     382,    89,    22,  -325,  -325,   140,   591,  -325,   591,    89,
      89,   143,    23,  -325,   157,   250,    85,   159,   160,    26,
     161,   172,   173,    89,  -325,   140,    89,   174,   -22,  -325,
    -325,  -325,     6,  -325,  -325,  -325,  -325,  -325,  -325,  -325,
     158,   180,   182,   188,   192,   197,   269,   195,   483,   483,
     196,   200,   483,   201,   537,   591,   220,   221,   223,   234,
     237,   591,   591,   238,   591,   591,   591,   591,  -325,   591,
     236,  -325,   240,   281,  1345,  -325,  -325,   -50,    25,  -325,
     235,   256,  -325,   241,  1675,  1675,    27,   337,  -325,  -325,
    -325,   262,   -24,  -325,  -325,  -325,  -325,  -325,  -325,   266,
    -325,  -325,  -325,  -325,  -325,   591,   591,   591,   591,   591,
    -325,  -325,   271,   272,  -325,   322,   582,   591,  -325,   275,
    -325,  1387,  1429,   591,   591,   591,   276,   282,    37,    37,
      89,    37,    37,  -325,  -325,   977,  -325,  -325,  -325,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,  -325,
    -325,  -325,   591,   384,   591,   292,    89,  -325,  -325,   294,
     295,   291,   292,  -325,  -325,   742,   293,   789,   836,   883,
     930,  -325,   299,   297,     7,  1471,   301,  1023,   302,  -325,
    -325,  1069,  1115,   300,   303,   305,   315,  -325,  1714,  1714,
    1714,  1750,  1750,  1784,  1784,   375,   375,   375,  1597,   273,
     273,  1836,  1836,   147,   147,   147,   147,   108,   108,   183,
     461,   461,    30,    30,    -8,    -8,    -8,    -8,  1812,   317,
     703,  -325,  -325,  -325,    89,  -325,  -325,   591,  -325,   619,
     619,   619,   591,  -325,   591,   591,   591,   483,  -325,   323,
     483,   325,  -325,  -325,  -325,   591,   591,  -325,    32,  -325,
     664,   127,   333,   334,   340,  1161,  1207,  1513,  1555,   401,
     139,  -325,  -325,  1812,   362,   327,   462,   468,   469,   369,
     380,   381,   387,   393,   591,   591,   483,   591,   423,   -21,
    -325,  -325,  -325,   262,    97,   262,  -325,  -325,  -325,  -325,
    -325,  1253,  1299,  -325,  1636,   281,  -325,  -325,  -325,  -325,
    -325,   483,   483,   281,  -325,  -325,  -325,  -325
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       3,   132,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     5,
       6,     7,     0,    37,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,     1,
       4,     8,   152,   149,     0,    15,    16,     0,     0,    30,
      24,    24,    24,     3,    10,     0,     0,     0,     0,    17,
       0,   146,     0,    36,   153,   154,     0,   133,     0,   146,
       0,     0,    30,    33,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    17,    13,   152,    17,     0,     0,   123,
     124,   125,   129,   117,   118,   119,   120,   121,   130,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,    67,     0,     0,     0,   108,   115,   116,     0,   147,
       0,     0,   155,   129,   150,   151,     0,     0,    29,    31,
      32,   137,     0,    28,    21,    25,    22,    23,     9,     0,
      18,    12,    71,    72,    52,   143,     0,     0,     0,     0,
      56,    57,     0,     0,    50,     0,     0,     0,    49,     0,
      53,     0,     0,     0,     0,   143,     0,     0,   110,   109,
       0,   111,   112,   103,   104,     0,    68,    39,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,    69,     0,     0,     0,     0,     0,   156,   157,     0,
       0,     0,     0,    27,    14,   144,     0,     0,     0,     0,
       0,    51,     0,     0,   129,     0,     0,     0,     0,    54,
      55,     0,     0,     0,     0,     0,     0,   131,    78,    79,
      80,    76,    77,    84,    85,    81,    82,    83,     0,    74,
      75,   101,   102,    97,    98,   100,    99,    93,    94,    92,
      95,    96,    86,    87,    88,    89,    90,    91,    73,   126,
       0,    35,   148,    11,   146,   138,    26,   143,   114,     0,
       0,     0,     0,    58,     0,     0,     0,     0,    59,     0,
       0,     0,    60,    61,   113,     0,   143,   128,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,    45,    62,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     139,   127,    34,   137,   133,   137,    63,    64,    65,    66,
      46,     0,     0,    43,     0,     0,    44,   140,   134,   136,
     135,     0,     0,     0,   142,    47,    48,   141
  };

  const short
  Parser::yypgoto_[] =
  {
    -325,  -325,     3,  -325,   -33,    31,  -325,   -30,  -325,  -325,
     421,  -325,   -15,    18,   -38,  -125,  -102,   -63,  -325,  -325,
    -325,   -11,  -110,  -324,  -325,   135,  -141,   -67,    40,  -325,
    -325,   431,  -325
  };

  const short
  Parser::yydefgoto_[] =
  {
       0,    15,    16,    17,    56,   130,    19,    78,    79,    20,
      71,    72,    21,    57,   131,   132,   133,   134,   135,   136,
     137,    23,   332,   242,   359,   360,   246,   138,    24,    25,
      43,    64,    65
  };

  const short
  Parser::yytable_[] =
  {
      34,    35,   146,   144,    63,   145,   174,   175,   198,    44,
     178,    44,  -132,  -132,   357,   358,    44,   232,    22,    26,
      40,    80,    81,    28,    29,   140,    87,    36,   141,     1,
       2,    18,     1,     2,    73,    22,    70,    38,     5,   378,
     379,   380,    30,    75,   263,    76,  -132,  -132,    18,   155,
     159,   181,   182,   160,   233,   234,    82,    73,   188,   189,
      27,   191,   192,   193,   194,   152,   195,    22,    53,    54,
      31,    22,    37,    32,   243,   164,   162,    58,   163,   376,
     228,    77,    77,    77,    18,    33,   229,   230,   147,    74,
      22,     1,    60,    39,    61,     1,     2,    41,    62,    58,
      42,   139,   245,   247,   248,   249,   250,   165,   165,   139,
      77,    44,    74,   255,   257,   225,   226,   227,   228,    45,
     261,   262,   245,    58,   229,   230,    58,   235,   236,   239,
     236,   229,   230,    46,   345,   236,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   329,   347,   348,   298,
      47,   300,     1,     2,   357,   358,     3,     4,     5,     6,
       7,     8,     9,    48,    10,   344,    11,    12,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   301,   241,  -137,
     333,   334,   229,   230,   306,    49,    50,    55,   266,    51,
      52,    59,    66,    67,    69,   339,   256,    68,   341,    13,
      14,  -138,  -138,  -138,  -138,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    83,   328,    84,    85,
      86,   229,   230,   148,   245,    62,   330,   330,   330,   335,
     384,   336,   337,   338,   373,   150,   151,   153,   387,   166,
     154,   156,   343,   245,   221,   222,   223,   224,   225,   226,
     227,   228,   157,   158,   161,   172,   302,   229,   230,   385,
     386,   167,    88,   168,    89,    90,    91,    92,     2,   169,
     170,   371,   372,     5,   374,   171,   173,   176,   331,   331,
     331,   177,   179,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   -40,   -40,   106,   107,
     108,   183,   184,   109,   185,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   196,   186,   119,   120,   187,   190,
     197,   237,   165,   240,   139,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   238,   241,   121,   122,   244,   229,   230,   251,
     123,   124,   125,   253,   252,   126,   127,   258,   264,   128,
      60,   -40,   129,    88,   265,    89,    90,    91,    92,     2,
     299,    60,   303,   305,     5,   308,   304,   313,   314,   316,
     318,   322,   321,   323,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   324,   326,   106,
     107,   108,   340,   342,   109,   362,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   349,   350,   119,   120,  -138,
    -138,  -138,   351,   209,   356,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   361,   121,   122,   366,   363,   229,
     230,   123,   124,   125,   364,   365,   126,   127,   367,   368,
     128,    60,   -40,   129,    88,   369,    89,    90,    91,    92,
       2,   370,   375,   149,   377,     5,   142,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,   107,   108,     0,     0,   109,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,   119,   120,
      89,    90,    91,   143,   223,   224,   225,   226,   227,   228,
       0,     0,     0,     0,     0,   229,   230,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   121,   122,     0,     0,
       0,     0,   123,   124,   125,     0,     0,   126,   127,     0,
       0,   128,    60,     0,   129,    89,    90,    91,   254,     2,
       0,     0,     0,     0,    89,    90,    91,   143,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      99,     0,     0,    93,    94,    95,    96,    97,    98,    99,
     121,   122,    89,    90,    91,   254,   123,   124,   125,     0,
       0,   126,   127,     0,     0,   180,     0,     0,   129,     0,
       0,    93,    94,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   122,     0,     0,     0,
       0,   123,   124,   125,   121,   122,   126,   127,     0,     0,
     123,   124,   125,   129,     0,   126,   127,     0,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   122,     0,   346,     0,     0,   123,   124,
     125,     0,     0,   126,   127,     0,     0,     0,     0,     0,
     129,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,     0,   209,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     0,     0,     0,     0,     0,   229,   230,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,   229,   230,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   327,
     209,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,     0,     0,     0,     0,     0,   229,   230,     0,     0,
       0,     0,     0,     0,     0,   307,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,   229,   230,     0,     0,     0,     0,     0,
       0,     0,   309,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     0,   209,     0,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,     0,     0,     0,     0,
     229,   230,     0,     0,     0,     0,     0,     0,     0,   310,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,   229,   230,     0,
       0,     0,     0,     0,     0,     0,   311,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,     0,
       0,     0,     0,     0,   229,   230,     0,     0,     0,     0,
       0,     0,     0,   312,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     0,     0,     0,     0,
       0,   229,   230,     0,     0,     0,     0,     0,     0,   267,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,   229,   230,     0,
       0,     0,     0,     0,     0,   317,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,   229,   230,     0,     0,     0,     0,     0,
       0,   319,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,   229,
     230,     0,     0,     0,     0,     0,     0,   320,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
       0,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,     0,     0,     0,     0,   229,   230,     0,     0,     0,
       0,     0,     0,   352,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     0,     0,     0,     0,
       0,   229,   230,     0,     0,     0,     0,     0,     0,   353,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,   229,   230,     0,
       0,     0,     0,     0,     0,   381,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,   229,   230,     0,     0,     0,     0,     0,
       0,   382,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,   229,
     230,     0,     0,   231,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     0,     0,     0,     0,
       0,   229,   230,     0,     0,   259,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,   229,   230,     0,     0,   260,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
       0,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,     0,     0,     0,     0,   229,   230,     0,     0,   315,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,   229,   230,     0,
       0,   354,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,   229,
     230,     0,     0,   355,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   325,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     0,     0,     0,     0,
       0,   229,   230,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     0,   209,   383,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,     0,     0,     0,     0,
     229,   230,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,   229,
     230,  -138,  -138,  -138,   202,   203,   204,   205,   206,   207,
     208,     0,   209,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     0,     0,     0,     0,     0,   229,   230,
    -138,  -138,   204,   205,   206,   207,   208,     0,   209,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,     0,
       0,     0,     0,     0,   229,   230,  -138,  -138,   206,   207,
     208,     0,   209,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     0,     0,     0,     0,     0,   229,   230,
     209,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,     0,     0,     0,     0,     0,   229,   230,  -138,  -138,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,     0,     0,     0,     0,
     229,   230
  };

  const short
  Parser::yycheck_[] =
  {
      11,    12,    69,    66,    42,    68,   108,   109,   133,    40,
     112,    40,     6,     6,    35,    36,    40,    67,     0,     5,
      17,    51,    52,     5,     6,     3,    59,    54,     6,     6,
       7,     0,     6,     7,    49,    17,    13,     3,    12,   363,
     364,   365,     6,    17,   185,    19,    40,    40,    17,    79,
      83,   114,   115,    86,   104,   105,    53,    72,   121,   122,
       5,   124,   125,   126,   127,    76,   129,    49,    99,    98,
       6,    53,    99,     6,    98,    69,    98,    37,   100,   100,
      88,    50,    51,    52,    53,     6,    94,    95,    70,    49,
      72,     6,    99,     0,   101,     6,     7,    98,   105,    59,
       6,    61,   165,   166,   167,   168,   169,   101,   101,    69,
      79,    40,    72,   176,   177,    85,    86,    87,    88,    98,
     183,   184,   185,    83,    94,    95,    86,   102,   103,   102,
     103,    94,    95,    98,   102,   103,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   307,    40,    41,   232,
       6,   234,     6,     7,    35,    36,    10,    11,    12,    13,
      14,    15,    16,     6,    18,   326,    20,    21,    80,    81,
      82,    83,    84,    85,    86,    87,    88,   235,   101,   102,
     310,   311,    94,    95,   242,    99,    99,     3,   190,    99,
      99,    99,    67,     6,   101,   317,   176,    67,   320,    53,
      54,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    99,   304,   100,     6,
      98,    94,    95,   100,   307,   105,   309,   310,   311,   312,
     375,   314,   315,   316,   356,    98,     6,    98,   383,   101,
     100,   100,   325,   326,    81,    82,    83,    84,    85,    86,
      87,    88,   100,   100,   100,     6,   236,    94,    95,   381,
     382,   101,     1,   101,     3,     4,     5,     6,     7,   101,
      98,   354,   355,    12,   357,    98,   101,   101,   309,   310,
     311,   101,   101,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   101,   101,    42,   101,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    98,   101,    55,    56,   101,   101,
     100,   106,   101,     6,   304,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   106,   101,    83,    84,   100,    94,    95,    98,
      89,    90,    91,    51,   102,    94,    95,   102,   102,    98,
      99,   100,   101,     1,   102,     3,     4,     5,     6,     7,
       6,    99,    98,   102,    12,   102,   101,    98,   101,    98,
      98,    98,   102,    98,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   102,   101,    37,
      38,    39,    99,    98,    42,    98,    44,    45,    46,    47,
      48,    49,    50,    51,    52,   102,   102,    55,    56,    64,
      65,    66,   102,    68,    43,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   102,    83,    84,    98,     6,    94,
      95,    89,    90,    91,     6,     6,    94,    95,    98,    98,
      98,    99,   100,   101,     1,    98,     3,     4,     5,     6,
       7,    98,    69,    72,   359,    12,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    38,    39,    -1,    -1,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    56,
       3,     4,     5,     6,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    83,    84,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    -1,
      -1,    98,    99,    -1,   101,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      83,    84,     3,     4,     5,     6,    89,    90,    91,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    89,    90,    91,    83,    84,    94,    95,    -1,    -1,
      89,    90,    91,   101,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    41,    -1,    -1,    89,    90,
      91,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
     101,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   106,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    57,    58,    59,    60,    61,    62,
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
      -1,    -1,    -1,    -1,    -1,   102,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    57,    58,    59,    60,    61,    62,    63,    64,
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
      65,    66,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    94,    95,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      94,    95,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,
      95,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    94,    95,    62,    63,    64,    65,
      66,    -1,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    94,    95,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      94,    95
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     6,     7,    10,    11,    12,    13,    14,    15,    16,
      18,    20,    21,    53,    54,   108,   109,   110,   112,   113,
     116,   119,   120,   128,   135,   136,     5,     5,   120,   120,
       6,     6,     6,     6,   128,   128,    54,    99,     3,     0,
     109,    98,     6,   137,    40,    98,    98,     6,     6,    99,
      99,    99,    99,    99,    98,     3,   111,   120,   135,    99,
      99,   101,   105,   121,   138,   139,    67,     6,    67,   101,
      13,   117,   118,   119,   135,    17,    19,   112,   114,   115,
     114,   114,   109,    99,   100,     6,    98,   111,     1,     3,
       4,     5,     6,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    37,    38,    39,    42,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    55,
      56,    83,    84,    89,    90,    91,    94,    95,    98,   101,
     112,   121,   122,   123,   124,   125,   126,   127,   134,   135,
       3,     6,   138,     6,   124,   124,   134,   120,   100,   117,
      98,     6,   128,    98,   100,   114,   100,   100,   100,   111,
     111,   100,    98,   100,    69,   101,   101,   101,   101,   101,
      98,    98,     6,   101,   123,   123,   101,   101,   123,   101,
      98,   124,   124,   101,   101,   101,   101,   101,   124,   124,
     101,   124,   124,   124,   124,   124,    98,   100,   122,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    68,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    94,
      95,    98,    67,   104,   105,   102,   103,   106,   106,   102,
       6,   101,   130,    98,   100,   124,   133,   124,   124,   124,
     124,    98,   102,    51,     6,   124,   135,   124,   102,    98,
      98,   124,   124,   133,   102,   102,   120,   102,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,     6,
     124,   121,   135,    98,   101,   102,   121,   103,   102,   103,
     103,   103,   103,    98,   101,    98,    98,   102,    98,   102,
     102,   102,    98,    98,   102,    69,   101,   106,   134,   133,
     124,   128,   129,   129,   129,   124,   124,   124,   124,   123,
      99,   123,    98,   124,   133,   102,    41,    40,    41,   102,
     102,   102,   102,   102,    98,    98,    43,    35,    36,   131,
     132,   102,    98,     6,     6,     6,    98,    98,    98,    98,
      98,   124,   124,   123,   124,    69,   100,   132,   130,   130,
     130,   102,   102,    69,   122,   123,   123,   122
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,   107,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     112,   113,   113,   113,   114,   114,   115,   115,   115,   116,
     117,   117,   118,   118,   118,   119,   119,   120,   120,   121,
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
     131,   132,   132,   133,   133,   133,   134,   134,   134,   135,
     135,   136,   137,   137,   138,   138,   139,   139
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     2,     5,
       3,     7,     5,     4,     6,     3,     3,     0,     3,     1,
       1,     5,     5,     5,     0,     2,     4,     3,     2,     5,
       0,     2,     2,     1,     7,     6,     3,     1,     1,     3,
       0,     2,     5,     7,     7,     5,     7,     9,     9,     2,
       2,     3,     2,     2,     3,     3,     2,     2,     4,     4,
       4,     4,     5,     7,     7,     7,     7,     1,     2,     2,
       1,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     5,     1,     2,
       2,     2,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     4,     1,
       1,     3,     1,     3,     4,     4,     4,     0,     2,     1,
       2,     4,     3,     0,     1,     3,     0,     1,     3,     2,
       4,     5,     1,     2,     1,     2,     3,     3
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
  "qualified_name", "action_ref", "optional_empty_parens", "cases", "case",
  "arg_calls", "arg_decls", "variable_decl", "const_decl", "declarator",
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
     204,   205,   209,   210,   211,   215,   217,   221,   223,   227,
     232,   233,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   287,   288,
     289,   291,   293,   297,   299,   301,   303,   305,   307,   309,
     311,   313,   315,   317,   319,   321,   323,   325,   327,   329,
     331,   333,   335,   337,   339,   341,   343,   345,   347,   349,
     351,   353,   355,   357,   359,   361,   363,   365,   367,   370,
     372,   374,   376,   378,   380,   382,   383,   386,   388,   390,
     392,   394,   396,   398,   400,   402,   406,   408,   410,   412,
     414,   416,   420,   422,   426,   431,   436,   453,   454,   457,
     458,   461,   463,   468,   469,   471,   476,   477,   479,   484,
     486,   491,   495,   497,   501,   502,   505,   507
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

#line 19 "/home/runner/work/Mana/Mana/compiler/Parser.yy"
} // mana
#line 2877 "/home/runner/work/Mana/Mana/build/generated/Parser.cpp"

#line 510 "/home/runner/work/Mana/Mana/compiler/Parser.yy"


#include "ParserDefinition.inl"
