#ifndef TYPES
#define TYPES

#define MAX_LEXEM_SIZE 80

typedef enum {
    FAILED,
    IDENTIFIER,
    POINT,
    ARROW,
    NEW_LINE,
    COLON,
    SEMICOLON,
    ONELINE_COMMENT,
    LITERALS,
    NUMERIC_LITERAL_DECIMAL,
    NUMERIC_LITERAL_HEX,
    SINGLE_STRING_LITERAL,
    DOUBLE_STRING_LITERAL,
    ROUND_LEFT_BRACKET,
    ROUND_RIGHT_BRACKET,
    SQUARE_LEFT_BRACKET,
    SQUARE_RIGHT_BRACKET,
    FIGURE_LEFT_BRACKET,
    FIGURE_RIGHT_BRACKET,
    OPERATORS,
    OPERATOR_PLUS,
    OPERATOR_MINUS,
    OPERATOR_DIVIDE,
    OPERATOR_MULTIPLY,
    OPERATOR_EXPONENT,
    OPERATOR_MODULUS,
    OPERATOR_INCREMENT,
    OPERATOR_DECREMENT,
    OPERATOR_ASSIGN,
    OPERATOR_ADD_ASSIGN,
    OPERATOR_SUB_ASSIGN,
    OPERATOR_MUL_ASSIGN,
    OPERATOR_DIV_ASSIGN,
    OPERATOR_MOD_ASSIGN,
    OPERATOR_EXP_ASSIGN,
    OPERATOR_EQUAL,
    OPERATOR_STRONG_EQUAL,
    OPERATOR_NOT_EQUAL,
    OPERATOR_STRONG_NOT_EQUAL,
    OPERATOR_GREATER,
    OPERATOR_LESS,
    OPERATOR_GREATER_EQUAL,
    OPERATOR_LESS_EQUAL,
    OPERATOR_LOGICAL_AND,
    OPERATOR_LOGICAL_OR,
    OPERATOR_LOGICAL_NOT,
    OPERATOR_AND,
    OPERATOR_OR,
    OPERATOR_LEFT_SHIFT,
    OPERATOR_RIGHT_SHIFT,
    RESERVED_WORDS,
    RESERVED_BREAK,
    RESERVED_CASE,
    RESERVED_CATCH,
    RESERVED_CLASS,
    RESERVED_CONST,
    RESERVED_CONTINUE,
    RESERVED_DEBUGGER,
    RESERVED_DEFAULT,
    RESERVED_DELETE,
    RESERVED_DO,
    RESERVED_ELSE,
    RESERVED_EXPORT,
    RESERVED_EXTENDS,
    RESERVED_FALSE,
    RESERVED_FINALLY,
    RESERVED_FOR,
    RESERVED_FUNCTION,
    RESERVED_IF,
    RESERVED_IMPORT,
    RESERVED_IN,
    RESERVED_INSTANCEOF,
    RESERVED_NEW,
    RESERVED_NULL,
    RESERVED_RETURN,
    RESERVED_SUPER,
    RESERVED_SWITCH,
    RESERVED_THIS,
    RESERVED_THROW,
    RESERVED_TRUE,
    RESERVED_TRY,
    RESERVED_TYPEOF,
    RESERVED_VAR,
    RESERVED_VOID,
    RESERVED_WHILE,
    RESERVED_WITH,
    RESERVED_LET,
    RESERVED_STATIC,
    RESERVED_YIELD,
    RESERVED_AWAIT,
    LEXEM_TYPE_SIZE
} LexemType;

typedef struct
{
    char name[MAX_LEXEM_SIZE];
    LexemType type;
} Lexem;

Lexem* empty_lexem();

LexemType from_string_to_lexem_type(char* str);
const char* from_lexem_type_to_string(LexemType type);

#endif