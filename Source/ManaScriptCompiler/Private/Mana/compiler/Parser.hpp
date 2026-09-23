// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file Parser.hpp
 ** Define the mana::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 25 "Parser.yy"

	#include "../runner/common/Setup.h"
	#include "SyntaxNode.h"
	#include "TypeDescriptor.h"

	namespace mana {
		class ParsingDriver;

		struct ActionReference
		{
			std::shared_ptr<mana::SyntaxNode> actor;
			std::string_view action;
			bool legacy = false;
		};
	}

#line 66 "Parser.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 19 "Parser.yy"
namespace mana {
#line 202 "Parser.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // action_ref
      char dummy1[sizeof (mana::ActionReference)];

      // tREAL
      char dummy2[sizeof (mana::float_t)];

      // tDIGIT
      char dummy3[sizeof (mana::int_t)];

      // line
      // declarations
      // allocate_declarations
      // declaration
      // actor
      // actions
      // action
      // struct
      // struct_members
      // struct_member
      // function
      // variable_type
      // block
      // statements
      // statement
      // expression
      // primary
      // constant
      // left_hand
      // cases
      // case
      // arg_calls
      // arg_decls
      // variable_decl
      // const_decl
      // declarator
      // variable_sizes
      // variable_size
      char dummy4[sizeof (std::shared_ptr<mana::SyntaxNode>)];

      // tTYPE
      char dummy5[sizeof (std::shared_ptr<mana::TypeDescriptor>)];

