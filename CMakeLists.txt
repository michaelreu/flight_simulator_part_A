cmake_minimum_required(VERSION 3.12)
project(14_12_12_46)

set(CMAKE_CXX_STANDARD 11)

add_executable(14_12_12_46 main.cpp Utils.cpp Utils.h expression/Expression.h expression/BinaryExpression.h expression/BinaryExpression.cpp expression/UnaryExpression.h  expression/UnaryExpression.cpp
        expression/Plus.h expression/Minus.h expression/Mult.h expression/Div.h expression/Num.h expression/Neg.h expression/Plus.cpp expression/Minus.cpp expression/Mult.cpp expression/Div.cpp expression/Num.cpp expression/Neg.cpp
        commands/Command.h commands/ExpressionCommand.h commands/ExpressionCommand.cpp commands/OpenServerCommand.h commands/OpenServerCommand.cpp
        reader/Reader.h reader/Reader.cpp
        shuntingYard/Operators.cpp shuntingYard/Operators.h shuntingYard/ShuntingYardExpression.h factory/ExpressionFactory.cpp factory/ExpressionFactory.h factory/CommandExpressionFactory.h maps/SymbolTable.cpp maps/SymbolTable.h reader/LexerParser.cpp reader/LexerParser.h
        factory/CommandExpressionFactory.cpp commands/ConnectCommand.cpp commands/ConnectCommand.h conditions/ConditionParser.cpp conditions/ConditionParser.h conditions/IfCommand.cpp conditions/IfCommand.h conditions/WhileCommand.cpp conditions/WhileCommand.h commands/vars/DefineVarCommand.cpp commands/vars/DefineVarCommand.h commands/AssignCommand.cpp commands/AssignCommand.h maps/VarValue.cpp maps/VarValue.h commands/PrintCommand.cpp commands/PrintCommand.h commands/SleepCommand.cpp commands/SleepCommand.h)
#Old/Token.cpp Old/Token.h Old/StringToDoubleClass.cpp Old/StringToDoubleClass.h Old/StrToDoubleShuntingYard.cpp Old/StrToDoubleShuntingYard.h tokens/Token1.cpp tokens/Token1.h