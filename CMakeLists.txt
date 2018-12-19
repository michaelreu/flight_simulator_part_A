cmake_minimum_required(VERSION 3.12)
project(14_12_12_46)

set(CMAKE_CXX_STANDARD 11)

add_executable(14_12_12_46 main.cpp Utils.cpp Utils.h expression/Expression.h expression/BinaryExpression.h expression/BinaryExpression.cpp expression/UnaryExpression.h  expression/UnaryExpression.cpp
        expression/Plus.h expression/Minus.h expression/Mult.h expression/Div.h expression/Num.h expression/Neg.h expression/Plus.cpp expression/Minus.cpp expression/Mult.cpp expression/Div.cpp expression/Num.cpp expression/Neg.cpp
        reader/Command.h reader/ExpressionCommand.h reader/ExpressionCommand.cpp reader/OpenServerCommand.h reader/OpenServerCommand.cpp
        reader/Reader.h reader/Reader.cpp
        shuntingYard/Operators.cpp shuntingYard/Operators.h shuntingYard/ShuntingYardExpression.h maps/CommandMapClass.h factory/ExpressionFactory.cpp factory/ExpressionFactory.h factory/CommandExpressionFactory.h maps/SymbolTable.cpp maps/SymbolTable.h reader/LexerParser.cpp reader/LexerParser.h
        maps/CommandFactoryMap.cpp maps/CommandFactoryMap.h maps/CommandMapClass.cpp factory/CommandExpressionFactory.cpp reader/ConnectCommand.cpp reader/ConnectCommand.h factory/ifCommandFactory.cpp factory/ifCommandFactory.h reader/ConditionParser.cpp reader/ConditionParser.h reader/IfCondition.cpp reader/IfCondition.h reader/WhileCondition.cpp reader/WhileCondition.h factory/whileCommandFactory.cpp factory/whileCommandFactory.h)
#Old/Token.cpp Old/Token.h Old/StringToDoubleClass.cpp Old/StringToDoubleClass.h Old/StrToDoubleShuntingYard.cpp Old/StrToDoubleShuntingYard.h tokens/Token1.cpp tokens/Token1.h