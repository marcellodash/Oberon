

// This file was automatically generated by Coco/R; don't modify it.
#if !defined(Ob_COCO_PARSER_H__)
#define Ob_COCO_PARSER_H__

#include <QStack>
#include <Oberon/ObSynTree.h>


#include "ObLexer.h"

namespace Ob {



class Parser {
private:
	enum {
		_EOF=0,
		_T_Literals_=1,
		_T_Hash=2,
		_T_Amp=3,
		_T_Lpar=4,
		_T_Latt=5,
		_T_Rpar=6,
		_T_Star=7,
		_T_Ratt=8,
		_T_Plus=9,
		_T_Comma=10,
		_T_Minus=11,
		_T_Dot=12,
		_T_2Dot=13,
		_T_Slash=14,
		_T_2Slash=15,
		_T_Colon=16,
		_T_ColonEq=17,
		_T_Semi=18,
		_T_Lt=19,
		_T_Leq=20,
		_T_Eq=21,
		_T_Gt=22,
		_T_Geq=23,
		_T_Lbrack=24,
		_T_Rbrack=25,
		_T_Hat=26,
		_T_Lbrace=27,
		_T_Bar=28,
		_T_Rbrace=29,
		_T_Tilde=30,
		_T_Keywords_=31,
		_T_ARRAY=32,
		_T_BEGIN=33,
		_T_BY=34,
		_T_CASE=35,
		_T_CONST=36,
		_T_DEFINITION=37,
		_T_DIV=38,
		_T_DO=39,
		_T_ELSE=40,
		_T_ELSIF=41,
		_T_END=42,
		_T_FALSE=43,
		_T_FOR=44,
		_T_IF=45,
		_T_IMPORT=46,
		_T_IN=47,
		_T_IS=48,
		_T_MOD=49,
		_T_MODULE=50,
		_T_NIL=51,
		_T_OF=52,
		_T_OR=53,
		_T_POINTER=54,
		_T_PROCEDURE=55,
		_T_RECORD=56,
		_T_REPEAT=57,
		_T_RETURN=58,
		_T_THEN=59,
		_T_TO=60,
		_T_TRUE=61,
		_T_TYPE=62,
		_T_UNTIL=63,
		_T_VAR=64,
		_T_WHILE=65,
		_T_Specials_=66,
		_T_ident=67,
		_T_integer=68,
		_T_real=69,
		_T_string=70,
		_T_hexchar=71,
		_T_hexstring=72,
		_T_Comment=73,
		_T_Eof=74,
		_T_MaxToken_=75
	};
	int maxT;

	int errDist;
	int minErrDist;

	void SynErr(int n, const char* ctx = 0);
	void Get();
	void Expect(int n, const char* ctx = 0);
	bool StartOf(int s);
	void ExpectWeak(int n, int follow);
	bool WeakSeparator(int n, int syFol, int repFol);
    void SynErr(const QString& sourcePath, int line, int col, int n, Ob::Errors* err, const char* ctx, const QString& = QString() );

public:
	Ob::Lexer *scanner;
	Ob::Errors  *errors;

	Ob::Token d_cur;
	Ob::Token d_next;
	QList<Ob::Token> d_comments;
	struct TokDummy
	{
		int kind;
	};
	TokDummy d_dummy;
	TokDummy *la;			// lookahead token
	
	int peek( quint8 la = 1 );

    void RunParser()
    {
        d_stack.push(&d_root);
        Parse();
        d_stack.pop();
    }
    
Ob::SynTree d_root;
	QStack<Ob::SynTree*> d_stack;
	void addTerminal() {
		if( d_cur.d_type != Ob::Tok_Semi && d_cur.d_type != Ob::Tok_Comma && d_cur.d_type != Ob::Tok_Dot && d_cur.d_type != Ob::Tok_Colon ){
			Ob::SynTree* n = new Ob::SynTree( d_cur ); d_stack.top()->d_children.append(n);
		}
	}



	Parser(Ob::Lexer *scanner,Ob::Errors*);
	~Parser();
	void SemErr(const char* msg);

	void Oberon();
	void module();
	void definition();
	void number();
	void qualident();
	void identdef();
	void ConstDeclaration();
	void ConstExpression();
	void expression();
	void TypeDeclaration();
	void type();
	void ArrayType();
	void RecordType();
	void PointerType();
	void ProcedureType();
	void LengthList();
	void length();
	void BaseType();
	void FieldListSequence();
	void FieldList();
	void IdentList();
	void FormalParameters();
	void VariableDeclaration();
	void designator();
	void selector();
	void ExpList();
	void SimpleExpression();
	void relation();
	void term();
	void AddOperator();
	void factor();
	void MulOperator();
	void set();
	void variableOrFunctionCall();
	void element();
	void statement();
	void assignmentOrProcedureCall();
	void IfStatement();
	void CaseStatement();
	void WhileStatement();
	void RepeatStatement();
	void ForStatement();
	void StatementSequence();
	void ElsifStatement();
	void ElseStatement();
	void Case();
	void CaseLabelList();
	void LabelRange();
	void label();
	void ElsifStatement2();
	void ProcedureDeclaration();
	void ProcedureHeading();
	void ProcedureBody();
	void DeclarationSequence();
	void ReturnStatement();
	void DeclarationSequence2();
	void FPSection();
	void FormalType();
	void ImportList();
	void import();

	void Parse();

}; // end Parser

} // namespace


#endif

