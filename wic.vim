if exists("b:current_syntax")
    finish
endif

" Comments
syntax match wicComment "\vUMM.*$"

" Operators
syntax match wicOperator '='
syntax match wicOperator '<='
syntax match wicOperator '>='
syntax match wicOperator '>'
syntax match wicOperator '<'
syntax match wicOperator '=='
syntax match wicOperator '-'
syntax match wicOperator '+'
syntax match wicOperator '*'
syntax match wicOperator '/'
syntax match wicOperator '!'
syntax match wicOperator '!='
syntax match wicOperator '||'
syntax match wicOperator '&&'

" Identifiers
syntax match wicIdentifier '\v[a-zA-Z][a-zA-Z0-9]*'

" Literals
syntax match wicLiteral '\v\d+'
syntax region wicLiteral start=/\v"/ skip=/\v\\./ end=/\v"/

" Keywords
syntax keyword wicKeyword DO I NEED FINDS A FROM CALLED AND ASK ABOUT SHOULD BE
syntax keyword wicKeyword THINK SHOW ME WATER LOOP RUN FROM GEESE CALCULATED
syntax keyword wicKeyword PLEASE WORK LIED
syntax match wicKeyword '\vRIGHT\?'

" Types
syntax keyword wicType int char string bool 

highlight link wicComment Comment
highlight link wicKeyword Keyword
highlight link wicOperator Operator
highlight link wicLiteral Constant
highlight link wicType Type
highlight link wicIdentifier Identifier