      // tSTRING
      // tIDENTIFIER
      // qualified_name
      char dummy6[sizeof (std::string_view)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    tDIGIT = 258,                  // tDIGIT
    tREAL = 259,                   // tREAL
    tSTRING = 260,                 // tSTRING
    tIDENTIFIER = 261,             // tIDENTIFIER
    tTYPE = 262,                   // tTYPE
    tDEFINE = 263,                 // tDEFINE
    tUNDEF = 264,                  // tUNDEF
    tINCLUDE = 265,                // tINCLUDE
    tIMPORT = 266,                 // tIMPORT
    tCONST = 267,                  // tCONST
    tNATIVE = 268,                 // tNATIVE
    tSTRUCT = 269,                 // tSTRUCT
    tACTOR = 270,                  // tACTOR
    tPHANTOM = 271,                // tPHANTOM
    tACTION = 272,                 // tACTION
    tMODULE = 273,                 // tMODULE
    tEXTEND = 274,                 // tEXTEND
    tNAMESPACE = 275,              // tNAMESPACE
    tUSING = 276,                  // tUSING
    tFALSE = 277,                  // tFALSE
    tTRUE = 278,                   // tTRUE
    tPRIORITY = 279,               // tPRIORITY
    tSELF = 280,                   // tSELF
    tSENDER = 281,                 // tSENDER
    tTHIS = 282,                   // tTHIS
    tNIL = 283,                    // tNIL
    tREQUEST = 284,                // tREQUEST
    tAwaitStart = 285,             // tAwaitStart
    tAwaitCompletion = 286,        // tAwaitCompletion
    tJOIN = 287,                   // tJOIN
    tBREAK = 288,                  // tBREAK
    tCONTINUE = 289,               // tCONTINUE
    tCASE = 290,                   // tCASE
    tDEFAULT = 291,                // tDEFAULT
    GOTO = 292,                    // GOTO
    tHALT = 293,                   // tHALT
    tLOCK = 294,                   // tLOCK
    tDC = 295,                     // tDC
    tARROW = 296,                  // tARROW
    tDO = 297,                     // tDO
    tELSE = 298,                   // tELSE
    tFOR = 299,                    // tFOR
    tIF = 300,                     // tIF
    tLOOP = 301,                   // tLOOP
    tYIELD = 302,                  // tYIELD
    tRETURN = 303,                 // tRETURN
    tROLLBACK = 304,               // tROLLBACK
    tSWITCH = 305,                 // tSWITCH
    tWHILE = 306,                  // tWHILE
    tPRINT = 307,                  // tPRINT
    tSTATIC = 308,                 // tSTATIC
    tALLOCATE = 309,               // tALLOCATE
    tCOMPLY = 310,                 // tCOMPLY
    tREFUSE = 311,                 // tREFUSE
    tAMUL = 312,                   // tAMUL
    tADIV = 313,                   // tADIV
    tAMOD = 314,                   // tAMOD
    tAADD = 315,                   // tAADD
    tASUB = 316,                   // tASUB
    tALSHFT = 317,                 // tALSHFT
    tARSHFT = 318,                 // tARSHFT
    tAAND = 319,                   // tAAND
    tAOR = 320,                    // tAOR
    tAXOR = 321,                   // tAXOR
    tAND = 322,                    // tAND
    tOR = 323,                     // tOR
    tEQ = 324,                     // tEQ
    tNE = 325,                     // tNE
    tGE = 326,                     // tGE
    tLE = 327,                     // tLE
    tLSHFT = 328,                  // tLSHFT
    tRSHFT = 329,                  // tRSHFT
    tPOW = 330,                    // tPOW
    tSIZEOF = 331,                 // tSIZEOF
    tUPLUS = 332,                  // tUPLUS
    tUMINUS = 333,                 // tUMINUS
    tINC = 334,                    // tINC
    tDEC = 335,                    // tDEC
    tUINC = 336,                   // tUINC
    tUDEC = 337                    // tUDEC
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 107, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_tDIGIT = 3,                            // tDIGIT
        S_tREAL = 4,                             // tREAL
        S_tSTRING = 5,                           // tSTRING
        S_tIDENTIFIER = 6,                       // tIDENTIFIER
        S_tTYPE = 7,                             // tTYPE
        S_tDEFINE = 8,                           // tDEFINE
        S_tUNDEF = 9,                            // tUNDEF
        S_tINCLUDE = 10,                         // tINCLUDE
        S_tIMPORT = 11,                          // tIMPORT
        S_tCONST = 12,                           // tCONST
        S_tNATIVE = 13,                          // tNATIVE
        S_tSTRUCT = 14,                          // tSTRUCT
        S_tACTOR = 15,                           // tACTOR
        S_tPHANTOM = 16,                         // tPHANTOM
        S_tACTION = 17,                          // tACTION
        S_tMODULE = 18,                          // tMODULE
        S_tEXTEND = 19,                          // tEXTEND
        S_tNAMESPACE = 20,                       // tNAMESPACE
        S_tUSING = 21,                           // tUSING
        S_tFALSE = 22,                           // tFALSE
        S_tTRUE = 23,                            // tTRUE
        S_tPRIORITY = 24,                        // tPRIORITY
        S_tSELF = 25,                            // tSELF
        S_tSENDER = 26,                          // tSENDER
        S_tTHIS = 27,                            // tTHIS
        S_tNIL = 28,                             // tNIL
        S_tREQUEST = 29,                         // tREQUEST
        S_tAwaitStart = 30,                      // tAwaitStart
        S_tAwaitCompletion = 31,                 // tAwaitCompletion
        S_tJOIN = 32,                            // tJOIN
        S_tBREAK = 33,                           // tBREAK
        S_tCONTINUE = 34,                        // tCONTINUE
        S_tCASE = 35,                            // tCASE
        S_tDEFAULT = 36,                         // tDEFAULT
        S_GOTO = 37,                             // GOTO
        S_tHALT = 38,                            // tHALT
        S_tLOCK = 39,                            // tLOCK
        S_tDC = 40,                              // tDC
        S_tARROW = 41,                           // tARROW
        S_tDO = 42,                              // tDO
        S_tELSE = 43,                            // tELSE
        S_tFOR = 44,                             // tFOR
        S_tIF = 45,                              // tIF
        S_tLOOP = 46,                            // tLOOP
        S_tYIELD = 47,                           // tYIELD
        S_tRETURN = 48,                          // tRETURN
        S_tROLLBACK = 49,                        // tROLLBACK
        S_tSWITCH = 50,                          // tSWITCH
        S_tWHILE = 51,                           // tWHILE
        S_tPRINT = 52,                           // tPRINT
        S_tSTATIC = 53,                          // tSTATIC
        S_tALLOCATE = 54,                        // tALLOCATE
        S_tCOMPLY = 55,                          // tCOMPLY
        S_tREFUSE = 56,                          // tREFUSE
        S_tAMUL = 57,                            // tAMUL
        S_tADIV = 58,                            // tADIV
        S_tAMOD = 59,                            // tAMOD
        S_tAADD = 60,                            // tAADD
        S_tASUB = 61,                            // tASUB
        S_tALSHFT = 62,                          // tALSHFT
        S_tARSHFT = 63,                          // tARSHFT
        S_tAAND = 64,                            // tAAND
        S_tAOR = 65,                             // tAOR
        S_tAXOR = 66,                            // tAXOR
        S_67_ = 67,                              // '='
        S_68_ = 68,                              // '?'
        S_69_ = 69,                              // ':'
        S_tAND = 70,                             // tAND
        S_tOR = 71,                              // tOR
        S_tEQ = 72,                              // tEQ
        S_tNE = 73,                              // tNE
        S_74_ = 74,                              // '>'
        S_tGE = 75,                              // tGE
        S_tLE = 76,                              // tLE
        S_77_ = 77,                              // '<'
        S_78_ = 78,                              // '|'
        S_79_ = 79,                              // '^'
        S_80_ = 80,                              // '&'
        S_tLSHFT = 81,                           // tLSHFT
        S_tRSHFT = 82,                           // tRSHFT
        S_83_ = 83,                              // '+'
        S_84_ = 84,                              // '-'
        S_85_ = 85,                              // '*'
        S_86_ = 86,                              // '/'
        S_87_ = 87,                              // '%'
        S_tPOW = 88,                             // tPOW
        S_tSIZEOF = 89,                          // tSIZEOF
        S_90_ = 90,                              // '!'
        S_91_ = 91,                              // '~'
        S_tUPLUS = 92,                           // tUPLUS
        S_tUMINUS = 93,                          // tUMINUS
        S_tINC = 94,                             // tINC
        S_tDEC = 95,                             // tDEC
        S_tUINC = 96,                            // tUINC
        S_tUDEC = 97,                            // tUDEC
        S_98_ = 98,                              // ';'
        S_99_ = 99,                              // '{'
        S_100_ = 100,                            // '}'
        S_101_ = 101,                            // '('
        S_102_ = 102,                            // ')'
        S_103_ = 103,                            // ','
        S_104_ = 104,                            // '.'
        S_105_ = 105,                            // '['
        S_106_ = 106,                            // ']'
        S_YYACCEPT = 107,                        // $accept
        S_program = 108,                         // program
        S_line = 109,                            // line
        S_declarations = 110,                    // declarations
        S_allocate_declarations = 111,           // allocate_declarations
        S_declaration = 112,                     // declaration
        S_actor = 113,                           // actor
        S_actions = 114,                         // actions
        S_action = 115,                          // action
        S_struct = 116,                          // struct
        S_struct_members = 117,                  // struct_members
        S_struct_member = 118,                   // struct_member
        S_function = 119,                        // function
        S_variable_type = 120,                   // variable_type
        S_block = 121,                           // block
        S_statements = 122,                      // statements
        S_statement = 123,                       // statement
        S_expression = 124,                      // expression
        S_primary = 125,                         // primary
        S_constant = 126,                        // constant
        S_left_hand = 127,                       // left_hand
        S_qualified_name = 128,                  // qualified_name
        S_action_ref = 129,                      // action_ref
        S_cases = 130,                           // cases
        S_case = 131,                            // case
        S_arg_calls = 132,                       // arg_calls
        S_arg_decls = 133,                       // arg_decls
        S_variable_decl = 134,                   // variable_decl
        S_const_decl = 135,                      // const_decl
        S_declarator = 136,                      // declarator
        S_variable_sizes = 137,                  // variable_sizes
        S_variable_size = 138                    // variable_size
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_action_ref: // action_ref
        value.move< mana::ActionReference > (std::move (that.value));
        break;

      case symbol_kind::S_tREAL: // tREAL
        value.move< mana::float_t > (std::move (that.value));
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        value.move< mana::int_t > (std::move (that.value));
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
        value.move< std::shared_ptr<mana::SyntaxNode> > (std::move (that.value));
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        value.move< std::shared_ptr<mana::TypeDescriptor> > (std::move (that.value));
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< std::string_view > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, mana::ActionReference&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const mana::ActionReference& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, mana::float_t&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const mana::float_t& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, mana::int_t&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const mana::int_t& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<mana::SyntaxNode>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<mana::SyntaxNode>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<mana::TypeDescriptor>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<mana::TypeDescriptor>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string_view&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string_view& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_action_ref: // action_ref
        value.template destroy< mana::ActionReference > ();
        break;

      case symbol_kind::S_tREAL: // tREAL
        value.template destroy< mana::float_t > ();
        break;

      case symbol_kind::S_tDIGIT: // tDIGIT
        value.template destroy< mana::int_t > ();
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
        value.template destroy< std::shared_ptr<mana::SyntaxNode> > ();
        break;

      case symbol_kind::S_tTYPE: // tTYPE
        value.template destroy< std::shared_ptr<mana::TypeDescriptor> > ();
        break;

      case symbol_kind::S_tSTRING: // tSTRING
      case symbol_kind::S_tIDENTIFIER: // tIDENTIFIER
      case symbol_kind::S_qualified_name: // qualified_name
        value.template destroy< std::string_view > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, mana::float_t v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const mana::float_t& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, mana::int_t v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const mana::int_t& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::shared_ptr<mana::TypeDescriptor> v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::shared_ptr<mana::TypeDescriptor>& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string_view v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string_view& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    Parser (mana::ParsingDriver* mParsingDriver_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tDIGIT (mana::int_t v)
      {
        return symbol_type (token::tDIGIT, std::move (v));
      }
#else
      static
      symbol_type
      make_tDIGIT (const mana::int_t& v)
      {
        return symbol_type (token::tDIGIT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tREAL (mana::float_t v)
      {
        return symbol_type (token::tREAL, std::move (v));
      }
#else
      static
      symbol_type
      make_tREAL (const mana::float_t& v)
      {
        return symbol_type (token::tREAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tSTRING (std::string_view v)
      {
        return symbol_type (token::tSTRING, std::move (v));
      }
#else
      static
      symbol_type
      make_tSTRING (const std::string_view& v)
      {
        return symbol_type (token::tSTRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tIDENTIFIER (std::string_view v)
      {
        return symbol_type (token::tIDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_tIDENTIFIER (const std::string_view& v)
      {
        return symbol_type (token::tIDENTIFIER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tTYPE (std::shared_ptr<mana::TypeDescriptor> v)
      {
        return symbol_type (token::tTYPE, std::move (v));
      }
#else
      static
      symbol_type
      make_tTYPE (const std::shared_ptr<mana::TypeDescriptor>& v)
      {
        return symbol_type (token::tTYPE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tDEFINE ()
      {
        return symbol_type (token::tDEFINE);
      }
#else
      static
      symbol_type
      make_tDEFINE ()
      {
        return symbol_type (token::tDEFINE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tUNDEF ()
      {
        return symbol_type (token::tUNDEF);
      }
#else
      static
      symbol_type
      make_tUNDEF ()
      {
        return symbol_type (token::tUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tINCLUDE ()
      {
        return symbol_type (token::tINCLUDE);
      }
#else
      static
      symbol_type
      make_tINCLUDE ()
      {
        return symbol_type (token::tINCLUDE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tIMPORT ()
      {
        return symbol_type (token::tIMPORT);
      }
#else
      static
      symbol_type
      make_tIMPORT ()
      {
        return symbol_type (token::tIMPORT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tCONST ()
      {
        return symbol_type (token::tCONST);
      }
#else
      static
      symbol_type
      make_tCONST ()
      {
        return symbol_type (token::tCONST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tNATIVE ()
      {
        return symbol_type (token::tNATIVE);
      }
#else
      static
      symbol_type
      make_tNATIVE ()
      {
        return symbol_type (token::tNATIVE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tSTRUCT ()
      {
        return symbol_type (token::tSTRUCT);
      }
#else
      static
      symbol_type
      make_tSTRUCT ()
      {
        return symbol_type (token::tSTRUCT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tACTOR ()
      {
        return symbol_type (token::tACTOR);
      }
#else
      static
      symbol_type
      make_tACTOR ()
      {
        return symbol_type (token::tACTOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tPHANTOM ()
      {
        return symbol_type (token::tPHANTOM);
      }
#else
      static
      symbol_type
      make_tPHANTOM ()
      {
        return symbol_type (token::tPHANTOM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tACTION ()
      {
        return symbol_type (token::tACTION);
      }
#else
      static
      symbol_type
      make_tACTION ()
      {
        return symbol_type (token::tACTION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tMODULE ()
      {
        return symbol_type (token::tMODULE);
      }
#else
      static
      symbol_type
      make_tMODULE ()
      {
        return symbol_type (token::tMODULE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tEXTEND ()
      {
        return symbol_type (token::tEXTEND);
      }
#else
      static
      symbol_type
      make_tEXTEND ()
      {
        return symbol_type (token::tEXTEND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tNAMESPACE ()
      {
        return symbol_type (token::tNAMESPACE);
      }
#else
      static
      symbol_type
      make_tNAMESPACE ()
      {
        return symbol_type (token::tNAMESPACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tUSING ()
      {
        return symbol_type (token::tUSING);
      }
#else
      static
      symbol_type
      make_tUSING ()
      {
        return symbol_type (token::tUSING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tFALSE ()
      {
        return symbol_type (token::tFALSE);
      }
#else
      static
      symbol_type
      make_tFALSE ()
      {
        return symbol_type (token::tFALSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tTRUE ()
      {
        return symbol_type (token::tTRUE);
      }
#else
      static
      symbol_type
      make_tTRUE ()
      {
        return symbol_type (token::tTRUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tPRIORITY ()
      {
        return symbol_type (token::tPRIORITY);
      }
#else
      static
      symbol_type
      make_tPRIORITY ()
      {
        return symbol_type (token::tPRIORITY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tSELF ()
      {
        return symbol_type (token::tSELF);
      }
#else
      static
      symbol_type
      make_tSELF ()
      {
        return symbol_type (token::tSELF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tSENDER ()
      {
        return symbol_type (token::tSENDER);
      }
#else
      static
      symbol_type
      make_tSENDER ()
      {
        return symbol_type (token::tSENDER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tTHIS ()
      {
        return symbol_type (token::tTHIS);
      }
#else
      static
      symbol_type
      make_tTHIS ()
      {
        return symbol_type (token::tTHIS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tNIL ()
      {
        return symbol_type (token::tNIL);
      }
#else
      static
      symbol_type
      make_tNIL ()
      {
        return symbol_type (token::tNIL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tREQUEST ()
      {
        return symbol_type (token::tREQUEST);
      }
#else
      static
      symbol_type
      make_tREQUEST ()
      {
        return symbol_type (token::tREQUEST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAwaitStart ()
      {
        return symbol_type (token::tAwaitStart);
      }
#else
      static
      symbol_type
      make_tAwaitStart ()
      {
        return symbol_type (token::tAwaitStart);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAwaitCompletion ()
      {
        return symbol_type (token::tAwaitCompletion);
      }
#else
      static
      symbol_type
      make_tAwaitCompletion ()
      {
        return symbol_type (token::tAwaitCompletion);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tJOIN ()
      {
        return symbol_type (token::tJOIN);
      }
#else
      static
      symbol_type
      make_tJOIN ()
      {
        return symbol_type (token::tJOIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tBREAK ()
      {
        return symbol_type (token::tBREAK);
      }
#else
      static
      symbol_type
      make_tBREAK ()
      {
        return symbol_type (token::tBREAK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tCONTINUE ()
      {
        return symbol_type (token::tCONTINUE);
      }
#else
      static
      symbol_type
      make_tCONTINUE ()
      {
        return symbol_type (token::tCONTINUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tCASE ()
      {
        return symbol_type (token::tCASE);
      }
#else
      static
      symbol_type
      make_tCASE ()
      {
        return symbol_type (token::tCASE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tDEFAULT ()
      {
        return symbol_type (token::tDEFAULT);
      }
#else
      static
      symbol_type
      make_tDEFAULT ()
      {
        return symbol_type (token::tDEFAULT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GOTO ()
      {
        return symbol_type (token::GOTO);
      }
#else
      static
      symbol_type
      make_GOTO ()
      {
        return symbol_type (token::GOTO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tHALT ()
      {
        return symbol_type (token::tHALT);
      }
#else
      static
      symbol_type
      make_tHALT ()
      {
        return symbol_type (token::tHALT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tLOCK ()
      {
        return symbol_type (token::tLOCK);
      }
#else
      static
      symbol_type
      make_tLOCK ()
      {
        return symbol_type (token::tLOCK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tDC ()
      {
        return symbol_type (token::tDC);
      }
#else
      static
      symbol_type
      make_tDC ()
      {
        return symbol_type (token::tDC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tARROW ()
      {
        return symbol_type (token::tARROW);
      }
#else
      static
      symbol_type
      make_tARROW ()
      {
        return symbol_type (token::tARROW);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tDO ()
      {
        return symbol_type (token::tDO);
      }
#else
      static
      symbol_type
      make_tDO ()
      {
        return symbol_type (token::tDO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tELSE ()
      {
        return symbol_type (token::tELSE);
      }
#else
      static
      symbol_type
      make_tELSE ()
      {
        return symbol_type (token::tELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tFOR ()
      {
        return symbol_type (token::tFOR);
      }
#else
      static
      symbol_type
      make_tFOR ()
      {
        return symbol_type (token::tFOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tIF ()
      {
        return symbol_type (token::tIF);
      }
#else
      static
      symbol_type
      make_tIF ()
      {
        return symbol_type (token::tIF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tLOOP ()
      {
        return symbol_type (token::tLOOP);
      }
#else
      static
      symbol_type
      make_tLOOP ()
      {
        return symbol_type (token::tLOOP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tYIELD ()
      {
        return symbol_type (token::tYIELD);
      }
#else
      static
      symbol_type
      make_tYIELD ()
      {
        return symbol_type (token::tYIELD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tRETURN ()
      {
        return symbol_type (token::tRETURN);
      }
#else
      static
      symbol_type
      make_tRETURN ()
      {
        return symbol_type (token::tRETURN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tROLLBACK ()
      {
        return symbol_type (token::tROLLBACK);
      }
#else
      static
      symbol_type
      make_tROLLBACK ()
      {
        return symbol_type (token::tROLLBACK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tSWITCH ()
      {
        return symbol_type (token::tSWITCH);
      }
#else
      static
      symbol_type
      make_tSWITCH ()
      {
        return symbol_type (token::tSWITCH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tWHILE ()
      {
        return symbol_type (token::tWHILE);
      }
#else
      static
      symbol_type
      make_tWHILE ()
      {
        return symbol_type (token::tWHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tPRINT ()
      {
        return symbol_type (token::tPRINT);
      }
#else
      static
      symbol_type
      make_tPRINT ()
      {
        return symbol_type (token::tPRINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tSTATIC ()
      {
        return symbol_type (token::tSTATIC);
      }
#else
      static
      symbol_type
      make_tSTATIC ()
      {
        return symbol_type (token::tSTATIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tALLOCATE ()
      {
        return symbol_type (token::tALLOCATE);
      }
#else
      static
      symbol_type
      make_tALLOCATE ()
      {
        return symbol_type (token::tALLOCATE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tCOMPLY ()
      {
        return symbol_type (token::tCOMPLY);
      }
#else
      static
      symbol_type
      make_tCOMPLY ()
      {
        return symbol_type (token::tCOMPLY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tREFUSE ()
      {
        return symbol_type (token::tREFUSE);
      }
#else
      static
      symbol_type
      make_tREFUSE ()
      {
        return symbol_type (token::tREFUSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAMUL ()
      {
        return symbol_type (token::tAMUL);
      }
#else
      static
      symbol_type
      make_tAMUL ()
      {
        return symbol_type (token::tAMUL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tADIV ()
      {
        return symbol_type (token::tADIV);
      }
#else
      static
      symbol_type
      make_tADIV ()
      {
        return symbol_type (token::tADIV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAMOD ()
      {
        return symbol_type (token::tAMOD);
      }
#else
      static
      symbol_type
      make_tAMOD ()
      {
        return symbol_type (token::tAMOD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAADD ()
      {
        return symbol_type (token::tAADD);
      }
#else
      static
      symbol_type
      make_tAADD ()
      {
        return symbol_type (token::tAADD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tASUB ()
      {
        return symbol_type (token::tASUB);
      }
#else
      static
      symbol_type
      make_tASUB ()
      {
        return symbol_type (token::tASUB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tALSHFT ()
      {
        return symbol_type (token::tALSHFT);
      }
#else
      static
      symbol_type
      make_tALSHFT ()
      {
        return symbol_type (token::tALSHFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tARSHFT ()
      {
        return symbol_type (token::tARSHFT);
      }
#else
      static
      symbol_type
      make_tARSHFT ()
      {
        return symbol_type (token::tARSHFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAAND ()
      {
        return symbol_type (token::tAAND);
      }
#else
      static
      symbol_type
      make_tAAND ()
      {
        return symbol_type (token::tAAND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAOR ()
      {
        return symbol_type (token::tAOR);
      }
#else
      static
      symbol_type
      make_tAOR ()
      {
        return symbol_type (token::tAOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAXOR ()
      {
        return symbol_type (token::tAXOR);
      }
#else
      static
      symbol_type
      make_tAXOR ()
      {
        return symbol_type (token::tAXOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tAND ()
      {
        return symbol_type (token::tAND);
      }
#else
      static
      symbol_type
      make_tAND ()
      {
        return symbol_type (token::tAND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tOR ()
      {
        return symbol_type (token::tOR);
      }
#else
      static
      symbol_type
      make_tOR ()
      {
        return symbol_type (token::tOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tEQ ()
      {
        return symbol_type (token::tEQ);
      }
#else
      static
      symbol_type
      make_tEQ ()
      {
        return symbol_type (token::tEQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tNE ()
      {
        return symbol_type (token::tNE);
      }
#else
      static
      symbol_type
      make_tNE ()
      {
        return symbol_type (token::tNE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tGE ()
      {
        return symbol_type (token::tGE);
      }
#else
      static
      symbol_type
      make_tGE ()
      {
        return symbol_type (token::tGE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tLE ()
      {
        return symbol_type (token::tLE);
      }
#else
      static
      symbol_type
      make_tLE ()
      {
        return symbol_type (token::tLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tLSHFT ()
      {
        return symbol_type (token::tLSHFT);
      }
#else
      static
      symbol_type
      make_tLSHFT ()
      {
        return symbol_type (token::tLSHFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tRSHFT ()
      {
        return symbol_type (token::tRSHFT);
      }
#else
      static
      symbol_type
      make_tRSHFT ()
      {
        return symbol_type (token::tRSHFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tPOW ()
      {
        return symbol_type (token::tPOW);
      }
#else
      static
      symbol_type
      make_tPOW ()
      {
        return symbol_type (token::tPOW);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tSIZEOF ()
      {
        return symbol_type (token::tSIZEOF);
      }
#else
      static
      symbol_type
      make_tSIZEOF ()
      {
        return symbol_type (token::tSIZEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tUPLUS ()
      {
        return symbol_type (token::tUPLUS);
      }
#else
      static
      symbol_type
      make_tUPLUS ()
      {
        return symbol_type (token::tUPLUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tUMINUS ()
      {
        return symbol_type (token::tUMINUS);
      }
#else
      static
      symbol_type
      make_tUMINUS ()
      {
        return symbol_type (token::tUMINUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tINC ()
      {
        return symbol_type (token::tINC);
      }
#else
      static
      symbol_type
      make_tINC ()
      {
        return symbol_type (token::tINC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tDEC ()
      {
        return symbol_type (token::tDEC);
      }
#else
      static
      symbol_type
      make_tDEC ()
      {
        return symbol_type (token::tDEC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tUINC ()
      {
        return symbol_type (token::tUINC);
      }
#else
      static
      symbol_type
      make_tUINC ()
      {
        return symbol_type (token::tUINC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tUDEC ()
      {
        return symbol_type (token::tUDEC);
      }
#else
      static
      symbol_type
      make_tUDEC ()
      {
        return symbol_type (token::tUDEC);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1937,     ///< Last index in yytable_.
      yynnts_ = 32,  ///< Number of nonterminal symbols.
      yyfinal_ = 40 ///< Termination state number.
    };


    // User arguments.
    mana::ParsingDriver* mParsingDriver;

  };


#line 19 "Parser.yy"
} // mana
#line 2722 "Parser.hpp"




#endif // !YY_YY_PARSER_HPP_INCLUDED
